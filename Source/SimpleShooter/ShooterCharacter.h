// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventINstigator, AActor *DamageCauser) override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	void Shoot();

	UPROPERTY(EditAnywhere)
	float RotationRate = 20;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere) 
	float Health;

	UPROPERTY(EditDefaultsOnly) // We do not want to be able to edit this at runtime
	TSubclassOf<AGun> GunClass; // It allows blueprint to restrict the classes that we can select from to only the classes that are subclasses of the Gun class

	UPROPERTY()
	AGun* Gun; // This is the actual gun - Once we have created an instance of the class, this is where we are going to store it
};
