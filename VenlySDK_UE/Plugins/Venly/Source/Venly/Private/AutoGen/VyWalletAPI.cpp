#include "VyWalletAPI.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "Utils/VyUtils.h"


void UVyWalletAPI::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyWalletAPI::GetWallets(const FVyQuery_GetWallets& Query, const FVyOnGetWalletsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets"),
		true,
		true);
	
	Context.SetEndpointId(2496658);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetWalletsResponse, FVyWalletDto, FVyOnGetWalletsComplete>(Context, OnComplete);
}

void UVyWalletAPI::CreateWallet(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets"),
		true,
		true);
	
	Context.SetEndpointId(7822753);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateWalletResponse, FVyWalletDto, FVyOnCreateWalletComplete>(Context, OnComplete);
}

void UVyWalletAPI::ExportWallet(FString WalletId, const FVyExportWalletRequest& Params, const FVyOnExportWalletComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/export"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(13995658);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyExportWalletResponse, FVyWalletKeystoreDto, FVyOnExportWalletComplete>(Context, OnComplete);
}

void UVyWalletAPI::ImportWalletKeyStore(const FVyKeystorePasswordWalletImportRequest& Params, const FVyOnImportWalletKeyStoreComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyImportWalletKeyStoreResponse, FVyWalletDto, FVyOnImportWalletKeyStoreComplete>(Context, OnComplete);
}

void UVyWalletAPI::ImportWalletPrivateKey(const FVyPrivateKeyWalletImportRequest& Params, const FVyOnImportWalletPrivateKeyComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyImportWalletPrivateKeyResponse, FVyWalletDto, FVyOnImportWalletPrivateKeyComplete>(Context, OnComplete);
}

void UVyWalletAPI::ImportWalletWif(const FVyWifWalletImportRequest& Params, const FVyOnImportWalletWifComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyImportWalletWifResponse, FVyWalletDto, FVyOnImportWalletWifComplete>(Context, OnComplete);
}

void UVyWalletAPI::ImportWalletWifPassphrase(const FVyWifPassphraseImportRequest& Params, const FVyOnImportWalletWifPassphraseComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyImportWalletWifPassphraseResponse, FVyWalletDto, FVyOnImportWalletWifPassphraseComplete>(Context, OnComplete);
}

void UVyWalletAPI::ImportWalletMigration(const FVyMigrationWalletImportRequest& Params, const FVyOnImportWalletMigrationComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets/import"),
		true,
		true);
	
	Context.SetEndpointId(5088775);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyImportWalletMigrationResponse, FVyWalletDto, FVyOnImportWalletMigrationComplete>(Context, OnComplete);
}

void UVyWalletAPI::ResubmitTransaction(const FVyResubmitTransactionRequest& Params, const FVyOnResubmitTransactionComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/resubmit"),
		true,
		true);
	
	Context.SetEndpointId(9702522);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyResubmitTransactionResponse, FVyTransactionResultDto, FVyOnResubmitTransactionComplete>(Context, OnComplete);
}

void UVyWalletAPI::ExecuteContract(const FVyExecuteContractRequest& Params, const FVyOnExecuteContractComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyExecuteContractResponse, FVyTransactionResultDto, FVyOnExecuteContractComplete>(Context, OnComplete);
}

void UVyWalletAPI::TransferGas(const FVyTransferGasRequest& Params, const FVyOnTransferGasComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyTransferGasResponse, FVyTransactionResultDto, FVyOnTransferGasComplete>(Context, OnComplete);
}

void UVyWalletAPI::TransferMultiToken(const FVyTransferMultiTokenRequest& Params, const FVyOnTransferMultiTokenComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyTransferMultiTokenResponse, FVyTransactionResultDto, FVyOnTransferMultiTokenComplete>(Context, OnComplete);
}

void UVyWalletAPI::TransferCryptoToken(const FVyTransferCryptoTokenRequest& Params, const FVyOnTransferCryptoTokenComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyTransferCryptoTokenResponse, FVyTransactionResultDto, FVyOnTransferCryptoTokenComplete>(Context, OnComplete);
}

void UVyWalletAPI::TransferNativeToken(const FVyTransferNativeTokenRequest& Params, const FVyOnTransferNativeTokenComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/execute"),
		true,
		true);
	
	Context.SetEndpointId(7367915);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyTransferNativeTokenResponse, FVyTransactionResultDto, FVyOnTransferNativeTokenComplete>(Context, OnComplete);
}

void UVyWalletAPI::CancelTransaction(const FVyTransactionCancelRequest& Params, const FVyOnCancelTransactionComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/transactions/cancel"),
		true,
		true);
	
	Context.SetEndpointId(5852602);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCancelTransactionResponse, FVyTransactionResultDto, FVyOnCancelTransactionComplete>(Context, OnComplete);
}

void UVyWalletAPI::SignTransaction(const FVySignTransactionRequest& Params, const FVyOnSignTransactionComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/signatures"),
		true,
		true);
	
	Context.SetEndpointId(2113825);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVySignTransactionResponse, FVySignatureResultDto, FVyOnSignTransactionComplete>(Context, OnComplete);
}

void UVyWalletAPI::IsValidSignature(const FVySignatureVerificationRequest& Params, const FVyOnIsValidSignatureComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/signatures/verification"),
		true,
		true);
	
	Context.SetEndpointId(12680289);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyIsValidSignatureResponse, bool, FVyOnIsValidSignatureComplete>(Context, OnComplete);
}

void UVyWalletAPI::ReadContract(const FVyReadContractRequest& Params, const FVyOnReadContractComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/contracts/read"),
		true,
		true);
	
	Context.SetEndpointId(13237583);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyReadContractResponse, FVyReadContractResultDto, FVyOnReadContractComplete>(Context, OnComplete);
}

void UVyWalletAPI::UpdateSecurity(FString Id, const FVyUpdateWalletSecurityRequest& Params, const FVyOnUpdateSecurityComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/security"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(15960902);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateSecurityResponse, FVyWalletDto, FVyOnUpdateSecurityComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetWallet(FString Id, const FVyQuery_GetWallet& Query, const FVyOnGetWalletComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(4101412);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetWalletResponse, FVyWalletDto, FVyOnGetWalletComplete>(Context, OnComplete);
}

void UVyWalletAPI::UpdateMetadata(FString Id, const FVyUpdateWalletMetadataRequest& Params, const FVyOnUpdateMetadataComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/metadata"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(5948518);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateMetadataResponse, FVyWalletDto, FVyOnUpdateMetadataComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetMultiTokenBalances(FString WalletId, const FVyQuery_GetMultiTokenBalances& Query, const FVyOnGetMultiTokenBalancesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/nonfungibles"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(10809317);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetMultiTokenBalancesResponse, FVyMultiTokenDto, FVyOnGetMultiTokenBalancesComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetWalletEvents(FString WalletId, const FVyOnGetWalletEventsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/events"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(8421077);
	
	VenlyCore->ExecuteRequest<FVyGetWalletEventsResponse, FVyWalletEventDto, FVyOnGetWalletEventsComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetNativeBalance(FString WalletId, const FVyOnGetNativeBalanceComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/balance"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(10269227);
	
	VenlyCore->ExecuteRequest<FVyGetNativeBalanceResponse, FVyNativeTokenDto, FVyOnGetNativeBalanceComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetCryptoTokenBalances(FString WalletId, const FVyQuery_GetCryptoTokenBalances& Query, const FVyOnGetCryptoTokenBalancesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/balance/tokens"), {WalletId}),
		true,
		true);
	
	Context.SetEndpointId(1185199);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCryptoTokenBalancesResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalancesComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetCryptoTokenBalance(FString WalletId, FString Token, const FVyOnGetCryptoTokenBalanceComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/balance/tokens/{1}"), {WalletId,Token}),
		true,
		true);
	
	Context.SetEndpointId(10154828);
	
	VenlyCore->ExecuteRequest<FVyGetCryptoTokenBalanceResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalanceComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetMultiTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetMultiTokenBalancesByAddress& Query, const FVyOnGetMultiTokenBalancesByAddressComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/nonfungibles"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(10809317);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetMultiTokenBalancesByAddressResponse, FVyMultiTokenDto, FVyOnGetMultiTokenBalancesByAddressComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetNativeBalanceByAddress(EVyChain Chain, FString WalletAddress, const FVyOnGetNativeBalanceByAddressComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/balance"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(10269227);
	
	VenlyCore->ExecuteRequest<FVyGetNativeBalanceByAddressResponse, FVyNativeTokenDto, FVyOnGetNativeBalanceByAddressComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetCryptoTokenBalancesByAddress(EVyChain Chain, FString WalletAddress, const FVyQuery_GetCryptoTokenBalancesByAddress& Query, const FVyOnGetCryptoTokenBalancesByAddressComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/balance/tokens"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(1185199);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCryptoTokenBalancesByAddressResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalancesByAddressComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetCryptoTokenBalanceByAddress(EVyChain Chain, FString WalletAddress, FString Token, const FVyOnGetCryptoTokenBalanceByAddressComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}/balance/tokens/{2}"), {VyUtils::EnumToString(Chain),WalletAddress,Token}),
		true,
		true);
	
	Context.SetEndpointId(10154828);
	
	VenlyCore->ExecuteRequest<FVyGetCryptoTokenBalanceByAddressResponse, FVyCryptoTokenDto, FVyOnGetCryptoTokenBalanceByAddressComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetTradingPairs(FString Id, const FVyOnGetTradingPairsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/swaps/pairs"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(12273301);
	
	VenlyCore->ExecuteRequest<FVyGetTradingPairsResponse, FVyTradingPairDto, FVyOnGetTradingPairsComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetAllMultiTokenBalances(const FVyQuery_GetAllMultiTokenBalances& Query, const FVyOnGetAllMultiTokenBalancesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets/nonfungibles"),
		true,
		true);
	
	Context.SetEndpointId(10809317);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetAllMultiTokenBalancesResponse, FVyWalletMultiTokensDto, FVyOnGetAllMultiTokenBalancesComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetClientsStatistics(const FVyQuery_GetClientsStatistics& Query, const FVyOnGetClientsStatisticsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets/clients/statistics"),
		true,
		true);
	
	Context.SetEndpointId(10946461);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetClientsStatisticsResponse, FVyClientStatisticsDto, FVyOnGetClientsStatisticsComplete>(Context, OnComplete);
}

void UVyWalletAPI::IsValidWalletAddress(EVyChain Chain, FString WalletAddress, const FVyOnIsValidWalletAddressComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/address/validation/{0}/{1}"), {VyUtils::EnumToString(Chain),WalletAddress}),
		true,
		true);
	
	Context.SetEndpointId(10307197);
	Context.SelectProperty(TEXT("valid"));
	
	VenlyCore->ExecuteRequest<FVyIsValidWalletAddressResponse, bool, FVyOnIsValidWalletAddressComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetTransactionInfo(EVyChain Chain, FString TransactionHash, const FVyQuery_GetTransactionInfo& Query, const FVyOnGetTransactionInfoComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/transactions/{0}/{1}/status"), {VyUtils::EnumToString(Chain),TransactionHash}),
		true,
		true);
	
	Context.SetEndpointId(3628103);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetTransactionInfoResponse, FVyTransactionInfoDto, FVyOnGetTransactionInfoComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetTransactionFees(EVyChain Chain, const FVyOnGetTransactionFeesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/transactions/{0}/fees"), {VyUtils::EnumToString(Chain)}),
		true,
		true);
	
	Context.SetEndpointId(8194384);
	
	VenlyCore->ExecuteRequest<FVyGetTransactionFeesResponse, FString, FVyOnGetTransactionFeesComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetExchangeRate(const FVyQuery_GetExchangeRate& Query, const FVyOnGetExchangeRateComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/swaps/rates"),
		true,
		true);
	
	Context.SetEndpointId(5442743);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetExchangeRateResponse, FVyExchangeRateResultDto, FVyOnGetExchangeRateComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetBlockchainInfo(EVyChain Chain, const FVyOnGetBlockchainInfoComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/chains/{0}"), {VyUtils::EnumToString(Chain)}),
		true,
		true);
	
	Context.SetEndpointId(3719959);
	
	VenlyCore->ExecuteRequest<FVyGetBlockchainInfoResponse, FVyBlockchainInfoDto, FVyOnGetBlockchainInfoComplete>(Context, OnComplete);
}

void UVyWalletAPI::GetSupportedWalletChains(const FVyOnGetSupportedWalletChainsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/chains"),
		true,
		true);
	
	Context.SetEndpointId(10114850);
	
	VenlyCore->ExecuteRequest<FVyGetSupportedWalletChainsResponse, EVyChain, FVyOnGetSupportedWalletChainsComplete>(Context, OnComplete);
}
