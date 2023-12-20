#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptNetwork.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "VyCryptoTokenTransactionRequest.generated.h"

/*
* Request parameters for a crypto token transaction
*/
USTRUCT(BlueprintType)
struct FVyCryptoTokenTransactionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The address to send the tokens to*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ToAddress;
	/**The preferred blockchain for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The network to use for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptNetwork Network;
	/**Chain-specific fields for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ChainSpecificFields;
	/**The address of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString TokenAddress;
	/**The value of the tokens to send*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Value;
	/**The ID of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt TokenId;
	/**(read-only) The type of the transaction, should be "TOKEN_TRANSFER"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("TOKEN_TRANSFER")};
	
	virtual ~FVyCryptoTokenTransactionRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyCryptoTokenTransactionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCryptoTokenTransactionRequestRef* ToObject(const FVyCryptoTokenTransactionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCryptoTokenTransactionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCryptoTokenTransactionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCryptoTokenTransactionRequest Data{};
};