// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/SItemsDataTypes.h"
#include "SEquipmentComponent.generated.h"

class USEquippableData;

UCLASS( ClassGroup=(Equipment), meta=(BlueprintSpawnableComponent) )
class SHOWPROJECT_API USEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USEquipmentComponent();

	UFUNCTION(BlueprintCallable)
	bool TryEquipItem(uint8 ItemSlots);

	UFUNCTION(BlueprintCallable)
	TSet<EItemID> GetEquippedItems() const;

	UFUNCTION(BlueprintCallable)
	void RemoveEquippedItem(EItemID ItemID);

	UFUNCTION(BlueprintCallable)
	bool IsSlotEquipped(uint8 ItemSlots) const;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TSet<EItemID> EquippedItems = TSet<EItemID>();

	UPROPERTY(Replicated, meta = (BitMask, BitmaskEnum = "/Script/ShowProject.EItemSlot"))
	uint8 EquippedSlots;

	TArray<EItemID> GetIDsFromBitmask(uint8 Bitmask) const;
	
};
