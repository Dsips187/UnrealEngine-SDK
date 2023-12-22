#include "VyNftAPI_BP.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "Utils/VyUtils.h"


void UVyNftAPI_BP::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyNftAPI_BP::GetTokenTypeMetadata(int ContractId, int TypeId, FString Id, const FVyOnGetTokenTypeMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/token-types/{1}/metadata"), {ContractId,TypeId}),
		false,
		false);
	
	Context.SetEndpointId(10615384);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTokenTypeMetadataResponse, FVyTokenTypeMetadataDto, FVyOnGetTokenTypeMetadataCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::UpdateTokenTypeMetadata(int ContractId, int TypeId, const FVyUpdateTokenTypeMetadataRequest& Params, const FVyOnUpdateTokenTypeMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PUT(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/token-types/{1}/metadata"), {ContractId,TypeId}),
		false,
		true);
	
	Context.SetEndpointId(7954128);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateTokenTypeMetadataResponse, FString, FVyOnUpdateTokenTypeMetadataCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetCompanyWallets(const FVyQuery_GetCompanyWallets& Query, const FVyOnGetCompanyWalletsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/wallets"),
		false,
		true);
	
	Context.SetEndpointId(2981747);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCompanyWalletsResponse, FVyPageWalletBalanceDto, FVyOnGetCompanyWalletsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::CreateCompanyWallet(const FVyCreateCompanyWalletRequest& Params, const FVyOnCreateCompanyWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/wallets"),
		false,
		true);
	
	Context.SetEndpointId(9786321);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateCompanyWalletResponse, FVyCompanyWalletDto, FVyOnCreateCompanyWalletCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::MintTokens(int ContractId, int TypeId, const FVyMintTokensRequest& Params, const FVyOnMintTokensCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/types/{1}/tokens"), {ContractId,TypeId}),
		false,
		true);
	
	Context.SetEndpointId(4660158);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyMintTokensResponse, FVyMintedTokensDto, FVyOnMintTokensCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetTokenTypes(int ContractId, const FVyOnGetTokenTypesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(11321205);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTokenTypesResponse, FVyTokenTypeDto, FVyOnGetTokenTypesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::CreateTokenType(int ContractId, const FVyCreateTokenTypeRequest& Params, const FVyOnCreateTokenTypeCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(14505577);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateTokenTypeResponse, FVyTokenTypeDto, FVyOnCreateTokenTypeCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetContracts(const FVyOnGetContractsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/minter/contracts"),
		false,
		true);
	
	Context.SetEndpointId(15437463);
	
	VenlyCore->ExecuteRequest_BP<FVyGetContractsResponse, FVyContractDto, FVyOnGetContractsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::CreateContract(const FVyCreateContractRequest& Params, const FVyOnCreateContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/minter/contracts"),
		false,
		true);
	
	Context.SetEndpointId(16631876);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateContractResponse, FVyContractDto, FVyOnCreateContractCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::AddNftMedia(const FVyAddNftMediaRequest& Params, const FVyOnAddNftMediaCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/media"),
		false,
		true);
	
	Context.SetEndpointId(9208033);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyAddNftMediaResponse, FVyNftMediaDto, FVyOnAddNftMediaCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::AddNftImage(const FVyAddNftImageRequest& Params, const FVyOnAddNftImageCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/api/images"),
		false,
		true);
	
	Context.SetEndpointId(15962314);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyAddNftImageResponse, FVyNftImageDto, FVyOnAddNftImageCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetContractMetadata(int ContractId, const FVyOnGetContractMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/metadata"), {ContractId}),
		false,
		false);
	
	Context.SetEndpointId(9222562);
	
	VenlyCore->ExecuteRequest_BP<FVyGetContractMetadataResponse, FVyContractMetadataDto, FVyOnGetContractMetadataCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::UpdateContractMetadata(int ContractId, const FVyUpdateContractMetadataRequest& Params, const FVyOnUpdateContractMetadataCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/metadata"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(3489912);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateContractMetadataResponse, FVyContractMetadataDto, FVyOnUpdateContractMetadataCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetTokens(EVyChain Chain, FString UserAddress, const FVyQuery_GetTokens& Query, const FVyOnGetTokensCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/{0}/{1}/items"), {VyUtils::EnumToString(Chain),UserAddress}),
		false,
		true);
	
	Context.SetEndpointId(16513255);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTokensResponse, FVyTokenDto, FVyOnGetTokensCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetCompanyWalletByChain(EVyChain Chain, const FVyQuery_GetCompanyWalletByChain& Query, const FVyOnGetCompanyWalletByChainCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}"), {VyUtils::EnumToString(Chain)}),
		false,
		true);
	
	Context.SetEndpointId(12217803);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCompanyWalletByChainResponse, FVyPageWalletBalanceDto, FVyOnGetCompanyWalletByChainCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetTokenInfos(int ContractId, int TokenTypeId, const FVyOnGetTokenInfosCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types/{1}/tokens"), {ContractId,TokenTypeId}),
		false,
		true);
	
	Context.SetEndpointId(12550541);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTokenInfosResponse, FVyTokenInfoDto, FVyOnGetTokenInfosCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetTokenType(int ContractId, int TokenTypeId, const FVyOnGetTokenTypeCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types/{1}"), {ContractId,TokenTypeId}),
		false,
		true);
	
	Context.SetEndpointId(10480699);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTokenTypeResponse, FVyTokenTypeDto, FVyOnGetTokenTypeCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetContract(int ContractId, const FVyOnGetContractCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(5270384);
	
	VenlyCore->ExecuteRequest_BP<FVyGetContractResponse, FVyContractDto, FVyOnGetContractCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::ArchiveContract(int ContractId, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::DELETE(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}"), {ContractId}),
		false,
		true);
	
	Context.SetEndpointId(16734103);
	
	VenlyCore->ExecuteRequest_BP<FVyApiUnitResponse, void, FVyOnCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetSupportedNftChains(const FVyOnGetSupportedNftChainsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/api/env"),
		false,
		false);
	
	Context.SetEndpointId(10114850);
	Context.SelectProperty(TEXT("supportedChainsForItemCreation"));
	
	VenlyCore->ExecuteRequest_BP<FVyGetSupportedNftChainsResponse, EVyChain, FVyOnGetSupportedNftChainsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::GetToken(FString ContractAddress, int TokenId, EVyChain Chain, const FVyOnGetTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/api/contracts/{0}/{1}/tokens/{2}"), {VyUtils::EnumToString(Chain),ContractAddress,TokenId}),
		false,
		false);
	
	Context.SetEndpointId(7661925);
	
	VenlyCore->ExecuteRequest_BP<FVyGetTokenResponse, FVyTokenDto, FVyOnGetTokenCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::DeleteCompanyWallet(EVyChain Chain, FString Address, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::DELETE(
		ApiEndpoint,
		FString::Format(TEXT("/api/wallets/{0}/{1}"), {VyUtils::EnumToString(Chain),Address}),
		true,
		true);
	
	Context.SetEndpointId(16081910);
	
	VenlyCore->ExecuteRequest_BP<FVyApiUnitResponse, void, FVyOnCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyNftAPI_BP::ArchiveTokenType(int ContractId, int TypeId, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::DELETE(
		ApiEndpoint,
		FString::Format(TEXT("/api/minter/contracts/{0}/token-types/{1}"), {ContractId,TypeId}),
		false,
		true);
	
	Context.SetEndpointId(204819);
	
	VenlyCore->ExecuteRequest_BP<FVyApiUnitResponse, void, FVyOnCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}
