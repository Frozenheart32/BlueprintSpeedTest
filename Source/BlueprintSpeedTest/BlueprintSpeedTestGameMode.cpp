// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintSpeedTestGameMode.h"
#include "BlueprintSpeedTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABlueprintSpeedTestGameMode::ABlueprintSpeedTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
