#include "AutoGen/Market/VyNode_Market_GetSupportedMarketChains.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetSupportedMarketChains_Market.h"
UClass* UVyNode_Market_GetSupportedMarketChains::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetSupportedMarketChains::GetResponseType() const
{
	return FVyGetSupportedMarketChainsResponse::StaticStruct();
}

FName UVyNode_Market_GetSupportedMarketChains::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetSupportedMarketChains::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetSupportedMarketChains);
}

FName UVyNode_Market_GetSupportedMarketChains::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetSupportedMarketChains::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetSupportedMarketChains::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
