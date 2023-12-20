#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VyOfferDto.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptRelationType.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetUserOffersByUserId_Market.generated.h"


/*
* Optional query to filter the GetUserOffersByUserId endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetUserOffersByUserId : public FVyQuery
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
	/**Filter based on the offer types*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Type;
	/**Filter based on the offer statuses*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Status;
	/**Filter based on the external user ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUserId;
	/**Filter based on the buyer status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool IsBuyer;
	/**Filter based on the relation type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptRelationType Relation;
};

//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyGetUserOffersByUserIdResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyOfferDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserOffersByUserIdCompleteBP, FVyGetUserOffersByUserIdResponse, Result);
