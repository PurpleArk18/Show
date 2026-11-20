// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "SItemsData.generated.h"

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