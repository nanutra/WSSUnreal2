// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoxCollider_CPP.generated.h"

UCLASS()
class WSUNEALTHIRDP_API ABoxCollider_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxCollider_CPP();

	//collisions box
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Collider")
		class UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ITEMS | Particles")
		class UParticleSystemComponent* IdleParticle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
