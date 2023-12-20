#include "AutoGen/Models/Nft/VyTokenDto.h"

const TMap<FName, FName>& FVyTokenDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
