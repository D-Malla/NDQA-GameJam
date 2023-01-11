// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPCs/NPCBase.h"
#include "EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class NDQA_GAMEJAM_API AEnemyBase : public ANPCBase
{
	GENERATED_BODY()

	class UBoxComponent;
	class USoundCue;
	class USphereComponent;


public:
	// Sets default values for this character's properties
	AEnemyBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Enemy Base Properties */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Enemy | Properties")
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Enemy | Properties")
	USoundCue* AttackSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Enemy | Properties")
	USoundCue* HitSound;

	/* Enemy Stats */
	float MaxHealth;
	float CurrentHealth;
	float DamageToVehicle;
	int32 ScrapsToRemove;

	/* Combat Functionality */
	void AttackVehicle(float DamageAmount);
	void AttackPlayer(AActor* HitPlayer, int32 RemoveScraps);

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	void Die();

private:

public:
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }
};
