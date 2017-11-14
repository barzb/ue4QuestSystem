// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestPropertyBase.h"
#include "QuestTypeInterface.h"
#include "KillQuest.generated.h"


UCLASS()
class QUESTSYSTEMCOMMONS_API UKillQuest : public UQuestPropertyBase, public IQuestTypeInterface
{
	GENERATED_BODY()

public:
	virtual void ExecuteQuestTypeBehaviour() override;

};
