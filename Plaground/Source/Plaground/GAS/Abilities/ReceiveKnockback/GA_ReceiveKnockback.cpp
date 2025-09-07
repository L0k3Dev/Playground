// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_ReceiveKnockback.h"

#include "GameFramework/Character.h"
#include "Plaground/Data/Structs/Knockback/KnockbackPayload.h"

UGA_ReceiveKnockback::UGA_ReceiveKnockback() : _baseStrength(1000.0f), _upwardBoost(250.0f)
{
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.ReceiveKnockback")));
	
	FAbilityTriggerData TriggerData;
	TriggerData.TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;
	TriggerData.TriggerTag = FGameplayTag::RequestGameplayTag(FName("Event.Knockback.Apply"));
	AbilityTriggers.Add(TriggerData);

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	
	//NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerInitiated;
}

void UGA_ReceiveKnockback::ActivateAbilityFromEvent(const FGameplayEventData& EventData)
{
	if (!CommitAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	ACharacter* TargetChar = Cast<ACharacter>(GetAvatarActorFromActorInfo());
	if (!TargetChar)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	FVector Direction = FVector::ZeroVector;
	float Strength = _baseStrength;
	float Duration = 0.0f;

	if (const UKnockbackPayload* Payload = Cast<UKnockbackPayload>(EventData.OptionalObject))
	{
		Direction = Payload->KnockbackData.Direction;
		Strength = Payload->KnockbackData.Strength;
		Duration = Payload->KnockbackData.Duration;
		//HitResult = Payload->KnockbackData.HitResult;
	}
	
	if (Direction.IsNearlyZero() && EventData.Instigator)
	{
		Direction = (GetAvatarActorFromActorInfo()->GetActorLocation() - EventData.Instigator->GetActorLocation()
			).GetSafeNormal();
	}

	Direction = Direction.GetSafeNormal();
	FVector Impulse = Direction * Strength;
	Impulse.Z += _upwardBoost;
	TargetChar->LaunchCharacter(Impulse, true, true);
	
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}

void UGA_ReceiveKnockback::EndAbility(const FGameplayAbilitySpecHandle SpecHandle,
	const FGameplayAbilityActorInfo* Info, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	
	Super::EndAbility(SpecHandle, Info, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
