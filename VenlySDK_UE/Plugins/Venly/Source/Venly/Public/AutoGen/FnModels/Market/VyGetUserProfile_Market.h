#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"

#include "VyGetUserProfile_Market.generated.h"


//RESPONSE [UserProfileDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetUserProfileResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyUserProfileDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserProfileCompleteBP, FVyGetUserProfileResponse, Result);
