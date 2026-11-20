// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/SItemsData.h"
#include "SInventoryComponent.generated.h"


UCLASS( ClassGroup=(Inventory), meta=(BlueprintSpawnableComponent) )
class SHOWPROJECT_API USInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USInventoryComponent();

	USInventoryComponent(TMap<EItemID, int> StartItems);

protected:
	UPROPERTY(Replicated)
	int MaxCapacity;

	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<EItemID, int> ItemContainer = TMap<EItemID, int>();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem(EItemID item);

	void RemoveItem(EItemID item);

	bool HasItem(EItemID item); 
	
	UFUNCTION(BlueprintCallable)
	int GetMaxCapacity() const;
	
	UFUNCTION(BlueprintCallable)
	int GetAvailableCapacity();

	UFUNCTION()
	void IncreaseMaxCapacity(int AmountToIncrease);
};
