#include "AutoGen/FnModels/Nft//VyUpdateContractMetadata_Nft.h"

const TMap<FName, FName>& FVyUpdateContractMetadataRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	};
	
	return LUT;
}
