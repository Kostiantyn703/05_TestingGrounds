// Fill out your copyright notice in the Description page of Project Settings.

#include "NextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// TODO protect against empty patrol roots

	// Get Patrol points
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	APatrollingGuard* PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	TArray<AActor*> PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	// Set Next Waypoint
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle Index
	int NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(WaypointKey.SelectedKeyName, NextIndex);


	UE_LOG(LogTemp, Warning, TEXT("waypoint index %i"), Index);
	
	return EBTNodeResult::Succeeded;
}
