// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputMappingContext.h"

#include "CRCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCRInteractionComponent;
class UAnimMontage;

UCLASS()
class COURSEROGUELIKE_API ACRCharacter : public ACharacter
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Editanywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(Editanywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;

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

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Input_PrimaryInteract;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	UCRInteractionComponent* InteractionComp;

	UPROPERTY(EditAnywhere)
	bool bIsDebugging = false;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void LookMouse(const FInputActionValue& Instance);
	void Move(const FInputActionInstance& Instance);
	void PrimaryAtack();
	void PrimaryAtack_TimeElapsed();
	void PrimaryInteract();
	void Jump();
	void StopJumping();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
