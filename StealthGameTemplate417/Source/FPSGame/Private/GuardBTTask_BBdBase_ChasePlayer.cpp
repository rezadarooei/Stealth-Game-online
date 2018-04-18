// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardBTTask_BBdBase_ChasePlayer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GuardAIController.h"
#include "FPSChasingAICharacter.h"
#include "FPSCharacter.h"

EBTNodeResult::Type UGuardBTTask_BBdBase_ChasePlayer::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AGuardAIController* GuardAIController=Cast<AGuardAIController>(OwnerComp.GetAIOwner());
	//AFPSCharacter* Player = Cast<AFPSCharacter>
	//	(GetWorld()->GetFirstPlayerController()->GetPawn());
	//if (Player) {
	//	OwnerComp.GetBlackboardComponent()->SetValue< UBlackboardKeyType_Vector > (GuardAIController->GuardKeyId, Player->GetActorLocation());
	//}
	FVector PlayerPosition = OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Vector>(GuardAIController->GuardKeyId);
	if (GuardAIController) {
		GuardAIController->MoveToLocation(PlayerPosition, 10.0f, true, true, false, true, 0, true);
		return::EBTNodeResult::Succeeded;
	}
	else {
		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Failed;
}
