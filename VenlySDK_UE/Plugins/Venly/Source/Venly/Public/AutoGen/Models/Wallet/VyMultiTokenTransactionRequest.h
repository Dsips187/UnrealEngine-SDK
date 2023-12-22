#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptNetwork.h"
#include "VyMultiTokenTransactionRequest.generated.h"

/*
* Request parameters for a multi-token transaction
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyMultiTokenTransactionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The recipient address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ToAddress;
	/**The preferred blockchain for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The network to use for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptNetwork Network;
	/**Chain-specific fields for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ChainSpecificFields;
	/**The address of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TokenAddress;
	/**The sender address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString FromAddress;
	/**The amount of tokens to transfer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The ID of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TokenId;
	/**(read-only) The transaction type, should be "NFT_TRANSFER"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("NFT_TRANSFER")};
	
	virtual ~FVyMultiTokenTransactionRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyMultiTokenTransactionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMultiTokenTransactionRequestRef* ToObject(const FVyMultiTokenTransactionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMultiTokenTransactionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMultiTokenTransactionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMultiTokenTransactionRequest Data{};
};