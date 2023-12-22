#include "AutoGen/Market/VyNode_Market_GetUserOffersByUserId.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOffersByUserId_Market.h"
UClass* UVyNode_Market_GetUserOffersByUserId::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOffersByUserId::GetResponseType() const
{
	return FVyGetUserOffersByUserIdResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOffersByUserId::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOffersByUserId::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOffersByUserId);
}

FName UVyNode_Market_GetUserOffersByUserId::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOffersByUserId::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOffersByUserId::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
