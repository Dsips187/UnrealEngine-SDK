#include "AutoGen/Market/VyNode_Market_GetDepositAddressesByUserId.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetDepositAddressesByUserId_Market.h"
UClass* UVyNode_Market_GetDepositAddressesByUserId::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetDepositAddressesByUserId::GetResponseType() const
{
	return FVyGetDepositAddressesByUserIdResponse::StaticStruct();
}

FName UVyNode_Market_GetDepositAddressesByUserId::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetDepositAddressesByUserId::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetDepositAddressesByUserId);
}

FName UVyNode_Market_GetDepositAddressesByUserId::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetDepositAddressesByUserId::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetDepositAddressesByUserId::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
