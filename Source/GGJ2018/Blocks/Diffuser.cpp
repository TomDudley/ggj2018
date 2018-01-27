// Fill out your copyright notice in the Description page of Project Settings.

#include "Diffuser.h"

void ADiffuser::DistortLight(FLightInfo InLight, FVector InNormal, FVector InDirection)
{	
	FVector FirstDirection = (GetActorRotation() + FRotator(0, 45, 0)).Vector();
	FVector SecondDirection = (GetActorRotation() + FRotator(0, 0, 0)).Vector();
	FVector ThirdDirection = (GetActorRotation() + FRotator(0, -45, 0)).Vector();

	EmitLight(FirstDirection, InLight, 500, this);
	EmitLight(SecondDirection, InLight, 500, this);
	EmitLight(ThirdDirection, InLight, 500, this);

}