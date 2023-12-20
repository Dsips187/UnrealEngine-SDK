#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"
#include "AutoGen/Models/Shared/VyTokenAttributeDto.h"

#include "VyOptTokenAttributeArray.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptTokenAttributeArrayBPL.MakeOptional", VyOptionalType = "TArray<FVyTokenAttributeDto>"))
struct VENLY_API FVyOptTokenAttributeArray : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	TArray<FVyTokenAttributeDto> Val;

	FVyOptTokenAttributeArray();

	explicit FVyOptTokenAttributeArray(TArray<FVyTokenAttributeDto> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};