// Fill out your copyright notice in the Description page of Project Settings.


#include "VyProvider_Public.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Kismet/GameplayStatics.h"
#include "VyRequestUtils.h"
#include "VyCore.h"

void UVyProvider_Public::ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete)
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
				ResponseContext.Code = -1;
				ResponseContext.Content = TEXT("OnProcessRequestComplete returned a NULL ResponsePtr");
			}

			auto _ = OnComplete.ExecuteIfBound(ResponseContext);
		});

	//Execute Request (Send HttpRequest - if conditions are met)
	ExecuteRequest(Context.Id);
}

void UVyProvider_Public::OnRequestComplete(FVyRequestId RequestId)
{
	if (InFlightRequests.Contains(RequestId))
	{
		InFlightRequests.Remove(RequestId);
	}
}

void UVyProvider_Public::ExecuteRequest(FVyRequestId RequestId)
{
	const auto& Context = GetBackend()->GetRequestContext(RequestId);
	const auto Request = InFlightRequests[RequestId];

	GetBackend()->SetRequestState(RequestId, EVyRequestState::Processing);
	Request->ProcessRequest();
	UE_LOG(LogVenlyBackend, Log, TEXT("(public) Request SENT (ID=%lld | URL=%s)"), Context.Id, *Request->GetURL())
}
