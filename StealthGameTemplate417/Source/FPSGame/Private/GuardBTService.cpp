// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardBTService.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FPSChasingAICharacter.h"
#include "GuardAIController.h"
#include "FPSCharacter.h"
UGuardBTService::UGuardBTService() {
	bCreateNodeInstance = true;
	
}
void UGuardBTService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	AGuardAIController* GuardAIController = Cast<AGuardAIController>(OwnerComp.GetAIOwner());
	if (GuardAIController) {
		AFPSCharacter* Charcter = Cast<AFPSCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (Charcter) {
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(GuardAIController->GuardKeyId, Charcter->GetActorLocation());
		}
	}
}
