#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyTransactionInfoDto.h"

#include "VyGetTransactionInfo_Wallet.generated.h"


/*
* Optional query to filter the GetTransactionInfo endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetTransactionInfo : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on a specific Endpoint*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Endpoint;
};

//RESPONSE [TxInfo]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetTransactionInfoResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionInfoDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTransactionInfoCompleteBP, FVyGetTransactionInfoResponse, Result);
