// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestPropertyInterface.h"
#include "QuestRequirementInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestRequirementInterface : public UQuestPropertyInterface
{
	GENERATED_BODY()
};


class QUESTSYSTEM_API IQuestRequirementInterface : public IQuestPropertyInterface
{
	GENERATED_BODY()

public:
	virtual FName GetPropertyName() const override;

	UFUNCTION()
	virtual bool CheckQuestRequirement() const = 0;
};
