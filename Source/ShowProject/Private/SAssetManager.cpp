// Copyright to Andres Echeverri 2023


#include "SAssetManager.h"
#include "AbilitySystem/SGameplayTags.h"
#include "Engine/Engine.h"

USAssetManager& USAssetManager::Get()
{
	check(GEngine);

	USAssetManager* SAssetmanager = Cast<USAssetManager>(GEngine->AssetManager);
	return *SAssetmanager;
}
void USAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FSGameplayTags::InitializeGameplayTags();
}
