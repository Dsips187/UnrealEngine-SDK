#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOfferDto.h"

#include "VyApproveOfferMetaTx_Market.generated.h"


//REQUEST [approveOfferMetaTx]
/*
* Request parameters to approve an offer using a meta transaction
*/
USTRUCT(BlueprintType)
struct FVyApproveOfferMetaTxRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The function signature of the offer approval transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString FunctionSignature;
	/**The R component of the offer approval transaction signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString R;
	/**The S component of the offer approval transaction signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString S;
	/**The V component of the offer approval transaction signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString V;
};


UCLASS(BlueprintType)
class UVyApproveOfferMetaTxRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyApproveOfferMetaTxRequestRef* ToObject(const FVyApproveOfferMetaTxRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyApproveOfferMetaTxRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyApproveOfferMetaTxRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyApproveOfferMetaTxRequest Data{};
};
//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyApproveOfferMetaTxResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnApproveOfferMetaTxCompleteBP, FVyApproveOfferMetaTxResponse, Result);
