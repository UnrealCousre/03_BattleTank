// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "../Public/TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) return;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) return;
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	auto OurTankName = GetOwner()->GetName();
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// calculate the outlaunchvelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		WorldSpaceAim,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace

	);
	if (bHaveAimSolution){ 
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	auto BarrelLocation = Barrel->GetComponentLocation();
	MoveBarrel(AimDirection);
	// 
	UE_LOG(LogTemp, Warning, TEXT("Aiming solution found"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming solution not found"))
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
	// Work out the difference
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
	// Move the barrel  the right amount this frame
	// Give a max elevation speed 

}
\