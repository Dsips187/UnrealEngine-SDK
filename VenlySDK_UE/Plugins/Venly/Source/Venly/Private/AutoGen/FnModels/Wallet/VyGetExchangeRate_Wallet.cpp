#include "AutoGen/FnModels/Wallet//VyGetExchangeRate_Wallet.h"

const TMap<FName, FName>& FVyQuery_GetExchangeRate::GetQueryLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("FromChain"), TEXT("fromSecretType")},
	{TEXT("ToChain"), TEXT("toSecretType")},
	};
	
	return LUT;
}
