// Fill out your copyright notice in the Description page of Project Settings.

#include "Quest.h"
#include "QuestSystem.h"
#include "QuestPropertyBase.h"

// v------------------ public -------------------v

UQuest::UQuest()
	: bInitialized(false)
	, QuestStatus(EQuestStatus::QS_Unavailable)
{

}

#pragma region IQuestInterface

void UQuest::Initialize()
{
	if (!IsInitialized())
	{
		ConstructQuestProperties();
		bInitialized = true;
	}
	else
	{
		UE_LOG(LogQuestSystem, Warning, TEXT("Tried to initialize quest '%s' multiple times"), *Title.ToString());
	}
}

bool UQuest::IsQuestUnavailable() const
{
	return GetQuestStatus() ==  EQuestStatus::QS_Unavailable;
}

bool UQuest::CanQuestBeStarted() const
{
	return GetQuestStatus() == EQuestStatus::QS_Available;
}

bool UQuest::HasQuestStarted() const
{
	return GetQuestStatus() == EQuestStatus::QS_Started;
}

bool UQuest::HasQuestEnded() const
{
	return GetQuestStatus() == EQuestStatus::QS_Ended;
}

bool UQuest::IsQuestAlreadyRewarded() const
{
	return GetQuestStatus() == EQuestStatus::QS_Rewarded;
}

bool UQuest::TryStartQuest(TScriptInterface<IQuestTakerInterface> QuestTaker)
{
	UpdateQuestStatus();

	if (CheckQuestRequirement())
	{
		QuestOwner = QuestTaker;
		unimplemented();

		return true;
	}

	return false;
}

void UQuest::EndQuest(EQuestEndReason EndReason)
{
	unimplemented();
}

EQuestStatus UQuest::GetQuestStatus() const
{
	return QuestStatus;
}

FText UQuest::GetQuestTitle() const
{
	return Title;
}

FText UQuest::GetQuestDescription() const
{
	return Description;
}

TScriptInterface<IQuestTakerInterface> UQuest::GetQuestOwner() const
{
	return QuestOwner;
}

#pragma endregion IQuestInterface

#pragma region IQuestPropertyInterfaces

void UQuest::ExecuteQuestTypeBehaviour()
{
	QuestType->ExecuteQuestTypeBehaviour();
}

void UQuest::EvaluateQuestRepeatability()
{
	Repeatability->EvaluateQuestRepeatability();
}

bool UQuest::CheckQuestRequirement() const
{
	if (CanQuestBeStarted() == false) {
		return false;
	}

	for (const TScriptInterface<IQuestRequirementInterface>& Requirement : Requirements)
	{
		if (Requirement->CheckQuestRequirement() == false) {
			return false;
		}
	}

	return true;
}

void UQuest::CollectQuestReward()
{
	for (TScriptInterface<IQuestRewardInterface>& Reward : Rewards)
	{
		Reward->CollectQuestReward();
	}
}

#pragma endregion IQuestPropertyInterfaces

// v------------------ protected -------------------v

void UQuest::UpdateQuestStatus()
{
	unimplemented();

	OnQuestStatusChanged.Broadcast(QuestStatus);
}

bool UQuest::IsInitialized() const
{
	return bInitialized;
}

void UQuest::ConstructQuestProperties()
{
	ConstructQuestType();
	ConstructQuestRepeatability();
	ConstructQuestRequirements();
	ConstructQuestRewards();
}

// v------------------ private -------------------v

void UQuest::ConstructQuestType()
{
	QuestType = NewObject<UQuestPropertyBase>(this, QuestTypeClass);
}

void UQuest::ConstructQuestRepeatability()
{
	Repeatability = NewObject<UQuestPropertyBase>(this, RepeatabilityClass);
}

void UQuest::ConstructQuestRequirements()
{
	for (TSubclassOf<UQuestPropertyBase>& RequirementClass : RequirementClasses) {
		Requirements.Add(NewObject<UQuestPropertyBase>(this, RequirementClass));
	}
}

void UQuest::ConstructQuestRewards()
{
	for (TSubclassOf<UQuestPropertyBase>& RewardClass : RewardClasses) {
		Rewards.Add(NewObject<UQuestPropertyBase>(this, RewardClass));
	}
}