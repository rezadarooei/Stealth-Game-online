// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "FPSGameMode.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Net/UnrealNetwork.h"
// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->OnSeePawn.AddDynamic(this,&AFPSAIGuard::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this,&AFPSAIGuard::OnHearNoise);

	GuardState = EAIState::Idle;
}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	OrginalRotaion=GetActorRotation();
	
}

void AFPSAIGuard::OnPawnSeen(APawn * SeenPawn)
{
	if (SeenPawn == nullptr) {
		return;
	}
	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12, FColor::Green, false, 10.0f);
	AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
	if (GM) {
		GM->CompleteMission(SeenPawn, false);
	}
	SetGuardState(EAIState::Alrted);
}

void AFPSAIGuard::OnHearNoise(APawn* InstigatorNoise, const FVector &Location, float Volume) {
	if (GuardState == EAIState::Alrted) {
		return;
	}
	DrawDebugSphere(GetWorld(),Location, 32.0f, 12, FColor::Red, false, 10.0f);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();
	FRotator NewLookAt=FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch = 0.0f;
	NewLookAt.Roll=0.0f;
	SetActorRotation(NewLookAt);

	GetWorldTimerManager().ClearTimer(TimerHandele_RestRotation);
	GetWorldTimerManager().SetTimer(TimerHandele_RestRotation, this, &AFPSAIGuard::RestOrintation, 3.0f, false);
	SetGuardState(EAIState::Suspicious);
}

void AFPSAIGuard::RestOrintation()
{
	if (GuardState == EAIState::Alrted) {
		return;
	}
	SetActorRotation(OrginalRotaion);
	SetGuardState(EAIState::Idle);
}
//it is for replicated states to the client
void AFPSAIGuard::onRep_GuardState()
{
	OnStateChanged(GuardState);
}
//the main state
void AFPSAIGuard::SetGuardState(EAIState NewState)
{
	if (GuardState==NewState) {
		return;
	}
	GuardState = NewState;
	onRep_GuardState();
	//OnStateChanged(GuardState);
}

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSAIGuard::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSAIGuard, GuardState);
}
