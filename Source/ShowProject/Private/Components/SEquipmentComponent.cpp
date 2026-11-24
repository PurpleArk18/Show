// Copyright to Andres Echeverri 2026


#include "Components/SEquipmentComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
USEquipmentComponent::USEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void USEquipmentComponent::RemoveEquippedItem(EItemID ItemID)
{
}

bool USEquipmentComponent::IsSlotEquipped(uint8 ItemSlots) const
{
	return (EquippedSlots & ItemSlots) != 0;
}

// Called when the game starts
void USEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

TArray<EItemID> USEquipmentComponent::GetIDsFromBitmask(uint8 Bitmask) const
{
	TArray<EItemID> ActiveIDs;
	const UEnum* EnumPtr = StaticEnum<EItemID>();
	if (!EnumPtr) return ActiveIDs;

	// NumEnums() - 1 skips the auto-generated _MAX entry
	for (int32 i = 0; i < EnumPtr->NumEnums() - 1; ++i)
	{
		int64 Value = EnumPtr->GetValueByIndex(i);

		if (Value != 0 && (Bitmask & Value) == Value)
		{
			ActiveIDs.Add(static_cast<EItemID>(Value));
		}
	}

	return ActiveIDs;
}

bool USEquipmentComponent::TryEquipItem(uint8 ItemSlots)
{
	if (IsSlotEquipped(ItemSlots))
	{
		return false;
	}
	else
	{
		EquippedSlots |= ItemSlots;
		TArray<EItemID> ItemSlotIDs = GetIDsFromBitmask(ItemSlots);

		return true;
	}
	
}

TSet<EItemID> USEquipmentComponent::GetEquippedItems() const
{
	return EquippedItems;
}

void USEquipmentComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USEquipmentComponent, EquippedItems);
}
