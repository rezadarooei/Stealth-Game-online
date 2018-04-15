// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSCharacter.h"
#include "FPSGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//ENABLE collision only for query like line trace(ساختن کلایدر برای کارهای مثل اورلپ)
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	//ignore all channels 
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	//only care two this(حساس بودن به کاراکتر به صورا اولپی)
	OverlapComp->SetBoxExtent(FVector(200.0f));
	//ابعادباکس
	RootComponent = OverlapComp;
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize=FVector(200.0f, 200.0f, 200.0f);
	DecalComp->SetupAttachment(OverlapComp);

}


void AFPSExtractionZone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	AFPSCharacter* MyPawn = Cast<AFPSCharacter>(OtherActor);
	if (MyPawn == nullptr) {
		return;
	}
	if (MyPawn->bIsCarryingObjective == true) {
		AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
		if (GM) {
			GM->CompleteMission(MyPawn,true);
		}
	}
	else { UGameplayStatics::PlaySound2D(this,ObjectiveMissingSound); }




}

