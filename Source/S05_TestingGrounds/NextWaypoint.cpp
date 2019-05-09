// Fill out your copyright notice in the Description page of Project Settings.

#include "NextWaypoint.h"


EBTNodeResult::Type UNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("ExecuteTask() is working"));
	return EBTNodeResult::Succeeded;
}
