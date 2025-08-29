// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlagroundGameMode.h"
#include "PlagroundCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlagroundGameMode::APlagroundGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
