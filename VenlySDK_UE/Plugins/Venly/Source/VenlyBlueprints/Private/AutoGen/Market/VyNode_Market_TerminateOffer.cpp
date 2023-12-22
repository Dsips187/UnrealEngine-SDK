#include "AutoGen/Market/VyNode_Market_TerminateOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyTerminateOffer_Market.h"
UClass* UVyNode_Market_TerminateOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_TerminateOffer::GetResponseType() const
{
	return FVyTerminateOfferResponse::StaticStruct();
}

FName UVyNode_Market_TerminateOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_TerminateOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, TerminateOffer);
}

FName UVyNode_Market_TerminateOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_TerminateOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_TerminateOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
