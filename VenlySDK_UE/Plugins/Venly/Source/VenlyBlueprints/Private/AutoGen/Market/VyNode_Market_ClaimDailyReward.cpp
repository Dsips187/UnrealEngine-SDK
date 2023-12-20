#include "AutoGen/Market/VyNode_Market_ClaimDailyReward.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "Models/VyCoreModels.h"
UClass* UVyNode_Market_ClaimDailyReward::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_ClaimDailyReward::GetResponseType() const
{
	return FVyApiUnitResponse::StaticStruct();
}

FName UVyNode_Market_ClaimDailyReward::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_ClaimDailyReward::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, ClaimDailyReward);
}

FName UVyNode_Market_ClaimDailyReward::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_ClaimDailyReward::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_ClaimDailyReward::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
