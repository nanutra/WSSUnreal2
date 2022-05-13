// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxCollider_CPP.h"
#include "Components/BoxComponent.h"
#include "particles/ParticleSystemComponent.h"

// Sets default values
ABoxCollider_CPP::ABoxCollider_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("CollideSphere"));
	RootComponent = BoxCollider;


	IdleParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticle"));
	IdleParticle->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ABoxCollider_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoxCollider_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

