#include "AutoGen/Market/VyNode_Market_CheckPayment.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "Models/VyCoreModels.h"
UClass* UVyNode_Market_CheckPayment::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CheckPayment::GetResponseType() const
{
	return FVyApiUnitResponse::StaticStruct();
}

FName UVyNode_Market_CheckPayment::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CheckPayment::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CheckPayment);
}

FName UVyNode_Market_CheckPayment::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CheckPayment::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CheckPayment::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
