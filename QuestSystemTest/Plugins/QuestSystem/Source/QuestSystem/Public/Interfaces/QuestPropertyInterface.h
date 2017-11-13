// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface.h"
#include "CoreMinimal.h"
#include "QuestPropertyInterface.generated.h"


UINTERFACE(MinimalAPI)
class UQuestPropertyInterface : public UInterface
{
	GENERATED_BODY()
};


class QUESTSYSTEM_API IQuestPropertyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual FName GetPropertyName() const = 0;
	
};
