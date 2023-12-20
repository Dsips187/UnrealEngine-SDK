#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyEip712RequestDto.h"
#include "VySignMessageRequestEip712RequestDto.generated.h"

/*
* Request parameters to sign a message using EIP712
*/
USTRUCT(BlueprintType)
struct FVySignMessageRequestEip712RequestDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The blockchain chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Chain;
	/**The EIP712 request data*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyEip712RequestDto Data;
	
	virtual ~FVySignMessageRequestEip712RequestDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVySignMessageRequestEip712RequestDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySignMessageRequestEip712RequestDtoRef* ToObject(const FVySignMessageRequestEip712RequestDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySignMessageRequestEip712RequestDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySignMessageRequestEip712RequestDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySignMessageRequestEip712RequestDto Data{};
};