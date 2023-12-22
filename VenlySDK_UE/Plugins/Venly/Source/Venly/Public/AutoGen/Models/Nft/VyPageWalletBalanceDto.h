#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Nft/VyPageableObjectDto.h"
#include "AutoGen/Models/Nft/VySortDto.h"
#include "AutoGen/Models/Wallet/VyWalletBalanceDtoDto.h"
#include "VyPageWalletBalanceDto.generated.h"

/*
* Page information and wallet balances
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyPageWalletBalanceDto : public FVyDTO
{
	GENERATED_BODY()
	/**Total number of pages*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TotalPages;
	/**Total number of elements*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TotalElements;
	/**Number of elements per page*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Size;
	/**List of wallet balance DTOs*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyWalletBalanceDtoDto> Content;
	/**Current page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Number;
	/**Sorting information*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVySortDto Sort;
	/**Pageable object information*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyPageableObjectDto Pageable;
	/**Number of elements in the current page*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int NumberOfElements;
	/**Indicates if it is the first page*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool First;
	/**Indicates if it is the last page*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Last;
	/**Indicates if the page is empty*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Empty;
};


UCLASS(BlueprintType)
class VENLY_API UVyPageWalletBalanceDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyPageWalletBalanceDtoRef* ToObject(const FVyPageWalletBalanceDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyPageWalletBalanceDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyPageWalletBalanceDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyPageWalletBalanceDto Data{};
};