// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
private:
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;
	ATank * GetPlayerTank() const;
	void Tick(float DeltaTime) override;
	
	
};
