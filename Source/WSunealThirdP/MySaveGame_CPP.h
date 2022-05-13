// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame_CPP.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_BODY()


	UPROPERTY(VisibleAnywhere, Category = GameSaveData)
		float Life;

	UPROPERTY(VisibleAnywhere, Category = GameSaveData)
		float maxLife;


	//UPROPERTY(VisibleAnywhere, Category = GameSaveData)
	//	UTransform myPos;


};


/**
 * 
 */
UCLASS()
class WSUNEALTHIRDP_API UMySaveGame_CPP : public USaveGame
{


	GENERATED_BODY()

public:
	//functions


	UMySaveGame_CPP();
	
	UPROPERTY(VisibleAnywhere,Category = Save)
		FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Save)
	int UserIndex;


	UPROPERTY(VisibleAnywhere, Category = Save)
		FPlayerStats playerStats;


};
