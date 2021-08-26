// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    // Cast to AShooterCharacter to get hold of the pawn and in turn be able to call the Shoot() method
    AShooterCharacter *Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if (Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    Character->Shoot();

    return EBTNodeResult::Succeeded;
}
