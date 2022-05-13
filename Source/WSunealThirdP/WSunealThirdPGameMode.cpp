// Copyright Epic Games, Inc. All Rights Reserved.

#include "WSunealThirdPGameMode.h"
#include "WSunealThirdPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWSunealThirdPGameMode::AWSunealThirdPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
