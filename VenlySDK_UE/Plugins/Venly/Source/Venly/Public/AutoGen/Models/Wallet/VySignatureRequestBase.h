#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VySignatureRequestBase.generated.h"

/*
* Base class for signature requests
*/
USTRUCT(BlueprintType)
struct VENLY_API FVySignatureRequestBase : public FVyDTO
{
	GENERATED_BODY()
	/**The preferred blockchain for the signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The ID of the wallet to use for the signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
};


UCLASS(BlueprintType)
class VENLY_API UVySignatureRequestBaseRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySignatureRequestBaseRef* ToObject(const FVySignatureRequestBase& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySignatureRequestBaseRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySignatureRequestBase& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySignatureRequestBase Data{};
};