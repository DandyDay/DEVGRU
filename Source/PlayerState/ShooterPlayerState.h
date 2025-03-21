// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Project/ShooterTypes/Team.h"
#include "ShooterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AShooterPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
	void AddToScore(float ScoreAmount);
	void AddToDefeats(int32 DefeatsAmount);

private:
	UPROPERTY()
	class AShooterCharacter* Character;
	UPROPERTY()
	class AShooterController* Controller;

	UPROPERTY(Replicated)
	int32 Defeats;

	UPROPERTY(ReplicatedUsing = OnRep_Team)
	ETeam Team = ETeam::ET_NoTeam;

	UFUNCTION()
	void OnRep_Team();

public:
	FORCEINLINE ETeam GetTeam() const { return Team; }
	void SetTeam(ETeam TeamToSet);
};
