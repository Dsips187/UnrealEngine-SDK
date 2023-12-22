#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Nft/VyContractMetadataDto.h"
#include "AutoGen/Optionals/VyOptTypeValueArray.h"

#include "VyUpdateContractMetadata_Nft.generated.h"


//REQUEST [updateContractMetadata]
/*
* Request parameters to update contract metadata
*/
USTRUCT(BlueprintType)
struct FVyUpdateContractMetadataRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Name;
	/**The symbol of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Symbol;
	/**The description of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Description;
	/**The URL of the contract's image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ImageUrl;
	/**The external URL of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUrl;
	/**An array of media types and values*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTypeValueArray Media;
	
	virtual ~FVyUpdateContractMetadataRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyUpdateContractMetadataRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateContractMetadataRequestRef* ToObject(const FVyUpdateContractMetadataRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateContractMetadataRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateContractMetadataRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateContractMetadataRequest Data{};
};
//RESPONSE [TokenContractMetadataView]
USTRUCT(BlueprintType)
struct FVyUpdateContractMetadataResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyContractMetadataDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateContractMetadataCompleteBP, FVyUpdateContractMetadataResponse, Result);
