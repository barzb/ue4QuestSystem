// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestManagerComponent.h"

UQuestManagerComponent::UQuestManagerComponent()
{

}


void UQuestManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeQuestManager();
}

void UQuestManagerComponent::InitializeQuestManager()
{
	InstantiateQuests();
	RestoreQuestsFromSavegame();
}

#if WITH_EDITOR
void UQuestManagerComponent::InstantiateEditorQuests()
{
	for (const TSubclassOf<UQuest>& EditorQuestClass : EditorQuestClasses)
	{
		TScriptInterface<IQuestInterface> NewEditorQuest = NewObject<UQuest>(this, EditorQuestClass);
		NewEditorQuest->Initialize();

		AllQuests.Add(NewEditorQuest);

		/*if (NewEditorQuest->CanQuestBeStarted())
		{
			AvailableQuests.Add(NewEditorQuest);
		}*/
	}
}
#endif

void UQuestManagerComponent::InstantiateQuests()
{
#if WITH_EDITOR
	InstantiateEditorQuests();
#endif
}

void UQuestManagerComponent::RestoreQuestsFromSavegame()
{
	
}
