#include "AutoGen/FnModels/Nft//VyUpdateTokenTypeMetadata_Nft.h"

const TMap<FName, FName>& FVyUpdateTokenTypeMetadataRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	};
	
	return LUT;
}
