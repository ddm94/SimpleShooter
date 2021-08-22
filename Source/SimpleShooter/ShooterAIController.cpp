// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if(AIBehavior != nullptr) 
    {
        RunBehaviorTree(AIBehavior);
    }
}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    //Get hold of the pawn Actor
    // APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // if (LineOfSightTo(PlayerPawn))
    // {
    //     SetFocus(PlayerPawn);
    //     MoveToActor(PlayerPawn, AcceptanceRadius);
    // }
    // else
    // {
    //     ClearFocus(EAIFocusPriority::Gameplay);
    //     StopMovement();
    // }
}