#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyDepositAddressDto.h"

#include "VyCreateDepositAddress_Market.generated.h"


//REQUEST [createDepositAddress]
//'FVyCreateDepositAddressRequest' already exists in 'AutoGen/FnModels/Market/VyCreateDepositAddressForUserId_Market.h'

//RESPONSE [DepositAddressDto]
USTRUCT(BlueprintType)
struct FVyCreateDepositAddressResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyDepositAddressDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateDepositAddressCompleteBP, FVyCreateDepositAddressResponse, Result);
