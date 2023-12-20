#include "AutoGen/FnModels/Wallet//VyGetWallets_Wallet.h"

const TMap<FName, FName>& FVyQuery_GetWallets::GetQueryLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
