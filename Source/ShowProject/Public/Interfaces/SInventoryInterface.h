// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SInventoryInterface.generated.h"

class USInventoryComponent;
class USStorableData;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOWPROJECT_API ISInventoryInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	USInventoryComponent* GetInventoryComponent() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddItemToInventory(const USStorableData* ItemData);
};
