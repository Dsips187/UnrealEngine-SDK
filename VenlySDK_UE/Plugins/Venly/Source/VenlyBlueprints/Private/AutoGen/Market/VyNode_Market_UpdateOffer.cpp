#include "AutoGen/Market/VyNode_Market_UpdateOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyUpdateOffer_Market.h"
UClass* UVyNode_Market_UpdateOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_UpdateOffer::GetResponseType() const
{
	return FVyUpdateOfferResponse::StaticStruct();
}

FName UVyNode_Market_UpdateOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_UpdateOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, UpdateOffer);
}

FName UVyNode_Market_UpdateOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_UpdateOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_UpdateOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
