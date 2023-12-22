#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Nft/VySortDto.h"
#include "VyPageableObjectDto.generated.h"

/*
* A pageable object
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyPageableObjectDto : public FVyDTO
{
	GENERATED_BODY()
	/**The offset of the pageable object*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Offset;
	/**The sorting criteria for the pageable object*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVySortDto Sort;
	/**Flag indicating if the object is unpaged*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Unpaged;
	/**Flag indicating if the object is paged*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Paged;
	/**The page number of the pageable object*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int PageNumber;
	/**The page size of the pageable object*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int PageSize;
};


UCLASS(BlueprintType)
class VENLY_API UVyPageableObjectDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyPageableObjectDtoRef* ToObject(const FVyPageableObjectDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyPageableObjectDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyPageableObjectDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyPageableObjectDto Data{};
};