// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GuardAIController.generated.h"
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class FPSGAME_API AGuardAIController : public AAIController
{
	GENERATED_BODY()

		UPROPERTY(Transient)
		UBehaviorTreeComponent* BehaviorTreeComp;

		UPROPERTY(Transient)
		UBlackboardComponent* BlackboardComp;

public:
	AGuardAIController();

	virtual void Possess(APawn* InPawn) override;

	uint8 GuardKeyId;

};
