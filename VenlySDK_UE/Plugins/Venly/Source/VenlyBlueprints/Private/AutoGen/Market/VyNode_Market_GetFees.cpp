#include "AutoGen/Market/VyNode_Market_GetFees.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetFees_Market.h"
UClass* UVyNode_Market_GetFees::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetFees::GetResponseType() const
{
	return FVyGetFeesResponse::StaticStruct();
}

FName UVyNode_Market_GetFees::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetFees::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetFees);
}

FName UVyNode_Market_GetFees::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetFees::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetFees::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
