// Fill out your copyright notice in the Description page of Project Settings.

#include "LightReciever.h"


// Sets default values
ALightReciever::ALightReciever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	RootComponent = RootComp;

	RecieverBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Reciever Overlap"));
	RecieverBox->SetBoxExtent(FVector(100.f));
	RecieverBox->SetCollisionProfileName(TEXT("BlockAll"));
	RecieverBox->SetupAttachment(RootComp);

}

// Called when the game starts or when spawned
void ALightReciever::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightReciever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightReciever::LightEntered(FLightInfo LightIn)
{

	LightIn.Colour.A = 255;

	if (LightIn.Colour == TargetLight.Colour)
	{
		OnLightReachedPoint.Broadcast();
	}
}

