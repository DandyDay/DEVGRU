// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Project/ShooterTypes/ItemTypes.h"
#include "ItemObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PROJECT_API AItemObject : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FIntPoint Dimensions;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Icon;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* IconRotated;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AItem> ItemClass;
	UPROPERTY(EditAnywhere)
	EItemType ItemType;
	
	bool Rotated;
	void Rotate();
	FIntPoint GetDimensions() const;
	UMaterialInterface* GetIcon() const { if (Rotated) return IconRotated; return Icon; }
	TSubclassOf<AItem> GetItemClass() const { return ItemClass; }
	bool IsRotated() const { return Rotated; }
	EItemType GetItemType() const { return ItemType; }
};
