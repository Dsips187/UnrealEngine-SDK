#include "AutoGen/Models/Wallet/VyTradingPairDetailsDto.h"

const TMap<FName, FName>& FVyTradingPairDetailsDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
