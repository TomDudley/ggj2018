// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Types.generated.h"

UENUM(BlueprintType)
enum class ELightColour : uint8 
{
	White
};

USTRUCT(BlueprintType)
struct FLightInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Light Info")
	FColor Colour;

	UPROPERTY(EditAnywhere, Category = "Light Info")
	float LightStrength;

	FORCEINLINE bool operator==(const FLightInfo &Other) const
	{
		return Colour == Other.Colour && LightStrength == Other.LightStrength;
	}
	
	FString ToString()
	{
		return Colour.ToString();
	}
};


UCLASS()
class GGJ2018_API UTypes : public UObject
{
	GENERATED_BODY()	
};
