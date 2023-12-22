#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"

#include "VyOptBool.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptBoolBPL.MakeOptional", VyOptionalType = "bool"))
struct VENLY_API FVyOptBool : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	bool Val;

	FVyOptBool();

	explicit FVyOptBool(bool Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};