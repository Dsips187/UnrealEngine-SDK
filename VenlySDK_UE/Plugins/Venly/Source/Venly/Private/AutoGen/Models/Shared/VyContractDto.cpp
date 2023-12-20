#include "AutoGen/Models/Shared/VyContractDto.h"

const TMap<FName, FName>& FVyContractDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	{TEXT("ImageUrl"), TEXT("image")},
	};
	
	return LUT;
}
