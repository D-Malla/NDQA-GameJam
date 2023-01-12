// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MainCharacter.generated.h"

class UAnimMontage;
class UCameraComponent;
class UInputComponent;
class UInputAction;
class UInputMappingContext;
class USceneComponent;
class USkeletalMeshComponent;
class USoundBase;

UCLASS()
class NDQA_GAMEJAM_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Weapon")
	TSubclassOf<AActor> WeaponBP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Input Callback Functions */
	// Called for movement input
	void Move(const FInputActionValue& Value);
	
	// Called for looking input
	void Look(const FInputActionValue& Value);

	/* Scrap System */
	UFUNCTION(BlueprintCallable)
	void AddScraps(int32 ScrapsAmount);

	UFUNCTION(BlueprintCallable)
	void RemoveScraps(int32 ScrapsAmount);


private:
	/* Base Components */
	// Character mesh. First person view(Just arms. Seen only by self).
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Main | Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* MeshComponent;

	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Main | Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

	/* Input */
	// Input mapping context for enhanced input.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaulMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MovementAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/* Player Stats */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Stats", meta = (AllowPrivateAccess = "true"))
	int32 MaxScraps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Stats", meta = (AllowPrivateAccess = "true"))
	int32 CurrentScraps;

public:	
	// Returns MainCharacter mesh.
	USkeletalMeshComponent* GetMesh() const { return MeshComponent; }

	// Returns our first person camera
	UCameraComponent* GetCameraComponent() const { return CameraComponent; }

	// Returns Player Current Health
	int32 GetCurrentScraps() const { return CurrentScraps; }

	// Returns Player MaxHealth
	int32 GetMaxScraps() const { return MaxScraps; }
};
