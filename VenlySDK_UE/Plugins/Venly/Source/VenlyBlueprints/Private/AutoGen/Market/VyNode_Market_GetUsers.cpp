#include "AutoGen/Market/VyNode_Market_GetUsers.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUsers_Market.h"
UClass* UVyNode_Market_GetUsers::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUsers::GetResponseType() const
{
	return FVyGetUsersResponse::StaticStruct();
}

FName UVyNode_Market_GetUsers::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUsers::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUsers);
}

FName UVyNode_Market_GetUsers::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUsers::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUsers::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
