// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"


// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//ENABLE collision only for query like line trace(ساختن کلایدر برای کارهای مثل اورلپ)
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	//ignore all channels 
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	//only care two this
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;

}


void AFPSExtractionZone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("it is work"))

}

