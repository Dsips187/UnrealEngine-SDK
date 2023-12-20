// Fill out your copyright notice in the Description page of Project Settings.


#include "VyProviderExtensions.h"
#include "VyCore.h"

void UVyProviderExtensions::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyProviderExtensions::BP_HasWallet(const FVyOnHasWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_has_wallet"));
	VenlyCore->ExecuteRequest_BP<FVyHasWalletResponse, bool, FVyOnHasWalletCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context.BaseRequest, OnComplete, OnSuccess, OnFail);
}

void UVyProviderExtensions::CPP_HasWallet(const FVyOnHasWalletComplete& OnComplete) const
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_has_wallet"));
	VenlyCore->ExecuteRequest<FVyHasWalletResponse, bool, FVyOnHasWalletComplete>(Context.BaseRequest, OnComplete);
}

void UVyProviderExtensions::BP_CreateWalletForUser(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_create_wallet"));
	Context.AddJsonContent(Params);
	VenlyCore->ExecuteRequest_BP<FVyCreateWalletResponse, FVyWalletDto, FVyOnCreateWalletForUserCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context.BaseRequest, OnComplete, OnSuccess, OnFail);
}

void UVyProviderExtensions::CPP_CreateWalletForUser(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletForUserComplete& OnComplete) const
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_create_wallet"));
	Context.AddJsonContent(Params);
	VenlyCore->ExecuteRequest<FVyCreateWalletResponse, FVyWalletDto, FVyOnCreateWalletForUserComplete>(Context.BaseRequest, OnComplete);
}

void UVyProviderExtensions::BP_GetWalletForUser(const FVyOnGetWalletForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_get_wallet"));
	VenlyCore->ExecuteRequest_BP<FVyGetWalletResponse, FVyWalletDto, FVyOnGetWalletForUserCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context.BaseRequest, OnComplete, OnSuccess, OnFail);
}

void UVyProviderExtensions::CPP_GetWalletForUser(const FVyOnGetWalletForUserComplete& OnComplete) const
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_get_wallet"));
	VenlyCore->ExecuteRequest<FVyGetWalletResponse, FVyWalletDto, FVyOnGetWalletForUserComplete>(Context.BaseRequest, OnComplete);
}

void UVyProviderExtensions::BP_HasMarketUser(const FVyOnHasMarketUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_has_market_user"));
	VenlyCore->ExecuteRequest_BP<FVyHasMarketUserResponse, bool, FVyOnHasMarketUserCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context.BaseRequest, OnComplete, OnSuccess, OnFail);
}

void UVyProviderExtensions::CPP_HasMarketUser(const FVyOnHasMarketUserComplete& OnComplete) const
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_has_market_user"));
	VenlyCore->ExecuteRequest<FVyHasMarketUserResponse, bool, FVyOnHasMarketUserComplete>(Context.BaseRequest, OnComplete);
}

void UVyProviderExtensions::BP_CreateMarketUserForUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateMarketUserForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_create_market_user"));
	Context.AddJsonContent(Params);
	VenlyCore->ExecuteRequest_BP<FVyCreateSubUserResponse, FVySubUserDto, FVyOnCreateMarketUserForUserCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context.BaseRequest, OnComplete, OnSuccess, OnFail);
}

void UVyProviderExtensions::CPP_CreateMarketUserForUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateMarketUserForUserComplete& OnComplete) const
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_create_market_user"));
	Context.AddJsonContent(Params);
	VenlyCore->ExecuteRequest<FVyCreateSubUserResponse, FVySubUserDto, FVyOnCreateMarketUserForUserComplete>(Context.BaseRequest, OnComplete);
}

void UVyProviderExtensions::BP_GetMarketUserForUser(const FVyOnGetMarketUserForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_get_market_user"));
	VenlyCore->ExecuteRequest_BP<FVyGetUserProfileResponse, FVyUserProfileDto, FVyOnGetMarketUserForUserCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context.BaseRequest, OnComplete, OnSuccess, OnFail);
}

void UVyProviderExtensions::CPP_GetMarketUserForUser(const FVyOnGetMarketUserForUserComplete& OnComplete) const
{
	auto Context = FVyExtensionRequestContext::Create(TEXT("user_get_market_user"));
	VenlyCore->ExecuteRequest<FVyGetUserProfileResponse, FVyUserProfileDto, FVyOnGetMarketUserForUserComplete>(Context.BaseRequest, OnComplete);
}
