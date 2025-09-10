// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_ReceiveKnockback.h"

#include "GameFramework/Character.h"
#include "Plaground/Data/Structs/Knockback/KnockbackPayload.h"

UGA_ReceiveKnockback::UGA_ReceiveKnockback() : _baseStrength(1000.0f), _upwardBoost(250.0f)
{
	
	//NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerInitiated;*/
}

void UGA_ReceiveKnockback::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	ACharacter* OwnChar = Cast<ACharacter>(GetAvatarActorFromActorInfo());
	if (!OwnChar)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	FVector Direction = FVector::ZeroVector;
	float Strength = _baseStrength;
	float Duration = 0.0f;

	if (const UKnockbackPayload* Payload = Cast<UKnockbackPayload>(TriggerEventData->OptionalObject))
	{
		Direction = Payload->KnockbackData.Direction;
		Strength = Payload->KnockbackData.Strength;
		Duration = Payload->KnockbackData.Duration;
		//HitResult = Payload->KnockbackData.HitResult;
	}
	
	if (Direction.IsNearlyZero() && TriggerEventData->Instigator)
	{
		Direction = (GetAvatarActorFromActorInfo()->GetActorLocation() - TriggerEventData->Instigator->GetActorLocation()
			).GetSafeNormal();
	}

	Direction = Direction.GetSafeNormal();
	FVector Impulse = Direction * Strength;
	Impulse.Z += _upwardBoost;
	OwnChar->LaunchCharacter(Impulse, true, true);
	
	UE_LOG(LogTemp, Error, TEXT("[UGA_ReceiveKnockback::ActivateAbilityFromEvent] - Sent knockback to %s | Impulse X = %f, Y = %f, Z = %f"),
	*OwnChar->GetName(), Impulse.X, Impulse.Y, Impulse.Z);
	
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}

void UGA_ReceiveKnockback::EndAbility(const FGameplayAbilitySpecHandle SpecHandle,
                                      const FGameplayAbilityActorInfo* Info, const FGameplayAbilityActivationInfo ActivationInfo,
                                      bool bReplicateEndAbility, bool bWasCancelled)
{
	
	Super::EndAbility(SpecHandle, Info, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
