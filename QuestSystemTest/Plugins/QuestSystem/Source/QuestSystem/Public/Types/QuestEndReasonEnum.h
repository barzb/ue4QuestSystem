// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EQuestEndReason : uint8
{
	QER_Completed,
	QER_Abandoned,
	QER_Failed,
	QER_Displaced,
	QER_Unavailable
};