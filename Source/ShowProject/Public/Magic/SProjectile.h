// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
class UParticleSystem;
class UNiagaraSystem;
class UNiagaraComponent;

UCLASS(Abstract)
class SHOWPROJECT_API ASProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASProjectile();

protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UNiagaraComponent> ParticleSystem;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UNiagaraSystem> TriggerVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	float SphereRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	float ProjectileSpeed;

	UFUNCTION()
	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnCollision(AActor* OtherActor);

	virtual void PostInitializeComponents() override;
};
