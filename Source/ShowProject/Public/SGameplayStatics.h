// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/SItemsDataTypes.h"
#include "SGameplayStatics.generated.h"

class USPlayerHUDVM;
/**
 * 
 */
UCLASS()
class SHOWPROJECT_API USGameplayStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static USPlayerHUDVM* GetHUDVM(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static TArray<EItemID> GetIDsFromBitmask(uint8 Bitmask);
};
