// Fill out your copyright notice in the Description page of Project Settings.

#include "LightEmitter.h"
#include "LightReciever.h"



// Sets default values
ALightEmitter::ALightEmitter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ALightEmitter::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(PulseHandle, this, &ALightEmitter::Pulse, 0.1f, true);
}	

void ALightEmitter::Pulse()
{
	EmitLight(GetActorForwardVector(), EmittedLight, LightDistance, this);
}
