#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptFulfillmentType.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptFulfillmentState.h"
#include "AutoGen/Models/Market/VyFulfillmentDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetFulfillments_Market.generated.h"


/*
* Optional query to filter the GetFulfillments endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetFulfillments : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Sort the results based on a specific field*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Sort the results in ascending or descending order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
	/**Filter based on a specific offer ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString OfferId;
	/**Filter based on a specific fulfillment ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Id;
	/**Filter based on a specific buyer ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString BuyerId;
	/**Filter based on the fulfillment status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptFulfillmentState Status;
	/**Filter based on the fulfillment type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptFulfillmentType Type;
};

//RESPONSE [findById_merged]
USTRUCT(BlueprintType)
struct FVyGetFulfillmentsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyFulfillmentDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetFulfillmentsCompleteBP, FVyGetFulfillmentsResponse, Result);
