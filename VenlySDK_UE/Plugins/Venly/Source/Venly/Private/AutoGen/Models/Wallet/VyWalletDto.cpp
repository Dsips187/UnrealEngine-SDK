#include "AutoGen/Models/Wallet/VyWalletDto.h"

const TMap<FName, FName>& FVyWalletDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	{TEXT("IsPrimary"), TEXT("primary")},
	};
	
	return LUT;
}
