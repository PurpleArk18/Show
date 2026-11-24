// Copyright to Andres Echeverri 2023


#include "Magic/ASDashProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TimerManager.h"
#include "GameFramework/Pawn.h"

AASDashProjectile::AASDashProjectile()
{
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

	ProjectileMovement->InitialSpeed = 6000.f;
}

void AASDashProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_DelayedDetonate, this, &AASDashProjectile::Trigger, DetonateDelay);
}

void AASDashProjectile::Trigger()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_DelayedDetonate);

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, TriggerVFX, GetActorLocation(), GetActorRotation());

	ParticleSystem->Deactivate();

	ProjectileMovement->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayedTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayedTeleport, this, &AASDashProjectile::TeleportInstigator, TeleportDelay);
}

void AASDashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ActorToTeleport)
	{
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
	}
}




