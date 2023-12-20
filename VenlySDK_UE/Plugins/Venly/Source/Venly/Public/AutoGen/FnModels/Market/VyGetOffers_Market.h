#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VyOfferDto.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetOffers_Market.generated.h"


/*
* Optional query to filter the GetOffers endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetOffers : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Filter based on the sort field*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Filter based on the sort order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
	/**Filter based on the offer type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Type;
	/**Filter based on the offer status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Status;
	/**Filter based on the offer ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Id;
	/**Filter based on the seller ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SellerId;
	/**Filter based on a specific Chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain Chain;
	/**Filter based on the contract address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ContractAddress;
	/**Filter based on whether to show upcoming offers*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool ShowUpcomingOffers;
};

//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyGetOffersResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyOfferDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetOffersCompleteBP, FVyGetOffersResponse, Result);
