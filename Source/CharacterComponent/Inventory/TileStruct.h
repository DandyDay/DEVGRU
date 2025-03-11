#pragma once

#include "CoreMinimal.h"
#include "TileStruct.generated.h"

USTRUCT(BlueprintType)
struct FTileStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	int X = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	int Y = 0;
};