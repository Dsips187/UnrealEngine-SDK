#include "AutoGen/Market/VyNode_Market_BidOnOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyBidOnOffer_Market.h"
UClass* UVyNode_Market_BidOnOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_BidOnOffer::GetResponseType() const
{
	return FVyBidOnOfferResponse::StaticStruct();
}

FName UVyNode_Market_BidOnOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_BidOnOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, BidOnOffer);
}

FName UVyNode_Market_BidOnOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_BidOnOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_BidOnOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
