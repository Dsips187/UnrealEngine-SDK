#include "VyNftAPI.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "Utils/VyUtils.h"


void UVyNftAPI::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyNftAPI::GetTokenTypeMetadata(int ContractId, int TypeId, FString Id, const FVyOnGetTokenTypeMetadataComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/token-types/{1}/metadata"), {ContractId,TypeId}),
		false,
		false);
	
	Context.SetEndpointId(10615384);
	
	VenlyCore->ExecuteRequest<FVyGetTokenTypeMetadataResponse, FVyTokenTypeMetadataDto, FVyOnGetTokenTypeMetadataComplete>(Context, OnComplete);
}

void UVyNftAPI::UpdateTokenTypeMetadata(int ContractId, int TypeId, const FVyUpdateTokenTypeMetadataRequest& Params, const FVyOnUpdateTokenTypeMetadataComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PUT(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/token-types/{1}/metadata"), {ContractId,TypeId}),
		false,
		true);
	
	Context.SetEndpointId(7954128);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateTokenTypeMetadataResponse, FString, FVyOnUpdateTokenTypeMetadataComplete>(Context, OnComplete);
}

void UVyNftAPI::GetCompanyWallets(const FVyQuery_GetCompanyWallets& Query, const FVyOnGetCompanyWalletsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets"),
		false,
		true);
	
	Context.SetEndpointId(2981747);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCompanyWalletsResponse, FVyPageWalletBalanceDto, FVyOnGetCompanyWalletsComplete>(Context, OnComplete);
}

void UVyNftAPI::CreateCompanyWallet(const FVyCreateCompanyWalletRequest& Params, const FVyOnCreateCompanyWalletComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets"),
		false,
		true);
	
	Context.SetEndpointId(9786321);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateCompanyWalletResponse, FVyCompanyWalletDto, FVyOnCreateCompanyWalletComplete>(Context, OnComplete);
}

void UVyNftAPI::MintTokens(int ContractId, int TypeId, const FVyMintTokensRequest& Params, const FVyOnMintTokensComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/types/{1}/tokens"), {ContractId,TypeId}),
		false,
		true);
	
	Context.SetEndpointId(4660158);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyMintTokensResponse, FVyMintedTokensDto, FVyOnMintTokensComplete>(Context, OnComplete);
}

void UVyNftAPI::GetTokenTypes(int ContractId, const FVyOnGetTokenTypesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(11321205);
	
	VenlyCore->ExecuteRequest<FVyGetTokenTypesResponse, FVyTokenTypeDto, FVyOnGetTokenTypesComplete>(Context, OnComplete);
}

void UVyNftAPI::CreateTokenType(int ContractId, const FVyCreateTokenTypeRequest& Params, const FVyOnCreateTokenTypeComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(14505577);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateTokenTypeResponse, FVyTokenTypeDto, FVyOnCreateTokenTypeComplete>(Context, OnComplete);
}

void UVyNftAPI::GetContracts(const FVyOnGetContractsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/minter/contracts"),
		false,
		true);
	
	Context.SetEndpointId(15437463);
	
	VenlyCore->ExecuteRequest<FVyGetContractsResponse, FVyContractDto, FVyOnGetContractsComplete>(Context, OnComplete);
}

void UVyNftAPI::CreateContract(const FVyCreateContractRequest& Params, const FVyOnCreateContractComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/minter/contracts"),
		false,
		true);
	
	Context.SetEndpointId(16631876);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateContractResponse, FVyContractDto, FVyOnCreateContractComplete>(Context, OnComplete);
}

void UVyNftAPI::AddNftMedia(const FVyAddNftMediaRequest& Params, const FVyOnAddNftMediaComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/media"),
		false,
		true);
	
	Context.SetEndpointId(9208033);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyAddNftMediaResponse, FVyNftMediaDto, FVyOnAddNftMediaComplete>(Context, OnComplete);
}

void UVyNftAPI::AddNftImage(const FVyAddNftImageRequest& Params, const FVyOnAddNftImageComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/images"),
		false,
		true);
	
	Context.SetEndpointId(15962314);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyAddNftImageResponse, FVyNftImageDto, FVyOnAddNftImageComplete>(Context, OnComplete);
}

void UVyNftAPI::GetContractMetadata(int ContractId, const FVyOnGetContractMetadataComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/metadata"), {ContractId}),
		false,
		false);
	
	Context.SetEndpointId(9222562);
	
	VenlyCore->ExecuteRequest<FVyGetContractMetadataResponse, FVyContractMetadataDto, FVyOnGetContractMetadataComplete>(Context, OnComplete);
}

void UVyNftAPI::UpdateContractMetadata(int ContractId, const FVyUpdateContractMetadataRequest& Params, const FVyOnUpdateContractMetadataComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/metadata"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(3489912);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateContractMetadataResponse, FVyContractMetadataDto, FVyOnUpdateContractMetadataComplete>(Context, OnComplete);
}

void UVyNftAPI::GetTokens(EVyChain Chain, FString UserAddress, const FVyQuery_GetTokens& Query, const FVyOnGetTokensComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/{0}/{1}/items"), {VyUtils::EnumToString(Chain),UserAddress}),
		false,
		true);
	
	Context.SetEndpointId(16513255);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetTokensResponse, FVyTokenDto, FVyOnGetTokensComplete>(Context, OnComplete);
}

void UVyNftAPI::GetCompanyWalletByChain(EVyChain Chain, const FVyQuery_GetCompanyWalletByChain& Query, const FVyOnGetCompanyWalletByChainComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}"), {VyUtils::EnumToString(Chain)}),
		false,
		true);
	
	Context.SetEndpointId(12217803);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCompanyWalletByChainResponse, FVyPageWalletBalanceDto, FVyOnGetCompanyWalletByChainComplete>(Context, OnComplete);
}

void UVyNftAPI::GetTokenInfos(int ContractId, int TokenTypeId, const FVyOnGetTokenInfosComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types/{1}/tokens"), {ContractId,TokenTypeId}),
		false,
		true);
	
	Context.SetEndpointId(12550541);
	
	VenlyCore->ExecuteRequest<FVyGetTokenInfosResponse, FVyTokenInfoDto, FVyOnGetTokenInfosComplete>(Context, OnComplete);
}

void UVyNftAPI::GetTokenType(int ContractId, int TokenTypeId, const FVyOnGetTokenTypeComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types/{1}"), {ContractId,TokenTypeId}),
		false,
		true);
	
	Context.SetEndpointId(10480699);
	
	VenlyCore->ExecuteRequest<FVyGetTokenTypeResponse, FVyTokenTypeDto, FVyOnGetTokenTypeComplete>(Context, OnComplete);
}

void UVyNftAPI::GetContract(int ContractId, const FVyOnGetContractComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(5270384);
	
	VenlyCore->ExecuteRequest<FVyGetContractResponse, FVyContractDto, FVyOnGetContractComplete>(Context, OnComplete);
}

void UVyNftAPI::ArchiveContract(int ContractId, const FVyOnComplete& OnComplete) const
{
	auto Context = FVyRequestContext::DELETE(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(16734103);
	
	VenlyCore->ExecuteRequest<FVyApiUnitResponse, void, FVyOnComplete>(Context, OnComplete);
}

void UVyNftAPI::GetSupportedNftChains(const FVyOnGetSupportedNftChainsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/env"),
		false,
		false);
	
	Context.SetEndpointId(10114850);
	Context.SelectProperty(TEXT("supportedChainsForItemCreation"));
	
	VenlyCore->ExecuteRequest<FVyGetSupportedNftChainsResponse, EVyChain, FVyOnGetSupportedNftChainsComplete>(Context, OnComplete);
}

void UVyNftAPI::GetToken(FString ContractAddress, int TokenId, EVyChain Chain, const FVyOnGetTokenComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/{1}/tokens/{2}"), {VyUtils::EnumToString(Chain),ContractAddress,TokenId}),
		false,
		false);
	
	Context.SetEndpointId(7661925);
	
	VenlyCore->ExecuteRequest<FVyGetTokenResponse, FVyTokenDto, FVyOnGetTokenComplete>(Context, OnComplete);
}

void UVyNftAPI::DeleteCompanyWallet(EVyChain Chain, FString Address, const FVyOnComplete& OnComplete) const
{
	auto Context = FVyRequestContext::DELETE(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}"), {VyUtils::EnumToString(Chain),Address}),
		true,
		true);
	
	Context.SetEndpointId(16081910);
	
	VenlyCore->ExecuteRequest<FVyApiUnitResponse, void, FVyOnComplete>(Context, OnComplete);
}

void UVyNftAPI::ArchiveTokenType(int ContractId, int TypeId, const FVyOnComplete& OnComplete) const
{
	auto Context = FVyRequestContext::DELETE(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types/{1}"), {ContractId,TypeId}),
		false,
		true);
	
	Context.SetEndpointId(204819);
	
	VenlyCore->ExecuteRequest<FVyApiUnitResponse, void, FVyOnComplete>(Context, OnComplete);
}
