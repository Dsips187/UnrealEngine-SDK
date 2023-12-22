#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOfferDto.h"

#include "VyAddOfferSignature_Market.generated.h"


//REQUEST [addOfferSignature]
/*
* Request parameters to add an offer signature
*/
USTRUCT(BlueprintType)
struct FVyAddOfferSignatureRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The signature to be added*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Signature;
};


UCLASS(BlueprintType)
class UVyAddOfferSignatureRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyAddOfferSignatureRequestRef* ToObject(const FVyAddOfferSignatureRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyAddOfferSignatureRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyAddOfferSignatureRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyAddOfferSignatureRequest Data{};
};
//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyAddOfferSignatureResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnAddOfferSignatureCompleteBP, FVyAddOfferSignatureResponse, Result);
