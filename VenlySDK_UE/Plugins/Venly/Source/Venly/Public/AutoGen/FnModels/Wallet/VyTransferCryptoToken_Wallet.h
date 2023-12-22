#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"
#include "AutoGen/Models/Wallet/VyCryptoTokenTransactionRequest.h"

#include "VyTransferCryptoToken_Wallet.generated.h"


//REQUEST [transferCryptoToken]
/*
* Request parameters to transfer a crypto token
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTransferCryptoTokenRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The transaction request for the token transfer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyCryptoTokenTransactionRequest TransactionRequest;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
};


UCLASS(BlueprintType)
class VENLY_API UVyTransferCryptoTokenRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransferCryptoTokenRequestRef* ToObject(const FVyTransferCryptoTokenRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransferCryptoTokenRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransferCryptoTokenRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransferCryptoTokenRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyTransferCryptoTokenResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnTransferCryptoTokenCompleteBP, FVyTransferCryptoTokenResponse, Result);
