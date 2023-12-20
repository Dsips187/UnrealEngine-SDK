// Fill out your copyright notice in the Description page of Project Settings.


#include "VyCore.h"

//#include "Editor.h"
#include "HttpManager.h"
#include "HttpModule.h"
#include "VyEditorSettings.h"
#include "VyProjectSettings.h"
#include "VyEnums.h"
#include "VyProviderManager.h"
#include "VyProvider_DevMode.h"
#include "VyProvider_Public.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/VyUtils.h"

class UVyProjectSettings;
EVyEnvironment UVyCore::CurrentEnvironment = EVyEnvironment::Sandbox;
EVyProviderType UVyCore::CurrentProviderType = EVyProviderType::None;

void UVyCore::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Collection.InitializeDependency<UVyProviderManager>();

	InFlightRequestIdCounter = new long();
	*InFlightRequestIdCounter = -1;

	////Retrieve Environment
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	CurrentEnvironment = projectSettings->Environment;
	CurrentProviderType = projectSettings->ProviderType;

	//Create Provider
	CreateProvider(CurrentProviderType);

	//Create Public Provider (Unauthorized Requests)
	PublicProvider = NewObject<UVyProvider_Public>(this);
	PublicProvider->Initialize();

	UE_LOG(LogVenlyBackend, Log, TEXT("BackendCore Initialized (%s)"), *UEnum::GetValueAsString(CurrentEnvironment))
}

void UVyCore::Deinitialize()
{
	Super::Deinitialize();

	delete InFlightRequestIdCounter;
}

void UVyCore::BeginPlay()
{
#if WITH_EDITOR
	//This is to ensure that the correct provider/environment is used (based on settings) inside the editor
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	CurrentEnvironment = projectSettings->Environment;

	const auto DesiredProvider = projectSettings->ProviderType;
	if(DesiredProvider != CurrentProviderType || Provider == nullptr)
	{
		CreateProvider(DesiredProvider);
	}

	UE_LOG(LogVenlyBackend, Log, TEXT("Venly API Ready (Env=%s | Provider=%s)"), *VyUtils::EnumToString(CurrentEnvironment), *VyUtils::EnumToString(CurrentProviderType))
#endif
}

void UVyCore::EndPlay()
{
	//Clean Up Provider
	if(Provider != nullptr)
	{
		Provider->Deinitialize();
		Provider->MarkAsGarbage();
	}

	Provider = nullptr;
	CurrentProviderType = EVyProviderType::None;

	//Signal Provider Manager (EndPlay)
	UVyProviderManager::GetSelf()->EndPlay();
}

void UVyCore::SignalRequestComplete(FVyRequestId RequestId)
{
	SetRequestState(RequestId, EVyRequestState::Complete);
	if (Provider) Provider->OnRequestComplete(RequestId);

	if(InFlightRequestContexts.Contains(RequestId))
	{
		InFlightRequestContexts.Remove(RequestId);
	}

	UE_LOG(LogVenlyBackend, Log, TEXT("Request COMPLETE (ID=%lld)"), RequestId)
}

void UVyCore::ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete) const
{
	if (Context.RequiresAuth) 
	{
		if(!HasProvider)
		{
			Context.ResponseEnveloped = true; //ensure the response is parsed as an enveloped response
			OnComplete.ExecuteIfBound(VyResponseUtils::CreateResponseContext_Failure(TEXT("NO_PROVIDER"), TEXT("Failed to execute the request, there is no provider initialized to execute authenticated requests.")));
			return;
		}

		Provider->ProcessRequest(Context, OnComplete);
	}
	else 
	{
		//No Auth required, use Public Provider
		PublicProvider->ProcessRequest(Context, OnComplete);
	}
}

const FVyRequestContext& UVyCore::GetRequestContext(FVyRequestId RequestId)
{
	checkf(InFlightRequestContexts.Contains(RequestId), TEXT("Backend does not contain a RequestContext with ID=%lld"), RequestId)
	return InFlightRequestContexts[RequestId];
}

FVyRequestContext& UVyCore::GetRequestContextRef(FVyRequestId RequestId)
{
	checkf(InFlightRequestContexts.Contains(RequestId), TEXT("Backend does not contain a RequestContext with ID=%lld"), RequestId)
	return InFlightRequestContexts[RequestId];
}

void UVyCore::RegisterRequestContext(FVyRequestContext& Context)
{
	checkf(Context.Id == -1, TEXT("VyBackendCore::RegisterRequestContext - Context has a valid ID already!"))
	Context.Id = _InterlockedIncrement(InFlightRequestIdCounter);

	UE_LOG(LogVenlyBackend, Log, TEXT("Request REGISTERED (ID=%lld | Verb=%s | Api=%s | Route=%s | Content=%s)"), Context.Id, *Context.Verb, *UEnum::GetValueAsString(Context.ApiEndpoint), *Context.Route, *Context.Content)
	InFlightRequestContexts.Add(Context.Id, Context);
}

bool UVyCore::CreateProvider(EVyProviderType ProviderType)
{
	//Make sure to deinitialize an active provider
	if(Provider != nullptr)
	{
		Provider->Deinitialize();
	}

	Provider = nullptr;
	HasProvider = false;
	CurrentProviderType = EVyProviderType::None;

	if (ProviderType == EVyProviderType::None) 
		return true;


	FString errMsg;
	Provider = UVyProviderManager::GetSelf()->CreateProvider(ProviderType, this, errMsg);
	if (Provider == nullptr)
	{
		UE_LOG(LogVenlyBackend, Error, TEXT("Failed to create provider (type=\'%s\'). Error = \'%s\'"), *VyUtils::EnumToString(ProviderType), *errMsg)
			return false;
	}

	//Initialize new provider
	Provider->Initialize();
	HasProvider = true;
	CurrentProviderType = ProviderType;

	return true;
}

void UVyCore::SetRequestState(FVyRequestId RequestId, EVyRequestState newState)
{
	checkf(InFlightRequestContexts.Contains(RequestId), TEXT("VyBackendCore::SetRequestState(...) - Request (%i) not found."), RequestId)

	auto& Context = InFlightRequestContexts[RequestId];
	Context.State = newState;
}
