// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Public/TrackComponent.h"


void UTankMovementComponent::Initialise(UTrackComponent* LeftTrackToSet, UTrackComponent* RightTrackToSet)
{
	
	leftTrack = LeftTrackToSet;
	rightTrack = RightTrackToSet;
}
void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	if (Throw == 0) return;
	if (!leftTrack || !rightTrack) return;
	leftTrack->SetThrottle(Throw);
	rightTrack->SetThrottle(Throw);
	

}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (Throw == 0) return;
	if (!leftTrack || !rightTrack) return;
	UE_LOG(LogTemp, Warning, TEXT(" Turn Right at %f "), Throw)
		// making throw x2 makes it at least rotate (kinda too fast ) TODO : Find normal track force value...
	leftTrack->SetThrottle(Throw );
	rightTrack->SetThrottle(-Throw );
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// No need for super, replacing whole functionality
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp,Warning,TEXT("%s vectoring to %s"), *TankName,*MoveVelocityString)
}
