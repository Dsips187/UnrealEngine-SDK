#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptSignatureRequestBase.h"
#include "AutoGen/Models/Wallet/VySignatureResultDto.h"

#include "VySignTransaction_Wallet.generated.h"


//REQUEST [signTransaction]
/*
* Request parameters to sign a transaction
*/
USTRUCT(BlueprintType)
struct FVySignTransactionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Pincode;
	/**The signature request object*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSignatureRequestBase SignatureRequest;
};


UCLASS(BlueprintType)
class UVySignTransactionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySignTransactionRequestRef* ToObject(const FVySignTransactionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySignTransactionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySignTransactionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySignTransactionRequest Data{};
};
//RESPONSE [signTransaction_merged]
USTRUCT(BlueprintType)
struct FVySignTransactionResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVySignatureResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnSignTransactionCompleteBP, FVySignTransactionResponse, Result);
