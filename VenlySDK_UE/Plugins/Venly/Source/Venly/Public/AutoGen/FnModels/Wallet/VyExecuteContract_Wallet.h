#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTransactionContractExecutionRequest.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"

#include "VyExecuteContract_Wallet.generated.h"


//REQUEST [executeContract]
/*
* Request parameters to execute a contract
*/
USTRUCT(BlueprintType)
struct FVyExecuteContractRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The transaction request for contract execution*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyTransactionContractExecutionRequest TransactionRequest;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
};


UCLASS(BlueprintType)
class UVyExecuteContractRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyExecuteContractRequestRef* ToObject(const FVyExecuteContractRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyExecuteContractRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyExecuteContractRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyExecuteContractRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct FVyExecuteContractResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnExecuteContractCompleteBP, FVyExecuteContractResponse, Result);
