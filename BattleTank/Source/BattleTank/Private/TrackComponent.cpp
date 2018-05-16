// Fill out your copyright notice in the Description page of Project Settings.

#include "TrackComponent.h"

void UTrackComponent::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %s throttle is %f "), *(Name), Throttle)

		// Clamp it so you cannot overdrive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(this->GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
