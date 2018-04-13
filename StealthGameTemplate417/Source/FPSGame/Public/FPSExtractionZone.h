// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

class UBoxComponent;

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSExtractionZone();

public:	
	UPROPERTY(VisibleAnywhere, Category = "ZOne")
	UBoxComponent* OverlapComp;
	UPROPERTY(VisibleAnywhere, Category = "Decal")
	UDecalComponent* DecalComp;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* ObjectiveMissingSound;
};
