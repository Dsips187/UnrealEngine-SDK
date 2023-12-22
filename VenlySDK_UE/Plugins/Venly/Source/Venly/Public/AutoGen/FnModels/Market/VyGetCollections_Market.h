#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Models/Market/VyCollectionDto.h"
#include "AutoGen/Optionals/VyOptInt.h"

#include "VyGetCollections_Market.generated.h"


/*
* Optional query to filter the GetCollections endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetCollections : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on a specific ContractAddress*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ContractAddress;
	/**Filter based on a specific Chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain Chain;
	/**Filter based on the premium state*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Premium;
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Filter based on the sort field*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Filter based on the sort order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
};

//RESPONSE [NFTCollectionDto]
USTRUCT(BlueprintType)
struct FVyGetCollectionsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyCollectionDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCollectionsCompleteBP, FVyGetCollectionsResponse, Result);
