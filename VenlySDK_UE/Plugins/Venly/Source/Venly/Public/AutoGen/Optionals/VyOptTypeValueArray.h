#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"
#include "AutoGen/Models/Shared/VyTypeValueDto.h"

#include "VyOptTypeValueArray.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptTypeValueArrayBPL.MakeOptional", VyOptionalType = "TArray<FVyTypeValueDto>"))
struct VENLY_API FVyOptTypeValueArray : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	TArray<FVyTypeValueDto> Val;

	FVyOptTypeValueArray();

	explicit FVyOptTypeValueArray(TArray<FVyTypeValueDto> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};