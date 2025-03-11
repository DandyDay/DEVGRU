// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CCTVWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UCCTVWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CCTVNum;

	void SetCCTVNum(int32 Num);
};
