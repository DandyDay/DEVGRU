// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Project/Weapon/RangedWeapon/FirearmWeapon/FirearmWeapon.h"

#include "Pistol.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API APistol : public AFirearmWeapon
{
	GENERATED_BODY()
public:
	virtual void AttackInitiated() override;
	virtual void AttackStopped() override;

private:
	UPROPERTY(EditAnywhere)
	float Damage = 10.f;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactParticles;
};
