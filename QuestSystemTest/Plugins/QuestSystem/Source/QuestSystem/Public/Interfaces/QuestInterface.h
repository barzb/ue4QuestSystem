// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestTakerInterface.h"
#include "QuestInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestInterface : public UInterface
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class EQuestEndReason : uint8
{
	QER_Completed,
	QER_Abandoned,
	QER_Failed,
	QER_Displaced,
	QER_Unavailable
};

UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
	QS_Unavailable,
	QS_Available,
	QS_Started,
	QS_Ended,
	QS_Rewarded
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
};
