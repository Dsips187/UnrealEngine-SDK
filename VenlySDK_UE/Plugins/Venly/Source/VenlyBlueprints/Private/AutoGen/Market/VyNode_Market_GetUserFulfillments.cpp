#include "AutoGen/Market/VyNode_Market_GetUserFulfillments.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserFulfillments_Market.h"
UClass* UVyNode_Market_GetUserFulfillments::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserFulfillments::GetResponseType() const
{
	return FVyGetUserFulfillmentsResponse::StaticStruct();
}

FName UVyNode_Market_GetUserFulfillments::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserFulfillments::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserFulfillments);
}

FName UVyNode_Market_GetUserFulfillments::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserFulfillments::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserFulfillments::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
