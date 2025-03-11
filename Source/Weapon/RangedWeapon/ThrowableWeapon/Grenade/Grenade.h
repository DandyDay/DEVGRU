// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Project/Weapon/RangedWeapon/ThrowableWeapon/ThrowableWeapon.h"
#include "Grenade.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AGrenade : public AThrowableWeapon
{
	GENERATED_BODY()
	
private:
	class AShooterCharacter* Character;

	virtual void ThrowWeapon() override;
	void FireGrenade();
};
