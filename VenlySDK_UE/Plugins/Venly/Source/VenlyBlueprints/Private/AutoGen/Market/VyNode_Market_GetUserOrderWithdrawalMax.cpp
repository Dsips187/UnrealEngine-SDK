#include "AutoGen/Market/VyNode_Market_GetUserOrderWithdrawalMax.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetUserOrderWithdrawalMax_Market.h"
UClass* UVyNode_Market_GetUserOrderWithdrawalMax::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetUserOrderWithdrawalMax::GetResponseType() const
{
	return FVyGetUserOrderWithdrawalMaxResponse::StaticStruct();
}

FName UVyNode_Market_GetUserOrderWithdrawalMax::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetUserOrderWithdrawalMax::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetUserOrderWithdrawalMax);
}

FName UVyNode_Market_GetUserOrderWithdrawalMax::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetUserOrderWithdrawalMax::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetUserOrderWithdrawalMax::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
