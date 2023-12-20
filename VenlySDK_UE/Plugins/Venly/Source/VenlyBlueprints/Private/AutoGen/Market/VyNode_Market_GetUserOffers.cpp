#include "AutoGen/Market/VyNode_Market_GetUserOffers.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOffers_Market.h"
UClass* UVyNode_Market_GetUserOffers::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOffers::GetResponseType() const
{
	return FVyGetUserOffersResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOffers::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOffers::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOffers);
}

FName UVyNode_Market_GetUserOffers::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOffers::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOffers::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
