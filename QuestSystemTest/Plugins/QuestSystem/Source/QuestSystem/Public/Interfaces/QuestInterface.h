// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface.h"
#include "CoreMinimal.h"

#include "QuestTakerInterface.h"
#include "Types/QuestEndReasonEnum.h"
#include "Types/QuestStatusEnum.h"

#include "QuestInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestInterface : public UInterface
{
	GENERATED_BODY()
};

class QUESTSYSTEM_API IQuestInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual bool TryStartQuest(TScriptInterface<IQuestTakerInterface> QuestTaker) = 0;

	UFUNCTION()
	virtual void EndQuest(EQuestEndReason EndReason) = 0;
	
	UFUNCTION()
	virtual EQuestStatus GetQuestStatus() const = 0;

	UFUNCTION()
	virtual FText GetQuestTitle() const = 0;

	UFUNCTION()
	virtual FText GetQuestDescription() const = 0;

	UFUNCTION()
	virtual TScriptInterface<IQuestTakerInterface> GetQuestOwner() const = 0;

	UFUNCTION()
	virtual void Initialize() = 0;

	UFUNCTION()
	virtual bool IsQuestUnavailable() const = 0;

	UFUNCTION()
	virtual bool CanQuestBeStarted() const = 0;

	UFUNCTION()
	virtual bool HasQuestStarted() const = 0;

	UFUNCTION()
	virtual bool HasQuestEnded() const = 0;

	UFUNCTION()
	virtual bool IsQuestAlreadyRewarded() const = 0;
};
