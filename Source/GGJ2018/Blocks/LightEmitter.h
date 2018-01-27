// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Block.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Data/Types.h"

#include "LightEmitter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLightHitReciever);

UCLASS()
class GGJ2018_API ALightEmitter : public ABlock
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightEmitter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 

public:	
	FTimerHandle PulseHandle;
	void Pulse();

	FOnLightHitReciever OnLightHitReciever;

	UPROPERTY(EditAnywhere, Category = "Light | Emitter")
	FLightInfo EmittedLight;

	UPROPERTY(EditAnywhere, Category = "Light | Distance")
	float LightDistance;

};
