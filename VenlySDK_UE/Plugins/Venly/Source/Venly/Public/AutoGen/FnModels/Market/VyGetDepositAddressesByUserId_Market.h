#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyDepositAddressDto.h"

#include "VyGetDepositAddressesByUserId_Market.generated.h"


//RESPONSE [DepositAddressDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetDepositAddressesByUserIdResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyDepositAddressDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetDepositAddressesByUserIdCompleteBP, FVyGetDepositAddressesByUserIdResponse, Result);
