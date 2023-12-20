#include "AutoGen/Market/VyNode_Market_GetUserOrdersByUserId.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOrdersByUserId_Market.h"
UClass* UVyNode_Market_GetUserOrdersByUserId::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOrdersByUserId::GetResponseType() const
{
	return FVyGetUserOrdersByUserIdResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOrdersByUserId::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOrdersByUserId::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOrdersByUserId);
}

FName UVyNode_Market_GetUserOrdersByUserId::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOrdersByUserId::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOrdersByUserId::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
