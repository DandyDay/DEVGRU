// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Project/Weapon/RangedWeapon/RangedWeapon.h"
#include "ThrowableWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AThrowableWeapon : public ARangedWeapon
{
	GENERATED_BODY()

public:
	virtual void AttackInitiated() override;
	virtual void AttackStopped() override;

private:
	
	UFUNCTION(BlueprintCallable)
	virtual void ThrowWeapon();
};
