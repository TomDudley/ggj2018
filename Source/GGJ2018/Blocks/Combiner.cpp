// Fill out your copyright notice in the Description page of Project Settings.

#include "Combiner.h"




void ACombiner::DistortLight(FLightInfo InLight, FVector InNormal, FVector InDirection)
{
	IncomingLights.Add(InLight);
	float TotalReds = 0;
	float TotalBlues = 0;
	float TotalGreens = 0;

	for (FLightInfo Light : IncomingLights)
	{
		TotalReds += Light.Colour.R;
		TotalBlues += Light.Colour.B;
		TotalGreens += Light.Colour.G;
	}

	if (IncomingLights.Num() > 0)
	{
		float UsableR = TotalReds;
		float UsableB = TotalBlues; 
		float UsableG = TotalGreens;

		FLightInfo NewColour;
		NewColour.Colour.R = FMath::Clamp(UsableR, 0.f, 255.f);
		NewColour.Colour.G = FMath::Clamp(UsableG, 0.f, 255.f);
		NewColour.Colour.B = FMath::Clamp(UsableB, 0.f, 255.f);

		EmitLight(GetActorForwardVector(), NewColour, 500.f, this);
	}
	
}
