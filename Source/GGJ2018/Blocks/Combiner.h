// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blocks/Block.h"
#include "Combiner.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2018_API ACombiner : public ABlock
{
	GENERATED_BODY()

	TArray<FLightInfo> IncomingLights;

	void DistortLight(FLightInfo InLight, FVector InNormal, FVector InDirection);

};
