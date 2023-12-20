#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/FnModels/Nft/VyNftDelegates.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/FnModels/Nft/VyAddNftMedia_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenType_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetContracts_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetSupportedNftChains_Nft.h"
#include "AutoGen/FnModels/Nft/VyCreateCompanyWallet_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenTypes_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetToken_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenTypeMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyUpdateTokenTypeMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyUpdateContractMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyCreateTokenType_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetCompanyWalletByChain_Nft.h"
#include "AutoGen/FnModels/Nft/VyAddNftImage_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokens_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetContract_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetContractMetadata_Nft.h"
#include "AutoGen/FnModels/Nft/VyMintTokens_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetTokenInfos_Nft.h"
#include "AutoGen/FnModels/Nft/VyCreateContract_Nft.h"
#include "AutoGen/FnModels/Nft/VyGetCompanyWallets_Nft.h"


#include "VyNftAPI.generated.h"

class UVyCore;
UCLASS(NotBlueprintType)
class VENLY_API UVyNftAPI : public UEngineSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	public:
	
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Venly|Nft")
	static UVyNftAPI* Get() { return GEngine->GetEngineSubsystem<UVyNftAPI>(); }
	
	/*
	* Retrieves the metadata for a specific token type.
	* @param ContractId - The ID of the contract that the token type belongs to.
	* @param TypeId - The ID of the token type.
	* @param Id - The ID of the metadata.
	* @param OnComplete - The callback function called when the metadata retrieval operation is complete. (Contains a FVyGetTokenTypeMetadataResponse)
	*/
	void GetTokenTypeMetadata(int ContractId, int TypeId, FString Id, const FVyOnGetTokenTypeMetadataComplete& OnComplete) const;
	
	/*
	* Updates the metadata of a token type.
	* @param ContractId - The ID of the contract.
	* @param TypeId - The ID of the token type.
	* @param Params - The parameters for updating the token type metadata.
	* @param OnComplete - The callback function called when the token type metadata update operation is complete. (Contains a FVyUpdateTokenTypeMetadataResponse)
	*/
	void UpdateTokenTypeMetadata(int ContractId, int TypeId, const FVyUpdateTokenTypeMetadataRequest& Params, const FVyOnUpdateTokenTypeMetadataComplete& OnComplete) const;
	
	/*
	* Retrieves the wallets associated with a company.
	* @param Query - The query parameters to filter the company wallets.
	* @param OnComplete - The callback function called when the retrieval of company wallets is complete. (Contains a FVyGetCompanyWalletsResponse)
	*/
	void GetCompanyWallets(const FVyQuery_GetCompanyWallets& Query, const FVyOnGetCompanyWalletsComplete& OnComplete) const;
	
	/*
	* Creates a new wallet for the company.
	* @param Params - The required parameters to create the company wallet.
	* @param OnComplete - The callback function called when the company wallet creation operation is complete. (Contains a FVyCreateCompanyWalletResponse)
	*/
	void CreateCompanyWallet(const FVyCreateCompanyWalletRequest& Params, const FVyOnCreateCompanyWalletComplete& OnComplete) const;
	
	/*
	* Mints tokens for a specific contract and type.
	* @param ContractId - The ID of the contract for which tokens are being minted.
	* @param TypeId - The ID of the type for which tokens are being minted.
	* @param Params - The required parameters for minting tokens.
	* @param OnComplete - The callback function called when the token minting operation is complete. (Contains a FVyMintTokensResponse)
	*/
	void MintTokens(int ContractId, int TypeId, const FVyMintTokensRequest& Params, const FVyOnMintTokensComplete& OnComplete) const;
	
	/*
	* Retrieves the token types for a specific contract.
	* @param ContractId - The ID of the contract to retrieve token types for.
	* @param OnComplete - The callback function called when the token types retrieval operation is complete. (Contains a FVyGetTokenTypesResponse)
	*/
	void GetTokenTypes(int ContractId, const FVyOnGetTokenTypesComplete& OnComplete) const;
	
	/*
	* Creates a new token type for a contract.
	* @param ContractId - The ID of the contract to create the token type for.
	* @param Params - The required parameters to create the token type.
	* @param OnComplete - The callback function called when the token type creation operation is complete. (Contains a FVyCreateTokenTypeResponse)
	*/
	void CreateTokenType(int ContractId, const FVyCreateTokenTypeRequest& Params, const FVyOnCreateTokenTypeComplete& OnComplete) const;
	
	/*
	* Retrieves a list of contracts.
	* @param OnComplete - The callback function called when the contract retrieval operation is complete. (Contains a FVyGetContractsResponse)
	*/
	void GetContracts(const FVyOnGetContractsComplete& OnComplete) const;
	
	/*
	* Creates a new contract for the application.
	* @param Params - The required parameters to create the contract.
	* @param OnComplete - The callback function called when the contract creation operation is complete. (Contains a FVyCreateContractResponse)
	*/
	void CreateContract(const FVyCreateContractRequest& Params, const FVyOnCreateContractComplete& OnComplete) const;
	
	/*
	* Adds media to an NFT.
	* @param Params - The required parameters to add media to the NFT.
	* @param OnComplete - The callback function called when the media addition operation is complete. (Contains a FVyAddNftMediaResponse)
	*/
	void AddNftMedia(const FVyAddNftMediaRequest& Params, const FVyOnAddNftMediaComplete& OnComplete) const;
	
	/*
	* Adds an image to an NFT.
	* @param Params - The required parameters to add the image to the NFT.
	* @param OnComplete - The callback function called when the image addition operation is complete. (Contains a FVyAddNftImageResponse)
	*/
	void AddNftImage(const FVyAddNftImageRequest& Params, const FVyOnAddNftImageComplete& OnComplete) const;
	
	/*
	* Retrieves the metadata for a contract.
	* @param ContractId - The ID of the contract.
	* @param OnComplete - The callback function called when the contract metadata retrieval operation is complete. (Contains a FVyGetContractMetadataResponse)
	*/
	void GetContractMetadata(int ContractId, const FVyOnGetContractMetadataComplete& OnComplete) const;
	
	/*
	* Updates the metadata of a contract.
	* @param ContractId - The ID of the contract to update.
	* @param Params - The parameters for updating the contract metadata.
	* @param OnComplete - The callback function called when the contract metadata update operation is complete. (Contains a FVyUpdateContractMetadataResponse)
	*/
	void UpdateContractMetadata(int ContractId, const FVyUpdateContractMetadataRequest& Params, const FVyOnUpdateContractMetadataComplete& OnComplete) const;
	
	/*
	* Retrieves the tokens for a specific user address on a given chain.
	* @param Chain - The chain on which the tokens are located.
	* @param UserAddress - The address of the user for whom the tokens are being retrieved.
	* @param Query - The query parameters for filtering the tokens.
	* @param OnComplete - The callback function called when the token retrieval operation is complete. (Contains a FVyGetTokensResponse)
	*/
	void GetTokens(EVyChain Chain, FString UserAddress, const FVyQuery_GetTokens& Query, const FVyOnGetTokensComplete& OnComplete) const;
	
	/*
	* Retrieves the company wallet for the specified blockchain.
	* @param Chain - The blockchain for which to retrieve the company wallet.
	* @param Query - The query parameters for retrieving the company wallet.
	* @param OnComplete - The callback function called when the company wallet retrieval operation is complete. (Contains a FVyGetCompanyWalletByChainResponse)
	*/
	void GetCompanyWalletByChain(EVyChain Chain, const FVyQuery_GetCompanyWalletByChain& Query, const FVyOnGetCompanyWalletByChainComplete& OnComplete) const;
	
	/*
	* Retrieves information about a specific token.
	* @param ContractId - The ID of the contract associated with the token.
	* @param TokenTypeId - The ID of the token type.
	* @param OnComplete - The callback function called when the token information retrieval operation is complete. (Contains a FVyGetTokenInfosResponse)
	*/
	void GetTokenInfos(int ContractId, int TokenTypeId, const FVyOnGetTokenInfosComplete& OnComplete) const;
	
	/*
	* Retrieves the token type with the specified ContractId and TokenTypeId.
	* @param ContractId - The ID of the contract.
	* @param TokenTypeId - The ID of the token type.
	* @param OnComplete - The callback function called when the token type retrieval operation is complete. (Contains a FVyGetTokenTypeResponse)
	*/
	void GetTokenType(int ContractId, int TokenTypeId, const FVyOnGetTokenTypeComplete& OnComplete) const;
	
	/*
	* Retrieves information about a specific contract.
	* @param ContractId - The ID of the contract to retrieve information for.
	* @param OnComplete - The callback function called when the contract retrieval operation is complete. (Contains a FVyGetContractResponse)
	*/
	void GetContract(int ContractId, const FVyOnGetContractComplete& OnComplete) const;
	
	/*
	* Archives a contract with the specified ID.
	* @param ContractId - The ID of the contract to be archived.
	* @param OnComplete - The callback function called when the contract archiving operation is complete.
	*/
	void ArchiveContract(int ContractId, const FVyOnComplete& OnComplete) const;
	
	/*
	* Retrieves the supported NFT chains for item creation.
	* @param OnComplete - The callback function called when the retrieval of supported NFT chains is complete. (Contains a FVyGetSupportedNftChainsResponse)
	*/
	void GetSupportedNftChains(const FVyOnGetSupportedNftChainsComplete& OnComplete) const;
	
	/*
	* Retrieves information about a specific token.
	* @param ContractAddress - The address of the contract that owns the token.
	* @param TokenId - The unique identifier of the token.
	* @param Chain - The blockchain network on which the token exists.
	* @param OnComplete - The callback function called when the token retrieval operation is complete. (Contains a FVyGetTokenResponse)
	*/
	void GetToken(FString ContractAddress, int TokenId, EVyChain Chain, const FVyOnGetTokenComplete& OnComplete) const;
	
	/*
	* Deletes a company wallet.
	* @param Chain - The chain of the wallet to be deleted.
	* @param Address - The address of the wallet to be deleted.
	* @param OnComplete - The callback function called when the wallet deletion operation is complete. (Does not return any value)
	*/
	void DeleteCompanyWallet(EVyChain Chain, FString Address, const FVyOnComplete& OnComplete) const;
	
	/*
	* Archives a token type for a specific contract.
	* @param ContractId - The ID of the contract that the token type belongs to.
	* @param TypeId - The ID of the token type to be archived.
	* @param OnComplete - The callback function called when the token type archiving operation is complete. (Contains a FVyApiUnitResponse)
	*/
	void ArchiveTokenType(int ContractId, int TypeId, const FVyOnComplete& OnComplete) const;
	
	
	private:
	UPROPERTY()
	UVyCore* VenlyCore;
	
	const EVyApiEndpoint ApiEndpoint{ EVyApiEndpoint::Nft };
};