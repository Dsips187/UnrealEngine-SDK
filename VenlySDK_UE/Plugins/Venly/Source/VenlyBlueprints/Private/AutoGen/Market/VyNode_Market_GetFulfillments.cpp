#include "AutoGen/Market/VyNode_Market_GetFulfillments.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetFulfillments_Market.h"
UClass* UVyNode_Market_GetFulfillments::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetFulfillments::GetResponseType() const
{
	return FVyGetFulfillmentsResponse::StaticStruct();
}

FName UVyNode_Market_GetFulfillments::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetFulfillments::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetFulfillments);
}

FName UVyNode_Market_GetFulfillments::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetFulfillments::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetFulfillments::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
