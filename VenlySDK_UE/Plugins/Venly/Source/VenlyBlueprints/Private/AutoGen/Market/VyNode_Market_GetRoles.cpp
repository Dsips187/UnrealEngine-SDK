#include "AutoGen/Market/VyNode_Market_GetRoles.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetRoles_Market.h"
UClass* UVyNode_Market_GetRoles::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetRoles::GetResponseType() const
{
	return FVyGetRolesResponse::StaticStruct();
}

FName UVyNode_Market_GetRoles::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetRoles::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetRoles);
}

FName UVyNode_Market_GetRoles::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetRoles::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetRoles::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
