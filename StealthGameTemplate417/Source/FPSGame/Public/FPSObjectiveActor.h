// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"
class USphereComponent;
UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:
//use as main component
	UPROPERTY(VisibleAnywhere,Category="Compnents")
	UStaticMeshComponent *MeshComp;
	//use as collision
	UPROPERTY(VisibleAnywhere, Category = "Compnents")

	USphereComponent *SephCom;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	void PlayEffect();
	
	UPROPERTY(EditDefaultsOnly, Category="Effcts")
	UParticleSystem* PickupFx;
public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
