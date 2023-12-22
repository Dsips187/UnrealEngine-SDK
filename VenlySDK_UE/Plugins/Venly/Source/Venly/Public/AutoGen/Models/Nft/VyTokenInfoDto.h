#pragma once
#include "Models/VyCoreModels.h"

#include "VyTokenInfoDto.generated.h"

/*
* Data structure representing token information
*/
USTRUCT(BlueprintType)
struct FVyTokenInfoDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Id;
	/**The type identifier of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TypeId;
	/**The metadata associated with the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Metadata;
	/**The date when the token was mined*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString MineDate;
	/**Indicates if the token is confirmed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Confirmed;
	/**The amount of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The hash of the transaction associated with the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
};


UCLASS(BlueprintType)
class UVyTokenInfoDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTokenInfoDtoRef* ToObject(const FVyTokenInfoDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTokenInfoDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTokenInfoDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTokenInfoDto Data{};
};