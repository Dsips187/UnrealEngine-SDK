#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Models/Market/VyCreditHistoryDto.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"

#include "VyGetCreditHistory_Market.generated.h"


/*
* Optional query to filter the GetCreditHistory endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetCreditHistory : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Filter based on the field to sort on*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Filter based on the sort order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
	/**Filter based on a specific keyword*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Keyword;
	/**Filter based on a specific reference ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ReferenceId;
};

//RESPONSE [getCreditHistory_object0]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetCreditHistoryResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyCreditHistoryDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCreditHistoryCompleteBP, FVyGetCreditHistoryResponse, Result);
