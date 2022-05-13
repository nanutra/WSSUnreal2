// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_CPP.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "WSunealThirdPCharacter.h"
#include "MySaveGame_CPP.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACharacter_CPP::ACharacter_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera_Arm"));
	CameraArm -> SetupAttachment(GetRootComponent());
	CameraArm->TargetArmLength = 600.f;

	myCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera"));
	myCamera->SetupAttachment(CameraArm);

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(125.f, 125.f, 0.f);

	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 5000.f;


}

// Called when the game starts or when spawned
void ACharacter_CPP::BeginPlay()
{
	Super::BeginPlay();


	//myAnim = Cast<UMyAnimInstance_combat>();
	UE_LOG(LogTemp, Warning, TEXT("Exit COllision"));
	

}

// Called every frame
void ACharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Inputs

// Called to bind functionality to input
void ACharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);


	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter_CPP::JumpAction);
	PlayerInputComponent->BindAction("StopJumping", IE_Pressed, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ACharacter_CPP::Attack);

	//translation
	PlayerInputComponent->BindAxis("MoveForward", this, &ACharacter_CPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacter_CPP::MoveRight);

	//rotation

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//attack 

	// 
	//PlayerInputComponent->BindAxis("LookUpRate", this, &APawn::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &AWSunealThirdPCharacter::LookUpAtRate);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &AWSunealThirdPCharacter::LookUpRate);

	/*
	PlayerInputComponent->BindAxis("turnRate", this, &ACharacter_CPP::Turn);
	PlayerInputComponent->BindAxis("lookRate", this, &ACharacter_CPP::LookUp);
	/**/

}

#pragma endregion Inputs

void ACharacter_CPP::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0) 
	{
		const FRotator rot = Controller->GetControlRotation();
		const FRotator yawRot(0.f, rot.Yaw, 0.f);

		const FVector direction = FRotationMatrix(yawRot).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, Value);
	}
}

void ACharacter_CPP::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0)
	{
		const FRotator rot = Controller->GetControlRotation();
		const FRotator yawRot(0.f, rot.Yaw, 0.f);

		const FVector direction = FRotationMatrix(yawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, Value);
	}
}

void ACharacter_CPP::Turn(float Value)
{
	if (Controller != nullptr && Value != 0)
	{
		AddControllerYawInput(Value * turnRate * GetWorld()->GetDeltaSeconds());
	}
}

void ACharacter_CPP::LookUp(float Value)
{
	if (Controller != nullptr && Value != 0)
	{
		AddControllerPitchInput(Value * lookRate * GetWorld()->GetDeltaSeconds());
	
	}
}

void ACharacter_CPP::JumpInformation(float Value)
{
	if (Controller != nullptr && Value != 0)
	{
		AddControllerPitchInput(Value * lookRate * GetWorld()->GetDeltaSeconds());

	}
}

void ACharacter_CPP::Attack()
{
	if (Controller != nullptr)
	{
		isA = true;
	}
}

void ACharacter_CPP::SetAnimInstance(class UMyAnimInstance_combat* inst)
{

}



//Fonctions pour sauvegarder


void ACharacter_CPP::SaveGame()
{
	UMySaveGame_CPP* SaveInstance = Cast<UMySaveGame_CPP>(UGameplayStatics::CreateSaveGameObject(UMySaveGame_CPP::StaticClass()));

	SaveInstance->playerStats.Life = life;
	SaveInstance->playerStats.maxLife = maxLife;

	UGameplayStatics::SaveGameToSlot(SaveInstance, SaveInstance->PlayerName, SaveInstance->UserIndex);

}

void ACharacter_CPP::LoadGame()
{
	UMySaveGame_CPP* LoadInstance = Cast<UMySaveGame_CPP>(UGameplayStatics::CreateSaveGameObject(UMySaveGame_CPP::StaticClass()));

	LoadInstance = Cast<UMySaveGame_CPP>(UGameplayStatics::LoadGameFromSlot(LoadInstance->PlayerName, LoadInstance->UserIndex));

	life = LoadInstance->playerStats.Life;
	maxLife = LoadInstance->playerStats.maxLife;

}






/*
bool ACharacter_CPP::JumpAction()
{
	if (Controller != nullptr)
	{
		

	}
}
/**/