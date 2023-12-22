#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/FnModels/Wallet/VyWalletDelegates.h"
#include "AutoGen/FnModels/Wallet/VyGetWallets_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyExportWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetNativeBalanceByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyCreateWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalances_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetExchangeRate_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetTransactionInfo_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferNativeToken_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyReadContract_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyUpdateMetadata_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferCryptoToken_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletWif_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetNativeBalance_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferGas_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetSupportedWalletChains_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalancesByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetMultiTokenBalancesByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletKeyStore_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetWalletEvents_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetTransactionFees_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyExecuteContract_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyIsValidWalletAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetMultiTokenBalances_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalance_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetBlockchainInfo_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferMultiToken_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VySignTransaction_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyCancelTransaction_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletMigration_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletWifPassphrase_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetTradingPairs_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalanceByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletPrivateKey_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyIsValidSignature_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetAllMultiTokenBalances_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetClientsStatistics_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyUpdateSecurity_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyResubmitTransaction_Wallet.h"


#include "VyWalletAPI.generated.h"

class UVyCore;
UCLASS(NotBlueprintType)
class VENLY_API UVyWalletAPI : public UEngineSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	public:
	
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Venly|Wallet")
	static UVyWalletAPI* Get() { return GEngine->GetEngineSubsystem<UVyWalletAPI>(); }
	
	/*
	* Retrieves a list of wallets based on the provided query parameters.
	* @param Query - The query parameters used to filter the wallets.
	* @param OnComplete - The callback function called when the wallet retrieval operation is complete. (Contains a FVyGetWalletsResponse)
	*/
	void GetWallets(const FVyQuery_GetWallets& Query, const FVyOnGetWalletsComplete& OnComplete) const;
	
	/*
	* Creates a new wallet for the application.
	* @param Params - The required parameters to create the wallet.
	* @param OnComplete - The callback function called when the wallet creation operation is complete. (Contains a FVyCreateWalletResponse)
	*/
	void CreateWallet(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletComplete& OnComplete) const;
	
	/*
	* Exports a wallet with the specified ID.
	* @param WalletId - The ID of the wallet to export.
	* @param Params - The required parameters for exporting the wallet.
	* @param OnComplete - The callback function called when the wallet export operation is complete. (Contains a FVyExportWalletResponse)
	*/
	void ExportWallet(FString WalletId, const FVyExportWalletRequest& Params, const FVyOnExportWalletComplete& OnComplete) const;
	
	/*
	* Imports a wallet using a keystore password.
	* @param Params - The required parameters to import the wallet using a keystore password.
	* @param OnComplete - The callback function called when the wallet import operation is complete. (Contains a FVyImportWalletKeyStoreResponse)
	*/
	void ImportWalletKeyStore(const FVyKeystorePasswordWalletImportRequest& Params, const FVyOnImportWalletKeyStoreComplete& OnComplete) const;
	
	/*
	* Imports a wallet using a private key.
	* @param Params - The required parameters to import the wallet using a private key.
	* @param OnComplete - The callback function called when the wallet import operation is complete. (Contains a FVyImportWalletPrivateKeyResponse)
	*/
	void ImportWalletPrivateKey(const FVyPrivateKeyWalletImportRequest& Params, const FVyOnImportWalletPrivateKeyComplete& OnComplete) const;
	
	/*
	* Imports a wallet using the Wallet Import Format (WIF).
	* @param Params - The required parameters to import the wallet using WIF.
	* @param OnComplete - The callback function called when the wallet import operation is complete. (Contains a FVyImportWalletWifResponse)
	*/
	void ImportWalletWif(const FVyWifWalletImportRequest& Params, const FVyOnImportWalletWifComplete& OnComplete) const;
	
	/*
	* Imports a wallet using a WIF (Wallet Import Format) passphrase.
	* @param Params - The required parameters to import the wallet using a WIF passphrase.
	* @param OnComplete - The callback function called when the wallet import operation is complete. (Contains a FVyImportWalletWifPassphraseResponse)
	*/
	void ImportWalletWifPassphrase(const FVyWifPassphraseImportRequest& Params, const FVyOnImportWalletWifPassphraseComplete& OnComplete) const;
	
	/*
	* Imports a wallet migration for the application.
	* @param Params - The required parameters to import the wallet migration.
	* @param OnComplete - The callback function called when the wallet migration import operation is complete. (Contains a FVyImportWalletMigrationResponse)
	*/
	void ImportWalletMigration(const FVyMigrationWalletImportRequest& Params, const FVyOnImportWalletMigrationComplete& OnComplete) const;
	
	/*
	* Resubmits a transaction for processing.
	* @param Params - The required parameters for resubmitting the transaction.
	* @param OnComplete - The callback function called when the transaction resubmission operation is complete. (Contains a FVyResubmitTransactionResponse)
	*/
	void ResubmitTransaction(const FVyResubmitTransactionRequest& Params, const FVyOnResubmitTransactionComplete& OnComplete) const;
	
	/*
	* Executes a contract transaction.
	* @param Params - The required parameters for executing the contract transaction.
	* @param OnComplete - The callback function called when the contract execution is complete. (Contains a FVyExecuteContractResponse)
	*/
	void ExecuteContract(const FVyExecuteContractRequest& Params, const FVyOnExecuteContractComplete& OnComplete) const;
	
	/*
	* Transfers gas from one account to another.
	* @param Params - The required parameters for the gas transfer.
	* @param OnComplete - The callback function called when the gas transfer operation is complete. (Contains a FVyTransferGasResponse)
	*/
	void TransferGas(const FVyTransferGasRequest& Params, const FVyOnTransferGasComplete& OnComplete) const;
	
	/*
	* Transfers multiple tokens in a single transaction.
	* @param Params - The required parameters for the token transfer.
	* @param OnComplete - The callback function called when the token transfer operation is complete. (Contains a FVyTransferMultiTokenResponse)
	*/
	void TransferMultiToken(const FVyTransferMultiTokenRequest& Params, const FVyOnTransferMultiTokenComplete& OnComplete) const;
	
	/*
	* Transfers a crypto token.
	* @param Params - The required parameters for the crypto token transfer.
	* @param OnComplete - The callback function called when the crypto token transfer operation is complete. (Contains a FVyTransferCryptoTokenResponse)
	*/
	void TransferCryptoToken(const FVyTransferCryptoTokenRequest& Params, const FVyOnTransferCryptoTokenComplete& OnComplete) const;
	
	/*
	* Transfers native tokens.
	* @param Params - The required parameters for the token transfer.
	* @param OnComplete - The callback function called when the token transfer operation is complete. (Contains a FVyTransferNativeTokenResponse)
	*/
	void TransferNativeToken(const FVyTransferNativeTokenRequest& Params, const FVyOnTransferNativeTokenComplete& OnComplete) const;
	
	/*
	* Cancels a transaction.
	* @param Params - The parameters required to cancel the transaction.
	* @param OnComplete - The callback function called when the transaction cancellation operation is complete. (Contains a FVyCancelTransactionResponse)
	*/
	void CancelTransaction(const FVyTransactionCancelRequest& Params, const FVyOnCancelTransactionComplete& OnComplete) const;
	
	/*
	* Signs a transaction using the provided parameters.
	* @param Params - The required parameters for signing the transaction.
	* @param OnComplete - The callback function called when the transaction signing operation is complete. (Contains a FVySignTransactionResponse)
	*/
	void SignTransaction(const FVySignTransactionRequest& Params, const FVyOnSignTransactionComplete& OnComplete) const;
	
	/*
	* Checks if a signature is valid.
	* @param Params - The parameters for signature verification.
	* @param OnComplete - The callback function called when the signature verification is complete. (Contains a FVyIsValidSignatureResponse)
	*/
	void IsValidSignature(const FVySignatureVerificationRequest& Params, const FVyOnIsValidSignatureComplete& OnComplete) const;
	
	/*
	* Reads a contract.
	* @param Params - The required parameters to read the contract.
	* @param OnComplete - The callback function called when the contract reading operation is complete. (Contains a FVyReadContractResponse)
	*/
	void ReadContract(const FVyReadContractRequest& Params, const FVyOnReadContractComplete& OnComplete) const;
	
	/*
	* Updates the security settings of a wallet.
	* @param Id - The ID of the wallet to update.
	* @param Params - The parameters for updating the wallet security.
	* @param OnComplete - The callback function called when the security update operation is complete. (Contains a FVyUpdateSecurityResponse)
	*/
	void UpdateSecurity(FString Id, const FVyUpdateWalletSecurityRequest& Params, const FVyOnUpdateSecurityComplete& OnComplete) const;
	
	/*
	* Retrieves information about a specific wallet.
	* @param Id - The unique identifier of the wallet.
	* @param Query - The query parameters for retrieving the wallet information.
	* @param OnComplete - The callback function called when the wallet retrieval operation is complete. (Contains a FVyGetWalletResponse)
	*/
	void GetWallet(FString Id, const FVyQuery_GetWallet& Query, const FVyOnGetWalletComplete& OnComplete) const;
	
	/*
	* Updates the metadata of a wallet.
	* @param Id - The ID of the wallet to update.
	* @param Params - The parameters to update the wallet metadata.
	* @param OnComplete - The callback function called when the metadata update operation is complete. (Contains a FVyUpdateMetadataResponse)
	*/
	void UpdateMetadata(FString Id, const FVyUpdateWalletMetadataRequest& Params, const FVyOnUpdateMetadataComplete& OnComplete) const;
	
	/*
	* Retrieves the balances of multiple tokens for a specific wallet.
	* @param WalletId - The ID of the wallet to retrieve the token balances for.
	* @param Query - The query parameters for retrieving the token balances.
	* @param OnComplete - The callback function called when the token balance retrieval operation is complete. (Contains a FVyGetMultiTokenBalancesResponse)
	*/
	void GetMultiTokenBalances(FString WalletId, const FVyQuery_GetMultiTokenBalances& Query, const FVyOnGetMultiTokenBalancesComplete& OnComplete) const;
	
	/*
	* Retrieves the events associated with a specific wallet.
	* @param WalletId - The ID of the wallet to retrieve events for.
	* @param OnComplete - The callback function called when the retrieval of wallet events is complete. (Contains a FVyGetWalletEventsResponse)
	*/
	void GetWalletEvents(FString WalletId, const FVyOnGetWalletEventsComplete& OnComplete) const;
	
	/*
	* Retrieves the native balance of a wallet.
	* @param WalletId - The ID of the wallet to retrieve the balance for.
	* @param OnComplete - The callback function called when the balance retrieval operation is complete. (Contains a FVyGetNativeBalanceResponse)
	*/
	void GetNativeBalance(FString WalletId, const FVyOnGetNativeBalanceComplete& OnComplete) const;
	
	/*
	* Retrieves the balances of crypto tokens for a specific wallet.
	* @param WalletId - The ID of the wallet to retrieve the token balances for.
	* @param Query - The query parameters to filter the token balances.
	* @param OnComplete - The callback function called when the retrieval of token balances is complete. (Contains a FVyGetCryptoTokenBalancesResponse)
	*/
	void GetCryptoTokenBalances(FString WalletId, const FVyQuery_GetCryptoTokenBalances& Query, const FVyOnGetCryptoTokenBalancesComplete& OnComplete) const;
	
	/*
	* Retrieves the balance of a specific crypto token in a wallet.
	* @param WalletId - The ID of the wallet to retrieve the token balance from.
	* @param Token - The symbol or name of the crypto token to retrieve the balance for.
	* @param OnComplete - The callback function called when the token balance retrieval operation is complete. (Contains a FVyGetCryptoTokenBalanceResponse)
	*/
	void GetCryptoTokenBalance(FString WalletId, FString Token, const FVyOnGetCryptoTokenBalanceComplete& OnComplete) const;
	
	/*
	* Retrieves the balances of multiple tokens for a specific wallet address on a given chain.
	* @param Chain - The chain on which the tokens are located.
	* @param WalletAddress - The address of the wallet for which to retrieve the token balances.
	* @param Query - The query parameters for the token balance retrieval.
	* @param OnComplete - The callback function called when the token balance retrieval operation is complete. (Contains a FVyGetMultiTokenBalancesByAddressResponse)
	*/
	void GetMultiTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetMultiTokenBalancesByAddress& Query, const FVyOnGetMultiTokenBalancesByAddressComplete& OnComplete) const;
	
	/*
	* Retrieves the native balance of a wallet address on a specific chain.
	* @param Chain - The chain on which the wallet address exists.
	* @param WalletAddress - The wallet address for which to retrieve the native balance.
	* @param OnComplete - The callback function called when the native balance retrieval operation is complete. (Contains a FVyGetNativeBalanceByAddressResponse)
	*/
	void GetNativeBalanceByAddress(EVyChain Chain, FString WalletAddress, const FVyOnGetNativeBalanceByAddressComplete& OnComplete) const;
	
	/*
	* Retrieves the balances of crypto tokens for a specific wallet address.
	* @param Chain - The chain on which the wallet address exists.
	* @param WalletAddress - The address of the wallet.
	* @param Query - The query parameters for retrieving the crypto token balances.
	* @param OnComplete - The callback function called when the retrieval of crypto token balances is complete. (Contains a FVyGetCryptoTokenBalancesByAddressResponse)
	*/
	void GetCryptoTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetCryptoTokenBalancesByAddress& Query, const FVyOnGetCryptoTokenBalancesByAddressComplete& OnComplete) const;
	
	/*
	* Retrieves the balance of a specific crypto token for a given wallet address on a specified chain.
	* @param Chain - The chain on which the wallet address and token exist.
	* @param WalletAddress - The address of the wallet for which the token balance is being retrieved.
	* @param Token - The token for which the balance is being retrieved.
	* @param OnComplete - The callback function called when the balance retrieval operation is complete. (Contains a FVyGetCryptoTokenBalanceByAddressResponse)
	*/
	void GetCryptoTokenBalanceByAddress(EVyChain Chain, FString WalletAddress, FString Token, const FVyOnGetCryptoTokenBalanceByAddressComplete& OnComplete) const;
	
	/*
	* Retrieves the trading pairs for a specific wallet.
	* @param Id - The identifier of the wallet.
	* @param OnComplete - The callback function called when the retrieval of trading pairs is complete. (Contains a FVyGetTradingPairsResponse)
	*/
	void GetTradingPairs(FString Id, const FVyOnGetTradingPairsComplete& OnComplete) const;
	
	/*
	* Retrieves the balances of all multi-tokens in the wallet.
	* @param Query - The query parameters for retrieving the multi-token balances.
	* @param OnComplete - The callback function called when the retrieval of multi-token balances is complete. (Contains a FVyGetAllMultiTokenBalancesResponse)
	*/
	void GetAllMultiTokenBalances(const FVyQuery_GetAllMultiTokenBalances& Query, const FVyOnGetAllMultiTokenBalancesComplete& OnComplete) const;
	
	/*
	* Retrieves statistics for clients of the wallet application.
	* @param Query - The query parameters for retrieving the clients statistics.
	* @param OnComplete - The callback function called when the retrieval of clients statistics is complete. (Contains a FVyGetClientsStatisticsResponse)
	*/
	void GetClientsStatistics(const FVyQuery_GetClientsStatistics& Query, const FVyOnGetClientsStatisticsComplete& OnComplete) const;
	
	/*
	* Checks if a given wallet address is valid for the specified chain.
	* @param Chain - The chain to validate the wallet address against.
	* @param WalletAddress - The wallet address to validate.
	* @param OnComplete - The callback function called when the wallet address validation operation is complete. (Contains a FVyIsValidWalletAddressResponse)
	*/
	void IsValidWalletAddress(EVyChain Chain, FString WalletAddress, const FVyOnIsValidWalletAddressComplete& OnComplete) const;
	
	/*
	* Retrieves information about a transaction.
	* @param Chain - The chain on which the transaction occurred.
	* @param TransactionHash - The hash of the transaction.
	* @param Query - The query parameters for retrieving transaction information.
	* @param OnComplete - The callback function called when the transaction information retrieval is complete. (Contains a FVyGetTransactionInfoResponse)
	*/
	void GetTransactionInfo(EVyChain Chain, FString TransactionHash, const FVyQuery_GetTransactionInfo& Query, const FVyOnGetTransactionInfoComplete& OnComplete) const;
	
	/*
	* Retrieves the transaction fees for a specific chain.
	* @param Chain - The chain for which to retrieve the transaction fees.
	* @param OnComplete - The callback function called when the transaction fees retrieval operation is complete. (Contains a FVyGetTransactionFeesResponse)
	*/
	void GetTransactionFees(EVyChain Chain, const FVyOnGetTransactionFeesComplete& OnComplete) const;
	
	/*
	* Retrieves the exchange rate for a specific query.
	* @param Query - The query parameters to retrieve the exchange rate.
	* @param OnComplete - The callback function called when the exchange rate retrieval operation is complete. (Contains a FVyGetExchangeRateResponse)
	*/
	void GetExchangeRate(const FVyQuery_GetExchangeRate& Query, const FVyOnGetExchangeRateComplete& OnComplete) const;
	
	/*
	* Retrieves information about a specific blockchain.
	* @param Chain - The enum value representing the blockchain for which to retrieve information.
	* @param OnComplete - The callback function called when the blockchain information retrieval operation is complete. (Contains a FVyGetBlockchainInfoResponse)
	*/
	void GetBlockchainInfo(EVyChain Chain, const FVyOnGetBlockchainInfoComplete& OnComplete) const;
	
	/*
	* Retrieves a list of supported wallet chains.
	* @param OnComplete - The callback function called when the retrieval of supported wallet chains is complete. (Contains a FVyGetSupportedWalletChainsResponse)
	*/
	void GetSupportedWalletChains(const FVyOnGetSupportedWalletChainsComplete& OnComplete) const;
	
	
	private:
	UPROPERTY()
	UVyCore* VenlyCore;
	
	const EVyApiEndpoint ApiEndpoint{ EVyApiEndpoint::Wallet };
};