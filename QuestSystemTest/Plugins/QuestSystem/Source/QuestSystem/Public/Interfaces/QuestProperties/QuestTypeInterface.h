// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestPropertyInterface.h"
#include "QuestTypeInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestTypeInterface : public UQuestPropertyInterface
{
	GENERATED_BODY()
};


class QUESTSYSTEM_API IQuestTypeInterface : public IQuestPropertyInterface
{
	GENERATED_BODY()

public:
	virtual FName GetPropertyName() const override;

	UFUNCTION()
	virtual void ExecuteQuestTypeBehaviour() = 0;
};
