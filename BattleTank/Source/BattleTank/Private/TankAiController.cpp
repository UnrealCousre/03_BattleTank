// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "../Public/Tank.h"
#include "../Public/TankAiController.h"




void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	

}



void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank;
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TANK NOT FOUND"))return; }
	else
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO limit fire rate
	}
}
