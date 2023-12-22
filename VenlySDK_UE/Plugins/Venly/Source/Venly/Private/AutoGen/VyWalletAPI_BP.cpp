#include "VyWalletAPI_BP.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "Utils/VyUtils.h"


void UVyWalletAPI_BP::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyWalletAPI_BP::GetWallets(const FVyQuery_GetWallets& Query, const FVyOnGetWalletsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets"),
		true,
		true);
	
	Context.SetEndpointId(2496658);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetWalletsResponse, FVyWalletDto, FVyOnGetWalletsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::CreateWallet(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets"),
		true,
		true);
	
	Context.SetEndpointId(7822753);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateWalletResponse, FVyWalletDto, FVyOnCreateWalletCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ExportWallet(FString WalletId, const FVyExportWalletRequest& Params, const FVyOnExportWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/export"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(13995658);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyExportWalletResponse, FVyWalletKeystoreDto, FVyOnExportWalletCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ImportWalletKeyStore(const FVyKeystorePasswordWalletImportRequest& Params, const FVyOnImportWalletKeyStoreCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyImportWalletKeyStoreResponse, FVyWalletDto, FVyOnImportWalletKeyStoreCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ImportWalletPrivateKey(const FVyPrivateKeyWalletImportRequest& Params, const FVyOnImportWalletPrivateKeyCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyImportWalletPrivateKeyResponse, FVyWalletDto, FVyOnImportWalletPrivateKeyCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ImportWalletWif(const FVyWifWalletImportRequest& Params, const FVyOnImportWalletWifCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyImportWalletWifResponse, FVyWalletDto, FVyOnImportWalletWifCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ImportWalletWifPassphrase(const FVyWifPassphraseImportRequest& Params, const FVyOnImportWalletWifPassphraseCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyImportWalletWifPassphraseResponse, FVyWalletDto, FVyOnImportWalletWifPassphraseCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ImportWalletMigration(const FVyMigrationWalletImportRequest& Params, const FVyOnImportWalletMigrationCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyImportWalletMigrationResponse, FVyWalletDto, FVyOnImportWalletMigrationCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ResubmitTransaction(const FVyResubmitTransactionRequest& Params, const FVyOnResubmitTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/resubmit"),
		true,
		true);
	
	Context.SetEndpointId(9702522);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyResubmitTransactionResponse, FVyTransactionResultDto, FVyOnResubmitTransactionCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ExecuteContract(const FVyExecuteContractRequest& Params, const FVyOnExecuteContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyExecuteContractResponse, FVyTransactionResultDto, FVyOnExecuteContractCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::TransferGas(const FVyTransferGasRequest& Params, const FVyOnTransferGasCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyTransferGasResponse, FVyTransactionResultDto, FVyOnTransferGasCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::TransferMultiToken(const FVyTransferMultiTokenRequest& Params, const FVyOnTransferMultiTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyTransferMultiTokenResponse, FVyTransactionResultDto, FVyOnTransferMultiTokenCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::TransferCryptoToken(const FVyTransferCryptoTokenRequest& Params, const FVyOnTransferCryptoTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyTransferCryptoTokenResponse, FVyTransactionResultDto, FVyOnTransferCryptoTokenCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::TransferNativeToken(const FVyTransferNativeTokenRequest& Params, const FVyOnTransferNativeTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyTransferNativeTokenResponse, FVyTransactionResultDto, FVyOnTransferNativeTokenCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::CancelTransaction(const FVyTransactionCancelRequest& Params, const FVyOnCancelTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/cancel"),
		true,
		true);
	
	Context.SetEndpointId(5852602);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCancelTransactionResponse, FVyTransactionResultDto, FVyOnCancelTransactionCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::SignTransaction(const FVySignTransactionRequest& Params, const FVyOnSignTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/signatures"),
		true,
		true);
	
	Context.SetEndpointId(2113825);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVySignTransactionResponse, FVySignatureResultDto, FVyOnSignTransactionCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::IsValidSignature(const FVySignatureVerificationRequest& Params, const FVyOnIsValidSignatureCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/signatures/verification"),
		true,
		true);
	
	Context.SetEndpointId(12680289);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyIsValidSignatureResponse, bool, FVyOnIsValidSignatureCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::ReadContract(const FVyReadContractRequest& Params, const FVyOnReadContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/contracts/read"),
		true,
		true);
	
	Context.SetEndpointId(13237583);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyReadContractResponse, FVyReadContractResultDto, FVyOnReadContractCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::UpdateSecurity(FString Id, const FVyUpdateWalletSecurityRequest& Params, const FVyOnUpdateSecurityCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/security"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(15960902);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateSecurityResponse, FVyWalletDto, FVyOnUpdateSecurityCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetWallet(FString Id, const FVyQuery_GetWallet& Query, const FVyOnGetWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(4101412);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetWalletResponse, FVyWalletDto, FVyOnGetWalletCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::UpdateMetadata(FString Id, const FVyUpdateWalletMetadataRequest& Params, const FVyOnUpdateMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/metadata"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(5948518);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateMetadataResponse, FVyWalletDto, FVyOnUpdateMetadataCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetMultiTokenBalances(FString WalletId, const FVyQuery_GetMultiTokenBalances& Query, const FVyOnGetMultiTokenBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/nonfungibles"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(10809317);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetMultiTokenBalancesResponse, FVyMultiTokenDto, FVyOnGetMultiTokenBalancesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetWalletEvents(FString WalletId, const FVyOnGetWalletEventsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/events"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(8421077);
	
	VenlyCore->ExecuteRequest_BP<FVyGetWalletEventsResponse, FVyWalletEventDto, FVyOnGetWalletEventsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetNativeBalance(FString WalletId, const FVyOnGetNativeBalanceCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/balance"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(10269227);
	
	VenlyCore->ExecuteRequest_BP<FVyGetNativeBalanceResponse, FVyNativeTokenDto, FVyOnGetNativeBalanceCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetCryptoTokenBalances(FString WalletId, const FVyQuery_GetCryptoTokenBalances& Query, const FVyOnGetCryptoTokenBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/balance/tokens"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(1185199);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCryptoTokenBalancesResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalancesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetCryptoTokenBalance(FString WalletId, FString Token, const FVyOnGetCryptoTokenBalanceCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/balance/tokens/{1}"), {WalletId,Token}),
		true,
		true);
	
	Context.SetEndpointId(10154828);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCryptoTokenBalanceResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalanceCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetMultiTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetMultiTokenBalancesByAddress& Query, const FVyOnGetMultiTokenBalancesByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/nonfungibles"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(10809317);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetMultiTokenBalancesByAddressResponse, FVyMultiTokenDto, FVyOnGetMultiTokenBalancesByAddressCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetNativeBalanceByAddress(EVyChain Chain, FString WalletAddress, const FVyOnGetNativeBalanceByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/balance"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(10269227);
	
	VenlyCore->ExecuteRequest_BP<FVyGetNativeBalanceByAddressResponse, FVyNativeTokenDto, FVyOnGetNativeBalanceByAddressCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetCryptoTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetCryptoTokenBalancesByAddress& Query, const FVyOnGetCryptoTokenBalancesByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/balance/tokens"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(1185199);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCryptoTokenBalancesByAddressResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalancesByAddressCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetCryptoTokenBalanceByAddress(EVyChain Chain, FString WalletAddress, FString Token, const FVyOnGetCryptoTokenBalanceByAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/balance/tokens/{2}"), {VyUtils::EnumToString(Chain),WalletAddress,Token}),
		true,
		true);
	
	Context.SetEndpointId(10154828);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCryptoTokenBalanceByAddressResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalanceByAddressCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetTradingPairs(FString Id, const FVyOnGetTradingPairsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/swaps/pairs"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(12273301);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTradingPairsResponse, FVyTradingPairDto, FVyOnGetTradingPairsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetAllMultiTokenBalances(const FVyQuery_GetAllMultiTokenBalances& Query, const FVyOnGetAllMultiTokenBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets/nonfungibles"),
		true,
		true);
	
	Context.SetEndpointId(10809317);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetAllMultiTokenBalancesResponse, FVyWalletMultiTokensDto, FVyOnGetAllMultiTokenBalancesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetClientsStatistics(const FVyQuery_GetClientsStatistics& Query, const FVyOnGetClientsStatisticsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets/clients/statistics"),
		true,
		true);
	
	Context.SetEndpointId(10946461);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetClientsStatisticsResponse, FVyClientStatisticsDto, FVyOnGetClientsStatisticsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::IsValidWalletAddress(EVyChain Chain, FString WalletAddress, const FVyOnIsValidWalletAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/address/validation/{0}/{1}"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(10307197);
	Context.SelectProperty(TEXT("valid"));
	
	VenlyCore->ExecuteRequest_BP<FVyIsValidWalletAddressResponse, bool, FVyOnIsValidWalletAddressCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetTransactionInfo(EVyChain Chain, FString TransactionHash, const FVyQuery_GetTransactionInfo& Query, const FVyOnGetTransactionInfoCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/transactions/{0}/{1}/status"), {VyUtils::EnumToString(Chain),TransactionHash}),
		true,
		true);
	
	Context.SetEndpointId(3628103);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTransactionInfoResponse, FVyTransactionInfoDto, FVyOnGetTransactionInfoCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetTransactionFees(EVyChain Chain, const FVyOnGetTransactionFeesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/transactions/{0}/fees"), {VyUtils::EnumToString(Chain)}),
		true,
		true);
	
	Context.SetEndpointId(8194384);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTransactionFeesResponse, FString, FVyOnGetTransactionFeesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetExchangeRate(const FVyQuery_GetExchangeRate& Query, const FVyOnGetExchangeRateCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/swaps/rates"),
		true,
		true);
	
	Context.SetEndpointId(5442743);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetExchangeRateResponse, FVyExchangeRateResultDto, FVyOnGetExchangeRateCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetBlockchainInfo(EVyChain Chain, const FVyOnGetBlockchainInfoCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/chains/{0}"), {VyUtils::EnumToString(Chain)}),
		true,
		true);
	
	Context.SetEndpointId(3719959);
	
	VenlyCore->ExecuteRequest_BP<FVyGetBlockchainInfoResponse, FVyBlockchainInfoDto, FVyOnGetBlockchainInfoCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyWalletAPI_BP::GetSupportedWalletChains(const FVyOnGetSupportedWalletChainsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/chains"),
		true,
		true);
	
	Context.SetEndpointId(10114850);
	
	VenlyCore->ExecuteRequest_BP<FVyGetSupportedWalletChainsResponse, EVyChain, FVyOnGetSupportedWalletChainsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}
