// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KnockbackPayload.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FKnockbackData
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction {FVector::ZeroVector};
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Strength {0.f};
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration {0.f};
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHitResult HitResult;
};

UCLASS(BlueprintType)
class PLAGROUND_API UKnockbackPayload : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities.Events.Knockback.Payload")
	FKnockbackData KnockbackData;
};
