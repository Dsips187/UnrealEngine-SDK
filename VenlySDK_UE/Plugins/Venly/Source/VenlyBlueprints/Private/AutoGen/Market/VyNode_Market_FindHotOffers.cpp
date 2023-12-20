#include "AutoGen/Market/VyNode_Market_FindHotOffers.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyFindHotOffers_Market.h"
UClass* UVyNode_Market_FindHotOffers::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_FindHotOffers::GetResponseType() const
{
	return FVyFindHotOffersResponse::StaticStruct();
}

FName UVyNode_Market_FindHotOffers::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_FindHotOffers::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, FindHotOffers);
}

FName UVyNode_Market_FindHotOffers::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_FindHotOffers::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_FindHotOffers::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
