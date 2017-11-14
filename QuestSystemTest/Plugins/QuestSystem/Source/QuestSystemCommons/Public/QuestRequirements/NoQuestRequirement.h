// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestPropertyBase.h"
#include "QuestRequirementInterface.h"
#include "NoQuestRequirement.generated.h"


UCLASS()
class QUESTSYSTEMCOMMONS_API UNoQuestRequirement : public UQuestPropertyBase, public IQuestRequirementInterface
{
	GENERATED_BODY()
	
public:
	virtual bool CheckQuestRequirement() const override;

};
