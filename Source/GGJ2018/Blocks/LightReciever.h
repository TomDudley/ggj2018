// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Data/Types.h"
#include "LightReciever.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLightReachedPoint);

UCLASS()
class GGJ2018_API ALightReciever : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* RootComp;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* RecieverBox;
	
public:	
	// Sets default values for this actor's properties
	ALightReciever();

	UPROPERTY(EditAnywhere, Category = "Light | Reciever")
	FLightInfo TargetLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LightEntered(FLightInfo LightIn);

	UPROPERTY(BlueprintAssignable, Category = "Light | Game Loop")
	FOnLightReachedPoint OnLightReachedPoint;
};
