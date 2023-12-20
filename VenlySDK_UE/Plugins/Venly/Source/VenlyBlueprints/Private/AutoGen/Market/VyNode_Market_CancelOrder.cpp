#include "AutoGen/Market/VyNode_Market_CancelOrder.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "Models/VyCoreModels.h"
UClass* UVyNode_Market_CancelOrder::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CancelOrder::GetResponseType() const
{
	return FVyApiUnitResponse::StaticStruct();
}

FName UVyNode_Market_CancelOrder::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CancelOrder::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CancelOrder);
}

FName UVyNode_Market_CancelOrder::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CancelOrder::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CancelOrder::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
