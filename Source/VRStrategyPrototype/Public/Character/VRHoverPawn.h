// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRHoverPawn.generated.h"


UCLASS()
class VRSTRATEGYPROTOTYPE_API AVRHoverPawn : public APawn
{
	GENERATED_BODY()

public:

	AVRHoverPawn();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoverMovement")
	float MovementSpeedMultiplier = 300.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoverMovement")
	float RotationSpeedMultiplier = 150.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoverMovement")
	float VerticalSpeedMultiplier = 150.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoverMovement")
	float MovementInputThreshold = 0.5f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoverMovement")
	float RotationInputThreshold = 0.8f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoverMovement")
	float VerticalInputThreshold = 0.8f;
	
	UFUNCTION(BlueprintCallable, Category = "HoverMovement")
	void ApplyMovementInput(const FVector2D& InputValue, FVector CameraForwardVector, FVector CameraRightVector);
	
	UFUNCTION(BlueprintCallable, Category = "HoverMovement")
	void ApplyVerticalAndRotationInput(const FVector2D& InputValue);
	
	
public:

};
