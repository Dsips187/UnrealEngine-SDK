#include "AutoGen/Models/Wallet/VyWalletMultiTokensDto.h"

const TMap<FName, FName>& FVyWalletMultiTokensDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
