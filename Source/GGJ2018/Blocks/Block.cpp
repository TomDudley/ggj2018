// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"



// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	RootComponent = RootComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	StaticMeshComp->SetupAttachment(RootComp);

	DirectionComp = CreateDefaultSubobject<UArrowComponent>(TEXT("Direction"));
	DirectionComp->SetupAttachment(RootComp);

	RecieverBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Reciever Overlap"));
	RecieverBox->SetBoxExtent(FVector(100.f));
	RecieverBox->SetCollisionProfileName(TEXT("BlockAll"));
	RecieverBox->SetupAttachment(RootComp);

}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlock::DistortLight(FLightInfo InLight, FVector HitNormal, FVector InDirection)
{
	UE_LOG(LogTemp, Log, TEXT("Distorting light in empty Block object"));
}

void ABlock::EmitLight(FVector Direction, FLightInfo OutLight, float Distance, ABlock* LightSource)
{

	if (true)
	{
		FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
		TraceParams.bTraceComplex = true;
		TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = false;
		TraceParams.AddIgnoredActor(LightSource);

		FHitResult HitRes;

		FVector TraceStart = GetActorLocation();
		FVector TraceEnd = GetActorLocation() + (Direction * Distance);
		FVector HitLocation;

		GetWorld()->LineTraceSingleByChannel(HitRes, TraceStart, TraceEnd, ECC_Camera, TraceParams);

		if (HitRes.bBlockingHit)
		{
			AActor* HitActor = HitRes.Actor.Get();
			HitLocation = HitRes.Location;

			if (Cast<ALightReciever>(HitActor))
			{
				Cast<ALightReciever>(HitActor)->LightEntered(OutLight);
				DrawDebugLine(GetWorld(), TraceStart, HitLocation, OutLight.Colour, false, 0.5f, 0, 5);
			}
			else if (Cast<ABlock>(HitActor))
			{
				Cast<ABlock>(HitActor)->DistortLight(OutLight, HitRes.Normal, Direction);
				DrawDebugLine(GetWorld(), TraceStart, HitLocation, OutLight.Colour, false, 0.5f, 0, 5);
			}
			else
			{
				DrawDebugLine(GetWorld(), TraceStart, HitLocation, OutLight.Colour, false, 0.5f, 0, 5);
			}
		}
		else
		{
			DrawDebugLine(GetWorld(), TraceStart, TraceEnd, OutLight.Colour, false, 0.5f, 0, 5);
		}
	}
}
