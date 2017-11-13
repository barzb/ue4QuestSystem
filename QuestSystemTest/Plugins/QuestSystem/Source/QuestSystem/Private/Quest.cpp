// Fill out your copyright notice in the Description page of Project Settings.

#include "Quest.h"
#include "QuestSystem.h"
#include "QuestPropertyBase.h"


UQuest::UQuest()
	: bInitialized(false)
	, QuestStatus(EQuestStatus::QS_Unavailable)
{

}

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

void UQuest::ConstructQuestProperties()
{
	ConstructQuestType();
	ConstructQuestRepeatability();
	ConstructQuestRequirements();
	ConstructQuestRewards();
}

void UQuest::UpdateQuestStatus()
{
	unimplemented();

	OnQuestStatusChanged.Broadcast(QuestStatus);
}

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

bool UQuest::IsInitialized() const
{
	return bInitialized;
}

bool UQuest::TryStartQuest(TScriptInterface<IQuestTakerInterface> QuestTaker)
{
	UpdateQuestStatus();

	if (CheckRequirement())
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


bool UQuest::CheckRequirement() const
{
	if (GetQuestStatus() != EQuestStatus::QS_Available) {
		return false;
	}

	for (const TScriptInterface<IQuestRequirementInterface>& Requirement : Requirements)
	{
		if (Requirement->CheckRequirement() == false) {
			return false;
		}
	}

	return true;
}


void UQuest::Collect()
{
	for (TScriptInterface<IQuestRewardInterface>& Reward : Rewards)
	{
		Reward->Collect();
	}
}