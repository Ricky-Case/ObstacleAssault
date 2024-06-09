// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool PlatformShouldRotate() const;
	void MovePlatform(float);
	void RotatePlatform(float);
	float FindDistance(FVector, FVector) const;

	FVector nextLocation;
	FVector startingLocation;
	FVector targetLocation;
	
	UPROPERTY(EditAnywhere, Category="Moving")
		FVector platformVelocity = FVector(200.0f, -100.0f, 0.0f);
	UPROPERTY(EditAnywhere, Category="Moving")
		float moveDistance = 500.0f;
	UPROPERTY(EditAnywhere, Category="Rotation")
		FRotator rotationVelocity;
};
