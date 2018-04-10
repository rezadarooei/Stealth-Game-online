// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSObjectiveActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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

// Called every frame
void AFPSObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSObjectiveActor::PlayEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFx, GetActorLocation());
}

void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	PlayEffect();
}

