#include "AutoGen/Market/VyNode_Market_CreateSubUser.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCreateSubUser_Market.h"
UClass* UVyNode_Market_CreateSubUser::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CreateSubUser::GetResponseType() const
{
	return FVyCreateSubUserResponse::StaticStruct();
}

FName UVyNode_Market_CreateSubUser::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CreateSubUser::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CreateSubUser);
}

FName UVyNode_Market_CreateSubUser::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CreateSubUser::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CreateSubUser::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
