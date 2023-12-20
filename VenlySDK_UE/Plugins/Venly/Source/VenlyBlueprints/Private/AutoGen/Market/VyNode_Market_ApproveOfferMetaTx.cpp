#include "AutoGen/Market/VyNode_Market_ApproveOfferMetaTx.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyApproveOfferMetaTx_Market.h"
UClass* UVyNode_Market_ApproveOfferMetaTx::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_ApproveOfferMetaTx::GetResponseType() const
{
	return FVyApproveOfferMetaTxResponse::StaticStruct();
}

FName UVyNode_Market_ApproveOfferMetaTx::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_ApproveOfferMetaTx::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, ApproveOfferMetaTx);
}

FName UVyNode_Market_ApproveOfferMetaTx::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_ApproveOfferMetaTx::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_ApproveOfferMetaTx::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
