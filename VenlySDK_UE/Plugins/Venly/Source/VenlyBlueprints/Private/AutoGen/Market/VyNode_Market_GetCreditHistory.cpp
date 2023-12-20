#include "AutoGen/Market/VyNode_Market_GetCreditHistory.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetCreditHistory_Market.h"
UClass* UVyNode_Market_GetCreditHistory::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetCreditHistory::GetResponseType() const
{
	return FVyGetCreditHistoryResponse::StaticStruct();
}

FName UVyNode_Market_GetCreditHistory::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetCreditHistory::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetCreditHistory);
}

FName UVyNode_Market_GetCreditHistory::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetCreditHistory::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetCreditHistory::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
