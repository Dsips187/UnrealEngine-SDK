#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetUsers_Market.generated.h"


/*
* Optional query to filter the GetUsers endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetUsers : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on a specific array of user IDs*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Id;
};

//RESPONSE [UserProfileDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetUsersResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyUserProfileDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUsersCompleteBP, FVyGetUsersResponse, Result);
