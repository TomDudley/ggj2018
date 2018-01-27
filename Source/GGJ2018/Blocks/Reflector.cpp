// Fill out your copyright notice in the Description page of Project Settings.

#include "Reflector.h"
#include "Kismet/KismetMathLibrary.h"

void AReflector::DistortLight(FLightInfo InLight, FVector InNormal, FVector InDirection)
{
	FVector ReflectionVector = UKismetMathLibrary::GetReflectionVector(InDirection, InNormal);
	EmitLight(ReflectionVector, InLight, 500, this);
}
