// Copyright to Andres Echeverri 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/SInventoryInterface.h"
#include "SBaseCharacter.generated.h"

class UAbilitySystemComponent;
class USAttributeSet;
class USGameplayAbility;
class USStorableData;

UCLASS(Abstract)
class SHOWPROJECT_API ASBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ISInventoryInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	USAttributeSet* GetAttributeSet() const { return AttributeSet; }

	USInventoryComponent* GetInventoryComponent() const;

	void AddItemToInventory(const USStorableData& ItemData);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<USAttributeSet> AttributeSet;

	void AddCharacterAbilities();

private:

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<USGameplayAbility>> StartupAbilities;

};
