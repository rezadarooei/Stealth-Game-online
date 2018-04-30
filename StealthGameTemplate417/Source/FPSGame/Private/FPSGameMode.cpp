// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "FPSGameState.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
	GameStateClass = AFPSGameState::StaticClass();
}
//what happened when the game end.(?? ????? ???? ?? ??? ?????? ??? ???? ?? ??? ???? ??? ??? ?? ?? ???? ??? ????? ?????? ?? ???? ???? ??)
void AFPSGameMode::CompleteMission(APawn * InstigatorPawn,bool bMissionSucess)
{
	if (InstigatorPawn) {
		
	}
	AFPSGameState* GS = GetGameState<AFPSGameState>();
	if (GS) {
		GS->MulticastOnMissionComplete(InstigatorPawn, bMissionSucess);
	}
	OnMissionComplete(InstigatorPawn,bMissionSucess);
}

