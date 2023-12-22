#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/FnModels/Market/VyMarketDelegates.h"
#include "AutoGen/FnModels/Market/VyGetDepositAddresses_Market.h"
#include "AutoGen/FnModels/Market/VyCreateDepositAddress_Market.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/FnModels/Market/VyGetUserOrdersByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyApproveOfferTx_Market.h"
#include "AutoGen/FnModels/Market/VyBidOnOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOffersByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyCreateAuctionOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetOffers_Market.h"
#include "AutoGen/FnModels/Market/VyCancelOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetCollection_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserFulfillments_Market.h"
#include "AutoGen/FnModels/Market/VyFindHotOffers_Market.h"
#include "AutoGen/FnModels/Market/VyGetCreditBalances_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrderByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyCreateSubUser_Market.h"
#include "AutoGen/FnModels/Market/VyGetWithdrawalFees_Market.h"
#include "AutoGen/FnModels/Market/VyGetCreditBalance_Market.h"
#include "AutoGen/FnModels/Market/VyGetSupportedMarketChains_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrders_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOffers_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrder_Market.h"
#include "AutoGen/FnModels/Market/VyGetFulfillments_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserPreferences_Market.h"
#include "AutoGen/FnModels/Market/VyTerminateOffer_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateOrder_Market.h"
#include "AutoGen/FnModels/Market/VyGetFees_Market.h"
#include "AutoGen/FnModels/Market/VyApproveOfferMetaTx_Market.h"
#include "AutoGen/FnModels/Market/VyGetUsers_Market.h"
#include "AutoGen/FnModels/Market/VyCreateOrder_Market.h"
#include "AutoGen/FnModels/Market/VyGetCreditHistory_Market.h"
#include "AutoGen/FnModels/Market/VyPurchaseOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrderWithdrawalMax_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateUserPreferences_Market.h"
#include "AutoGen/FnModels/Market/VyPrepareOfferTransaction_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserProfile_Market.h"
#include "AutoGen/FnModels/Market/VyGetCollections_Market.h"
#include "AutoGen/FnModels/Market/VyGetDepositAddressesByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyGetOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetFulfillment_Market.h"
#include "AutoGen/FnModels/Market/VyCreateDepositAddressForUserId_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateFulfillmentAssociation_Market.h"
#include "AutoGen/FnModels/Market/VyGetRoles_Market.h"
#include "AutoGen/FnModels/Market/VyAddOfferSignature_Market.h"
#include "AutoGen/FnModels/Market/VyCreateSaleOffer_Market.h"


#include "VyMarketAPI.generated.h"

class UVyCore;
UCLASS(NotBlueprintType)
class VENLY_API UVyMarketAPI : public UEngineSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	public:
	
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Venly|Market")
	static UVyMarketAPI* Get() { return GEngine->GetEngineSubsystem<UVyMarketAPI>(); }
	
	/*
	* Retrieves the user's preferences.
	* @param OnComplete - The callback function called when the user preferences retrieval operation is complete. (Contains a FVyGetUserPreferencesResponse)
	*/
	void GetUserPreferences(const FVyOnGetUserPreferencesComplete& OnComplete) const;
	
	/*
	* Updates the user preferences for the application.
	* @param Params - The required parameters to update the user preferences.
	* @param OnComplete - The callback function called when the user preferences update operation is complete. (Contains a FVyUpdateUserPreferencesResponse)
	*/
	void UpdateUserPreferences(const FVyUpdateUserPreferencesRequest& Params, const FVyOnUpdateUserPreferencesComplete& OnComplete) const;
	
	/*
	* Approves an offer using a meta transaction.
	* @param OfferId - The ID of the offer to be approved.
	* @param Params - The required parameters for approving the offer using a meta transaction.
	* @param OnComplete - The callback function called when the meta transaction approval operation is complete. (Contains a FVyApproveOfferMetaTxResponse)
	*/
	void ApproveOfferMetaTx(FString OfferId, const FVyApproveOfferMetaTxRequest& Params, const FVyOnApproveOfferMetaTxComplete& OnComplete) const;
	
	/*
	* Retrieves a list of users based on the specified query parameters.
	* @param Query - The query parameters used to filter the list of users.
	* @param OnComplete - The callback function called when the user retrieval operation is complete. (Contains a FVyGetUsersResponse)
	*/
	void GetUsers(const FVyQuery_GetUsers& Query, const FVyOnGetUsersComplete& OnComplete) const;
	
	/*
	* Creates a new sub user for the application.
	* @param Params - The required parameters to create the sub user.
	* @param OnComplete - The callback function called when the sub user creation operation is complete. (Contains a FVyCreateSubUserResponse)
	*/
	void CreateSubUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateSubUserComplete& OnComplete) const;
	
	/*
	* Retrieves the deposit addresses associated with a specific user.
	* @param UserId - The unique identifier of the user.
	* @param OnComplete - The callback function called when the retrieval of deposit addresses is complete. (Contains a FVyGetDepositAddressesByUserIdResponse)
	*/
	void GetDepositAddressesByUserId(FString UserId, const FVyOnGetDepositAddressesByUserIdComplete& OnComplete) const;
	
	/*
	* Creates a new deposit address for a specific user.
	* @param UserId - The ID of the user for whom the deposit address is being created.
	* @param Params - The required parameters to create the deposit address.
	* @param OnComplete - The callback function called when the deposit address creation operation is complete. (Contains a FVyCreateDepositAddressForUserIdResponse)
	*/
	void CreateDepositAddressForUserId(FString UserId, const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressForUserIdComplete& OnComplete) const;
	
	/*
	* Retrieves the deposit addresses for the user.
	* @param OnComplete - The callback function called when the retrieval of deposit addresses is complete. (Contains a FVyGetDepositAddressesResponse)
	*/
	void GetDepositAddresses(const FVyOnGetDepositAddressesComplete& OnComplete) const;
	
	/*
	* Creates a new deposit address for the user.
	* @param Params - The required parameters to create the deposit address.
	* @param OnComplete - The callback function called when the deposit address creation operation is complete. (Contains a FVyCreateDepositAddressResponse)
	*/
	void CreateDepositAddress(const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressComplete& OnComplete) const;
	
	/*
	* Creates a new order for the market.
	* @param Params - The required parameters to create the order.
	* @param OnComplete - The callback function called when the order creation operation is complete. (Contains a FVyCreateOrderResponse)
	*/
	void CreateOrder(const FVyCreateOrderRequest& Params, const FVyOnCreateOrderComplete& OnComplete) const;
	
	/*
	* Cancels an order.
	* @param OrderId - The ID of the order to be canceled.
	* @param OnComplete - The callback function called when the order cancellation operation is complete.
	*/
	void CancelOrder(FString OrderId, const FVyOnComplete& OnComplete) const;
	
	/*
	* Checks the status of a payment.
	* @param Id - The ID of the payment to check.
	* @param OnComplete - The callback function called when the payment status check is complete. (Contains a FVyApiUnitResponse)
	*/
	void CheckPayment(FString Id, const FVyOnComplete& OnComplete) const;
	
	/*
	* Retrieves a list of offers.
	* @param Query - The query parameters for retrieving the offers.
	* @param OnComplete - The callback function called when the offer retrieval operation is complete. (Contains a FVyGetOffersResponse)
	*/
	void GetOffers(const FVyQuery_GetOffers& Query, const FVyOnGetOffersComplete& OnComplete) const;
	
	/*
	* Creates a new auction offer.
	* @param Params - The required parameters to create the auction offer.
	* @param OnComplete - The callback function called when the auction offer creation operation is complete. (Contains a FVyCreateAuctionOfferResponse)
	*/
	void CreateAuctionOffer(const FVyAuctionOfferRequest& Params, const FVyOnCreateAuctionOfferComplete& OnComplete) const;
	
	/*
	* Creates a new sale offer for the market.
	* @param Params - The required parameters to create the sale offer.
	* @param OnComplete - The callback function called when the sale offer creation operation is complete. (Contains a FVyCreateSaleOfferResponse)
	*/
	void CreateSaleOffer(const FVySaleOfferRequest& Params, const FVyOnCreateSaleOfferComplete& OnComplete) const;
	
	/*
	* Bids on an offer in the market.
	* @param Id - The unique identifier of the offer to bid on.
	* @param Params - The required parameters for the bid.
	* @param OnComplete - The callback function called when the bid on offer operation is complete. (Contains a FVyBidOnOfferResponse)
	*/
	void BidOnOffer(FString Id, const FVyBidRequest& Params, const FVyOnBidOnOfferComplete& OnComplete) const;
	
	/*
	* Retrieves a list of fulfillments.
	* @param Query - The query parameters for retrieving the fulfillments.
	* @param OnComplete - The callback function called when the fulfillment retrieval operation is complete. (Contains a FVyGetFulfillmentsResponse)
	*/
	void GetFulfillments(const FVyQuery_GetFulfillments& Query, const FVyOnGetFulfillmentsComplete& OnComplete) const;
	
	/*
	* Terminates an offer in the market.
	* @param Params - The required parameters to terminate the offer.
	* @param OnComplete - The callback function called when the offer termination operation is complete. (Contains a FVyTerminateOfferResponse)
	*/
	void TerminateOffer(const FVyTerminateOfferRequest& Params, const FVyOnTerminateOfferComplete& OnComplete) const;
	
	/*
	* Purchases an offer from the market.
	* @param Params - The required parameters to purchase the offer.
	* @param OnComplete - The callback function called when the offer purchase operation is complete. (Contains a FVyPurchaseOfferResponse)
	*/
	void PurchaseOffer(const FVyPurchaseOfferRequest& Params, const FVyOnPurchaseOfferComplete& OnComplete) const;
	
	/*
	* Cancels an offer in the market.
	* @param Params - The required parameters to cancel the offer.
	* @param OnComplete - The callback function called when the offer cancellation operation is complete. (Contains a FVyCancelOfferResponse)
	*/
	void CancelOffer(const FVyCancelOfferRequest& Params, const FVyOnCancelOfferComplete& OnComplete) const;
	
	/*
	* Retrieves collections from the market.
	* @param Query - The query parameters for retrieving collections.
	* @param OnComplete - The callback function called when the retrieval of collections is complete. (Contains a FVyGetCollectionsResponse)
	*/
	void GetCollections(const FVyQuery_GetCollections& Query, const FVyOnGetCollectionsComplete& OnComplete) const;
	
	/*
	* Updates an existing order.
	* @param OrderId - The ID of the order to be updated.
	* @param Params - The required parameters to update the order.
	* @param OnComplete - The callback function called when the order update operation is complete. (Contains a FVyUpdateOrderResponse)
	*/
	void UpdateOrder(FString OrderId, const FVyUpdateOrderRequest& Params, const FVyOnUpdateOrderComplete& OnComplete) const;
	
	/*
	* Retrieves information about a specific offer.
	* @param Id - The unique identifier of the offer.
	* @param OnComplete - The callback function called when the offer retrieval operation is complete. (Contains a FVyGetOfferResponse)
	*/
	void GetOffer(FString Id, const FVyOnGetOfferComplete& OnComplete) const;
	
	/*
	* Updates an offer in the market.
	* @param Id - The unique identifier of the offer to update.
	* @param Params - The required parameters to update the offer.
	* @param OnComplete - The callback function called when the offer update operation is complete. (Contains a FVyUpdateOfferResponse)
	*/
	void UpdateOffer(FString Id, const FVyUpdateOfferRequest& Params, const FVyOnUpdateOfferComplete& OnComplete) const;
	
	/*
	* Approves an offer transaction.
	* @param Id - The ID of the offer to approve the transaction for.
	* @param Params - The required parameters to approve the offer transaction.
	* @param OnComplete - The callback function called when the offer transaction approval operation is complete. (Contains a FVyApproveOfferTxResponse)
	*/
	void ApproveOfferTx(FString Id, const FVyApproveOfferTxRequest& Params, const FVyOnApproveOfferTxComplete& OnComplete) const;
	
	/*
	* Adds a signature to an offer.
	* @param Id - The ID of the offer to add the signature to.
	* @param Params - The required parameters to add the signature to the offer.
	* @param OnComplete - The callback function called when the signature addition operation is complete. (Contains a FVyAddOfferSignatureResponse)
	*/
	void AddOfferSignature(FString Id, const FVyAddOfferSignatureRequest& Params, const FVyOnAddOfferSignatureComplete& OnComplete) const;
	
	/*
	* Updates the fulfillment association for a transaction.
	* @param Params - The required parameters to update the fulfillment association.
	* @param OnComplete - The callback function called when the fulfillment association update operation is complete. (Contains a FVyUpdateFulfillmentAssociationResponse)
	*/
	void UpdateFulfillmentAssociation(const FVyUpdateFulfillmentAssociationRequest& Params, const FVyOnUpdateFulfillmentAssociationComplete& OnComplete) const;
	
	/*
	* Retrieves the orders of a user by their ID.
	* @param UserId - The ID of the user whose orders are to be retrieved.
	* @param OnComplete - The callback function called when the order retrieval operation is complete. (Contains a FVyGetUserOrdersByUserIdResponse)
	*/
	void GetUserOrdersByUserId(FString UserId, const FVyOnGetUserOrdersByUserIdComplete& OnComplete) const;
	
	/*
	* Retrieves a specific user order by user ID and order ID.
	* @param UserId - The ID of the user whose order is being retrieved.
	* @param OrderId - The ID of the order being retrieved.
	* @param OnComplete - The callback function called when the order retrieval operation is complete. (Contains a FVyGetUserOrderByUserIdResponse)
	*/
	void GetUserOrderByUserId(FString UserId, FString OrderId, const FVyOnGetUserOrderByUserIdComplete& OnComplete) const;
	
	/*
	* Retrieves the offers made by a user.
	* @param UserId - The ID of the user whose offers are to be retrieved.
	* @param Query - The query parameters for filtering the user's offers.
	* @param OnComplete - The callback function called when the retrieval of user offers is complete. (Contains a FVyGetUserOffersByUserIdResponse)
	*/
	void GetUserOffersByUserId(FString UserId, const FVyQuery_GetUserOffersByUserId& Query, const FVyOnGetUserOffersByUserIdComplete& OnComplete) const;
	
	/*
	* Retrieves the credit balance for a user.
	* @param UserId - The ID of the user.
	* @param Query - The query parameters for retrieving the credit balance.
	* @param OnComplete - The callback function called when the credit balance retrieval operation is complete. (Contains a FVyGetCreditBalanceResponse)
	*/
	void GetCreditBalance(FString UserId, const FVyQuery_GetCreditBalance& Query, const FVyOnGetCreditBalanceComplete& OnComplete) const;
	
	/*
	* Retrieves the user profile information.
	* @param Id - The ID of the user.
	* @param OnComplete - The callback function called when the user profile retrieval operation is complete. (Contains a FVyGetUserProfileResponse)
	*/
	void GetUserProfile(FString Id, const FVyOnGetUserProfileComplete& OnComplete) const;
	
	/*
	* Retrieves the roles associated with the user.
	* @param OnComplete - The callback function called when the role retrieval operation is complete. (Contains a FVyGetRolesResponse)
	*/
	void GetRoles(const FVyOnGetRolesComplete& OnComplete) const;
	
	/*
	* Retrieves the orders associated with the user.
	* @param OnComplete - The callback function called when the retrieval of user orders is complete. (Contains a FVyGetUserOrdersResponse)
	*/
	void GetUserOrders(const FVyOnGetUserOrdersComplete& OnComplete) const;
	
	/*
	* Retrieves information about a user order.
	* @param OrderId - The ID of the order to retrieve information for.
	* @param OnComplete - The callback function called when the order retrieval operation is complete. (Contains a FVyGetUserOrderResponse)
	*/
	void GetUserOrder(FString OrderId, const FVyOnGetUserOrderComplete& OnComplete) const;
	
	/*
	* Retrieves the maximum withdrawal amount for user orders.
	* @param OnComplete - The callback function called when the retrieval of the maximum withdrawal amount is complete. (Contains a FVyGetUserOrderWithdrawalMaxResponse)
	*/
	void GetUserOrderWithdrawalMax(const FVyOnGetUserOrderWithdrawalMaxComplete& OnComplete) const;
	
	/*
	* Retrieves the offers made by a user.
	* @param Query - The query parameters for retrieving user offers.
	* @param OnComplete - The callback function called when the retrieval of user offers is complete. (Contains a FVyGetUserOffersResponse)
	*/
	void GetUserOffers(const FVyQuery_GetUserOffers& Query, const FVyOnGetUserOffersComplete& OnComplete) const;
	
	/*
	* Retrieves the fulfillments for the user.
	* @param Query - The query parameters for retrieving the fulfillments.
	* @param OnComplete - The callback function called when the fulfillment retrieval operation is complete. (Contains a FVyGetUserFulfillmentsResponse)
	*/
	void GetUserFulfillments(const FVyQuery_GetUserFulfillments& Query, const FVyOnGetUserFulfillmentsComplete& OnComplete) const;
	
	/*
	* Retrieves the credit balances for the user.
	* @param Query - The query parameters for retrieving the credit balances.
	* @param OnComplete - The callback function called when the credit balances retrieval operation is complete. (Contains a FVyGetCreditBalancesResponse)
	*/
	void GetCreditBalances(const FVyQuery_GetCreditBalances& Query, const FVyOnGetCreditBalancesComplete& OnComplete) const;
	
	/*
	* Retrieves the credit history for a specific currency.
	* @param Currency - The type of currency for which to retrieve the credit history.
	* @param Query - The query parameters for retrieving the credit history.
	* @param OnComplete - The callback function called when the credit history retrieval operation is complete. (Contains a FVyGetCreditHistoryResponse)
	*/
	void GetCreditHistory(EVyCurrencyType Currency, const FVyQuery_GetCreditHistory& Query, const FVyOnGetCreditHistoryComplete& OnComplete) const;
	
	/*
	* Claims the daily reward for the user.
	* @param OnComplete - The callback function called when the daily reward claim operation is complete. (Does not return any value)
	*/
	void ClaimDailyReward(const FVyOnComplete& OnComplete) const;
	
	/*
	* Retrieves the list of supported market chains.
	* @param OnComplete - The callback function called when the retrieval operation is complete. (Contains a FVyGetSupportedMarketChainsResponse)
	*/
	void GetSupportedMarketChains(const FVyOnGetSupportedMarketChainsComplete& OnComplete) const;
	
	/*
	* Prepares an offer transaction for the specified offer ID.
	* @param Id - The ID of the offer for which to prepare the transaction.
	* @param Query - The query parameters for preparing the offer transaction.
	* @param OnComplete - The callback function called when the offer transaction preparation is complete. (Contains a FVyPrepareOfferTransactionResponse)
	*/
	void PrepareOfferTransaction(FString Id, const FVyQuery_PrepareOfferTransaction& Query, const FVyOnPrepareOfferTransactionComplete& OnComplete) const;
	
	/*
	* Finds hot offers in the market.
	* @param Query - The query parameters for finding hot offers.
	* @param OnComplete - The callback function called when the hot offer search operation is complete. (Contains a FVyFindHotOffersResponse)
	*/
	void FindHotOffers(const FVyQuery_FindHotOffers& Query, const FVyOnFindHotOffersComplete& OnComplete) const;
	
	/*
	* Retrieves the fulfillment information for a specific ID.
	* @param Id - The ID of the fulfillment to retrieve.
	* @param OnComplete - The callback function called when the fulfillment retrieval operation is complete. (Contains a FVyGetFulfillmentResponse)
	*/
	void GetFulfillment(FString Id, const FVyOnGetFulfillmentComplete& OnComplete) const;
	
	/*
	* Retrieves the withdrawal fees for a specific chain.
	* @param Chain - The chain for which to retrieve the withdrawal fees.
	* @param OnComplete - The callback function called when the retrieval of withdrawal fees is complete. (Contains a FVyGetWithdrawalFeesResponse)
	*/
	void GetWithdrawalFees(EVyChain Chain, const FVyOnGetWithdrawalFeesComplete& OnComplete) const;
	
	/*
	* Retrieves the fees for a specific offer in the market.
	* @param Chain - The chain on which the offer is located.
	* @param ContractAddress - The contract address of the offer.
	* @param OnComplete - The callback function called when the fee retrieval operation is complete. (Contains a FVyGetFeesResponse)
	*/
	void GetFees(EVyChain Chain, FString ContractAddress, const FVyOnGetFeesComplete& OnComplete) const;
	
	/*
	* Retrieves a collection by its public ID.
	* @param PublicId - The public ID of the collection to retrieve.
	* @param OnComplete - The callback function called when the collection retrieval operation is complete. (Contains a FVyGetCollectionResponse)
	*/
	void GetCollection(FString PublicId, const FVyOnGetCollectionComplete& OnComplete) const;
	
	
	private:
	UPROPERTY()
	UVyCore* VenlyCore;
	
	const EVyApiEndpoint ApiEndpoint{ EVyApiEndpoint::Market };
};