// Copyright to Andres Echeverri 2023


#include "Items/SEffectItem.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/MeshComponent.h"
#include "GameFramework/Pawn.h"
#include "Data/SStorableData.h"
#include "Interfaces/SInventoryInterface.h"
#include "Interfaces/SStorable.h"



// Sets default values
ASEffectItem::ASEffectItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ASEffectItem::Interaction_Implementation(APawn* InstigatorPawn)
{
	ApplyEffectToTarget(InstigatorPawn, InstantEffectClass);
	Destroy();
}

// Called when the game starts or when spawned
void ASEffectItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASEffectItem::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> EffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

	if (TargetASC == nullptr) return;

	check(EffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(EffectClass, 1.0f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

void ASEffectItem::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TScriptInterface<ISInventoryInterface> InventoryInterface;
	if (OtherActor->GetClass()->ImplementsInterface(USInventoryInterface::StaticClass()))
	{
		InventoryInterface.SetObject(OtherActor);
		InventoryInterface.SetInterface(Cast<ISInventoryInterface>(OtherActor));
		ISStorable::Execute_Store(this, InventoryInterface);
		Destroy();
	}
}

void ASEffectItem::Store_Implementation(const TScriptInterface<ISInventoryInterface>& Inventory)
{
	UObject* TargetObject = Inventory.GetObject();

	if (IsValid(TargetObject) && TargetObject->Implements<USInventoryInterface>())
	{
		ISInventoryInterface::Execute_AddItemToInventory(TargetObject, StorableData);
	}
}

void ASEffectItem::Remove_Implementation(const TScriptInterface<ISInventoryInterface>& Inventory)
{
}

UTexture2D* ASEffectItem::GetStorageIcon_Implementation()
{
	return StorableData->StorageIcon;
}

FText ASEffectItem::GetStorageName_Implementation()
{
	return StorableData->StorageName;
}

FText ASEffectItem::GetStorageDescription_Implementation()
{
	return StorableData->StorageDescription;
}

