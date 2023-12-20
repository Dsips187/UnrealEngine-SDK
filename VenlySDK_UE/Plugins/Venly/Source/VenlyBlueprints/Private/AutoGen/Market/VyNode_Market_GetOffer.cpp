#include "AutoGen/Market/VyNode_Market_GetOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetOffer_Market.h"
UClass* UVyNode_Market_GetOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetOffer::GetResponseType() const
{
	return FVyGetOfferResponse::StaticStruct();
}

FName UVyNode_Market_GetOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetOffer);
}

FName UVyNode_Market_GetOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
