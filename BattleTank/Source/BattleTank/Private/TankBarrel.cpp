// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"
#include "../Public/TankBarrel.h" // usuwa mi to blad intelisense

void UTankBarrel::Elevate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto ElevationChange = RelativeSpeed * fMaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, fMinElevation, fMaxElevation);
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}


