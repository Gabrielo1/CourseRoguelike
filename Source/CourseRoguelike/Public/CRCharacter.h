// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputMappingContext.h"

#include "CRCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class COURSEROGUELIKE_API ACRCharacter : public ACharacter
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Editanywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

public:
	// Sets default values for this character's properties
	ACRCharacter();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultInputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Input_Jump;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Input_LookMouse;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Input_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Input_PrimaryAtack;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void LookMouse(const FInputActionValue& Instance);
	void Move(const FInputActionInstance& Instance);
	void PrimaryAtack();
	void Jump(); //To do: Add time that button was pressed to make higher jump if player hold the button longer

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
