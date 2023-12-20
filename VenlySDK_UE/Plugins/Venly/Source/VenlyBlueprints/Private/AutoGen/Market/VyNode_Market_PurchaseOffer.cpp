#include "AutoGen/Market/VyNode_Market_PurchaseOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyPurchaseOffer_Market.h"
UClass* UVyNode_Market_PurchaseOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_PurchaseOffer::GetResponseType() const
{
	return FVyPurchaseOfferResponse::StaticStruct();
}

FName UVyNode_Market_PurchaseOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_PurchaseOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, PurchaseOffer);
}

FName UVyNode_Market_PurchaseOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_PurchaseOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_PurchaseOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
