// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DT_BaseAttributes.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PLAGROUND_API FDT_BaseAttributes : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Stats")
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Stats")
	int MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Stats")
	int Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Stats")
	int Armor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Movement")
	float MaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Movement")
	float Acceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Movement")
	float Deacceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes.Movement")
	float TurnRateZ;
};
