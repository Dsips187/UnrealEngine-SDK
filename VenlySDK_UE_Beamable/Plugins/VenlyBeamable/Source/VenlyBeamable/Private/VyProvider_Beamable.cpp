// Fill out your copyright notice in the Description page of Project Settings.


#include "VyProvider_Beamable.h"
#include "VyBeamableProxy.h"
#include "Utils/VyResponseUtils.h"
#include "Misc/VyProjectSettings.h"

void UVyProvider_Beamable::OnInitialize()
{
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	if (projectSettings == nullptr)
	{
		UE_LOG(LogVenlyBeamable, Error, TEXT("[Beamable Provider] Venly Project setting not found..."))
			return;
	}

	//Retrieve config
	CurrentEnvironment = projectSettings->Environment;
}

void UVyProvider_Beamable::ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete)
{
	auto Proxy = UVyBeamableProxy::Get();

	if (Proxy == nullptr)
	{
		auto response = VyResponseUtils::CreateResponseContext_Failure(TEXT("BEAMABLE_PROVIDER"), TEXT("Proxy (\'UVyBeamableProxy\') cannot be retrieved."));
		auto _ = OnComplete.ExecuteIfBound(response);
		return;
	}

	Proxy->ExecuteRequest(Context, CurrentEnvironment, OnComplete);
}
