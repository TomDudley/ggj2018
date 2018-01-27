// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Data/Types.h"
#include "DrawDebugHelpers.h"
#include "LightReciever.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Block.generated.h"

UCLASS()
class GGJ2018_API ABlock : public AActor
{

	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* RootComp;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* DirectionComp;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* RecieverBox;

public:	
	// Sets default values for this actor's properties
	ABlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void DistortLight(FLightInfo InLight, FVector InNormal, FVector InDirection);
	virtual void EmitLight(FVector Direction, FLightInfo OutLight, float Distance, ABlock* LightSource);
};
