// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform() { PrimaryActorTick.bCanEverTick = true; } // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
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

	UE_LOG(LogTemp, Display, TEXT("MOVE DISTANCE: %f"), moveDistance);
}

bool AMovingPlatform::PlatformShouldRotate() const { return (FindDistance(startingLocation, GetActorLocation()) >= moveDistance); }

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if(PlatformShouldRotate())
	{
		FVector newTarget = startingLocation;
		startingLocation = targetLocation;
		targetLocation = newTarget;
		platformVelocity *= -1.0f;

		UE_LOG(LogTemp, Display, TEXT("%s REVERSING."), *GetName());
		UE_LOG(LogTemp, Display, TEXT("OVERSHOT TARGET BY: %f"), FindDistance(startingLocation, GetActorLocation()));
	}

	nextLocation += (platformVelocity * DeltaTime);
	SetActorLocation(nextLocation);
}

void AMovingPlatform::RotatePlatform(float DeltaTime) { AddActorLocalRotation(rotationVelocity * DeltaTime); }

float AMovingPlatform::FindDistance(FVector posA, FVector posB) const
{
	const FVector travelVector = posB - posA;

	const float distance = (
		FMath::Sqrt(
			travelVector.X * travelVector.X
			+ travelVector.Y * travelVector.Y
			+ travelVector.Z * travelVector.Z
		)
	);

	return distance;
}