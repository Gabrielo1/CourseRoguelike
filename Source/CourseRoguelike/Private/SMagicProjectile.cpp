// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraComponent.h"

// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->SetSimulatePhysics(true);
	RootComponent = SphereComp;

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>("EffectComp");
	NiagaraComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.f;
	MovementComp->ProjectileGravityScale = 0.f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bShouldBounce = false;
	MovementComp->bInitialVelocityInLocalSpace = true;
	

}

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	//SphereComp->OnComponentHit.AddDynamic(this, &ASMagicProjectile::Impact);
}

//void ASMagicProjectile::Impact(UPrimitiveComponent* Projectile, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	if (GEngine)
//	{
//		GEngine->AddOnScreenDebugMessage(
//			-1,           // Identificador (Key). Usa -1 para añadir un mensaje nuevo sin sobreescribir otros.
//			5.0f,         // Duración en pantalla (en segundos).
//			FColor::Orange,  // Color del texto.
//			TEXT("Proyectil colisionó!") // Mensaje a imprimir.
//		);
//	}
//}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

