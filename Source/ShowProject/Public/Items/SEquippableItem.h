// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "Items/SBaseItem.h"
#include "Interfaces/SEquippable.h"
#include "Interfaces/SStorable.h"
#include "SEquippableItem.generated.h"

/**
 * 
 */
UCLASS()
class SHOWPROJECT_API ASEquippableItem : public ASBaseItem, public ISEquippable, public ISStorable
{
	GENERATED_BODY()
	
};
