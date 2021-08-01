// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun();

	// Allow us to pull the trigger on the gun from wherever we are binding input
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere) // We do not want to be able to edit the pointers but we do want to be able to see the properties of those pointers.
	USceneComponent *Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent *Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;
};
