// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class PP5UEBUNG1_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(BlueprintReadOnly, Category = "default", EditAnywhere)
		float Health;

	UPROPERTY(BlueprintReadOnly, Category = "default", EditAnywhere)
		int32 Score;

	UPROPERTY(BlueprintReadOnly, Category = "default", EditAnywhere)
		int32 Ammo;

	UFUNCTION(Category = "default", BlueprintCallable)
		void PickUpAmmo();

	UFUNCTION(Category = "default", BlueprintCallable)
		void AttackPlayer();


};
