// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubclassOf.h"

#include "Interfaces/QuestInterface.h"
#include "Interfaces/QuestProperties/QuestRepeatabilityInterface.h"
#include "Interfaces/QuestProperties/QuestRequirementInterface.h"
#include "Interfaces/QuestProperties/QuestRewardInterface.h"
#include "Interfaces/QuestProperties/QuestTypeInterface.h"

#include "QuestPropertyBase.h"
#include "Quest.generated.h"

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

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest")
	FText Title;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest")
	FText Description;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestTypeInterface"))
	TSubclassOf<UQuestPropertyBase> QuestTypeClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestRepeatabilityInterface"))
	TSubclassOf<UQuestPropertyBase> RepeatabilityClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestRequirementInterface"))
	TArray<TSubclassOf<UQuestPropertyBase>> RequirementClasses;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Quest", meta = (MustImplement = "QuestRewardInterface"))
	TArray<TSubclassOf<UQuestPropertyBase>> RewardClasses;


	UQuest();

#pragma region IQuestInterface
	virtual void Initialize() override;

	virtual bool IsQuestUnavailable() const override;

	virtual bool CanQuestBeStarted() const override;

	virtual bool HasQuestStarted() const override;

	virtual bool HasQuestEnded() const override;

	virtual bool IsQuestAlreadyRewarded() const override;

	virtual bool TryStartQuest(TScriptInterface<IQuestTakerInterface> QuestTaker) override;

	virtual void EndQuest(EQuestEndReason EndReason) override;

	virtual EQuestStatus GetQuestStatus() const override;

	virtual FText GetQuestTitle() const override;

	virtual FText GetQuestDescription() const override;

	virtual TScriptInterface<IQuestTakerInterface> GetQuestOwner() const override;
#pragma endregion IQuestInterface


#pragma region IQuestPropertyInterfaces
	virtual void ExecuteQuestTypeBehaviour() override;
	
	virtual void EvaluateQuestRepeatability() override;

	virtual bool CheckQuestRequirement() const override;
	
	virtual void CollectQuestReward() override;
#pragma endregion IQuestPropertyInterfaces

protected:
	UFUNCTION()
	virtual void UpdateQuestStatus();

	UFUNCTION()
	bool IsInitialized() const;

	UFUNCTION()
	virtual void ConstructQuestProperties();

private:
	UFUNCTION()
	void ConstructQuestRewards();

	UFUNCTION()
	void ConstructQuestRequirements();

	UFUNCTION()
	void ConstructQuestRepeatability();

	UFUNCTION()
	void ConstructQuestType();


	UPROPERTY()
	TScriptInterface<IQuestTypeInterface> QuestType;

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
};
