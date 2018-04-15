// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = "setup")
	void SetBarrelComponent(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = "setup")
	void SetTurretComponent(UTankTurret * TurretToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();
	
private:
	UPROPERTY(EditAnywhere, Category = "Firing")
		float fLaunchSpeed = 4000; 
};
