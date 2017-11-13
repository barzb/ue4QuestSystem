// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestPropertyBase.h"
#include "../Interfaces/QuestProperties/QuestTypeInterface.h"
#include "KillQuest.generated.h"


UCLASS()
class QUESTSYSTEM_API UKillQuest : public UQuestPropertyBase, public IQuestTypeInterface
{
	GENERATED_BODY()

public:
	virtual void ExecuteQuestTypeBehaviour() override;

};
