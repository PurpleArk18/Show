// Copyright to Andres Echeverri 2023


#include "Components/SInventoryComponent.h"
#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
USInventoryComponent::USInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	MaxCapacity = 4;
	// ...
}

USInventoryComponent::USInventoryComponent(TMap<EItemID, int> StartItems)
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	ItemContainer = StartItems;
	MaxCapacity = 4;
}


// Called when the game starts
void USInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void USInventoryComponent::AddItem(EItemID item)
{
	if (ItemContainer.Num() < MaxCapacity)
	{
		if (ItemContainer.Contains(item))
		{
			ItemContainer[item] += 1;
		}
		else
		{
			ItemContainer.Add(item);
		}
	}
}

void USInventoryComponent::RemoveItem(EItemID item)
{
	if (ItemContainer.Contains(item))
	{
		if (ItemContainer[item] > 0)
		{
			ItemContainer[item] -= 1;
		}
		else
		{
			ItemContainer.Remove(item);
		}
	}
}

bool USInventoryComponent::HasItem(EItemID item)
{
	return ItemContainer.Contains(item);
}

int USInventoryComponent::GetMaxCapacity() const
{
	return MaxCapacity;
}

int USInventoryComponent::GetAvailableCapacity()
{
	return MaxCapacity - ItemContainer.Num();
}

void USInventoryComponent::IncreaseMaxCapacity(int AmountToIncrease)
{
	MaxCapacity += AmountToIncrease;
}

TMap<EItemID, int> USInventoryComponent::GetCurrentItems() const
{
	return ItemContainer;
}

void USInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USInventoryComponent, MaxCapacity);
}

