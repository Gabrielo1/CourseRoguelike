// Fill out your copyright notice in the Description page of Project Settings.


#include "CRInteractionComponent.h"
#include "CRGameplayInterface.h"

// Sets default values for this component's properties
UCRInteractionComponent::UCRInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	InteractionDistance = 1000.f;
	// ...
}


// Called when the game starts
void UCRInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCRInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCRInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();

	FVector EyeLocation;	
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);


	FVector End = EyeLocation + (EyeRotation.Vector() * InteractionDistance);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);
	
	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<UCRGameplayInterface>())
		{
			APawn* MyPawn = Cast<APawn>(MyOwner);
			// if (MyPawn) is not necessary becuase if MyPawn is nullptr, the Interact function will still be called with a nullptr parameter.
			
			ICRGameplayInterface::Execute_Interact(HitActor, MyPawn);	
		}
	}

	if (bIsDebugging)
	{
		DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Green, false, 2.f, 0, 2.f);
	}
}

