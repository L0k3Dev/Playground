// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_ReceiveKnockback.generated.h"

/**
 * 
 */
UCLASS()
class PLAGROUND_API UGA_ReceiveKnockback : public UGameplayAbility
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "Knockback")
	float _baseStrength;
	UPROPERTY(EditDefaultsOnly, Category = "Knockback")
	float _upwardBoost;
	
public:
	UGA_ReceiveKnockback();

	virtual void ActivateAbilityFromEvent(const FGameplayEventData& EventData);

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle SpecHandle,
		const FGameplayAbilityActorInfo* Info,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility, bool bWasCancelled
		) override;
};
