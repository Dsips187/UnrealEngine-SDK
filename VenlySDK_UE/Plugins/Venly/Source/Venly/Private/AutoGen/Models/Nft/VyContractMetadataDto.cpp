#include "AutoGen/Models/Nft/VyContractMetadataDto.h"

const TMap<FName, FName>& FVyContractMetadataDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	};
	
	return LUT;
}
