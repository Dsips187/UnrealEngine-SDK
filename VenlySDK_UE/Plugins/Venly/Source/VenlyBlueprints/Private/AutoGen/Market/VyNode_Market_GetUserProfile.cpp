#include "AutoGen/Market/VyNode_Market_GetUserProfile.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserProfile_Market.h"
UClass* UVyNode_Market_GetUserProfile::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserProfile::GetResponseType() const
{
	return FVyGetUserProfileResponse::StaticStruct();
}

FName UVyNode_Market_GetUserProfile::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserProfile::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserProfile);
}

FName UVyNode_Market_GetUserProfile::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserProfile::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserProfile::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
