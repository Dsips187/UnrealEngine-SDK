#include "AutoGen/Market/VyNode_Market_CancelOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCancelOffer_Market.h"
UClass* UVyNode_Market_CancelOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CancelOffer::GetResponseType() const
{
	return FVyCancelOfferResponse::StaticStruct();
}

FName UVyNode_Market_CancelOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CancelOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CancelOffer);
}

FName UVyNode_Market_CancelOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CancelOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CancelOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
