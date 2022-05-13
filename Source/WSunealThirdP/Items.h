// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class WSUNEALTHIRDP_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

	//colliders
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="ITEMS | Collision")
	class USphereComponent* CollideSphere;

	//mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ITEMS | Mesh")
		class UStaticMeshComponent* Mesh;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WEAPON")
		class USkeletalMeshComponent* Weapon;


	//particles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ITEMS | Particles")
	class UParticleSystemComponent* IdleParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ITEMS | Particles")
	class UParticleSystem* OverlapParticle;


	//Sounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ITEMS | Sound")
	class USoundCue* OverlapSound;


	//variables
	float PosSin;
	bool isEquiped = false;

	UPROPERTY(EditAnywhere, Category = "Animation")
	bool canFloat = false;
	//float RunningTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	void EquipWeapon(class ACharacter_CPP* myChar);
};
