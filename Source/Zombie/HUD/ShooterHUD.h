// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterHUD.generated.h"

class UBuyShop;
class UCharacterOverlay;
class UTexture2D;

USTRUCT(BlueprintType)
struct FHUDPackage
{
	GENERATED_BODY()
public:
	UTexture2D* CrosshairsCenter;
	UTexture2D* CrosshairsLeft;
	UTexture2D* CrosshairsRight;
	UTexture2D* CrosshairsTop;
	UTexture2D* CrosshairsBottom;
};


UCLASS()
class ZOMBIE_API AShooterHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override; 

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	TSubclassOf<UUserWidget> CharacterOverlayClass;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	TSubclassOf<UUserWidget> HitMarkerHeadClass;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	TSubclassOf<UUserWidget> HitMarkerBodyClass;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	TSubclassOf<UUserWidget> ShopOverlayClass;
	
	UPROPERTY()
	UCharacterOverlay* CharacterOverlay;

	UPROPERTY()
	UBuyShop* ShopOverlay; 
protected:
	virtual void BeginPlay() override;
private:
	FHUDPackage HUDPackage;

	void DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter);

	void AddCharacterOverlay();

	void AddShopOverlay();
	void RemoveShopOverlay(); 
public:
	FORCEINLINE void SetHUDPackage(FHUDPackage Package) { HUDPackage = Package; }
	FORCEINLINE void ShowShop()  { AddShopOverlay(); }
	FORCEINLINE void RemoveShop()  { RemoveShopOverlay(); }

};
