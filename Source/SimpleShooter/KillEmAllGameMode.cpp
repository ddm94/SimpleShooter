// Fill out your copyright notice in the Description page of Project Settings.

#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn *PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    APlayerController *PlayerController = Cast<APlayerController>(PawnKilled->GetController());

    // Player has lost
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }

    // For loop over ShooterAI in world:
    for (AShooterAIController *Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        // Is not dead?
        if (!Controller->IsDead())
        {
            // Game is not over yet
            return;
        }
    }
    // Player wins
    EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    // Returns a range obj (sort of like a list) that goes over all of the controllers in the world
    for (AController *Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
