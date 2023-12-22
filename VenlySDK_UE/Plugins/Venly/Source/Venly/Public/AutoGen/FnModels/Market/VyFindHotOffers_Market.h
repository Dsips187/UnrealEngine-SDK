#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Models/Market/VyHotOfferDto.h"

#include "VyFindHotOffers_Market.generated.h"


/*
* Optional query to filter the FindHotOffers endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_FindHotOffers : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Sort the results based on a specific field*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Specify the sort order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
};

//RESPONSE [findHotOffers_object0]
USTRUCT(BlueprintType)
struct FVyFindHotOffersResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyHotOfferDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnFindHotOffersCompleteBP, FVyFindHotOffersResponse, Result);
