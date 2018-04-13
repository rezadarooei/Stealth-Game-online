// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSObjectiveActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSCharacter.h"

// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SephCom = CreateDefaultSubobject<USphereComponent>(TEXT("SephereComponet"));
	SephCom->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SephCom->SetCollisionResponseToAllChannels(ECR_Ignore);
	SephCom->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SephCom->SetupAttachment(MeshComp);
	

}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();

	PlayEffect();
}

void AFPSObjectiveActor::PlayEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFx, GetActorLocation());
}

void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{

	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("it is work"))

	PlayEffect();
	AFPSCharacter* MyCharcter = Cast<AFPSCharacter>(OtherActor); //treat otherActor as FPSCharcter my character is temporary character(رفتار کردن )
	if (MyCharcter) { 

		MyCharcter->bIsCarryingObjective = true;
		
		Destroy();

	}
}

