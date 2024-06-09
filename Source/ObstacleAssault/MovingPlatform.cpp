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
	targetLocation = startingLocation
					+ (
						platformVelocity / (
							FMath::Sqrt(
								platformVelocity.X * platformVelocity.X
								+ platformVelocity.Y * platformVelocity.Y
								+ platformVelocity.Z * platformVelocity.Z
						))
					) * moveDistance;
	nextLocation = startingLocation;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(FindDistance(startingLocation, GetActorLocation()) >= moveDistance)
	{
		FVector newTarget = startingLocation;
		startingLocation = targetLocation;
		targetLocation = newTarget;
		platformVelocity *= -1.0f;
	}

	// Move the MovingPlatform.
	nextLocation += (platformVelocity * DeltaTime);
	SetActorLocation(nextLocation);
}

float AMovingPlatform::FindDistance(FVector posA, FVector posB)
{
	FVector travelVector = posB - posA;

	float distance = (
		FMath::Sqrt(
			travelVector.X * travelVector.X
			+ travelVector.Y * travelVector.Y
			+ travelVector.Z * travelVector.Z
		)
	);

	return distance;
}