#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptNetwork.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "VyNativeTokenTransactionRequest.generated.h"

/*
* Request parameters for a native token transaction
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyNativeTokenTransactionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The recipient's address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ToAddress;
	/**The preferred blockchain for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The network to use for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptNetwork Network;
	/**Chain-specific fields for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ChainSpecificFields;
	/**Additional data for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Data;
	/**The value to transfer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Value;
	/**(read-only) The transaction type, should be "TRANSFER"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("TRANSFER")};
	
	virtual ~FVyNativeTokenTransactionRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyNativeTokenTransactionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNativeTokenTransactionRequestRef* ToObject(const FVyNativeTokenTransactionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNativeTokenTransactionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNativeTokenTransactionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNativeTokenTransactionRequest Data{};
};