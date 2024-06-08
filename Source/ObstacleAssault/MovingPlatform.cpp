// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startingLocation = GetActorLocation();
	nextLocation = startingLocation;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(FindDistanceTravelled() >= maximumDistance)
	{
		startingLocation = GetActorLocation();
		platformVelocity *= -1.0f;
	}

	// Move the MovingPlatform.
	nextLocation += (platformVelocity * DeltaTime);
	SetActorLocation(nextLocation);
}

float AMovingPlatform::FindDistanceTravelled()
{
	FVector travelVector = GetActorLocation() - startingLocation;

	float distanceTravelled = (
		FMath::Sqrt(
			travelVector.X * travelVector.X
			+ travelVector.Y * travelVector.Y
			+ travelVector.Z * travelVector.Z
		)
	);

	return distanceTravelled;
}