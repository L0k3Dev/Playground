// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_Base.h"

UGA_Base::UGA_Base(const FObjectInitializer& ObjectInitializer)
{
	FGameplayTag DefaultTriggerTag = FGameplayTag::RequestGameplayTag(FName("Abilities.Characters.Basic"));

	FAbilityTriggerData TriggerData;
	TriggerData.TriggerTag = DefaultTriggerTag;
	TriggerData.TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;

	AbilityTriggers.Add(TriggerData);
}

void UGA_Base::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                               const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UE_LOG(LogTemp, Log, TEXT(" --> Ability Activated <--"));
	
	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

void UGA_Base::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	
}
