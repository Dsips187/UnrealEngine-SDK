#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyWalletEventDto.h"

#include "VyGetWalletEvents_Wallet.generated.h"


//RESPONSE [ApplicationEventResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetWalletEventsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyWalletEventDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetWalletEventsCompleteBP, FVyGetWalletEventsResponse, Result);
