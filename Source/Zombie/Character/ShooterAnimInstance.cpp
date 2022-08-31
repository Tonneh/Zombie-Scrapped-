// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"

#include "ShooterCharacter.h"

void UShooterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner()); 
}

void UShooterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (ShooterCharacter == nullptr) 
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner()); 
	}
	if (ShooterCharacter == nullptr) return;
	if (Combat == nullptr)
	{
		Combat = ShooterCharacter->GetCombat(); 
	}
	if (Combat == nullptr) return; 
	bWeaponEquipped = ShooterCharacter->IsWeaponEquipped();
	bIsAiming = ShooterCharacter->IsAiming();
	bIsSprinting = ShooterCharacter->IsSprinting();
	WeaponType = ShooterCharacter->GetWeaponType(); 

}
