// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Project/Weapon/RangedWeapon/FirearmWeapon/FirearmWeapon.h"
#include "Rifle.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API ARifle : public AFirearmWeapon
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void AttackInitiated() override;
	virtual void AttackStopped() override;
	
};
