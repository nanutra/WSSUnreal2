// Fill out your copyright notice in the Description page of Project Settings.


#include "Items.h"
#include "Components/SphereComponent.h"
#include "particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Character_CPP.h"


// Sets default values
AItems::AItems()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//collide sphere setup
	CollideSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollideSphere"));
	RootComponent = CollideSphere;

	//sphere collider
	CollideSphere->OnComponentBeginOverlap.AddDynamic(this, &AItems::OnOverlapBegin);
	CollideSphere->OnComponentEndOverlap.AddDynamic(this, &AItems::OnOverlapEnd);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	IdleParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticle"));
	IdleParticle->SetupAttachment(GetRootComponent());

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// il faut faire bouger l'objeyt wola

	if (canFloat)
	{
		FVector NewLocation = GetActorLocation();
		float RunningTime = GetGameTimeSinceCreation();
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20

		//rotation
		FRotator NewRotation = GetActorRotation();	//Get rotation de l'objet 
		float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
		NewRotation.Yaw += DeltaRotation;			//Rotation sur l'axe Z


		//Set du transform
		SetActorLocationAndRotation(NewLocation, NewRotation);
	}

	/**/
}


void AItems::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (isEquiped) return;
	
	//UE_LOG(LogTemp,Warning, TEXT("Enter COllision"))
	if (OverlapParticle)
	{
		//faire sspawn la particle
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticle, GetActorLocation(), FRotator(0.f), true);

	}

	if (OverlapSound)
	{
		UGameplayStatics::PlaySound2D(this, OverlapSound, 2.75f);
	}

	//collide avec le player
	if (OtherActor)
	{
		ACharacter_CPP* curChar = Cast<ACharacter_CPP>(OtherActor);

		if (curChar)
		{
			EquipWeapon(curChar);
		}


	}
	//Destroy();
}

void AItems::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Exit COllision"));
}


void AItems::EquipWeapon(class ACharacter_CPP* myChar)
{

	//Optionnel, bloquer les collisions des la camera d'un certain types de pawn avec la camera
	Weapon->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	Weapon->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	Weapon->SetSimulatePhysics(false);

	const USkeletalMeshSocket* weaponSocket = myChar->GetMesh()->GetSocketByName("WeaponSocket");
	 
	if (Weapon)
	{
		weaponSocket->AttachActor(this, myChar->GetMesh());
		isEquiped = true;
	}


}