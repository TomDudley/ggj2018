// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ2018GameModeBase.h"
#include "Core/GGJ_PlayerController.h"
#include "Core/GGJ_Pawn.h"




AGGJ2018GameModeBase::AGGJ2018GameModeBase()
{
	PlayerControllerClass = AGGJ_PlayerController::StaticClass();
	DefaultPawnClass = AGGJ_Pawn::StaticClass();
}
