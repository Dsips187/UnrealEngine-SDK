#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyRoleInfoDto.h"

#include "VyGetRoles_Market.generated.h"


//RESPONSE [GrantedAuthority]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetRolesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyRoleInfoDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetRolesCompleteBP, FVyGetRolesResponse, Result);
