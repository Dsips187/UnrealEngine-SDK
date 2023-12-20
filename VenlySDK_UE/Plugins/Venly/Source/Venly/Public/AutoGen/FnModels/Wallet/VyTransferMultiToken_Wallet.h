#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyMultiTokenTransactionRequest.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"

#include "VyTransferMultiToken_Wallet.generated.h"


//REQUEST [transferMultiToken]
/*
* Request parameters to transfer a MultiToken
*/
USTRUCT(BlueprintType)
struct FVyTransferMultiTokenRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The transaction request for the MultiToken transfer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyMultiTokenTransactionRequest TransactionRequest;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
};


UCLASS(BlueprintType)
class UVyTransferMultiTokenRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransferMultiTokenRequestRef* ToObject(const FVyTransferMultiTokenRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransferMultiTokenRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransferMultiTokenRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransferMultiTokenRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct FVyTransferMultiTokenResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnTransferMultiTokenCompleteBP, FVyTransferMultiTokenResponse, Result);
