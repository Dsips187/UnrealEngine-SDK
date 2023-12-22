#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/FnModels/Market/VyMarketDelegates.h"
#include "AutoGen/FnModels/Market/VyGetSupportedMarketChains_Market.h"
#include "AutoGen/FnModels/Market/VyGetOffers_Market.h"
#include "AutoGen/FnModels/Market/VyAddOfferSignature_Market.h"
#include "AutoGen/FnModels/Market/VyGetCollection_Market.h"
#include "AutoGen/FnModels/Market/VyGetCreditBalances_Market.h"
#include "AutoGen/FnModels/Market/VyGetWithdrawalFees_Market.h"
#include "AutoGen/FnModels/Market/VyGetFulfillments_Market.h"
#include "AutoGen/FnModels/Market/VyCreateSubUser_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOffers_Market.h"
#include "AutoGen/FnModels/Market/VyApproveOfferMetaTx_Market.h"
#include "AutoGen/FnModels/Market/VyCreateDepositAddressForUserId_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrder_Market.h"
#include "AutoGen/FnModels/Market/VyGetOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetCollections_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserPreferences_Market.h"
#include "AutoGen/FnModels/Market/VyGetDepositAddressesByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyFindHotOffers_Market.h"
#include "AutoGen/FnModels/Market/VyCancelOffer_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateFulfillmentAssociation_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrderByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyGetDepositAddresses_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOffersByUserId_Market.h"
#include "Models/VyCoreModels.h"
#include "AutoGen/FnModels/Market/VyBidOnOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetFulfillment_Market.h"
#include "AutoGen/FnModels/Market/VyGetRoles_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateOrder_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateUserPreferences_Market.h"
#include "AutoGen/FnModels/Market/VyCreateAuctionOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserFulfillments_Market.h"
#include "AutoGen/FnModels/Market/VyCreateOrder_Market.h"
#include "AutoGen/FnModels/Market/VyPurchaseOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetCreditHistory_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrders_Market.h"
#include "AutoGen/FnModels/Market/VyPrepareOfferTransaction_Market.h"
#include "AutoGen/FnModels/Market/VyTerminateOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetFees_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrdersByUserId_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserProfile_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserOrderWithdrawalMax_Market.h"
#include "AutoGen/FnModels/Market/VyCreateDepositAddress_Market.h"
#include "AutoGen/FnModels/Market/VyCreateSaleOffer_Market.h"
#include "AutoGen/FnModels/Market/VyGetCreditBalance_Market.h"
#include "AutoGen/FnModels/Market/VyUpdateOffer_Market.h"
#include "AutoGen/FnModels/Market/VyApproveOfferTx_Market.h"
#include "AutoGen/FnModels/Market/VyGetUsers_Market.h"


#include "VyMarketAPI_BP.generated.h"

class UVyCore;
UCLASS(NotBlueprintType)
class VENLY_API UVyMarketAPI_BP : public UEngineSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	public:
	
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Venly|Market")
	static UVyMarketAPI_BP* Get() { return GEngine->GetEngineSubsystem<UVyMarketAPI_BP>(); }
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserPreferences(const FVyOnGetUserPreferencesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void UpdateUserPreferences(const FVyUpdateUserPreferencesRequest& Params, const FVyOnUpdateUserPreferencesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void ApproveOfferMetaTx(FString OfferId, const FVyApproveOfferMetaTxRequest& Params, const FVyOnApproveOfferMetaTxCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetUsers(const FVyQuery_GetUsers& Query, const FVyOnGetUsersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CreateSubUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateSubUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetDepositAddressesByUserId(FString UserId, const FVyOnGetDepositAddressesByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CreateDepositAddressForUserId(FString UserId, const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressForUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetDepositAddresses(const FVyOnGetDepositAddressesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CreateDepositAddress(const FVyCreateDepositAddressRequest& Params, const FVyOnCreateDepositAddressCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CreateOrder(const FVyCreateOrderRequest& Params, const FVyOnCreateOrderCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CancelOrder(FString OrderId, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CheckPayment(FString Id, const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetOffers(const FVyQuery_GetOffers& Query, const FVyOnGetOffersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CreateAuctionOffer(const FVyAuctionOfferRequest& Params, const FVyOnCreateAuctionOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CreateSaleOffer(const FVySaleOfferRequest& Params, const FVyOnCreateSaleOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void BidOnOffer(FString Id, const FVyBidRequest& Params, const FVyOnBidOnOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetFulfillments(const FVyQuery_GetFulfillments& Query, const FVyOnGetFulfillmentsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void TerminateOffer(const FVyTerminateOfferRequest& Params, const FVyOnTerminateOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void PurchaseOffer(const FVyPurchaseOfferRequest& Params, const FVyOnPurchaseOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void CancelOffer(const FVyCancelOfferRequest& Params, const FVyOnCancelOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetCollections(const FVyQuery_GetCollections& Query, const FVyOnGetCollectionsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void UpdateOrder(FString OrderId, const FVyUpdateOrderRequest& Params, const FVyOnUpdateOrderCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetOffer(FString Id, const FVyOnGetOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void UpdateOffer(FString Id, const FVyUpdateOfferRequest& Params, const FVyOnUpdateOfferCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void ApproveOfferTx(FString Id, const FVyApproveOfferTxRequest& Params, const FVyOnApproveOfferTxCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void AddOfferSignature(FString Id, const FVyAddOfferSignatureRequest& Params, const FVyOnAddOfferSignatureCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void UpdateFulfillmentAssociation(const FVyUpdateFulfillmentAssociationRequest& Params, const FVyOnUpdateFulfillmentAssociationCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserOrdersByUserId(FString UserId, const FVyOnGetUserOrdersByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserOrderByUserId(FString UserId, FString OrderId, const FVyOnGetUserOrderByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetUserOffersByUserId(FString UserId, const FVyQuery_GetUserOffersByUserId& Query, const FVyOnGetUserOffersByUserIdCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetCreditBalance(FString UserId, const FVyQuery_GetCreditBalance& Query, const FVyOnGetCreditBalanceCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserProfile(FString Id, const FVyOnGetUserProfileCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetRoles(const FVyOnGetRolesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserOrders(const FVyOnGetUserOrdersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserOrder(FString OrderId, const FVyOnGetUserOrderCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetUserOrderWithdrawalMax(const FVyOnGetUserOrderWithdrawalMaxCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetUserOffers(const FVyQuery_GetUserOffers& Query, const FVyOnGetUserOffersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetUserFulfillments(const FVyQuery_GetUserFulfillments& Query, const FVyOnGetUserFulfillmentsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetCreditBalances(const FVyQuery_GetCreditBalances& Query, const FVyOnGetCreditBalancesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void GetCreditHistory(EVyCurrencyType Currency, const FVyQuery_GetCreditHistory& Query, const FVyOnGetCreditHistoryCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void ClaimDailyReward(const FVyOnCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetSupportedMarketChains(const FVyOnGetSupportedMarketChainsCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void PrepareOfferTransaction(FString Id, const FVyQuery_PrepareOfferTransaction& Query, const FVyOnPrepareOfferTransactionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market", meta=(AutoCreateRefTerm="Query"))
	void FindHotOffers(const FVyQuery_FindHotOffers& Query, const FVyOnFindHotOffersCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetFulfillment(FString Id, const FVyOnGetFulfillmentCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetWithdrawalFees(EVyChain Chain, const FVyOnGetWithdrawalFeesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetFees(EVyChain Chain, FString ContractAddress, const FVyOnGetFeesCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Venly|Market")
	void GetCollection(FString PublicId, const FVyOnGetCollectionCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	
	
	private:
	UPROPERTY()
	UVyCore* VenlyCore;
	
	const EVyApiEndpoint ApiEndpoint{ EVyApiEndpoint::Market };
};