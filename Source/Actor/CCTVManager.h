// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Project/Interfaces/InteractableObject.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CCTVManager.generated.h"

UCLASS()
class PROJECT_API ACCTVManager : public AActor, public IInteractableObject
{
	GENERATED_BODY()
	
public:	
	ACCTVManager();
	virtual void Interact(AActor* Interactor) override;
	
protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereCollisionComponent;
	
private:
	class AShooterController* ShooterController;
	
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void TurnOffCCTV(class AShooterCharacter* ShooterCharacter);
	void AddCCTVWidget();
	void TurnOnCCTV(AShooterCharacter* ShooterCharacter);
	void WatchNextCCTV();
	void WatchPrevCCTV();
	
	UPROPERTY()
	TArray<AActor*> CameraActors;
	UPROPERTY(VisibleAnywhere)
	bool bInteracting = false;
	int CurrentCameraIndex;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCCTVWidget> CCTVWidgetClass;
	UCCTVWidget* CCTVWidget;
};
