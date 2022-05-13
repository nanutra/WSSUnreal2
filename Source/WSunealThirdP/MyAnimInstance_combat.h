// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance_combat.generated.h"

/**
 * 
 */
UCLASS()
class WSUNEALTHIRDP_API UMyAnimInstance_combat : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeInitializeAnimation() override;

	


	UFUNCTION(BlueprintCallable, Category = animation)
	void UpdateAnimationAxis();


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Chara)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Chara)
		float SpeedR;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Chara)
		float JumpVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Chara)
		class APawn* myPawn;

	bool isAttacking = false;




};
