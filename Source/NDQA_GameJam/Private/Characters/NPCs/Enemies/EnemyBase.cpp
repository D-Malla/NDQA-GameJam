// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPCs/Enemies/EnemyBase.h"

AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Enemy Stats */
	MaxHealth = 100.f;
	CurrentHealth = MaxHealth;

	DamageToVehicle = 15.f;
	ScrapsToRemove = 10;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	//CombatSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::CombatSphereOnOverlapBegin);
	//CombatSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::CombatSphereOnOverlapEnd);

	//CombatCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::CombatOnOverlapBegin);
	//CombatCollision->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::CombatOnOverlapEnd);
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyBase::AttackVehicle(float DamageAmount)
{

}

void AEnemyBase::AttackPlayer(AActor* HitPlayer, int32 RemoveScraps)
{
	
}

float AEnemyBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	CurrentHealth -= DamageAmount;

	if (CurrentHealth -= DamageAmount)
	{
		Die();
	}
	return DamageAmount;
}

void AEnemyBase::Die()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Enemy Died!!!")));
	}
}