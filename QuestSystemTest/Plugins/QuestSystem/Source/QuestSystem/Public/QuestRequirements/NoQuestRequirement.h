// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../QuestPropertyBase.h"
#include "../Interfaces/QuestProperties/QuestRequirementInterface.h"
#include "NoQuestRequirement.generated.h"


UCLASS()
class QUESTSYSTEM_API UNoQuestRequirement : public UQuestPropertyBase, public IQuestRequirementInterface
{
	GENERATED_BODY()
	
public:
	virtual bool CheckRequirement() const override;

};
