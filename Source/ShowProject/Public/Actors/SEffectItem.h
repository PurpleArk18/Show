// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "Items/SBaseItem.h"
#include "Interfaces/SInteractable.h"
#include "Components/MeshComponent.h"
#include "SEffectItem.generated.h"

class UGameplayEffect;

UCLASS()
class SHOWPROJECT_API ASEffectItem : public ASBaseItem, public ISInteractable
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

	virtual void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

};
