#include "AutoGen/Market/VyNode_Market_ApproveOfferTx.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyApproveOfferTx_Market.h"
UClass* UVyNode_Market_ApproveOfferTx::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_ApproveOfferTx::GetResponseType() const
{
	return FVyApproveOfferTxResponse::StaticStruct();
}

FName UVyNode_Market_ApproveOfferTx::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_ApproveOfferTx::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, ApproveOfferTx);
}

FName UVyNode_Market_ApproveOfferTx::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_ApproveOfferTx::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_ApproveOfferTx::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
