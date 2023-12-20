#include "AutoGen/Market/VyNode_Market_CreateSaleOffer.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCreateSaleOffer_Market.h"
UClass* UVyNode_Market_CreateSaleOffer::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CreateSaleOffer::GetResponseType() const
{
	return FVyCreateSaleOfferResponse::StaticStruct();
}

FName UVyNode_Market_CreateSaleOffer::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CreateSaleOffer::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CreateSaleOffer);
}

FName UVyNode_Market_CreateSaleOffer::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CreateSaleOffer::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CreateSaleOffer::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
