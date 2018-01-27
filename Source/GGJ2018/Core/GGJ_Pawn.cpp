// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ_Pawn.h"


// Sets default values
AGGJ_Pawn::AGGJ_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGGJ_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGJ_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGGJ_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

