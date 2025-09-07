// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_Knockback.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Plaground/Characters/BaseCharacter.h"
#include "Plaground/Data/Structs/Knockback/KnockbackPayload.h"

UGA_Knockback::UGA_Knockback(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer),
_defaultStrength(1200.f), _defaultDuration(0.1f)
{
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Knockback")));

	FAbilityTriggerData TriggerData;
	TriggerData.TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;
	TriggerData.TriggerTag = FGameplayTag::RequestGameplayTag(FName("Event.Knockback.Request"));
	AbilityTriggers.Add(TriggerData);

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	//NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
}

void UGA_Knockback::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}
	
	ABaseCharacter* OwnerCharacter = Cast<ABaseCharacter>(GetAvatarActorFromActorInfo());
	if (!OwnerCharacter || !OwnerCharacter->Target)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
		return;
	}

	if (!_knockbackPayload)
	{
		_knockbackPayload = NewObject<UKnockbackPayload>(this);
	}

	FHitResult Hit;
	FGameplayAbilityTargetDataHandle TDH;
	BuildSingleTargetDataFromTrace(Cast<ACharacter>(OwnerCharacter), OwnerCharacter->Target, Hit, TDH);

	FVector Direction = FVector::ZeroVector;

	if (!Hit.ImpactNormal.IsNearlyZero())
	{
		Direction = -Hit.ImpactNormal;
	}

	if (Direction.IsNearlyZero())
	{
		Direction = (OwnerCharacter->Target->GetActorLocation() - OwnerCharacter->GetActorLocation()).GetSafeNormal();
	}
	
	_knockbackPayload->KnockbackData.Direction = Direction.GetSafeNormal();
	_knockbackPayload->KnockbackData.Strength = _defaultStrength;
	_knockbackPayload->KnockbackData.Duration = _defaultDuration;
	_knockbackPayload->KnockbackData.HitResult = Hit;
	
	FGameplayEventData EventData;
	EventData.OptionalObject = _knockbackPayload;
	EventData.TargetData = TDH;
	EventData.EventMagnitude = _defaultStrength;
	EventData.Instigator = OwnerCharacter;

	const FGameplayTag KnockbackTag = FGameplayTag::RequestGameplayTag(FName("Event.Knockback.Apply"));
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(OwnerCharacter->Target, KnockbackTag, EventData);
	
	UE_LOG(LogTemp, Log, TEXT("[GA_Knockback::ActivateAbility] - Sent knockback to %s | Strength= %.1f",
		*OwnerCharacter->Target->GetName(), _defaultStrength));
	
	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

void UGA_Knockback::EndAbility(const FGameplayAbilitySpecHandle SpecHandle, const FGameplayAbilityActorInfo* Info,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{

	
	Super::EndAbility(SpecHandle, Info, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

bool UGA_Knockback::BuildSingleTargetDataFromTrace(ACharacter* Instigator, AActor* Target, FHitResult& OutHit,FGameplayAbilityTargetDataHandle& OutData) const
{
	if (!Target || !Instigator)
	{
		UE_LOG(LogTemp, Warning, TEXT("[GA_Knockback::BuildSingleTargetDataFromTrace] - Invalid Instigator or Target"));
		return false;
	}

	FVector Start = Instigator->GetActorLocation();
	FVector End = Target->GetActorLocation();

	if (UCapsuleComponent* Capsule = Instigator->GetCapsuleComponent())
	{
		End += FVector(0.f, 0.f, Capsule->GetScaledCapsuleHalfHeight() * 0.5f);
	}

	FCollisionQueryParams Params(
		SCENE_QUERY_STAT(KnockbackTrace),
		false,
		Instigator
		);
	Params.AddIgnoredActor(Instigator);
	
	bool bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, Params);

	if (!bHit)
	{
		OutHit.TraceStart = Start;
		OutHit.Location = End;
	}

#if WITH_EDITOR
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f, 0, 1.f);
	if (bHit)
	{
		DrawDebugPoint(GetWorld(), OutHit.ImpactPoint, 12.f, FColor::Purple, false, 2.f);
	}
#endif
	FGameplayAbilityTargetData_SingleTargetHit* SingleHit = new FGameplayAbilityTargetData_SingleTargetHit(OutHit);
	OutData.Clear();
	OutData.Add(SingleHit);

	return true;
}
