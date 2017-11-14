// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestPropertyBase.h"
#include "QuestRepeatabilityInterface.h"
#include "OneTimeQuest.generated.h"


UCLASS()
class QUESTSYSTEMCOMMONS_API UOneTimeQuest : public UQuestPropertyBase, public IQuestRepeatabilityInterface
{
	GENERATED_BODY()

public:
	virtual void EvaluateQuestRepeatability() override;
};
