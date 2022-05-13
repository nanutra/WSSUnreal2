// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyAnimInstance_combat.h"
#include "Character_CPP.generated.h"


UCLASS()
class WSUNEALTHIRDP_API ACharacter_CPP : public ACharacter
{
	GENERATED_BODY()

	bool isJumping = false;

public:
	// Sets default values for this character's properties
	ACharacter_CPP();

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAcces = "true"))
	class USpringArmComponent* CameraArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAcces = "true"))
	class UCameraComponent* myCamera;

	//cameraMovement
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float turnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float lookRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
		float life;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
		float maxLife;

	bool isA = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Chara)
		class UMyAnimInstance_combat* myAnim;

	//UFUNCTION(BlueprintCallable)
	//bool JumpAction();
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void JumpInformation(float Value);

	//Movement
	void MoveForward(float	 Value);
	void MoveRight(float	 Value);

	// Rotation
	void Turn(float Value);
	void LookUp(float Value);

	void Attack();

	void SetAnimInstance(class UMyAnimInstance_combat* inst); 



	UFUNCTION(BlueprintCallable )
		void SaveGame();

	UFUNCTION(BlueprintCallable )
		void LoadGame();


};
