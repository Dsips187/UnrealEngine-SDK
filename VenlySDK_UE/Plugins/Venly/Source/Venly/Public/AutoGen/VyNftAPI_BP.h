#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/FnModels/Nft/VyNftDelegates.h"
#include "AutoGen/FnModels/Nft/VyGetContractMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenInfos_Nft.h"
#include "AutoGen/FnModels/Nft/VyMintTokens_Nft.h"
#include "AutoGen/FnModels/Nft/VyUpdateContractMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetContract_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenTypes_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenType_Nft.h"
#include "AutoGen/FnModels/Nft/VyCreateCompanyWallet_Nft.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/FnModels/Nft/VyGetCompanyWalletByChain_Nft.h"
#include "AutoGen/FnModels/Nft/VyAddNftMedia_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokens_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetToken_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetCompanyWallets_Nft.h"
#include "AutoGen/FnModels/Nft/VyUpdateTokenTypeMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenTypeMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyCreateContract_Nft.h"
#include "AutoGen/FnModels/Nft/VyCreateTokenType_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetContracts_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetSupportedNftChains_Nft.h"
#include "AutoGen/FnModels/Nft/VyAddNftImage_Nft.h"


#include "VyNftAPI_BP.generated.h"

class UVyCore;
UCLASS(NotBlueprintType)
class VENLY_API UVyNftAPI_BP : public UEngineSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	public:
	
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Venly|Nft")
	static UVyNftAPI_BP* Get() { return GEngine->GetEngineSubsystem<UVyNftAPI_BP>(); }
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetTokenTypeMetadata(int ContractId, int TypeId, FString Id, const FVyOnGetTokenTypeMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void UpdateTokenTypeMetadata(int ContractId, int TypeId, const FVyUpdateTokenTypeMetadataRequest& Params, const FVyOnUpdateTokenTypeMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft", meta=(AutoCreateRefTerm="Query"))
	void GetCompanyWallets(const FVyQuery_GetCompanyWallets& Query, const FVyOnGetCompanyWalletsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void CreateCompanyWallet(const FVyCreateCompanyWalletRequest& Params, const FVyOnCreateCompanyWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void MintTokens(int ContractId, int TypeId, const FVyMintTokensRequest& Params, const FVyOnMintTokensCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetTokenTypes(int ContractId, const FVyOnGetTokenTypesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void CreateTokenType(int ContractId, const FVyCreateTokenTypeRequest& Params, const FVyOnCreateTokenTypeCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetContracts(const FVyOnGetContractsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void CreateContract(const FVyCreateContractRequest& Params, const FVyOnCreateContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void AddNftMedia(const FVyAddNftMediaRequest& Params, const FVyOnAddNftMediaCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void AddNftImage(const FVyAddNftImageRequest& Params, const FVyOnAddNftImageCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetContractMetadata(int ContractId, const FVyOnGetContractMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void UpdateContractMetadata(int ContractId, const FVyUpdateContractMetadataRequest& Params, const FVyOnUpdateContractMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft", meta=(AutoCreateRefTerm="Query"))
	void GetTokens(EVyChain Chain, FString UserAddress, const FVyQuery_GetTokens& Query, const FVyOnGetTokensCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft", meta=(AutoCreateRefTerm="Query"))
	void GetCompanyWalletByChain(EVyChain Chain, const FVyQuery_GetCompanyWalletByChain& Query, const FVyOnGetCompanyWalletByChainCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetTokenInfos(int ContractId, int TokenTypeId, const FVyOnGetTokenInfosCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetTokenType(int ContractId, int TokenTypeId, const FVyOnGetTokenTypeCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetContract(int ContractId, const FVyOnGetContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void ArchiveContract(int ContractId, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetSupportedNftChains(const FVyOnGetSupportedNftChainsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void GetToken(FString ContractAddress, int TokenId, EVyChain Chain, const FVyOnGetTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void DeleteCompanyWallet(EVyChain Chain, FString Address, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Nft")
	void ArchiveTokenType(int ContractId, int TypeId, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	
	private:
	UPROPERTY()
	UVyCore* VenlyCore;
	
	const EVyApiEndpoint ApiEndpoint{ EVyApiEndpoint::Nft };
};