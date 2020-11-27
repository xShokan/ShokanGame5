// Copyright Epic Games, Inc. All Rights Reserved.

#include "shokan_game0GameMode.h"
#include "shokan_game0Character.h"
#include "UObject/ConstructorHelpers.h"

Ashokan_game0GameMode::Ashokan_game0GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
