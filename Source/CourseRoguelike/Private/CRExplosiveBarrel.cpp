// Fill out your copyright notice in the Description page of Project Settings.


#include "CRExplosiveBarrel.h"

// Sets default values
ACRExplosiveBarrel::ACRExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

// Called when the game starts or when spawned
void ACRExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACRExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

