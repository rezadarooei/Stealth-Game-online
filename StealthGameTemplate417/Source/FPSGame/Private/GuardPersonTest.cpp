// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardPersonTest.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGuardPersonTest::AGuardPersonTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("SensingPawn"));
	sensingComp->OnSeePawn.AddDynamic(this, &AGuardPersonTest::OnPawnSeen );
}

// Called when the game starts or when spawned
void AGuardPersonTest::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGuardPersonTest::OnPawnSeen(APawn * SeenPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("it is see"))
	if (SeenPawn == nullptr) { return; }
	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12, FColor::Green, false, 10.0f);
	
}

// Called every frame
void AGuardPersonTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGuardPersonTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

