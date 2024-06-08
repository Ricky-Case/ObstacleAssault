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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float FindDistanceTravelled();

	FVector nextLocation = FVector(0.0f, 0.0f, 0.0f);
	FVector startingLocation = FVector(-14960.0f,-2640.0f,4056.0f);
	
	UPROPERTY(EditAnywhere, Category="Moving Platform")
		FVector platformVelocity = FVector(200.0f, -100.0f, 0.0f);
	UPROPERTY(EditAnywhere)
		float maximumDistance = 500.0f;
};
