#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyOptWalletType.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptWalletTypeBPL.MakeOptional", VyOptionalType = "EVyWalletType"))
struct VENLY_API FVyOptWalletType : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	EVyWalletType Val;

	FVyOptWalletType();

	explicit FVyOptWalletType(EVyWalletType Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};