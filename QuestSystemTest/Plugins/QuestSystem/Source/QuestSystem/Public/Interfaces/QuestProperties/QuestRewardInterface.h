// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestPropertyInterface.h"
#include "QuestRewardInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestRewardInterface : public UQuestPropertyInterface
{
	GENERATED_BODY()
};

class QUESTSYSTEM_API IQuestRewardInterface : public IQuestPropertyInterface
{
	GENERATED_BODY()

public:
	virtual FName GetPropertyName() const override;

	UFUNCTION()
	virtual void CollectQuestReward() = 0;
};
