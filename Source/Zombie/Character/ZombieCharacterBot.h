// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieCharacterBot.generated.h"

UCLASS()
class ZOMBIE_API AZombieCharacterBot : public ACharacter
{
	GENERATED_BODY()

public:
	AZombieCharacterBot();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void ReceiveDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatorController, AActor* DamageCauser);
	
private:

	UPROPERTY(EditAnywhere) 
	float MaxHealth = 100.f;

	float Health = MaxHealth;

	UPROPERTY(EditAnywhere)
	UAnimMontage* DeathAnimation;

	bool IsDead = false;
	
	FTimerHandle DeathTimer;
	float DeathDelay = 3;

	void StartDeathTimer();
	void DeathTimerFinished(); 
public:	
	virtual void Tick(float DeltaTime) override;
	
};