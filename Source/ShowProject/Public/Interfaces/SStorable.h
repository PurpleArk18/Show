// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Items/SItemsData.h"
#include "SStorable.generated.h"

class UTexture2D;
enum class EItemID : uint8;
class ISInventoryInterface;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USStorable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOWPROJECT_API ISStorable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Store(const TScriptInterface<ISInventoryInterface>& Inventory);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Remove(const TScriptInterface<ISInventoryInterface>& Inventory);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UTexture2D* GetStorageIcon();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FText GetStorageName();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FText GetStorageDescription();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	EItemID GetStorageID();

};
