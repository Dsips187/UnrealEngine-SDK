#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyClientStatisticsDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetClientsStatistics_Wallet.generated.h"


/*
* Optional query to filter the GetClientsStatistics endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetClientsStatistics : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific client IDs*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Clients;
};

//RESPONSE [ClientsStatisticsDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetClientsStatisticsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyClientStatisticsDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetClientsStatisticsCompleteBP, FVyGetClientsStatisticsResponse, Result);
