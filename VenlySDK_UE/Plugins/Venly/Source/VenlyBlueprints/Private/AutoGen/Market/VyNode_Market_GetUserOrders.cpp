#include "AutoGen/Market/VyNode_Market_GetUserOrders.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOrders_Market.h"
UClass* UVyNode_Market_GetUserOrders::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOrders::GetResponseType() const
{
	return FVyGetUserOrdersResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOrders::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOrders::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOrders);
}

FName UVyNode_Market_GetUserOrders::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOrders::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOrders::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
