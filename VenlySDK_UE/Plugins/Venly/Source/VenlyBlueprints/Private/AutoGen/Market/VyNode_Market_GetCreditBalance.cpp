#include "AutoGen/Market/VyNode_Market_GetCreditBalance.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetCreditBalance_Market.h"
UClass* UVyNode_Market_GetCreditBalance::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetCreditBalance::GetResponseType() const
{
	return FVyGetCreditBalanceResponse::StaticStruct();
}

FName UVyNode_Market_GetCreditBalance::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetCreditBalance::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetCreditBalance);
}

FName UVyNode_Market_GetCreditBalance::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetCreditBalance::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetCreditBalance::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
