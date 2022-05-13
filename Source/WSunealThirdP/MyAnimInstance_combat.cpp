// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance_combat.h"
#include "Character_CPP.h"

void UMyAnimInstance_combat::NativeInitializeAnimation()
{
	if (myPawn == nullptr)
	{
	
		myPawn = TryGetPawnOwner();

		if (Cast<ACharacter_CPP>(myPawn))
		{
			//myPawn->SetAnimInstance();
		}
		//myPawn
		//myPawn->InputComponent->BindAction("Attack", IE_Pressed, this, &UMyAnimInstance_combat::Attack);
	}
}



void UMyAnimInstance_combat::UpdateAnimationAxis()
{
	if (myPawn)
	{


		FVector speedVect = myPawn->GetVelocity();
		FVector horizontalSpeed = FVector(speedVect.X, speedVect.Y, 0.f);
		
		Speed = speedVect.X;
		SpeedR = speedVect.Y;
		JumpVelocity = speedVect.Z;

	}
}
/*
void UMyAnimInstance_combat::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("9a attaque ola"));
}

/**/