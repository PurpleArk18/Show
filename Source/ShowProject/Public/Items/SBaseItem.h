// Copyright to Andres Echeverri 2026

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBaseItem.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS(Abstract)
class SHOWPROJECT_API ASBaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASBaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USphereComponent> SphereCollider;

	UFUNCTION()
	virtual void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
