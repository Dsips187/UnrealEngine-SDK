#include "AutoGen/Market/VyNode_Market_CreateAuctionOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCreateAuctionOffer_Market.h"
UClass* UVyNode_Market_CreateAuctionOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CreateAuctionOffer::GetResponseType() const
{
	return FVyCreateAuctionOfferResponse::StaticStruct();
}

FName UVyNode_Market_CreateAuctionOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CreateAuctionOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CreateAuctionOffer);
}

FName UVyNode_Market_CreateAuctionOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CreateAuctionOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CreateAuctionOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
