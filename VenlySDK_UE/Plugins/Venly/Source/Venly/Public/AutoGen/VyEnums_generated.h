#pragma once
#include "VyEnums_generated.generated.h"

/*
* Chain Enumeration
*/
UENUM(BlueprintType)
enum class EVyChain : uint8
{
	/**Represents a chain that is not supported.*/
	NOT_SUPPORTED UMETA(DisplayName = "NotSupported"),
	/**Represents the Arbitrum chain.*/
	ARBITRUM UMETA(DisplayName = "Arbitrum"),
	/**Represents the Aeternity chain.*/
	AETERNITY UMETA(DisplayName = "Aeternity"),
	/**Represents the Avac chain.*/
	AVAC UMETA(DisplayName = "Avac"),
	/**Represents the Bitcoin chain.*/
	BITCOIN UMETA(DisplayName = "Bitcoin"),
	/**Represents the Bsc chain.*/
	BSC UMETA(DisplayName = "Bsc"),
	/**Represents the Ethereum chain.*/
	ETHEREUM UMETA(DisplayName = "Ethereum"),
	/**Represents the Gochain chain.*/
	GOCHAIN UMETA(DisplayName = "Gochain"),
	/**Represents the Hedera chain.*/
	HEDERA UMETA(DisplayName = "Hedera"),
	/**Represents the Litecoin chain.*/
	LITECOIN UMETA(DisplayName = "Litecoin"),
	/**Represents the Tron chain.*/
	TRON UMETA(DisplayName = "Tron"),
	/**Represents the Vechain chain.*/
	VECHAIN UMETA(DisplayName = "Vechain"),
	/**Represents the Matic chain.*/
	MATIC UMETA(DisplayName = "Matic"),
	/**Represents the Neo chain.*/
	NEO UMETA(DisplayName = "Neo"),
	/**Represents the Imx chain.*/
	IMX UMETA(DisplayName = "Imx"),
};

/*
* Wallet Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyWalletType : uint8
{
	/**Represents an unclaimed wallet.*/
	UNCLAIMED UMETA(DisplayName = "Unclaimed"),
	/**Represents a widget wallet.*/
	WIDGET_WALLET UMETA(DisplayName = "WidgetWallet"),
	/**Represents an API wallet.*/
	API_WALLET UMETA(DisplayName = "ApiWallet"),
};

/*
* Sort Order Enumeration
*/
UENUM(BlueprintType)
enum class EVySortOrder : uint8
{
	/**Represents an ascending sort order.*/
	ASC UMETA(DisplayName = "Asc"),
	/**Represents a descending sort order.*/
	DESC UMETA(DisplayName = "Desc"),
};

/*
* Wallet Import Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyWalletImportType : uint8
{
	/**Represents an Aeternity keystore wallet import type.*/
	AETERNITY_KEYSTORE UMETA(DisplayName = "AeternityKeystore"),
	/**Represents an Aeternity private key wallet import type.*/
	AETERNITY_PRIVATE_KEY UMETA(DisplayName = "AeternityPrivateKey"),
	/**Represents a Binance Smart Chain keystore wallet import type.*/
	BSC_KEYSTORE UMETA(DisplayName = "BscKeystore"),
	/**Represents a Binance Smart Chain private key wallet import type.*/
	BSC_PRIVATE_KEY UMETA(DisplayName = "BscPrivateKey"),
	/**Represents an Avalanche keystore wallet import type.*/
	AVAC_KEYSTORE UMETA(DisplayName = "AvacKeystore"),
	/**Represents an Avalanche private key wallet import type.*/
	AVAC_PRIVATE_KEY UMETA(DisplayName = "AvacPrivateKey"),
	/**Represents an Ethereum keystore wallet import type.*/
	ETHEREUM_KEYSTORE UMETA(DisplayName = "EthereumKeystore"),
	/**Represents a Polygon (Matic) keystore wallet import type.*/
	MATIC_KEYSTORE UMETA(DisplayName = "MaticKeystore"),
	/**Represents an Ethereum private key wallet import type.*/
	ETHEREUM_PRIVATE_KEY UMETA(DisplayName = "EthereumPrivateKey"),
	/**Represents a Polygon (Matic) private key wallet import type.*/
	MATIC_PRIVATE_KEY UMETA(DisplayName = "MaticPrivateKey"),
	/**Represents a GoChain keystore wallet import type.*/
	GOCHAIN_KEYSTORE UMETA(DisplayName = "GochainKeystore"),
	/**Represents a GoChain private key wallet import type.*/
	GOCHAIN_PRIVATE_KEY UMETA(DisplayName = "GochainPrivateKey"),
	/**Represents a Hedera keystore wallet import type.*/
	HEDERA_KEYSTORE UMETA(DisplayName = "HederaKeystore"),
	/**Represents a Hedera private key wallet import type.*/
	HEDERA_PRIVATE_KEY UMETA(DisplayName = "HederaPrivateKey"),
	/**Represents a VeChain private key wallet import type.*/
	VECHAIN_PRIVATE_KEY UMETA(DisplayName = "VechainPrivateKey"),
	/**Represents a VeChain keystore wallet import type.*/
	VECHAIN_KEYSTORE UMETA(DisplayName = "VechainKeystore"),
	/**Represents a Bitcoin WIF (Wallet Import Format) wallet import type.*/
	BITCOIN_WIF UMETA(DisplayName = "BitcoinWif"),
	/**Represents a Bitcoin WIF (Wallet Import Format) with passphrase wallet import type.*/
	BITCOIN_WIF_PASSPHRASE UMETA(DisplayName = "BitcoinWifPassphrase"),
	/**Represents a Litecoin WIF (Wallet Import Format) wallet import type.*/
	LITECOIN_WIF UMETA(DisplayName = "LitecoinWif"),
	/**Represents a NEO keystore wallet import type.*/
	NEO_KEYSTORE UMETA(DisplayName = "NeoKeystore"),
	/**Represents a NEO private key wallet import type.*/
	NEO_PRIVATE_KEY UMETA(DisplayName = "NeoPrivateKey"),
	/**Represents a NEO WIF (Wallet Import Format) wallet import type.*/
	NEO_WIF UMETA(DisplayName = "NeoWif"),
	/**Represents an IMX keystore wallet import type.*/
	IMX_KEYSTORE UMETA(DisplayName = "ImxKeystore"),
	/**Represents an IMX private key wallet import type.*/
	IMX_PRIVATE_KEY UMETA(DisplayName = "ImxPrivateKey"),
	/**Represents a migration wallet import type.*/
	MIGRATION UMETA(DisplayName = "Migration"),
};

/*
* Signature Type Enumeration
*/
UENUM(BlueprintType)
enum class EVySignatureType : uint8
{
	/**Represents a signature in hexadecimal format.*/
	HEX_SIGNATURE UMETA(DisplayName = "HexSignature"),
	/**Represents a signature for a submitted and signed transaction.*/
	SUBMITTED_AND_SIGNED_TRANSACTION_SIGNATURE UMETA(DisplayName = "SubmittedAndSignedTransactionSignature"),
	/**Represents a signature for a transaction.*/
	TRANSACTION_SIGNATURE UMETA(DisplayName = "TransactionSignature"),
	/**Represents a raw signature.*/
	RAW_SIGNATURE UMETA(DisplayName = "RawSignature"),
};

/*
* Token Attribute Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyTokenAttributeType : uint8
{
	/**Represents a token attribute related to statistics.*/
	stat UMETA(DisplayName = "Stat"),
	/**Represents a token attribute related to properties.*/
	property UMETA(DisplayName = "Property"),
	/**Represents a token attribute related to boosts.*/
	boost UMETA(DisplayName = "Boost"),
	/**Represents a token attribute related to systems.*/
	system UMETA(DisplayName = "System"),
};

/*
* Wallet Event Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyWalletEventType : uint8
{
	/**Represents the creation of a wallet.*/
	WALLET_CREATED UMETA(DisplayName = "WalletCreated"),
	/**Represents the creation of an unclaimed email wallet.*/
	UNCLAIMED_EMAIL_WALLET_CREATED UMETA(DisplayName = "UnclaimedEmailWalletCreated"),
	/**Represents the creation of an unclaimed wallet.*/
	UNCLAIMED_WALLET_CREATED UMETA(DisplayName = "UnclaimedWalletCreated"),
	/**Represents the creation of a signature.*/
	SIGNATURE_CREATED UMETA(DisplayName = "SignatureCreated"),
	/**Represents an incoming transaction.*/
	INCOMING_TRANSACTION UMETA(DisplayName = "IncomingTransaction"),
	/**Represents an outgoing transaction.*/
	OUTGOING_TRANSACTION UMETA(DisplayName = "OutgoingTransaction"),
	/**Represents the import of a wallet.*/
	WALLET_IMPORTED UMETA(DisplayName = "WalletImported"),
	/**Represents the linking of a wallet.*/
	WALLET_LINKED UMETA(DisplayName = "WalletLinked"),
	/**Represents the unlinking of a wallet.*/
	WALLET_UNLINKED UMETA(DisplayName = "WalletUnlinked"),
	/**Represents the archiving of a wallet.*/
	WALLET_ARCHIVED UMETA(DisplayName = "WalletArchived"),
	/**Represents the unarchiving of a wallet.*/
	WALLET_UNARCHIVED UMETA(DisplayName = "WalletUnarchived"),
	/**Represents a recoverable wallet.*/
	WALLET_RECOVERABLE UMETA(DisplayName = "WalletRecoverable"),
	/**Represents the export of a wallet.*/
	WALLET_EXPORTED UMETA(DisplayName = "WalletExported"),
	/**Represents an unrecoverable wallet.*/
	WALLET_UNRECOVERABLE UMETA(DisplayName = "WalletUnrecoverable"),
	/**Represents the addition of an API key to a wallet.*/
	WALLET_API_KEY_ADDED UMETA(DisplayName = "WalletApiKeyAdded"),
	/**Represents the removal of an API key from a wallet.*/
	WALLET_API_KEY_REMOVED UMETA(DisplayName = "WalletApiKeyRemoved"),
	/**Represents the update of a master PIN.*/
	MASTER_PIN_UPDATED UMETA(DisplayName = "MasterPinUpdated"),
	/**Represents the update of a custom PIN.*/
	CUSTOM_PIN_UPDATED UMETA(DisplayName = "CustomPinUpdated"),
	/**Represents the addition of a custom PIN.*/
	CUSTOM_PIN_ADDED UMETA(DisplayName = "CustomPinAdded"),
	/**Represents the removal of a custom PIN.*/
	CUSTOM_PIN_REMOVED UMETA(DisplayName = "CustomPinRemoved"),
	/**Represents the claiming of a wallet.*/
	WALLET_CLAIMED UMETA(DisplayName = "WalletClaimed"),
	/**Represents the entry of a wrong PIN.*/
	WRONG_PIN_ENTERED UMETA(DisplayName = "WrongPinEntered"),
	/**Represents the reaching of the maximum number of PIN tries.*/
	PIN_MAX_TRIES_REACHED UMETA(DisplayName = "PinMaxTriesReached"),
	/**Represents the successful validation of a PIN.*/
	PIN_SUCCESSFULLY_VALIDATED UMETA(DisplayName = "PinSuccessfullyValidated"),
};

/*
* Transaction State Enumeration
*/
UENUM(BlueprintType)
enum class EVyTransactionState : uint8
{
	/**Represents an unknown transaction state.*/
	UNKNOWN UMETA(DisplayName = "Unknown"),
	/**Represents a pending transaction state.*/
	PENDING UMETA(DisplayName = "Pending"),
	/**Represents a failed transaction state.*/
	FAILED UMETA(DisplayName = "Failed"),
	/**Represents a succeeded transaction state.*/
	SUCCEEDED UMETA(DisplayName = "Succeeded"),
};

/*
* Order Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyOrderType : uint8
{
	/**Represents a sell order.*/
	SELL UMETA(DisplayName = "Sell"),
	/**Represents a buy order.*/
	BUY UMETA(DisplayName = "Buy"),
};

/*
* Exchange Enumeration
*/
UENUM(BlueprintType)
enum class EVyExchange : uint8
{
	/**Represents the AvaxWavax exchange.*/
	AVAX_WAVAX UMETA(DisplayName = "AvaxWavax"),
	/**Represents the BscWbnb exchange.*/
	BSC_WBNB UMETA(DisplayName = "BscWbnb"),
	/**Represents the Vexchange exchange.*/
	VEXCHANGE UMETA(DisplayName = "Vexchange"),
	/**Represents the Uniswap exchange.*/
	UNISWAP UMETA(DisplayName = "Uniswap"),
	/**Represents the Totle exchange.*/
	TOTLE UMETA(DisplayName = "Totle"),
	/**Represents the OneInch exchange.*/
	ONE_INCH UMETA(DisplayName = "OneInch"),
};

/*
* Currency Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyCurrencyType : uint8
{
	/**Represents the USDC currency.*/
	USDC UMETA(DisplayName = "Usdc"),
	/**Represents the VENS currency.*/
	VENS UMETA(DisplayName = "Vens"),
};

/*
* Verification State Enumeration
*/
UENUM(BlueprintType)
enum class EVyVerificationState : uint8
{
	/**Represents a verified state.*/
	VERIFIED UMETA(DisplayName = "Verified"),
	/**Represents a state with no verification.*/
	NO_VERIFICATION UMETA(DisplayName = "NoVerification"),
	/**Represents a state indicating fraud.*/
	FRAUD UMETA(DisplayName = "Fraud"),
};

/*
* Offer Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyOfferType : uint8
{
	/**Represents an auction offer.*/
	AUCTION UMETA(DisplayName = "Auction"),
	/**Represents a sale offer.*/
	SALE UMETA(DisplayName = "Sale"),
};

/*
* Offer State Enumeration
*/
UENUM(BlueprintType)
enum class EVyOfferState : uint8
{
	/**Represents a new offer state.*/
	NEW UMETA(DisplayName = "New"),
	/**Represents a waiting for association offer state.*/
	WAITING_FOR_ASSOCIATION UMETA(DisplayName = "WaitingForAssociation"),
	/**Represents an initiating offer state.*/
	INITIATING_OFFER UMETA(DisplayName = "InitiatingOffer"),
	/**Represents a ready offer state.*/
	READY UMETA(DisplayName = "Ready"),
	/**Represents a refused offer state.*/
	REFUSED UMETA(DisplayName = "Refused"),
	/**Represents a closed offer state.*/
	CLOSED UMETA(DisplayName = "Closed"),
	/**Represents a terminated offer state.*/
	TERMINATED UMETA(DisplayName = "Terminated"),
	/**Represents an error offer state.*/
	ERROR UMETA(DisplayName = "Error"),
};

/*
* Visibility Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyVisibilityType : uint8
{
	/**Represents a public visibility type.*/
	PUBLIC UMETA(DisplayName = "Public"),
	/**Represents an unlisted visibility type.*/
	UNLISTED UMETA(DisplayName = "Unlisted"),
	/**Represents a private visibility type.*/
	PRIVATE UMETA(DisplayName = "Private"),
};

/*
* User Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyUserType : uint8
{
	/**Represents a sub user.*/
	SUB_USER UMETA(DisplayName = "SubUser"),
};

/*
* Trading Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyTradingType : uint8
{
	/**Represents a deposit transaction.*/
	DEPOSIT UMETA(DisplayName = "Deposit"),
	/**Represents a withdrawal transaction.*/
	WITHDRAWAL UMETA(DisplayName = "Withdrawal"),
};

/*
* Order State Enumeration
*/
UENUM(BlueprintType)
enum class EVyOrderState : uint8
{
	/**Represents an approved order.*/
	APPROVED UMETA(DisplayName = "Approved"),
	/**Represents an order that is requesting approval.*/
	REQUESTING_APPROVAL UMETA(DisplayName = "RequestingApproval"),
	/**Represents a pending order.*/
	PENDING UMETA(DisplayName = "Pending"),
	/**Represents a paid order.*/
	PAID UMETA(DisplayName = "Paid"),
	/**Represents a completed order.*/
	COMPLETED UMETA(DisplayName = "Completed"),
	/**Represents a failed order.*/
	FAILED UMETA(DisplayName = "Failed"),
	/**Represents a canceled order.*/
	CANCELED UMETA(DisplayName = "Canceled"),
	/**Represents an order that is waiting for funds.*/
	WAITING_FOR_FUNDS UMETA(DisplayName = "WaitingForFunds"),
};

/*
* Fulfillment State Enumeration
*/
UENUM(BlueprintType)
enum class EVyFulfillmentState : uint8
{
	/**Represents a queued fulfillment state.*/
	QUEUED UMETA(DisplayName = "Queued"),
	/**Represents a processing fulfillment state.*/
	PROCESSING UMETA(DisplayName = "Processing"),
	/**Represents a completed fulfillment state.*/
	COMPLETED UMETA(DisplayName = "Completed"),
	/**Represents an error fulfillment state.*/
	ERROR UMETA(DisplayName = "Error"),
	/**Represents a fulfillment state waiting for association.*/
	WAITING_FOR_ASSOCIATION UMETA(DisplayName = "WaitingForAssociation"),
};

/*
* Fulfillment Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyFulfillmentType : uint8
{
	/**Represents a reimbursement fulfillment.*/
	REIMBURSEMENT UMETA(DisplayName = "Reimbursement"),
	/**Represents a termination fulfillment.*/
	TERMINATION UMETA(DisplayName = "Termination"),
	/**Represents a purchase fulfillment.*/
	PURCHASE UMETA(DisplayName = "Purchase"),
};

/*
* Collection Source Enumeration
*/
UENUM(BlueprintType)
enum class EVyCollectionSource : uint8
{
	/**Represents a collection source from content management.*/
	CONTENT_MANAGEMENT UMETA(DisplayName = "ContentManagement"),
	/**Represents a generated collection source.*/
	GENERATED UMETA(DisplayName = "Generated"),
};

/*
* Relation Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyRelationType : uint8
{
	/**Represents a buyer.*/
	BUYER UMETA(DisplayName = "Buyer"),
	/**Represents a seller.*/
	SELLER UMETA(DisplayName = "Seller"),
	/**Represents a bidder.*/
	BIDDER UMETA(DisplayName = "Bidder"),
};

/*
* Credit History Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyCreditHistoryType : uint8
{
	/**Represents a deposit transaction.*/
	DEPOSIT UMETA(DisplayName = "Deposit"),
	/**Represents a withdrawal transaction.*/
	WITHDRAWAL UMETA(DisplayName = "Withdrawal"),
	/**Represents a purchase transaction.*/
	PURCHASE UMETA(DisplayName = "Purchase"),
	/**Represents a market fee transaction.*/
	MARKET_FEE UMETA(DisplayName = "MarketFee"),
	/**Represents a contract owner fee transaction.*/
	CONTRACT_OWNER_FEE UMETA(DisplayName = "ContractOwnerFee"),
	/**Represents a sell transaction.*/
	SELL UMETA(DisplayName = "Sell"),
	/**Represents a commission transaction.*/
	COMMISSION UMETA(DisplayName = "Commission"),
	/**Represents a genesis transaction.*/
	GENESIS UMETA(DisplayName = "Genesis"),
	/**Represents a reward for buying an offer.*/
	OFFER_BOUGHT_REWARD UMETA(DisplayName = "OfferBoughtReward"),
	/**Represents a reward for placing a bid.*/
	BID_PLACED_REWARD UMETA(DisplayName = "BidPlacedReward"),
	/**Represents a reward for selling an offer.*/
	OFFER_SOLD_REWARD UMETA(DisplayName = "OfferSoldReward"),
	/**Represents a reward for making a deposit.*/
	DEPOSIT_REWARD UMETA(DisplayName = "DepositReward"),
	/**Represents a reward for a verified listing.*/
	VERIFIED_LISTING_REWARD UMETA(DisplayName = "VerifiedListingReward"),
	/**Represents a transaction fee for creating an offer.*/
	OFFER_CREATED_TX_FEE UMETA(DisplayName = "OfferCreatedTxFee"),
	/**Represents a daily VENS reward.*/
	DAILY_VENS_REWARD UMETA(DisplayName = "DailyVensReward"),
	/**Represents a credit from the reward pool.*/
	REWARD_POOL_CREDIT UMETA(DisplayName = "RewardPoolCredit"),
	/**Represents a community reward.*/
	COMMUNITY_REWARD UMETA(DisplayName = "CommunityReward"),
};

/*
* Reference Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyReferenceType : uint8
{
	/**Represents a fulfillment reference.*/
	FULFILLMENT UMETA(DisplayName = "Fulfillment"),
	/**Represents an offer reference.*/
	OFFER UMETA(DisplayName = "Offer"),
	/**Represents an order reference.*/
	ORDER UMETA(DisplayName = "Order"),
	/**Represents a reward campaign reference.*/
	REWARD_CAMPAIGN UMETA(DisplayName = "RewardCampaign"),
	/**Represents no reference.*/
	NONE UMETA(DisplayName = "None"),
};

/*
* Credit History Fee Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyCreditHistoryFeeType : uint8
{
	/**Represents a deposit fee.*/
	DEPOSIT UMETA(DisplayName = "Deposit"),
	/**Represents a withdrawal fee.*/
	WITHDRAWAL UMETA(DisplayName = "Withdrawal"),
	/**Represents a purchase fee.*/
	PURCHASE UMETA(DisplayName = "Purchase"),
	/**Represents a market fee.*/
	MARKET_FEE UMETA(DisplayName = "MarketFee"),
	/**Represents a contract owner fee.*/
	CONTRACT_OWNER_FEE UMETA(DisplayName = "ContractOwnerFee"),
	/**Represents a genesis fee.*/
	GENESIS UMETA(DisplayName = "Genesis"),
	/**Represents a reward for buying an offer.*/
	OFFER_BOUGHT_REWARD UMETA(DisplayName = "OfferBoughtReward"),
	/**Represents a reward for placing a bid.*/
	BID_PLACED_REWARD UMETA(DisplayName = "BidPlacedReward"),
	/**Represents a reward for selling an offer.*/
	OFFER_SOLD_REWARD UMETA(DisplayName = "OfferSoldReward"),
	/**Represents a reward for depositing.*/
	DEPOSIT_REWARD UMETA(DisplayName = "DepositReward"),
	/**Represents a reward for a verified listing.*/
	VERIFIED_LISTING_REWARD UMETA(DisplayName = "VerifiedListingReward"),
	/**Represents a fee for creating an offer transaction.*/
	OFFER_CREATED_TX_FEE UMETA(DisplayName = "OfferCreatedTxFee"),
	/**Represents a daily VENS reward.*/
	DAILY_VENS_REWARD UMETA(DisplayName = "DailyVensReward"),
	/**Represents a credit to the reward pool.*/
	REWARD_POOL_CREDIT UMETA(DisplayName = "RewardPoolCredit"),
	/**Represents a community reward.*/
	COMMUNITY_REWARD UMETA(DisplayName = "CommunityReward"),
};

/*
* Credit History State Enumeration
*/
UENUM(BlueprintType)
enum class EVyCreditHistoryState : uint8
{
	/**Represents a pending credit history state.*/
	PENDING UMETA(DisplayName = "Pending"),
	/**Represents a failed credit history state.*/
	FAILED UMETA(DisplayName = "Failed"),
	/**Represents a successful credit history state.*/
	SUCCESS UMETA(DisplayName = "Success"),
};

/*
* Company Wallet Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyCompanyWalletType : uint8
{
	/**Represents a deployer wallet.*/
	DEPLOYER UMETA(DisplayName = "Deployer"),
	/**Represents a funder wallet.*/
	FUNDER UMETA(DisplayName = "Funder"),
	/**Represents a company minter wallet.*/
	COMPANY_MINTER UMETA(DisplayName = "CompanyMinter"),
	/**Represents a minter wallet.*/
	MINTER UMETA(DisplayName = "Minter"),
};

/*
* Storage Type Enumeration
*/
UENUM(BlueprintType)
enum class EVyStorageType : uint8
{
	/**Represents cloud storage.*/
	CLOUD UMETA(DisplayName = "Cloud"),
	/**Represents IPFS storage.*/
	IPFS UMETA(DisplayName = "Ipfs"),
	/**Represents custom storage.*/
	CUSTOM UMETA(DisplayName = "Custom"),
};
