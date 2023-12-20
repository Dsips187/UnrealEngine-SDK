#include "AutoGen/Market/VyNode_Market_UpdateOrder.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyUpdateOrder_Market.h"
UClass* UVyNode_Market_UpdateOrder::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_UpdateOrder::GetResponseType() const
{
	return FVyUpdateOrderResponse::StaticStruct();
}

FName UVyNode_Market_UpdateOrder::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_UpdateOrder::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, UpdateOrder);
}

FName UVyNode_Market_UpdateOrder::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_UpdateOrder::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_UpdateOrder::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
