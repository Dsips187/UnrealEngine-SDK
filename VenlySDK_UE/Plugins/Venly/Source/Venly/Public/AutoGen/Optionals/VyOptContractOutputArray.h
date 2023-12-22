#pragma once

#include "CoreMinimal.h"
#include "Misc/VyOptional.h"
#include "AutoGen/Models/Wallet/VyContractOutputDto.h"

#include "VyOptContractOutputArray.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX.
USTRUCT(BlueprintType, meta = (HasNativeMake = "Venly.VyOptContractOutputArrayBPL.MakeOptional", VyOptionalType = "TArray<FVyContractOutputDto>"))
struct VENLY_API FVyOptContractOutputArray : public FVyOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	TArray<FVyContractOutputDto> Val;

	FVyOptContractOutputArray();

	explicit FVyOptContractOutputArray(TArray<FVyContractOutputDto> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;

	virtual TSharedPtr<FJsonValue> GetJsonValue() const  override;
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) override;
};