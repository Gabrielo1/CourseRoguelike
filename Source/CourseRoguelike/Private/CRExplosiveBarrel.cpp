// Fill out your copyright notice in the Description page of Project Settings.


#include "CRExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ACRExplosiveBarrel::ACRExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    MeshComp->SetSimulatePhysics(true);

	// TODO: Study collision profiles and set the appropriate one for the barrel
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComp->SetupAttachment(MeshComp);
//	RadialForceComp->ImpulseStrength = 1000.f;
}

// Called when the game starts or when spawned
void ACRExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	MeshComp->OnComponentHit.AddDynamic(this, &ACRExplosiveBarrel::Impact);
}

void ACRExplosiveBarrel::Explode()
{

    RadialForceComp->FireImpulse();
   
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,           // Identificador (Key). Usa -1 para añadir un mensaje nuevo sin sobreescribir otros.
            5.0f,         // Duración en pantalla (en segundos).
            FColor::Red,  // Color del texto.
            TEXT("BOOM!") // Mensaje a imprimir.
        );
    }
}

void ACRExplosiveBarrel::Impact(UPrimitiveComponent* Projectile, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
    Explode();
}

// Called every frame
void ACRExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

