// Fill out your copyright notice in the Description page of Project Settings.

#include "PP5Uebung1.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::PickUpAmmo() {
	this->Ammo += 5;
}

void AMyCharacter::AttackPlayer() {
	if (this->Ammo > 0)
	{
		this->Ammo--;

		const FVector actorLocation = GetActorLocation();

		const FVector endTrace = actorLocation + GetActorForwardVector() * 100000;

		static FName FireTraceIdent = FName(TEXT("WeaponTrace"));

		FCollisionQueryParams TraceParams(FireTraceIdent, true, this);

		FHitResult HitResult;
		AMyCharacter* other;

		if (GetWorld()->LineTraceSingle(HitResult, actorLocation, endTrace, TraceParams, FCollisionObjectQueryParams()) && (other = (AMyCharacter*)HitResult.Actor.Get()) != nullptr)
		{
			other->Health--;
			this->Score++;
		}
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

