// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestPropertyBase.h"
#include "QuestRewardInterface.h"
#include "CurrencyReward.generated.h"


UCLASS()
class QUESTSYSTEMCOMMONS_API UCurrencyReward : public UQuestPropertyBase, public IQuestRewardInterface
{
	GENERATED_BODY()
	
public:
	virtual void CollectQuestReward() override;

};
