// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/VyRequestUtils.h"

#include "HttpModule.h"
#include "VyCore.h"
#include "VyCoreModels.h"
#include "VyOptional.h"
#include "Kismet/GameplayStatics.h"

TMap<EVyApiEndpoint, FString> VyRequestUtils::SandboxURLs = {
	{EVyApiEndpoint::Auth, TEXT("https://login-staging.venly.io")},
	{EVyApiEndpoint::Wallet, TEXT("https://api-wallet-staging.venly.io")},
	{EVyApiEndpoint::Nft, TEXT("https://api-business-staging.venly.io")},
	{EVyApiEndpoint::Market, TEXT("https://api-staging.venly.market")},
};

TMap<EVyApiEndpoint, FString> VyRequestUtils::ProductionURLs = {
	{EVyApiEndpoint::Auth, TEXT("https://login.venly.io")},
	{EVyApiEndpoint::Wallet, TEXT("https://api-wallet.venly.io")},
	{EVyApiEndpoint::Nft, TEXT("https://api-business.venly.io")},
	{EVyApiEndpoint::Market, TEXT("https://api.venly.market")},
};

FString VyRequestUtils::ResolveEndpointURL(const FVyRequestContext& Context)
{
	if (Context.ApiEndpoint == EVyApiEndpoint::None) return TEXT("");
	if (Context.ApiEndpoint == EVyApiEndpoint::Extension) return Context.Route;

	auto targetEnvironment = UVyCore::GetEnvironment();
	if (Context.UsePreferredEnvironment)
	{
		targetEnvironment = Context.PreferredEnvironment;
	}

	const auto baseURL = targetEnvironment == EVyEnvironment::Sandbox
		? SandboxURLs[Context.ApiEndpoint]
		: ProductionURLs[Context.ApiEndpoint];

	if (Context.Query.IsEmpty()) return FString::Format(TEXT("{0}{1}"), { *baseURL, *Context.Route });
	return FString::Format(TEXT("{0}{1}?{2}"), { *baseURL, *Context.Route, *Context.Query });
}

void VyRequestUtils::FVyQueryToString(const UStruct* QueryStructDefinition, const void* QueryStruct, FString& OutQueryString)
{
	check(QueryStructDefinition->IsChildOf(FVyQuery::StaticStruct()))

		bool isFirstParam = true;
	const auto baseQuery = static_cast<const FVyQuery*>(QueryStruct);
	for (TFieldIterator<FProperty> It(QueryStructDefinition); It; ++It)
	{
		const FProperty* Property = *It;
		const auto OptionalProperty = Property->ContainerPtrToValuePtr<FVyOptional>(QueryStruct);

		if (OptionalProperty->IsSet)
		{
			FString QueryName = baseQuery->GetQueryName(Property);
			FString QueryValue{};
			if(!OptionalProperty->ToString(QueryValue))
			{
				UE_LOG(LogVenlyBackend, Error, TEXT("VyQueryToString >> Failed to create string representation for Query Parameter \'%s\'"), *QueryName)
				continue;
			}

			if (!isFirstParam) OutQueryString += TEXT("&");
			OutQueryString += FString::Printf(TEXT("%s=%s"), *QueryName, *QueryValue);
			isFirstParam = false;
		}
	}
}

TUnrealRequestPtr VyRequestUtils::CreateHttpRequest(FVyRequestContext& Context)
{
	Context.State = EVyRequestState::Initiating;

	const auto NewRequest = FHttpModule::Get().CreateRequest();

	NewRequest->SetHeader(TEXT("X-KS-USER-AGENT"), FString::Printf(TEXT("Unreal-%s"), *UGameplayStatics::GetPlatformName()));

	if (Context.ContentType == EVyHttpContentType::Json)
		NewRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	else if (Context.ContentType == EVyHttpContentType::Form)
		NewRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));

	NewRequest->SetHeader(TEXT("Accept"), TEXT("application/json"));

	NewRequest->SetVerb(Context.Verb);
	NewRequest->SetURL(VyRequestUtils::ResolveEndpointURL(Context));

	if (Context.ContentType != EVyHttpContentType::None)
		NewRequest->SetContentAsString(Context.Content);

	return NewRequest;
}
