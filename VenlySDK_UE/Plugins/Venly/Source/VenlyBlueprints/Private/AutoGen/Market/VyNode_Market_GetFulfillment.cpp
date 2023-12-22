#include "AutoGen/Market/VyNode_Market_GetFulfillment.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetFulfillment_Market.h"
UClass* UVyNode_Market_GetFulfillment::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetFulfillment::GetResponseType() const
{
	return FVyGetFulfillmentResponse::StaticStruct();
}

FName UVyNode_Market_GetFulfillment::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetFulfillment::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetFulfillment);
}

FName UVyNode_Market_GetFulfillment::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetFulfillment::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetFulfillment::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
