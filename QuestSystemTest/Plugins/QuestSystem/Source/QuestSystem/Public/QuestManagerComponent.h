// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Interfaces/QuestInterface.h"
#include "Quest.h"

#include "QuestManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UQuestManagerComponent();

	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void InitializeQuestManager();

#if WITH_EDITOR
	UFUNCTION()
	void InstantiateEditorQuests();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UQuest>> EditorQuestClasses;
#endif

private:
	UFUNCTION() // TODO
	void InstantiateQuests();

	UFUNCTION() // TODO
	void RestoreQuestsFromSavegame();


	UPROPERTY()
	TArray<TScriptInterface<IQuestInterface>> AllQuests;

	UPROPERTY()
	TArray<TScriptInterface<IQuestInterface>> AvailableQuests;

	UPROPERTY()
	TArray<TScriptInterface<IQuestInterface>> StartedQuests;

	UPROPERTY()
	TArray<TScriptInterface<IQuestInterface>> CompletedQuests;

	UPROPERTY()
	TArray<TScriptInterface<IQuestInterface>> FailedQuests;
};
