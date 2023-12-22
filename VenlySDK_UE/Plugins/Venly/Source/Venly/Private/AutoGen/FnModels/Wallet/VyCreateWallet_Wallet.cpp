#include "AutoGen/FnModels/Wallet//VyCreateWallet_Wallet.h"

const TMap<FName, FName>& FVyCreateWalletRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
