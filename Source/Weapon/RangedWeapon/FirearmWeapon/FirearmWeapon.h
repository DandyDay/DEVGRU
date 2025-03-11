// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Project/Weapon/RangedWeapon/RangedWeapon.h"
#include "FirearmWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AFirearmWeapon : public ARangedWeapon
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void AttackInitiated() override;
	virtual void AttackStopped() override;
	
	// Crosshair
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	class UTexture2D* CrosshairsCenter;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	UTexture2D* CrosshairsLeft;
	
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	UTexture2D* CrosshairsRight;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	UTexture2D* CrosshairsTop;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	UTexture2D* CrosshairsBottom;

	// Automatic fire
	UPROPERTY(EditAnywhere, Category = Combat)
	bool bAutomatic = true;

	// Recoil
	UPROPERTY(EditAnywhere, Category = Combat)
	float RecoilMinPitch = -0.25f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float RecoilMaxPitch = 0.15f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float RecoilMinYaw = -0.15f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float RecoilMaxYaw = 0.15f;

	// Montage
	void PlayReloadAnim();

protected:
	// Casing
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ACasing> CasingClass;

	// Check FirstShot for Recoil
	bool bIsFirstShot = true;
	
	// Recoil
	UPROPERTY(EditAnywhere)
	float RecoilMultiplier = 1.f;
	UPROPERTY(EditAnywhere)
	float HandSwayRandPitch = 1.f;
	UPROPERTY(EditAnywhere)
	float HandSwayRandYaw = 1.f;
	UPROPERTY(EditAnywhere)
	float HandSwayRandRoll = 1.f;
	FTransform WeaponRecoil;
	FTransform CalcRecoil();
	UPROPERTY()
	FTransform FollowerRecoil;
	UPROPERTY()
	FTransform LeaderRecoil;
	void InterpolateWeaponRecoil(float DeltaTime);
	void AddControllerRecoil();

	// Montage
	UPROPERTY(EditAnywhere, Category="Reload Animation")
	class UAnimSequence* WeaponReloadAnimation;
	
public:
	FORCEINLINE FTransform GetFollowerRecoil() const { return FollowerRecoil; }
	FORCEINLINE FTransform GetLeaderRecoil() const { return LeaderRecoil; }
	FORCEINLINE float GetHandSwayRandYaw() const { return HandSwayRandYaw; }
	FORCEINLINE float GetHandSwayRandPitch() const { return HandSwayRandPitch; }
	FORCEINLINE float GetHandSwayRandRoll() const { return HandSwayRandRoll; }
};
