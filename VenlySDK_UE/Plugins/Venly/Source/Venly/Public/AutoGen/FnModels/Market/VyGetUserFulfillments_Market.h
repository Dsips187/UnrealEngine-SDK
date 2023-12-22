#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Models/Market/VyFulfillmentDto.h"
#include "AutoGen/Optionals/VyOptFulfillmentState.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptFulfillmentType.h"

#include "VyGetUserFulfillments_Market.generated.h"


/*
* Optional query to filter the GetUserFulfillments endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetUserFulfillments : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Filter based on the sorting field*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Filter based on the sorting order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
	/**Filter based on the fulfillment type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptFulfillmentType Type;
	/**Filter based on the fulfillment status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptFulfillmentState Status;
	/**Filter based on whether the user is a buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool IsBuyer;
	/**Filter based on the external user ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUserId;
};

//RESPONSE [findById_merged]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetUserFulfillmentsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyFulfillmentDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserFulfillmentsCompleteBP, FVyGetUserFulfillmentsResponse, Result);
