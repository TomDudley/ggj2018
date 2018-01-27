// Fill out your copyright notice in the Description page of Project Settings.

#include "Defractor.h"




void ADefractor::DistortLight(FLightInfo InLight, FVector InNormal, FVector InDirection)
{
	TArray<FLightInfo> ValidColours;
	FLightInfo NewR;
	FLightInfo NewG;
	FLightInfo NewB;

	NewR.Colour = FColor(InLight.Colour.R, 0, 0);
	FVector RedDirection = (GetActorRotation() + FRotator(0, 45, 0)).Vector();

	NewG.Colour = FColor(0, InLight.Colour.G,0);
	FVector GreenDirection = (GetActorRotation() + FRotator(0, 0, 0)).Vector();

	NewB.Colour = FColor(0, 0, InLight.Colour.B);
	FVector BlueDirection = (GetActorRotation() + FRotator(0, -45, 0)).Vector();

	if (NewR.Colour.R > 0)
	{
		ValidColours.Add(NewR);
		EmitLight(RedDirection, NewR, 500.f, this);
	}
	
	if (NewG.Colour.G > 0)
	{
		ValidColours.Add(NewG);
		EmitLight(GreenDirection, NewG, 500.f, this);
	}
	
	if (NewB.Colour.B > 0)
	{
		ValidColours.Add(NewB);
		EmitLight(BlueDirection, NewB, 500.f, this);
	}
}
