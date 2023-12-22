#include "AutoGen/Market/VyNode_Market_GetUserOrder.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOrder_Market.h"
UClass* UVyNode_Market_GetUserOrder::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOrder::GetResponseType() const
{
	return FVyGetUserOrderResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOrder::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOrder::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOrder);
}

FName UVyNode_Market_GetUserOrder::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOrder::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOrder::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
