#include "AutoGen/Market/VyNode_Market_GetOffers.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetOffers_Market.h"
UClass* UVyNode_Market_GetOffers::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetOffers::GetResponseType() const
{
	return FVyGetOffersResponse::StaticStruct();
}

FName UVyNode_Market_GetOffers::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetOffers::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetOffers);
}

FName UVyNode_Market_GetOffers::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetOffers::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetOffers::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
