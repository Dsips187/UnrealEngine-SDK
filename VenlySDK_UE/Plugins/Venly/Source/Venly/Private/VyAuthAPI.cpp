// Fill out your copyright notice in the Description page of Project Settings.


#include "VyAuthAPI.h"
#include "VyCore.h"

void UVyAuthAPI::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	VenlyCore = Cast<UVyCore>(Collection.InitializeDependency(UVyCore::StaticClass()));
}

void UVyAuthAPI::CPP_GetAuthToken(const FString& ClientId, const FString& ClientSecret,	const FVyOnGetAuthTokenComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		EVyApiEndpoint::Auth,
		TEXT("/auth/realms/Arkane/protocol/openid-connect/token"),
		false,
		false);

	const auto FormData = TMap<FString, FString>{
{TEXT("grant_type"), TEXT("client_credentials")},
{TEXT("client_id"), ClientId},
{TEXT("client_secret"), ClientSecret}	};
	Context.AddFormContent(FormData);

	VenlyCore->ExecuteRequest<FVyGetAuthTokenResponse, FVyAuthToken, FVyOnGetAuthTokenComplete>(Context, OnComplete);
}

void UVyAuthAPI::CPP_GetAuthToken(const FString& ClientId, const FString& ClientSecret, EVyEnvironment Environment,	const FVyOnGetAuthTokenComplete& OnComplete) const
{
	auto Context = FVyRequestContext::POST(
		EVyApiEndpoint::Auth,
		TEXT("/auth/realms/Arkane/protocol/openid-connect/token"),
		false,
		false);

	const auto FormData = TMap<FString, FString>{
{TEXT("grant_type"), TEXT("client_credentials")},
{TEXT("client_id"), ClientId},
{TEXT("client_secret"), ClientSecret} };
	Context.AddFormContent(FormData);

	Context.SetPreferredEnvironment(Environment);

	VenlyCore->ExecuteRequest<FVyGetAuthTokenResponse, FVyAuthToken, FVyOnGetAuthTokenComplete>(Context, OnComplete);
}


void UVyAuthAPI::BP_GetAuthToken(const FString& ClientId, const FString& ClientSecret,
                              const FVyOnGetAuthTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail)
{
	auto Context = FVyRequestContext::POST(
		EVyApiEndpoint::Auth,
		TEXT("/auth/realms/Arkane/protocol/openid-connect/token"),
		false,
		false);

	const auto FormData = TMap<FString, FString>{
{TEXT("grant_type"), TEXT("client_credentials")},
{TEXT("client_id"), ClientId},
{TEXT("client_secret"), ClientSecret} };
	Context.AddFormContent(FormData);

	VenlyCore->ExecuteRequest_BP<FVyGetAuthTokenResponse, FVyAuthToken, FVyOnGetAuthTokenCompleteBP, FVyOnSuccessBP, FVyOnFailBP>(Context, OnComplete, OnSuccess, OnFail);
}
