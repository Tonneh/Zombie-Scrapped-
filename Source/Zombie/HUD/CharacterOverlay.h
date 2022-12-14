// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterOverlay.generated.h"


class UImage;
class UProgressBar;
class UTextBlock;

UCLASS()
class ZOMBIE_API UCharacterOverlay : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HealthText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Ammo;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HoldingAmmo;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Slash;
	UPROPERTY(meta = (BindWidget))
	UImage* Weapon;
};
