// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestPropertyInterface.h"
#include "QuestRepeatabilityInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestRepeatabilityInterface : public UQuestPropertyInterface
{
	GENERATED_BODY()
};


class QUESTSYSTEM_API IQuestRepeatabilityInterface : public IQuestPropertyInterface
{
	GENERATED_BODY()

public:
	virtual FName GetPropertyName() const override;
	
	UFUNCTION()
	virtual void EvaluateQuestRepeatability() = 0;
};
