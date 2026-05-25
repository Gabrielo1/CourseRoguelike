// Fill out your copyright notice in the Description page of Project Settings.


#include "CRCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Enhanced input
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ACRCharacter::ACRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ACRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACRCharacter::MoveForward(const FInputActionInstance& AxisValue) // (float Value)
{
	check(this);
	//AddMovementInput(GetActorForwardVector(), Value);
}

void ACRCharacter::Move(const FInputActionInstance& Instance)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	
	// Get value from input (combined value from WASD keys or single Gamepad stick) and convert to Vector (x,y)
	const FVector2D AxisValue = Instance.GetValue().Get<FVector2D>();
	
	//Move forward/back
	AddMovementInput(ControlRot.Vector(), AxisValue.Y);
	
	//Move Rigth/Left strafe
//	const FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxes(EAxis::Y);
//	AddMovementInput(RightVector, AxisValue.X);
}

void ACRCharacter::AddControllerYawInput(float Value)
{

}

// Called every frame
void ACRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();

	Subsystem->AddMappingContext(DefaultInputMapping, 0);

	// Example of deprecated input system
	//PlayerInputComponent->BindAxis("IA_Forward_Backward_CRCharacter_Input", this, &ACRCharacter::MoveForward);

	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	//InputComp->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ACRCharacter::MoveForward);

	InputComp->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ACRCharacter::Move);
	
}

