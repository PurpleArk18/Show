// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/SItemsDataTypes.h"
#include "SEquippableData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SHOWPROJECT_API USEquippableData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equippable Data")
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equippable Data")
	FText SocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equippable Data", meta = (BitMask, BitmaskEnum = "/Script/ShowProject.EItemSlot"))
	uint8 ItemSlot;
};
