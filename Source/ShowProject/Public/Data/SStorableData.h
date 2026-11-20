// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Items/SItemsData.h"
#include "SStorableData.generated.h"

class UTexture2D;
/**
 * 
 */
UCLASS(BlueprintType)
class SHOWPROJECT_API USStorableData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Storage")
	EItemID StorageID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Storage")
	TObjectPtr<UTexture2D> StorageIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Storage")
	FText StorageName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Storage")
	FText StorageDescription;
};
