// Fill out your copyright notice in the Description page of Project Settings.

#include "VyProviderBase.h"
#include "VyCore.h"

void UVyProviderBase::Initialize()
{
	OnInitialize();
	IsInitialized = true;
}

void UVyProviderBase::Deinitialize()
{
	OnDeinitialize();
	IsInitialized = false;
}

void UVyProviderBase::ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete)
{
	auto _ = OnComplete.ExecuteIfBound(VyResponseUtils::CreateResponseContext_Failure(TEXT("PROVIDER_BASE"), TEXT("Current provider does not have an implementation for \'ProcessRequest\'...")));
}

UVyCore* UVyProviderBase::GetBackend()
{
	if (!Backend)
		Backend = Cast<UVyCore>(GetOuter());

	return Backend;
}
