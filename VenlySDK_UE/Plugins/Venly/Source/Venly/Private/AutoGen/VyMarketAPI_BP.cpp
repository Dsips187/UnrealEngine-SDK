#include "VyMarketAPI_BP.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "Utils/VyUtils.h"


void UVyMarketAPI_BP::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyMarketAPI_BP::GetUserPreferences(const FVyOnGetUserPreferencesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/preferences"),
		true,
		true);
	
	Context.SetEndpointId(1426702);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserPreferencesResponse, FVyUserPreferencesDto, FVyOnGetUserPreferencesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::UpdateUserPreferences(const FVyUpdateUserPreferencesRequest& Params, const FVyOnUpdateUserPreferencesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PUT(
		ApiEndpoint,
		TEXT("/user/preferences"),
		true,
		true);
	
	Context.SetEndpointId(2686084);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateUserPreferencesResponse, FVyUserPreferencesDto, FVyOnUpdateUserPreferencesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::ApproveOfferMetaTx(FString OfferId, const FVyApproveOfferMetaTxRequest& Params, const FVyOnApproveOfferMetaTxCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PUT(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/metaTxApprove"), {OfferId}),
		true,
		true);
	
	Context.SetEndpointId(1045412);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyApproveOfferMetaTxResponse, FVyOfferDto, FVyOnApproveOfferMetaTxCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUsers(const FVyQuery_GetUsers& Query, const FVyOnGetUsersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/users"),
		true,
		true);
	
	Context.SetEndpointId(8200462);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUsersResponse, FVyUserProfileDto, FVyOnGetUsersCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CreateSubUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateSubUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/users"),
		true,
		true);
	
	Context.SetEndpointId(6789365);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateSubUserResponse, FVySubUserDto, FVyOnCreateSubUserCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetDepositAddressesByUserId(FString UserId, const FVyOnGetDepositAddressesByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/deposit-addresses"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(7534952);
	
	VenlyCore->ExecuteRequest_BP<FVyGetDepositAddressesByUserIdResponse, FVyDepositAddressDto, FVyOnGetDepositAddressesByUserIdCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CreateDepositAddressForUserId(FString UserId, const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressForUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/deposit-addresses"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(10145447);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateDepositAddressForUserIdResponse, FVyDepositAddressDto, FVyOnCreateDepositAddressForUserIdCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetDepositAddresses(const FVyOnGetDepositAddressesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/deposit-addresses"),
		true,
		true);
	
	Context.SetEndpointId(7534952);
	
	VenlyCore->ExecuteRequest_BP<FVyGetDepositAddressesResponse, FVyDepositAddressDto, FVyOnGetDepositAddressesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CreateDepositAddress(const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/user/deposit-addresses"),
		true,
		true);
	
	Context.SetEndpointId(10145447);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateDepositAddressResponse, FVyDepositAddressDto, FVyOnCreateDepositAddressCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CreateOrder(const FVyCreateOrderRequest& Params, const FVyOnCreateOrderCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/orders"),
		true,
		true);
	
	Context.SetEndpointId(5822529);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateOrderResponse, FVyOrderDto, FVyOnCreateOrderCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CancelOrder(FString OrderId, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/orders/{0}/cancel"), {OrderId}),
		false,
		true);
	
	Context.SetEndpointId(11564717);
	
	VenlyCore->ExecuteRequest_BP<FVyApiUnitResponse, void, FVyOnCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CheckPayment(FString Id, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/orders/{0}/check-completed"), {Id}),
		false,
		false);
	
	Context.SetEndpointId(16385723);
	
	VenlyCore->ExecuteRequest_BP<FVyApiUnitResponse, void, FVyOnCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetOffers(const FVyQuery_GetOffers& Query, const FVyOnGetOffersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/offers"),
		true,
		false);
	
	Context.SetEndpointId(3342145);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetOffersResponse, FVyOfferDto, FVyOnGetOffersCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CreateAuctionOffer(const FVyAuctionOfferRequest& Params, const FVyOnCreateAuctionOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/offers"),
		true,
		true);
	
	Context.SetEndpointId(5265865);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateAuctionOfferResponse, FVyAuctionDto, FVyOnCreateAuctionOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CreateSaleOffer(const FVySaleOfferRequest& Params, const FVyOnCreateSaleOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/offers"),
		true,
		true);
	
	Context.SetEndpointId(5859608);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCreateSaleOfferResponse, FVySaleDto, FVyOnCreateSaleOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::BidOnOffer(FString Id, const FVyBidRequest& Params, const FVyOnBidOnOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/bid"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(12734659);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyBidOnOfferResponse, FVyOfferDto, FVyOnBidOnOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetFulfillments(const FVyQuery_GetFulfillments& Query, const FVyOnGetFulfillmentsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		false);
	
	Context.SetEndpointId(13269404);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetFulfillmentsResponse, FVyFulfillmentDto, FVyOnGetFulfillmentsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::TerminateOffer(const FVyTerminateOfferRequest& Params, const FVyOnTerminateOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(13296484);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyTerminateOfferResponse, FVyOfferTerminationDto, FVyOnTerminateOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::PurchaseOffer(const FVyPurchaseOfferRequest& Params, const FVyOnPurchaseOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(1078220);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyPurchaseOfferResponse, FVyOfferPurchaseDto, FVyOnPurchaseOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::CancelOffer(const FVyCancelOfferRequest& Params, const FVyOnCancelOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		ApiEndpoint,
		TEXT("/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(4766016);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyCancelOfferResponse, FVyOfferCancellationDto, FVyOnCancelOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetCollections(const FVyQuery_GetCollections& Query, const FVyOnGetCollectionsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/collections"),
		true,
		false);
	
	Context.SetEndpointId(15189639);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCollectionsResponse, FVyCollectionDto, FVyOnGetCollectionsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::UpdateOrder(FString OrderId, const FVyUpdateOrderRequest& Params, const FVyOnUpdateOrderCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/orders/{0}"), {OrderId}),
		true,
		true);
	
	Context.SetEndpointId(2269847);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateOrderResponse, FVyOrderDto, FVyOnUpdateOrderCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetOffer(FString Id, const FVyOnGetOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}"), {Id}),
		true,
		false);
	
	Context.SetEndpointId(11291766);
	
	VenlyCore->ExecuteRequest_BP<FVyGetOfferResponse, FVyOfferDto, FVyOnGetOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::UpdateOffer(FString Id, const FVyUpdateOfferRequest& Params, const FVyOnUpdateOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(15075489);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateOfferResponse, FVyOfferDto, FVyOnUpdateOfferCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::ApproveOfferTx(FString Id, const FVyApproveOfferTxRequest& Params, const FVyOnApproveOfferTxCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/txapprove"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(3552717);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyApproveOfferTxResponse, FVyOfferDto, FVyOnApproveOfferTxCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::AddOfferSignature(FString Id, const FVyAddOfferSignatureRequest& Params, const FVyOnAddOfferSignatureCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/signature"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(11837149);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyAddOfferSignatureResponse, FVyOfferDto, FVyOnAddOfferSignatureCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::UpdateFulfillmentAssociation(const FVyUpdateFulfillmentAssociationRequest& Params, const FVyOnUpdateFulfillmentAssociationCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::PATCH(
		ApiEndpoint,
		TEXT("/fulfillments/txAssociation"),
		true,
		false);
	
	Context.SetEndpointId(8608621);
	Context.AddJsonContent(Params);
	
	VenlyCore->ExecuteRequest_BP<FVyUpdateFulfillmentAssociationResponse, FVyFulfillmentAssociationDto, FVyOnUpdateFulfillmentAssociationCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOrdersByUserId(FString UserId, const FVyOnGetUserOrdersByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/orders"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(7316794);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOrdersByUserIdResponse, FVyOrderDto, FVyOnGetUserOrdersByUserIdCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOrderByUserId(FString UserId, FString OrderId, const FVyOnGetUserOrderByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/orders/{1}"), {UserId,OrderId}),
		true,
		true);
	
	Context.SetEndpointId(8001767);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOrderByUserIdResponse, FVyOrderDto, FVyOnGetUserOrderByUserIdCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOffersByUserId(FString UserId, const FVyQuery_GetUserOffersByUserId& Query, const FVyOnGetUserOffersByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/offers"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(4434228);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOffersByUserIdResponse, FVyOfferDto, FVyOnGetUserOffersByUserIdCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetCreditBalance(FString UserId, const FVyQuery_GetCreditBalance& Query, const FVyOnGetCreditBalanceCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}/balance"), {UserId}),
		true,
		true);
	
	Context.SetEndpointId(9953487);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCreditBalanceResponse, FVyUserCreditBalanceDto, FVyOnGetCreditBalanceCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserProfile(FString Id, const FVyOnGetUserProfileCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/users/{0}"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(3657653);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserProfileResponse, FVyUserProfileDto, FVyOnGetUserProfileCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetRoles(const FVyOnGetRolesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/roles"),
		true,
		true);
	
	Context.SetEndpointId(12024485);
	
	VenlyCore->ExecuteRequest_BP<FVyGetRolesResponse, FVyRoleInfoDto, FVyOnGetRolesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOrders(const FVyOnGetUserOrdersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/orders"),
		true,
		true);
	
	Context.SetEndpointId(7316794);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOrdersResponse, FVyOrderDto, FVyOnGetUserOrdersCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOrder(FString OrderId, const FVyOnGetUserOrderCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/user/orders/{0}"), {OrderId}),
		true,
		true);
	
	Context.SetEndpointId(8001767);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOrderResponse, FVyOrderDto, FVyOnGetUserOrderCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOrderWithdrawalMax(const FVyOnGetUserOrderWithdrawalMaxCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/orders/withdrawals/max-amount"),
		true,
		true);
	
	Context.SetEndpointId(9199462);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOrderWithdrawalMaxResponse, FVyUserOrderWithdrawalMaxDto, FVyOnGetUserOrderWithdrawalMaxCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserOffers(const FVyQuery_GetUserOffers& Query, const FVyOnGetUserOffersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/offers"),
		true,
		true);
	
	Context.SetEndpointId(4434228);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserOffersResponse, FVyOfferDto, FVyOnGetUserOffersCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetUserFulfillments(const FVyQuery_GetUserFulfillments& Query, const FVyOnGetUserFulfillmentsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/fulfillments"),
		true,
		true);
	
	Context.SetEndpointId(4787887);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetUserFulfillmentsResponse, FVyFulfillmentDto, FVyOnGetUserFulfillmentsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetCreditBalances(const FVyQuery_GetCreditBalances& Query, const FVyOnGetCreditBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/credits"),
		true,
		true);
	
	Context.SetEndpointId(6900154);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCreditBalancesResponse, FVyUserCreditBalanceDto, FVyOnGetCreditBalancesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetCreditHistory(EVyCurrencyType Currency, const FVyQuery_GetCreditHistory& Query, const FVyOnGetCreditHistoryCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/user/credits/{0}/history"), {VyUtils::EnumToString(Currency)}),
		true,
		true);
	
	Context.SetEndpointId(2856995);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCreditHistoryResponse, FVyCreditHistoryDto, FVyOnGetCreditHistoryCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::ClaimDailyReward(const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/user/credits/vens/daily-reward/claim"),
		false,
		true);
	
	Context.SetEndpointId(11928291);
	
	VenlyCore->ExecuteRequest_BP<FVyApiUnitResponse, void, FVyOnCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetSupportedMarketChains(const FVyOnGetSupportedMarketChainsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/orders/chains"),
		true,
		true);
	
	Context.SetEndpointId(10114850);
	Context.SelectProperty(TEXT("name"));
	
	VenlyCore->ExecuteRequest_BP<FVyGetSupportedMarketChainsResponse, EVyChain, FVyOnGetSupportedMarketChainsCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::PrepareOfferTransaction(FString Id, const FVyQuery_PrepareOfferTransaction& Query, const FVyOnPrepareOfferTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/offers/{0}/preparation/transactions"), {Id}),
		true,
		true);
	
	Context.SetEndpointId(7543904);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyPrepareOfferTransactionResponse, FVyOfferPreparationDto, FVyOnPrepareOfferTransactionCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::FindHotOffers(const FVyQuery_FindHotOffers& Query, const FVyOnFindHotOffersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		TEXT("/offers/hot"),
		true,
		false);
	
	Context.SetEndpointId(15254255);
	Context.AddQuery(&Query);
	
	VenlyCore->ExecuteRequest_BP<FVyFindHotOffersResponse, FVyHotOfferDto, FVyOnFindHotOffersCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetFulfillment(FString Id, const FVyOnGetFulfillmentCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/fulfillments/{0}"), {Id}),
		true,
		false);
	
	Context.SetEndpointId(5971439);
	
	VenlyCore->ExecuteRequest_BP<FVyGetFulfillmentResponse, FVyFulfillmentDto, FVyOnGetFulfillmentCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetWithdrawalFees(EVyChain Chain, const FVyOnGetWithdrawalFeesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/fees/withdrawal/{0}"), {VyUtils::EnumToString(Chain)}),
		true,
		true);
	
	Context.SetEndpointId(7577411);
	
	VenlyCore->ExecuteRequest_BP<FVyGetWithdrawalFeesResponse, FVyWithdrawalFeeDto, FVyOnGetWithdrawalFeesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetFees(EVyChain Chain, FString ContractAddress, const FVyOnGetFeesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/fees/offer/{0}/{1}"), {VyUtils::EnumToString(Chain),ContractAddress}),
		true,
		true);
	
	Context.SetEndpointId(13116442);
	
	VenlyCore->ExecuteRequest_BP<FVyGetFeesResponse, FVyOfferFeeDto, FVyOnGetFeesCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}

void UVyMarketAPI_BP::GetCollection(FString PublicId, const FVyOnGetCollectionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::GET(
		ApiEndpoint,
		FString::Format(TEXT("/collections/{0}"), {PublicId}),
		true,
		false);
	
	Context.SetEndpointId(7269542);
	
	VenlyCore->ExecuteRequest_BP<FVyGetCollectionResponse, FVyCollectionDto, FVyOnGetCollectionCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}
