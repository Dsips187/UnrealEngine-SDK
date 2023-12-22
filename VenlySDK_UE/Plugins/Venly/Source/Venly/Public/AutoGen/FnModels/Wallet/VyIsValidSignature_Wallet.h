#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptBool.h"

#include "VyIsValidSignature_Wallet.generated.h"


//REQUEST [SignatureVerificationRequest]
/*
* Request parameters for signature verification
*/
USTRUCT(BlueprintType)
struct FVySignatureVerificationRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The blockchain on which the signature was created*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The address of the signer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SignerAddress;
	/**The message that was signed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Message;
	/**The signature to be verified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Signature;
	/**Flag indicating whether the message has a prefix*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Prefix;
	
	virtual ~FVySignatureVerificationRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVySignatureVerificationRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySignatureVerificationRequestRef* ToObject(const FVySignatureVerificationRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySignatureVerificationRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySignatureVerificationRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySignatureVerificationRequest Data{};
};
//RESPONSE [#type]
USTRUCT(BlueprintType)
struct FVyIsValidSignatureResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") bool Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnIsValidSignatureCompleteBP, FVyIsValidSignatureResponse, Result);
