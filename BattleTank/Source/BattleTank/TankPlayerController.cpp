// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controler not possesing tank"))
	}
	else
	{
	UE_LOG(LogTemp,Warning,TEXT("Player controler at begin play %s"),*(ControlledTank->GetName()))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// aim towards crosshair
	//UE_LOG(LogTemp, Warning, TEXT("PLAYER CONTROLER TICKING"));
	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if(GetSightRayLocation(HitLocation)){ // side effect, its raytraces
	 // out parameter
		GetControlledTank()->AimAt(HitLocation);
	}
}
// Get world location through raytrace , true if hits landscape
bool ATankPlayerController::GetSightRayLocation(FVector &HitLocation) const
{
	HitLocation = FVector(1.0);
	// find crosshair postition
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto ScreenLocation = FVector2D(ViewPortSizeX* fCrosshairXLocation, ViewPortSizeY *  fCrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *(ScreenLocation.ToString()))
		// deproject the screen position of the crosshair to world direction
		FVector LookDirection;
		if (GetLookDirection(ScreenLocation, LookDirection))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *(LookDirection.ToString()));;
			//line trace along it and see what we hit
			GetLookVectorHitLocation(HitLocation,LookDirection);
		}
	
	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded but must be passed in
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector & HitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceEnd = StartLocation +(LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation,
		LineTraceEnd,
		ECollisionChannel::ECC_Visibility
		))
	{
		HitLocation = HitResult.Location;
		return true;
	}

		return false;

	
}
