// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAiController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
private:

	virtual void BeginPlay() override;
	
	void Tick(float DeltaTime) override;
	// How close can ai get to player
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 500.0f;
};
