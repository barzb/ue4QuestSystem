// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "QuestSystemTestGameMode.h"
#include "QuestSystemTestPlayerController.h"
#include "QuestSystemTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AQuestSystemTestGameMode::AQuestSystemTestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AQuestSystemTestPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}