// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TrackComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTrackComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "input")
		void SetThrottle(float Throttle);

	//Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxForce = 400000.0f; // tank is 40 tonnes at 1 g acceleration
};
