// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_Knockback.generated.h"

class UKnockbackPayload;
/**
 * 
 */
UCLASS()
class PLAGROUND_API UGA_Knockback : public UGameplayAbility
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	UKnockbackPayload* _knockbackPayload;

	UPROPERTY(EditDefaultsOnly, Category = "Knockback")
	float _defaultStrength;
	UPROPERTY(EditDefaultsOnly, Category = "Knockback")
	float _defaultDuration;
	
public:
	UGA_Knockback(const FObjectInitializer& ObjectInitializer);

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
		) override;
	
	virtual void EndAbility(
		const FGameplayAbilitySpecHandle SpecHandle,
		const FGameplayAbilityActorInfo* Info,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility, bool bWasCancelled
		) override;

	bool BuildSingleTargetDataFromTrace(ACharacter* Instigator, AActor* Target, FHitResult& OutHit, FGameplayAbilityTargetDataHandle& OutData) const;

};
