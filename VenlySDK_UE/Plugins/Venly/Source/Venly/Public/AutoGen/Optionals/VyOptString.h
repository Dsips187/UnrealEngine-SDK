#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"

#include "VyOptString.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptStringBPL.MakeOptional", VyOptionalType = "FString"))
struct VENLY_API FVyOptString : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	FString Val;

	FVyOptString();

	explicit FVyOptString(FString Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};