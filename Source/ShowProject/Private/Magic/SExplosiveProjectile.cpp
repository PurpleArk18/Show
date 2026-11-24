// Copyright to Andres Echeverri 2026


#include "Magic/SExplosiveProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

void ASExplosiveProjectile::Explode_Implementation()
{
	if (!IsPendingKillPending())
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, TriggerVFX, GetActorLocation(), GetActorRotation());
		Destroy();
	}
}

void ASExplosiveProjectile::OnCollision(AActor* OtherActor)
{
	Explode();
}
