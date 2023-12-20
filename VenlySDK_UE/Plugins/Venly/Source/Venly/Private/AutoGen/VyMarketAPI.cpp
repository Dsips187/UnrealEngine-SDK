#include "VyMarketAPI.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "Utils/VyUtils.h"


void UVyMarketAPI::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyMarketAPI::GetUserPreferences(const FVyOnGetUserPreferencesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/preferences"),
		true,
		true);
	
	Context.SetEndpointId(1426702);
	
	VenlyCore->ExecuteRequest<FVyGetUserPreferencesResponse, FVyUserPreferencesDto, FVyOnGetUserPreferencesComplete>(Context, OnComplete);
}

void UVyMarketAPI::UpdateUserPreferences(const FVyUpdateUserPreferencesRequest& Params, const FVyOnUpdateUserPreferencesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PUT(
		ApiEndpoint,
		TEXT("/user/preferences"),
		true,
		true);
	
	Context.SetEndpointId(2686084);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateUserPreferencesResponse, FVyUserPreferencesDto, FVyOnUpdateUserPreferencesComplete>(Context, OnComplete);
}

void UVyMarketAPI::ApproveOfferMetaTx(FString OfferId, const FVyApproveOfferMetaTxRequest& Params, const FVyOnApproveOfferMetaTxComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PUT(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/metaTxApprove"), {OfferId}),
		true,
		true);
	
	Context.SetEndpointId(1045412);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyApproveOfferMetaTxResponse, FVyOfferDto, FVyOnApproveOfferMetaTxComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUsers(const FVyQuery_GetUsers& Query, const FVyOnGetUsersComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/users"),
		true,
		true);
	
	Context.SetEndpointId(8200462);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetUsersResponse, FVyUserProfileDto, FVyOnGetUsersComplete>(Context, OnComplete);
}

void UVyMarketAPI::CreateSubUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateSubUserComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/users"),
		true,
		true);
	
	Context.SetEndpointId(6789365);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateSubUserResponse, FVySubUserDto, FVyOnCreateSubUserComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetDepositAddressesByUserId(FString UserId, const FVyOnGetDepositAddressesByUserIdComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/deposit-addresses"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(7534952);
	
	VenlyCore->ExecuteRequest<FVyGetDepositAddressesByUserIdResponse, FVyDepositAddressDto, FVyOnGetDepositAddressesByUserIdComplete>(Context, OnComplete);
}

void UVyMarketAPI::CreateDepositAddressForUserId(FString UserId, const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressForUserIdComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/deposit-addresses"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(10145447);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateDepositAddressForUserIdResponse, FVyDepositAddressDto, FVyOnCreateDepositAddressForUserIdComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetDepositAddresses(const FVyOnGetDepositAddressesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/deposit-addresses"),
		true,
		true);
	
	Context.SetEndpointId(7534952);
	
	VenlyCore->ExecuteRequest<FVyGetDepositAddressesResponse, FVyDepositAddressDto, FVyOnGetDepositAddressesComplete>(Context, OnComplete);
}

void UVyMarketAPI::CreateDepositAddress(const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/user/deposit-addresses"),
		true,
		true);
	
	Context.SetEndpointId(10145447);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateDepositAddressResponse, FVyDepositAddressDto, FVyOnCreateDepositAddressComplete>(Context, OnComplete);
}

void UVyMarketAPI::CreateOrder(const FVyCreateOrderRequest& Params, const FVyOnCreateOrderComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/orders"),
		true,
		true);
	
	Context.SetEndpointId(5822529);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateOrderResponse, FVyOrderDto, FVyOnCreateOrderComplete>(Context, OnComplete);
}

void UVyMarketAPI::CancelOrder(FString OrderId, const FVyOnComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/orders/{0}/cancel"), {OrderId}),
		false,
		true);
	
	Context.SetEndpointId(11564717);
	
	VenlyCore->ExecuteRequest<FVyApiUnitResponse, void, FVyOnComplete>(Context, OnComplete);
}

void UVyMarketAPI::CheckPayment(FString Id, const FVyOnComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/orders/{0}/check-completed"), {Id}),
		false,
		false);
	
	Context.SetEndpointId(16385723);
	
	VenlyCore->ExecuteRequest<FVyApiUnitResponse, void, FVyOnComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetOffers(const FVyQuery_GetOffers& Query, const FVyOnGetOffersComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/offers"),
		true,
		false);
	
	Context.SetEndpointId(3342145);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetOffersResponse, FVyOfferDto, FVyOnGetOffersComplete>(Context, OnComplete);
}

void UVyMarketAPI::CreateAuctionOffer(const FVyAuctionOfferRequest& Params, const FVyOnCreateAuctionOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/offers"),
		true,
		true);
	
	Context.SetEndpointId(5265865);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateAuctionOfferResponse, FVyAuctionDto, FVyOnCreateAuctionOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::CreateSaleOffer(const FVySaleOfferRequest& Params, const FVyOnCreateSaleOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/offers"),
		true,
		true);
	
	Context.SetEndpointId(5859608);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCreateSaleOfferResponse, FVySaleDto, FVyOnCreateSaleOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::BidOnOffer(FString Id, const FVyBidRequest& Params, const FVyOnBidOnOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/bid"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(12734659);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyBidOnOfferResponse, FVyOfferDto, FVyOnBidOnOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetFulfillments(const FVyQuery_GetFulfillments& Query, const FVyOnGetFulfillmentsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		false);
	
	Context.SetEndpointId(13269404);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetFulfillmentsResponse, FVyFulfillmentDto, FVyOnGetFulfillmentsComplete>(Context, OnComplete);
}

void UVyMarketAPI::TerminateOffer(const FVyTerminateOfferRequest& Params, const FVyOnTerminateOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(13296484);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyTerminateOfferResponse, FVyOfferTerminationDto, FVyOnTerminateOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::PurchaseOffer(const FVyPurchaseOfferRequest& Params, const FVyOnPurchaseOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(1078220);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyPurchaseOfferResponse, FVyOfferPurchaseDto, FVyOnPurchaseOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::CancelOffer(const FVyCancelOfferRequest& Params, const FVyOnCancelOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(4766016);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyCancelOfferResponse, FVyOfferCancellationDto, FVyOnCancelOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetCollections(const FVyQuery_GetCollections& Query, const FVyOnGetCollectionsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/collections"),
		true,
		false);
	
	Context.SetEndpointId(15189639);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCollectionsResponse, FVyCollectionDto, FVyOnGetCollectionsComplete>(Context, OnComplete);
}

void UVyMarketAPI::UpdateOrder(FString OrderId, const FVyUpdateOrderRequest& Params, const FVyOnUpdateOrderComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/orders/{0}"), {OrderId}),
		true,
		true);
	
	Context.SetEndpointId(2269847);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateOrderResponse, FVyOrderDto, FVyOnUpdateOrderComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetOffer(FString Id, const FVyOnGetOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}"), {Id}),
		true,
		false);
	
	Context.SetEndpointId(11291766);
	
	VenlyCore->ExecuteRequest<FVyGetOfferResponse, FVyOfferDto, FVyOnGetOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::UpdateOffer(FString Id, const FVyUpdateOfferRequest& Params, const FVyOnUpdateOfferComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(15075489);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateOfferResponse, FVyOfferDto, FVyOnUpdateOfferComplete>(Context, OnComplete);
}

void UVyMarketAPI::ApproveOfferTx(FString Id, const FVyApproveOfferTxRequest& Params, const FVyOnApproveOfferTxComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/txapprove"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(3552717);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyApproveOfferTxResponse, FVyOfferDto, FVyOnApproveOfferTxComplete>(Context, OnComplete);
}

void UVyMarketAPI::AddOfferSignature(FString Id, const FVyAddOfferSignatureRequest& Params, const FVyOnAddOfferSignatureComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/signature"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(11837149);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyAddOfferSignatureResponse, FVyOfferDto, FVyOnAddOfferSignatureComplete>(Context, OnComplete);
}

void UVyMarketAPI::UpdateFulfillmentAssociation(const FVyUpdateFulfillmentAssociationRequest& Params, const FVyOnUpdateFulfillmentAssociationComplete& OnComplete) const
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		TEXT("/fulfillments/txAssociation"),
		true,
		false);
	
	Context.SetEndpointId(8608621);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest<FVyUpdateFulfillmentAssociationResponse, FVyFulfillmentAssociationDto, FVyOnUpdateFulfillmentAssociationComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOrdersByUserId(FString UserId, const FVyOnGetUserOrdersByUserIdComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/orders"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(7316794);
	
	VenlyCore->ExecuteRequest<FVyGetUserOrdersByUserIdResponse, FVyOrderDto, FVyOnGetUserOrdersByUserIdComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOrderByUserId(FString UserId, FString OrderId, const FVyOnGetUserOrderByUserIdComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/orders/{1}"), {UserId,OrderId}),
		true,
		true);
	
	Context.SetEndpointId(8001767);
	
	VenlyCore->ExecuteRequest<FVyGetUserOrderByUserIdResponse, FVyOrderDto, FVyOnGetUserOrderByUserIdComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOffersByUserId(FString UserId, const FVyQuery_GetUserOffersByUserId& Query, const FVyOnGetUserOffersByUserIdComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/offers"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(4434228);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetUserOffersByUserIdResponse, FVyOfferDto, FVyOnGetUserOffersByUserIdComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetCreditBalance(FString UserId, const FVyQuery_GetCreditBalance& Query, const FVyOnGetCreditBalanceComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/balance"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(9953487);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCreditBalanceResponse, FVyUserCreditBalanceDto, FVyOnGetCreditBalanceComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserProfile(FString Id, const FVyOnGetUserProfileComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(3657653);
	
	VenlyCore->ExecuteRequest<FVyGetUserProfileResponse, FVyUserProfileDto, FVyOnGetUserProfileComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetRoles(const FVyOnGetRolesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/roles"),
		true,
		true);
	
	Context.SetEndpointId(12024485);
	
	VenlyCore->ExecuteRequest<FVyGetRolesResponse, FVyRoleInfoDto, FVyOnGetRolesComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOrders(const FVyOnGetUserOrdersComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/orders"),
		true,
		true);
	
	Context.SetEndpointId(7316794);
	
	VenlyCore->ExecuteRequest<FVyGetUserOrdersResponse, FVyOrderDto, FVyOnGetUserOrdersComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOrder(FString OrderId, const FVyOnGetUserOrderComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/user/orders/{0}"), {OrderId}),
		true,
		true);
	
	Context.SetEndpointId(8001767);
	
	VenlyCore->ExecuteRequest<FVyGetUserOrderResponse, FVyOrderDto, FVyOnGetUserOrderComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOrderWithdrawalMax(const FVyOnGetUserOrderWithdrawalMaxComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/orders/withdrawals/max-amount"),
		true,
		true);
	
	Context.SetEndpointId(9199462);
	
	VenlyCore->ExecuteRequest<FVyGetUserOrderWithdrawalMaxResponse, FVyUserOrderWithdrawalMaxDto, FVyOnGetUserOrderWithdrawalMaxComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserOffers(const FVyQuery_GetUserOffers& Query, const FVyOnGetUserOffersComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/offers"),
		true,
		true);
	
	Context.SetEndpointId(4434228);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetUserOffersResponse, FVyOfferDto, FVyOnGetUserOffersComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetUserFulfillments(const FVyQuery_GetUserFulfillments& Query, const FVyOnGetUserFulfillmentsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(4787887);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetUserFulfillmentsResponse, FVyFulfillmentDto, FVyOnGetUserFulfillmentsComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetCreditBalances(const FVyQuery_GetCreditBalances& Query, const FVyOnGetCreditBalancesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/credits"),
		true,
		true);
	
	Context.SetEndpointId(6900154);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCreditBalancesResponse, FVyUserCreditBalanceDto, FVyOnGetCreditBalancesComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetCreditHistory(EVyCurrencyType Currency, const FVyQuery_GetCreditHistory& Query, const FVyOnGetCreditHistoryComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/user/credits/{0}/history"), {VyUtils::EnumToString(Currency)}),
		true,
		true);
	
	Context.SetEndpointId(2856995);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyGetCreditHistoryResponse, FVyCreditHistoryDto, FVyOnGetCreditHistoryComplete>(Context, OnComplete);
}

void UVyMarketAPI::ClaimDailyReward(const FVyOnComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/credits/vens/daily-reward/claim"),
		false,
		true);
	
	Context.SetEndpointId(11928291);
	
	VenlyCore->ExecuteRequest<FVyApiUnitResponse, void, FVyOnComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetSupportedMarketChains(const FVyOnGetSupportedMarketChainsComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/orders/chains"),
		true,
		true);
	
	Context.SetEndpointId(10114850);
	Context.SelectProperty(TEXT("name"));
	
	VenlyCore->ExecuteRequest<FVyGetSupportedMarketChainsResponse, EVyChain, FVyOnGetSupportedMarketChainsComplete>(Context, OnComplete);
}

void UVyMarketAPI::PrepareOfferTransaction(FString Id, const FVyQuery_PrepareOfferTransaction& Query, const FVyOnPrepareOfferTransactionComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/preparation/transactions"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(7543904);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyPrepareOfferTransactionResponse, FVyOfferPreparationDto, FVyOnPrepareOfferTransactionComplete>(Context, OnComplete);
}

void UVyMarketAPI::FindHotOffers(const FVyQuery_FindHotOffers& Query, const FVyOnFindHotOffersComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/offers/hot"),
		true,
		false);
	
	Context.SetEndpointId(15254255);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest<FVyFindHotOffersResponse, FVyHotOfferDto, FVyOnFindHotOffersComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetFulfillment(FString Id, const FVyOnGetFulfillmentComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/fulfillments/{0}"), {Id}),
		true,
		false);
	
	Context.SetEndpointId(5971439);
	
	VenlyCore->ExecuteRequest<FVyGetFulfillmentResponse, FVyFulfillmentDto, FVyOnGetFulfillmentComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetWithdrawalFees(EVyChain Chain, const FVyOnGetWithdrawalFeesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/fees/withdrawal/{0}"), {VyUtils::EnumToString(Chain)}),
		true,
		true);
	
	Context.SetEndpointId(7577411);
	
	VenlyCore->ExecuteRequest<FVyGetWithdrawalFeesResponse, FVyWithdrawalFeeDto, FVyOnGetWithdrawalFeesComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetFees(EVyChain Chain, FString ContractAddress, const FVyOnGetFeesComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/fees/offer/{0}/{1}"), {VyUtils::EnumToString(Chain),ContractAddress}),
		true,
		true);
	
	Context.SetEndpointId(13116442);
	
	VenlyCore->ExecuteRequest<FVyGetFeesResponse, FVyOfferFeeDto, FVyOnGetFeesComplete>(Context, OnComplete);
}

void UVyMarketAPI::GetCollection(FString PublicId, const FVyOnGetCollectionComplete& OnComplete) const
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/collections/{0}"), {PublicId}),
		true,
		false);
	
	Context.SetEndpointId(7269542);
	
	VenlyCore->ExecuteRequest<FVyGetCollectionResponse, FVyCollectionDto, FVyOnGetCollectionComplete>(Context, OnComplete);
}
