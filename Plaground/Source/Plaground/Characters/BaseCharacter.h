// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UGameplayAbility;
class UBaseAttributeSet;
class UAbilitySystemComponent;
class UDataTable;

UCLASS()
class PLAGROUND_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Target")
	AActor* Target;
	
protected:
	UPROPERTY(VisibleAnywhere, Category = "Settings|GAS", meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* _ASC;

	UPROPERTY()
	TSubclassOf<UBaseAttributeSet> _attributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|GAS|Data", meta = (AllowPrivateAccess = "true"))
	UDataTable* _statsTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Settings|GAS|Data", meta = (AllowPrivateAccess = "true"))
	FName _rowName = "BaseStats";

#pragma region Abilities
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|GAS|Abilities", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayAbility> _knockbackAbility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|GAS|Abilities|Events", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayAbility> _receiveKnockbackAbility;

#pragma endregion
	
	const FGameplayTag _knockbackTag = FGameplayTag::RequestGameplayTag("Ability.Knockback");
	const FGameplayTag _receiveKnockbackTag = FGameplayTag::RequestGameplayTag("Ability.ReceiveKnockback");
	
public:	
	// Sets default values for this character's properties
	ABaseCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InitializeStats(UDataTable* DataTable, FName RowName);
	void InitializeAbilities();

private:
	void SendInitialPushEvent();
};
