// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Items/SBaseItem.h"
#include "Interfaces/SInteractable.h"
#include "Interfaces/SStorable.h"
#include "Components/MeshComponent.h"
#include "SEffectItem.generated.h"

class USStorableData;
class UTexture2D;
class ISInventoryInterface;

UCLASS()
class SHOWPROJECT_API ASEffectItem : public ASBaseItem, public ISInteractable, public ISStorable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASEffectItem();

	void Interaction_Implementation(APawn* InstigatorPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect>  EffectClass);

	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UGameplayEffect> InstantEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<USStorableData> StorableData;

	virtual void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	void Store_Implementation(const TScriptInterface<ISInventoryInterface>& Inventory);
	void Remove_Implementation(const TScriptInterface<ISInventoryInterface>& Inventory);
	UTexture2D* GetStorageIcon_Implementation();
	FText GetStorageName_Implementation();
	FText GetStorageDescription_Implementation();
};
