#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyResubmitTransaction_Wallet.generated.h"


//REQUEST [resubmitTransaction]
/*
* Request parameters to resubmit a transaction
*/
USTRUCT(BlueprintType)
struct FVyResubmitTransactionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The preferred blockchain for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The hash of the transaction to be resubmitted*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
	
	virtual ~FVyResubmitTransactionRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyResubmitTransactionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyResubmitTransactionRequestRef* ToObject(const FVyResubmitTransactionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyResubmitTransactionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyResubmitTransactionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyResubmitTransactionRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct FVyResubmitTransactionResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnResubmitTransactionCompleteBP, FVyResubmitTransactionResponse, Result);
