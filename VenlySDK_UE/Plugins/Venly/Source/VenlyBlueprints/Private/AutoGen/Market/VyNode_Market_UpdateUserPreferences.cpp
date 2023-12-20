#include "AutoGen/Market/VyNode_Market_UpdateUserPreferences.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyUpdateUserPreferences_Market.h"
UClass* UVyNode_Market_UpdateUserPreferences::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_UpdateUserPreferences::GetResponseType() const
{
	return FVyUpdateUserPreferencesResponse::StaticStruct();
}

FName UVyNode_Market_UpdateUserPreferences::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_UpdateUserPreferences::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, UpdateUserPreferences);
}

FName UVyNode_Market_UpdateUserPreferences::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_UpdateUserPreferences::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_UpdateUserPreferences::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
