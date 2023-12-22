#include "AutoGen/Market/VyNode_Market_PrepareOfferTransaction.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyPrepareOfferTransaction_Market.h"
UClass* UVyNode_Market_PrepareOfferTransaction::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_PrepareOfferTransaction::GetResponseType() const
{
	return FVyPrepareOfferTransactionResponse::StaticStruct();
}

FName UVyNode_Market_PrepareOfferTransaction::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_PrepareOfferTransaction::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, PrepareOfferTransaction);
}

FName UVyNode_Market_PrepareOfferTransaction::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_PrepareOfferTransaction::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_PrepareOfferTransaction::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
