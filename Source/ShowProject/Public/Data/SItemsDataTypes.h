// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "SItemsDataTypes.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	WEAPON,
	POTION,
	SHIELD,
	HELMET,
	ARMOR,
	RING,
	AMULET,
	// Add more item types as needed
};

UENUM(BlueprintType)
enum class EItemID : uint8
{
	HEALTH_POTION,
	MANA_POTION,
	SPEED_POTION,
	GOLD_POTION,
	IRON_SWORD,
	STEEL_SWORD,
	WOODEN_SHIELD,
	IRON_SHIELD,
	LEATHER_HELMET,
	STEEL_HELMET,
	LEATHER_ARMOR,
	STEEL_ARMOR,
	AMULET_OF_POWER,
	RING_OF_PROTECTION,
	// Add more item IDs as needed
};

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EItemSlot : uint8
{
	NONE = 0 UMETA(Hidden),
	HEAD = 1 << 0,
	BODY = 1 << 1,
	LEGS = 1 << 2,
	FEET = 1 << 3,
	WEAPON = 1 << 4,
	SHIELD = 1 << 5,
	RING = 1 << 6,
	AMULET = 1 << 7,
	// Add more item slots as needed
};
ENUM_CLASS_FLAGS(EItemSlot);