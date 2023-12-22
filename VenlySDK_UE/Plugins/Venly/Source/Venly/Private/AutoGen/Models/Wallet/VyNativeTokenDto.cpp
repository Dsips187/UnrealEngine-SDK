#include "AutoGen/Models/Wallet/VyNativeTokenDto.h"

const TMap<FName, FName>& FVyNativeTokenDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
