// Fill out your copyright notice in the Description page of Project Settings.


#include "VyProvider_DevMode.h"

#include "VyAuthAPI.h"
#include "HttpModule.h"
#include "VyCore.h"
#include "VyEditorSettings.h"
#include "Interfaces/IHttpResponse.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/VyRequestUtils.h"

void UVyProvider_DevMode::ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete)
{
	//Create Request
	const auto Request = VyRequestUtils::CreateHttpRequest(Context);
	InFlightRequests.Add(Context.Id, Request);

	//Bind with Request OnComplete
	Request->OnProcessRequestComplete().BindLambda([this, Context, OnComplete](const FHttpRequestPtr Request, const FHttpResponsePtr Response, const bool)
		{
			FVyResponseContext ResponseContext = {};
			ResponseContext.IsContentEnveloped = Context.ResponseEnveloped;

			if (Response.IsValid())
			{
				ResponseContext.Code = Response->GetResponseCode();
				ResponseContext.Content = Response->GetContentAsString();
			}
			else
			{
				ResponseContext = VyResponseUtils::CreateResponseContext_Failure(TEXT("DEVMODE_PROVIDER"), TEXT("OnProcessRequestComplete returned a NULL ResponsePtr"));
			}

			auto _ = OnComplete.ExecuteIfBound(ResponseContext);
		});

	//Execute Request (Send HttpRequest - if conditions are met)
	ExecuteRequest(Context.Id);
}

void UVyProvider_DevMode::OnRequestComplete(FVyRequestId RequestId)
{
	if (InFlightRequests.Contains(RequestId))
	{
		InFlightRequests.Remove(RequestId);
	}
}

void UVyProvider_DevMode::OnInitialize()
{
	const auto settings = GetDefault<UVyEditorSettings>();
	ClientId = settings->ClientId;
	ClientSecret = settings->ClientSecret;
}

void UVyProvider_DevMode::QueueRequest(FVyRequestId RequestId)
{
	const auto& Context = GetBackend()->GetRequestContext(RequestId);
	if (Context.State != EVyRequestState::None || Context.State != EVyRequestState::Processing)
	{
		GetBackend()->SetRequestState(RequestId, EVyRequestState::Queued);
		QueuedRequests.Enqueue(RequestId);
		return;
	}

	UE_LOG(LogVenlyProvider, Warning, TEXT("VyBackendCore::QueueRequest(...) - Request (%lld) cannot be queue, current State is set to (%s)"), RequestId, *UEnum::GetDisplayValueAsText(Context.State).ToString())
}

void UVyProvider_DevMode::CheckQueuedRequests()
{
	while (true)
	{
		FVyRequestId RequestId;
		if (!QueuedRequests.Dequeue(RequestId))
		{
			break;
		}

		ExecuteRequest(RequestId);
	}
}

void UVyProvider_DevMode::ExecuteRequest(FVyRequestId RequestId)
{
	const auto& Context = GetBackend()->GetRequestContext(RequestId);
	const auto Request = InFlightRequests[RequestId];

	if (Context.RequiresAuth)
	{
		if (!AuthTokenRetrievalFailed)
		{
			if (!IsAuthTokenValid())
			{
				QueueRequest(RequestId);
				UE_LOG(LogVenlyProvider, Verbose, TEXT("VyBackendCore::ProcessRequest(...) - Request (%lld) queued (missing AuthToken)"), RequestId)
					return;
			}
			
			Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *AuthToken.Token));
		}
		else
		{
			UE_LOG(LogVenlyBackend, Warning, TEXT("Request (%lld) will probably fail (failed to retrieve valid AuthToken)"), Context.Id)
		}
	}

	GetBackend()->SetRequestState(RequestId, EVyRequestState::Processing);

	Request->ProcessRequest();
	UE_LOG(LogVenlyBackend, Log, TEXT("Request SENT (ID=%lld | URL=%s)"), Context.Id, *Request->GetURL())
}

bool UVyProvider_DevMode::IsAuthTokenValid()
{
	if (AuthToken.IsValid()) return true;

	//Refresh Auth Token
	FVyOnGetAuthTokenComplete OnComplete;
	OnComplete.BindLambda([this](FVyGetAuthTokenResponse response)
		{
			if (response.Success)
			{
				AuthToken = response.Result;
			}
			else
			{
				UE_LOG(LogVenlyBackend, Warning, TEXT("Failed to retrieve a valid AuthToken (HttpCode=%i) || Error=%s"), response.ResponseContext.Code, *response.ResponseContext.Content);
			}

			AuthTokenRetrievalFailed = !response.Success;
			CheckQueuedRequests();
		});


	UVyAuthAPI::Get()->CPP_GetAuthToken(ClientId, ClientSecret, OnComplete);

	return false;
}
