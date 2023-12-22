#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/FnModels/Wallet/VyWalletDelegates.h"
#include "AutoGen/FnModels/Wallet/VySignTransaction_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyReadContract_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyCancelTransaction_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferMultiToken_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetWalletEvents_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetTradingPairs_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetTransactionFees_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletWifPassphrase_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyUpdateSecurity_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyIsValidSignature_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferNativeToken_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetAllMultiTokenBalances_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletKeyStore_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalance_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletPrivateKey_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferGas_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetWallets_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyUpdateMetadata_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetSupportedWalletChains_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetClientsStatistics_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetNativeBalance_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalances_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalancesByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetMultiTokenBalances_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyExportWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyTransferCryptoToken_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletMigration_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetBlockchainInfo_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetNativeBalanceByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyCreateWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyIsValidWalletAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetMultiTokenBalancesByAddress_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetTransactionInfo_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetExchangeRate_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletWif_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyResubmitTransaction_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyExecuteContract_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalanceByAddress_Wallet.h"


#include "VyWalletAPI_BP.generated.h"

class UVyCore;
UCLASS(NotBlueprintType)
class VENLY_API UVyWalletAPI_BP : public UEngineSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	public:
	
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Venly|Wallet")
	static UVyWalletAPI_BP* Get() { return GEngine->GetEngineSubsystem<UVyWalletAPI_BP>(); }
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetWallets(const FVyQuery_GetWallets& Query, const FVyOnGetWalletsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void CreateWallet(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ExportWallet(FString WalletId, const FVyExportWalletRequest& Params, const FVyOnExportWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ImportWalletKeyStore(const FVyKeystorePasswordWalletImportRequest& Params, const FVyOnImportWalletKeyStoreCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ImportWalletPrivateKey(const FVyPrivateKeyWalletImportRequest& Params, const FVyOnImportWalletPrivateKeyCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ImportWalletWif(const FVyWifWalletImportRequest& Params, const FVyOnImportWalletWifCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ImportWalletWifPassphrase(const FVyWifPassphraseImportRequest& Params, const FVyOnImportWalletWifPassphraseCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ImportWalletMigration(const FVyMigrationWalletImportRequest& Params, const FVyOnImportWalletMigrationCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ResubmitTransaction(const FVyResubmitTransactionRequest& Params, const FVyOnResubmitTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ExecuteContract(const FVyExecuteContractRequest& Params, const FVyOnExecuteContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void TransferGas(const FVyTransferGasRequest& Params, const FVyOnTransferGasCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void TransferMultiToken(const FVyTransferMultiTokenRequest& Params, const FVyOnTransferMultiTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void TransferCryptoToken(const FVyTransferCryptoTokenRequest& Params, const FVyOnTransferCryptoTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void TransferNativeToken(const FVyTransferNativeTokenRequest& Params, const FVyOnTransferNativeTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void CancelTransaction(const FVyTransactionCancelRequest& Params, const FVyOnCancelTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void SignTransaction(const FVySignTransactionRequest& Params, const FVyOnSignTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void IsValidSignature(const FVySignatureVerificationRequest& Params, const FVyOnIsValidSignatureCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void ReadContract(const FVyReadContractRequest& Params, const FVyOnReadContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void UpdateSecurity(FString Id, const FVyUpdateWalletSecurityRequest& Params, const FVyOnUpdateSecurityCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetWallet(FString Id, const FVyQuery_GetWallet& Query, const FVyOnGetWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void UpdateMetadata(FString Id, const FVyUpdateWalletMetadataRequest& Params, const FVyOnUpdateMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetMultiTokenBalances(FString WalletId, const FVyQuery_GetMultiTokenBalances& Query, const FVyOnGetMultiTokenBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetWalletEvents(FString WalletId, const FVyOnGetWalletEventsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetNativeBalance(FString WalletId, const FVyOnGetNativeBalanceCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetCryptoTokenBalances(FString WalletId, const FVyQuery_GetCryptoTokenBalances& Query, const FVyOnGetCryptoTokenBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetCryptoTokenBalance(FString WalletId, FString Token, const FVyOnGetCryptoTokenBalanceCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetMultiTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetMultiTokenBalancesByAddress& Query, const FVyOnGetMultiTokenBalancesByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetNativeBalanceByAddress(EVyChain Chain, FString WalletAddress, const FVyOnGetNativeBalanceByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetCryptoTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetCryptoTokenBalancesByAddress& Query, const FVyOnGetCryptoTokenBalancesByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetCryptoTokenBalanceByAddress(EVyChain Chain, FString WalletAddress, FString Token, const FVyOnGetCryptoTokenBalanceByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetTradingPairs(FString Id, const FVyOnGetTradingPairsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetAllMultiTokenBalances(const FVyQuery_GetAllMultiTokenBalances& Query, const FVyOnGetAllMultiTokenBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetClientsStatistics(const FVyQuery_GetClientsStatistics& Query, const FVyOnGetClientsStatisticsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void IsValidWalletAddress(EVyChain Chain, FString WalletAddress, const FVyOnIsValidWalletAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetTransactionInfo(EVyChain Chain, FString TransactionHash, const FVyQuery_GetTransactionInfo& Query, const FVyOnGetTransactionInfoCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetTransactionFees(EVyChain Chain, const FVyOnGetTransactionFeesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet", meta=(AutoCreateRefTerm="Query"))
	void GetExchangeRate(const FVyQuery_GetExchangeRate& Query, const FVyOnGetExchangeRateCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetBlockchainInfo(EVyChain Chain, const FVyOnGetBlockchainInfoCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Wallet")
	void GetSupportedWalletChains(const FVyOnGetSupportedWalletChainsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	
	private:
	UPROPERTY()
	UVyCore* VenlyCore;
	
	const EVyApiEndpoint ApiEndpoint{ EVyApiEndpoint::Wallet };
};