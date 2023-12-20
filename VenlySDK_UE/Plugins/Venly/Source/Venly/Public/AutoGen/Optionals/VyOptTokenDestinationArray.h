#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"
#include "AutoGen/Models/Nft/VyTokenDestinationDto.h"

#include "VyOptTokenDestinationArray.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptTokenDestinationArrayBPL.MakeOptional", VyOptionalType = "TArray<FVyTokenDestinationDto>"))
struct VENLY_API FVyOptTokenDestinationArray : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	TArray<FVyTokenDestinationDto> Val;

	FVyOptTokenDestinationArray();

	explicit FVyOptTokenDestinationArray(TArray<FVyTokenDestinationDto> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};