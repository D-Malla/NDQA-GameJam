// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GameJamGameMode.h"
#include "Characters/MainCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameJamGameMode::AGameJamGameMode()
: Super()
{
	// Set default pawn class to our BP Character (AMainCharacter).
	static ConstructorHelpers::FClassFinder<APawn> PLayerPawnClassFinder(TEXT("/Game/Characters/Main/Blueprint/BP_MainCharacter"));
	DefaultPawnClass = PLayerPawnClassFinder.Class;
}
