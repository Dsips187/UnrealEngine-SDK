#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserPreferencesDto.h"

#include "VyGetUserPreferences_Market.generated.h"


//RESPONSE [UserPreferencesDto]
USTRUCT(BlueprintType)
struct FVyGetUserPreferencesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyUserPreferencesDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserPreferencesCompleteBP, FVyGetUserPreferencesResponse, Result);
