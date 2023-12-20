#include "AutoGen/Models/Nft/VyTokenTypeMetadataDto.h"

const TMap<FName, FName>& FVyTokenTypeMetadataDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	{TEXT("ImageThumbnailUrl"), TEXT("imageThumbnail")},
	{TEXT("ImagePreviewUrl"), TEXT("imagePreview")},
	};
	
	return LUT;
}
