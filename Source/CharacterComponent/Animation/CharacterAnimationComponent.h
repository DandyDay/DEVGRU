// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Project/ShooterTypes/TuringInPlace.h"
#include "CharacterAnimationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_API UCharacterAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCharacterAnimationComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Montages
	void PlayFireMontage(bool bAiming);
	void PlayReloadMontage();
	void PlayElimMontage();
	void PlayThowGrenadeMontage(bool bThrow);
	UFUNCTION(BlueprintCallable)
	void PlaySwapEquipMontage();
	void PlaySwapUnequipMontage();

protected:
	virtual void BeginPlay() override;

private:
	class AShooterCharacter* OwnerShooterCharacter;
	
	// Montages
	UPROPERTY(EditAnywhere, Category="Combat")
	class UAnimMontage* FireWeaponMontage;
	UPROPERTY(EditAnywhere, Category="Combat")
	UAnimMontage* ReloadMontage;
	UPROPERTY(EditAnywhere, Category="Combat")
	UAnimMontage* ElimMontage;
	UPROPERTY(EditAnywhere, Category="Combat")
	UAnimMontage* ThrowGrenadeMontage;
	UPROPERTY(EditAnywhere, Category="Combat")
	UAnimMontage* SwapEquipMontage;
	UPROPERTY(EditAnywhere, Category="Combat")
	UAnimMontage* SwapUnequipMontage;

	// Aimoffset
	void AimOffset(float DeltaTime);
	
	// TurnInPlace
	float AO_Yaw;
	float InterpAO_Yaw;
	float AO_Pitch;
	FRotator StartingAimRotation;
	FRotator PrevRotation;

	ETurningInPlace TurningInPlace = ETurningInPlace::ETIP_NotTurning;
	void TurnInPlace(float DeltaTime);
	
	bool bRotateRootBone;

public:
	void SetOwnerShooterCharacter(AShooterCharacter* Owner) { OwnerShooterCharacter = Owner; }
	ETurningInPlace GetTurningInPlace() const { return TurningInPlace; }
	float GetAO_Yaw() const { return AO_Yaw; }
	float GetAO_Pitch() const { return AO_Pitch; }
	bool GetbRotateRootBone() const { return bRotateRootBone; }
};
