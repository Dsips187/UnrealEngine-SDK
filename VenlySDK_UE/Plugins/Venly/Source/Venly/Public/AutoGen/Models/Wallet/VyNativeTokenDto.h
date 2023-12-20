#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyNativeTokenDto.generated.h"

/*
* Data transfer object for native blockchain tokens
*/
USTRUCT(BlueprintType)
struct FVyNativeTokenDto : public FVyDTO
{
	GENERATED_BODY()
	/**Indicates if the token is available*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Available;
	/**The blockchain chain of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The token balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Balance;
	/**The gas balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double GasBalance;
	/**The token symbol*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The gas symbol*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString GasSymbol;
	/**The raw token balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString RawBalance;
	/**The raw gas balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString RawGasBalance;
	/**The number of decimals for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Decimals;
	
	virtual ~FVyNativeTokenDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyNativeTokenDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNativeTokenDtoRef* ToObject(const FVyNativeTokenDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNativeTokenDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNativeTokenDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNativeTokenDto Data{};
};