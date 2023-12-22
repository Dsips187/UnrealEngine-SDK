#pragma once
#include "Models/VyCoreModels.h"

#include "VyCryptoTokenDto.generated.h"

/*
* Data transfer object for a crypto token
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCryptoTokenDto : public FVyDTO
{
	GENERATED_BODY()
	/**The address of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TokenAddress;
	/**The raw balance of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString RawBalance;
	/**The balance of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Balance;
	/**The number of decimal places for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Decimals;
	/**The symbol of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The logo of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Logo;
	/**The type of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
	/**Indicates if the token is transferable*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Transferable;
	/**The name of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
};


UCLASS(BlueprintType)
class VENLY_API UVyCryptoTokenDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCryptoTokenDtoRef* ToObject(const FVyCryptoTokenDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCryptoTokenDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCryptoTokenDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCryptoTokenDto Data{};
};