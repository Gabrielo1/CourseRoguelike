// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRExplosiveBarrel.generated.h"

class URadialForceComponent;

UCLASS()
class COURSEROGUELIKE_API ACRExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACRExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComp;


	UPROPERTY(VisibleAnywhere)
	TObjectPtr<URadialForceComponent> RadialForceComp;

	

	UFUNCTION()
	void Explode();

	UFUNCTION()
	void Impact(
		UPrimitiveComponent* Projectile,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
