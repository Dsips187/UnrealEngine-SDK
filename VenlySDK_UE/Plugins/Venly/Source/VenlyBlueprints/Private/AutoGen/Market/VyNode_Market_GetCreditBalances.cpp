#include "AutoGen/Market/VyNode_Market_GetCreditBalances.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetCreditBalances_Market.h"
UClass* UVyNode_Market_GetCreditBalances::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetCreditBalances::GetResponseType() const
{
	return FVyGetCreditBalancesResponse::StaticStruct();
}

FName UVyNode_Market_GetCreditBalances::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetCreditBalances::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetCreditBalances);
}

FName UVyNode_Market_GetCreditBalances::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetCreditBalances::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetCreditBalances::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
