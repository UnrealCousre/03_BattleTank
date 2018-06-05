// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
class UTrackComponent;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "Tank Movement")
		void IntendMoveForward(float Throw);
		UFUNCTION(BlueprintCallable, Category = "Initialisation")
		void Initialise(UTrackComponent* LeftTrackToSet, UTrackComponent* RightTrackToSet);
		UFUNCTION(BlueprintCallable, Category = "Tank Movement")
		void IntendTurnRight(float Throw);
		virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	UTrackComponent * leftTrack =nullptr;
	UTrackComponent* rightTrack = nullptr;
};
