#include "AutoGen/FnModels/Wallet//VyGetAllMultiTokenBalances_Wallet.h"

const TMap<FName, FName>& FVyQuery_GetAllMultiTokenBalances::GetQueryLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
