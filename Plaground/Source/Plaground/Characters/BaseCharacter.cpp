// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Plaground/Data/DataTables/DT_BaseAttributes.h"
#include "Plaground/GAS/AttributeSets/BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

#pragma region GAS
	_ASC = CreateDefaultSubobject<UAbilitySystemComponent>("Ability System Component");
	_ASC->SetIsReplicated(false);
	
#pragma endregion
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitializeStats(_statsTable, _rowName);
	InitializeAbilities();

	UE_LOG(LogTemp, Log, TEXT("Health: %f"), _ASC->GetNumericAttribute(UBaseAttributeSet::GetHealthAttribute()));
	UE_LOG(LogTemp, Log, TEXT("Attack: %f"), _ASC->GetNumericAttribute(UBaseAttributeSet::GetDamageAttribute()));

	if (_baseTag.IsValid())
	{
		FGameplayEventData Payload;
		Payload.EventTag = _baseTag;
		Payload.Instigator = this;
		Payload.Target = this;

		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(this, _baseTag, Payload);
	}
}

void ABaseCharacter::InitializeStats(UDataTable* DataTable, FName RowName)
{
	if (DataTable)
	{
		static const FString ContextString(TEXT("Character Attribute Context"));
		FDT_BaseAttributes* Attributes = DataTable->FindRow<FDT_BaseAttributes>(RowName, ContextString);

		_ASC->InitStats(UBaseAttributeSet::StaticClass(), nullptr);

		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetHealthAttribute(), Attributes->Health);
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetMaxHealthAttribute(), Attributes->MaxHealth);
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetDamageAttribute(), Attributes->Damage);
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetArmorAttribute(), Attributes->Armor);
		
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetMaxSpeedAttribute(), Attributes->MaxSpeed);
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetAccelerationAttribute(), Attributes->Acceleration);
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetDeaccelerationAttribute(), Attributes->Deacceleration);
		_ASC->SetNumericAttributeBase(UBaseAttributeSet::GetTurnRateZAttribute(), Attributes->TurnRateZ);

		
		UE_LOG(LogTemp, Warning, TEXT("Attributes Loaded!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("DataTable not found or RowName is invalid!"));
	}
}

void ABaseCharacter::InitializeAbilities()
{
	_ASC-> InitAbilityActorInfo(this, this);
	if (_baseAbility)
	{
		_ASC->GiveAbility(FGameplayAbilitySpec(_baseAbility, 1, 0));
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

