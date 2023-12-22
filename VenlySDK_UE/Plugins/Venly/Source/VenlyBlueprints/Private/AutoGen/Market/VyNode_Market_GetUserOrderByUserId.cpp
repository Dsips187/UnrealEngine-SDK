#include "AutoGen/Market/VyNode_Market_GetUserOrderByUserId.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOrderByUserId_Market.h"
UClass* UVyNode_Market_GetUserOrderByUserId::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOrderByUserId::GetResponseType() const
{
	return FVyGetUserOrderByUserIdResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOrderByUserId::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOrderByUserId::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOrderByUserId);
}

FName UVyNode_Market_GetUserOrderByUserId::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOrderByUserId::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOrderByUserId::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
