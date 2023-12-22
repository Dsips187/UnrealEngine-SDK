#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"

#include "VyOptInt.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptIntBPL.MakeOptional", VyOptionalType = "int"))
struct VENLY_API FVyOptInt : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	int Val;

	FVyOptInt();

	explicit FVyOptInt(int Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};