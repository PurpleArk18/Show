// Copyright to Andres Echeverri 2026


#include "Items/SBaseItem.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASBaseItem::ASBaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetIsReplicated(true);
	SphereCollider->SetMobility(EComponentMobility::Movable);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetIsReplicated(true);

	SphereCollider->SetupAttachment(Root);
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ASBaseItem::BeginPlay()
{
	Super::BeginPlay();

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ASBaseItem::OnSphereOverlapBegin);
}

void ASBaseItem::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}