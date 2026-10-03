// Fill out your copyright notice in the Description page of Project Settings.


#include "VRStrategyPrototype/Public/Character/VRHoverPawn.h"

#include "GameFramework/InputSettings.h"

AVRHoverPawn::AVRHoverPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AVRHoverPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVRHoverPawn::ApplyMovementInput(const FVector2D& InputValue, FVector CameraForwardVector, FVector CameraRightVector)
{
	const float MovementInputX = InputValue.X;
	const float MovementInputY = InputValue.Y;
	const float TimeElapsed = GetWorld()->GetDeltaSeconds();

	const FVector ForwardVector = CameraForwardVector.GetSafeNormal2D();
	const FVector RightVector = CameraRightVector.GetSafeNormal2D();

	FVector Offset = FVector::ZeroVector;
	if (FMath::Abs(MovementInputX) >= MovementInputThreshold)
	{
		Offset += RightVector * MovementInputX * MovementSpeedMultiplier * TimeElapsed;
	}
	if (FMath::Abs(MovementInputY) >= MovementInputThreshold)
	{
		Offset += ForwardVector * MovementInputY * MovementSpeedMultiplier * TimeElapsed;
	}
	if (!Offset.IsNearlyZero())
	{
		AddActorWorldOffset(Offset);
	}
	/*
	const float MovementInputX = InputValue.X; 
	const float MovementInputY = InputValue.Y; 
	const float TimeElapsed = GetWorld()->GetDeltaSeconds();
	bool IsAnyInputMovement = false;
	float PawnMovementX = 0.f;
	float PawnMovementY = 0.f;
	if (abs(MovementInputX) >= MovementInputThreshold)
	{
		PawnMovementY = MovementInputX * MovementSpeedMultiplier * TimeElapsed; // Axes are different on stick vs pawn
		IsAnyInputMovement = true;
	}
	if (abs(MovementInputY) >= MovementInputThreshold)
	{
		PawnMovementX = MovementInputY * MovementSpeedMultiplier * TimeElapsed;
		IsAnyInputMovement = true;
	}
	if (IsAnyInputMovement)
	{
		AddActorWorldOffset(FVector(PawnMovementX, PawnMovementY, 0.f)); // Axes are different on stick vs pawn
	}
	*/
}

void AVRHoverPawn::ApplyVerticalAndRotationInput(const FVector2D& InputValue)
{
	const float RotationMovementInput = InputValue.X; 
	const float VerticalMovementInput = InputValue.Y; 
	const float TimeElapsed = GetWorld()->GetDeltaSeconds();
	
	if (abs(RotationMovementInput) >= RotationInputThreshold)
	{
		const FRotator RotationFromInput(0.f, RotationMovementInput * RotationSpeedMultiplier * TimeElapsed, 0.f);
		AddActorWorldRotation(RotationFromInput);
	}
	
	if (abs(VerticalMovementInput) >= VerticalInputThreshold)
	{
		float VerticalMovementFromInput = VerticalMovementInput * VerticalSpeedMultiplier * TimeElapsed;
		AddActorWorldOffset(FVector(0.f, 0.f, VerticalMovementFromInput));
	}
}


