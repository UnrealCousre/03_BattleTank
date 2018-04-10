// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank * GetControlledTank() const;
	
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	// return out parameter, true if hit landscape
	bool GetSightRayLocation(FVector &HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;

	UPROPERTY(EditAnywhere)
	float fCrosshairYLocation = 0.3333;
	UPROPERTY(EditAnywhere)
		float fCrosshairXLocation = 0.5;

	bool GetLookVectorHitLocation(FVector &HitLocation, FVector LookDirection) const;
};
