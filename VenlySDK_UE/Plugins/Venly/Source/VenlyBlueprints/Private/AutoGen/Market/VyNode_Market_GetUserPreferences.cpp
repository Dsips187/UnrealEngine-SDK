#include "AutoGen/Market/VyNode_Market_GetUserPreferences.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserPreferences_Market.h"
UClass* UVyNode_Market_GetUserPreferences::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserPreferences::GetResponseType() const
{
	return FVyGetUserPreferencesResponse::StaticStruct();
}

FName UVyNode_Market_GetUserPreferences::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserPreferences::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserPreferences);
}

FName UVyNode_Market_GetUserPreferences::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserPreferences::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserPreferences::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
