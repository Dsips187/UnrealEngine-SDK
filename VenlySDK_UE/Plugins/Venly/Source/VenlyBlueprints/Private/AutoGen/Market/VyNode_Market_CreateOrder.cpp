#include "AutoGen/Market/VyNode_Market_CreateOrder.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCreateOrder_Market.h"
UClass* UVyNode_Market_CreateOrder::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CreateOrder::GetResponseType() const
{
	return FVyCreateOrderResponse::StaticStruct();
}

FName UVyNode_Market_CreateOrder::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CreateOrder::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CreateOrder);
}

FName UVyNode_Market_CreateOrder::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CreateOrder::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CreateOrder::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
