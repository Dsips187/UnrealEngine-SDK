#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptNetwork.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "VyGasTransactionRequest.generated.h"

/*
* Request parameters for a gas transaction
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyGasTransactionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The address to send the transaction to*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ToAddress;
	/**The preferred blockchain for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The network to use for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptNetwork Network;
	/**Chain-specific fields for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ChainSpecificFields;
	/**The value of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Value;
	/**(read-only) The type of the transaction, should be "GAS_TRANSFER"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("GAS_TRANSFER")};
	
	virtual ~FVyGasTransactionRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyGasTransactionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyGasTransactionRequestRef* ToObject(const FVyGasTransactionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyGasTransactionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyGasTransactionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyGasTransactionRequest Data{};
};