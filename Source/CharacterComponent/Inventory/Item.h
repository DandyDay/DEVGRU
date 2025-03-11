#pragma once

#include "Project/Interfaces/InteractableObject.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Item.generated.h"

UCLASS()
class PROJECT_API AItem : public AActor, public IInteractableObject
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void BeginPlay() override;
	
protected:
	class AItemObject* GetDefaultItemObject();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereCollisionComponent;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AItemObject> ItemObjectClass;
	
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void Interact(AActor* Interactor) override;

public:
	TSubclassOf<AItemObject> GetItemObjectClass() const { return ItemObjectClass; }
};

