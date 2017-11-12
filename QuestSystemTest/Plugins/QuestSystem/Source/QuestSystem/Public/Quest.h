// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Interfaces/QuestInterface.h"
#include "Interfaces/QuestProperties/QuestRepeatabilityInterface.h"
#include "Interfaces/QuestProperties/QuestRequirementInterface.h"
#include "Interfaces/QuestProperties/QuestRewardInterface.h"
#include "Interfaces/QuestProperties/QuestTypeInterface.h"

#include "Quest.generated.h"

class UQuestPropertyBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestStatusChangedSignature, EQuestStatus, NewQuestStatus);

UCLASS(Blueprintable, ABSTRACT)
class QUESTSYSTEM_API UQuest 
	: public UObject
	, public IQuestInterface
	, public IQuestTypeInterface
	, public IQuestRepeatabilityInterface
	, public IQuestRequirementInterface
	, public IQuestRewardInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Quest")
	FOnQuestStatusChangedSignature OnQuestStatusChanged;

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest")
	FText Title;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest")
	FText Description;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestTypeInterface"))
	TSubclassOf<UQuestPropertyBase> TypeClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestRepeatabilityInterface"))
	TSubclassOf<UQuestPropertyBase> RepeatabilityClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestRequirementInterface"))
	TArray<TSubclassOf<UQuestPropertyBase>> RequirementClasses;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestRewardInterface"))
	TArray<TSubclassOf<UQuestPropertyBase>> RewardClasses;

private:
	UPROPERTY()
	TScriptInterface<IQuestTypeInterface> Type;

	UPROPERTY()
	TScriptInterface<IQuestRepeatabilityInterface> Repeatability;

	UPROPERTY()
	TArray<TScriptInterface<IQuestRequirementInterface>> Requirements;

	UPROPERTY()
	TArray<TScriptInterface<IQuestRewardInterface>> Rewards;

	UPROPERTY()
	TScriptInterface<IQuestTakerInterface> QuestOwner;

	UPROPERTY()
	EQuestStatus QuestStatus;

	bool bInitialized;

public:
	UQuest();

	void Initialize();

protected:
	virtual void ConstructQuestProperties();

	virtual void UpdateQuestStatus();

	bool IsInitialized() const;

private:
	void ConstructQuestRewards();

	void ConstructQuestRequirements();

	void ConstructQuestRepeatability();

	void ConstructQuestType();

#pragma region IQuestInterface
public:
	virtual bool TryStartQuest(TScriptInterface<IQuestTakerInterface> QuestTaker) override;

	virtual void EndQuest(EQuestEndReason EndReason) override;

	virtual EQuestStatus GetQuestStatus() const override;

	virtual FText GetQuestTitle() const override;

	virtual FText GetQuestDescription() const override;

	virtual TScriptInterface<IQuestTakerInterface> GetQuestOwner() const override;
#pragma endregion IQuestInterface


#pragma region IQuestRepeatabilityInterface
public:
	
#pragma endregion IQuestRepeatabilityInterface


#pragma region IQuestRequirementInterface
public:
	virtual bool CheckRequirement() const override;
	
#pragma endregion IQuestRequirementInterface


#pragma region IQuestTypeInterface
public:
	
#pragma endregion IQuestTypeInterface


#pragma region IQuestRewardInterface
public:
	virtual void Collect() override;
#pragma endregion IQuestRewardInterface

};
