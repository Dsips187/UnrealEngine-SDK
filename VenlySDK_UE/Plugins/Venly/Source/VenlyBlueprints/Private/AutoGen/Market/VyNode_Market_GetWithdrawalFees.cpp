#include "AutoGen/Market/VyNode_Market_GetWithdrawalFees.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetWithdrawalFees_Market.h"
UClass* UVyNode_Market_GetWithdrawalFees::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetWithdrawalFees::GetResponseType() const
{
	return FVyGetWithdrawalFeesResponse::StaticStruct();
}

FName UVyNode_Market_GetWithdrawalFees::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetWithdrawalFees::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetWithdrawalFees);
}

FName UVyNode_Market_GetWithdrawalFees::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetWithdrawalFees::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetWithdrawalFees::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
