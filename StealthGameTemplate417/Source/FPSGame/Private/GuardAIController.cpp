// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FPSChasingAICharacter.h"

AGuardAIController::AGuardAIController()
{
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlacboardComp"));
}

void AGuardAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	AFPSChasingAICharacter* Guard = Cast<AFPSChasingAICharacter>(InPawn);
	if (Guard && Guard->GuardBehaviorTree) {
		BlackboardComp->InitializeBlackboard(*Guard->GuardBehaviorTree->BlackboardAsset);
		GuardKeyId = BlackboardComp->GetKeyID("Target");
		BehaviorTreeComp->StartTree(*Guard->GuardBehaviorTree);

	}
	else {
		UE_LOG(LogTemp,Warning,TEXT("it is not attached"))
	}

}
