// Fill out your copyright notice in the Description page of Project Settings.


#include "VyEditorBPL.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/VyEditorSettings.h"
#include "Misc/VyProjectSettings.h"
#include "Models\VyEnums.h"
#include "Providers/VyProviderManager.h"

FString UVyEditorBPL::GetClientId()
{
	if (GEditor)
	{
		const auto editorSettings = GetDefault<UVyEditorSettings>();
		return editorSettings->ClientId;
	}
	
	return TEXT("");
}

FString UVyEditorBPL::GetClientSecret()
{
	if (GEditor)
	{
		const auto editorSettings = GetDefault<UVyEditorSettings>();
		return editorSettings->ClientSecret;
	}

	return TEXT("");
}

void UVyEditorBPL::SetProviderType(EVyProviderType ProviderType)
{
	if (GEditor)
	{
		const auto projectSettings = GetMutableDefault<UVyProjectSettings>();
		projectSettings->ProviderType = ProviderType;
		projectSettings->SaveConfig();
	}
}

EVyProviderType UVyEditorBPL::GetProviderType()
{
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	return projectSettings->ProviderType;
}

EVyEnvironment UVyEditorBPL::GetEnvironment()
{
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	return projectSettings->Environment;
}

FString UVyEditorBPL::BuildRealmString()
{
	if (GEditor)
	{
		const auto editorSettings = GetDefault<UVyEditorSettings>();

		TArray<FString> realms;
		if (editorSettings->HasWalletApiAccess) realms.Add(TEXT("WALLET"));
		if (editorSettings->HasNftApiAccess) realms.Add(TEXT("NFT"));
		if (editorSettings->HasMarketApiAccess) realms.Add(TEXT("MARKET"));

		if (realms.IsEmpty())
			return TEXT("No Access");

		const auto separatorChar = TEXT(" | ");
		return FString::Join(realms, separatorChar);
	}

	return TEXT("");
}

FString UVyEditorBPL::ValidateProviderType(EVyProviderType ProviderType)
{
	if(UVyProviderManager::GetSelf()->IsProviderAvailable(ProviderType))
	{
		return TEXT("");
	}
	
	switch (ProviderType)
	{
	case EVyProviderType::PlayFab: return TEXT("PlayFab Provider is not available. Make sure that both the VenlyPlayFab and PlayFab plugins are installed and activated.");
	case EVyProviderType::Beamable: return TEXT("Beamable Provider is not available. Make sure that both the VenlyBeamable and Beamable plugins are installed and activated.");
	}

	return TEXT("Provider Type is not available.");
}

void UVyEditorBPL::ValidateProviderType2(EVyProviderType ProviderType, bool& isValid, FString& message)
{
	message.Empty();
	isValid = UVyProviderManager::GetSelf()->IsProviderAvailable(ProviderType);

	if(!isValid)
	{
		if (ProviderType == EVyProviderType::PlayFab) message = TEXT("PlayFab Provider is not available. Make sure that both the VenlyPlayFab and PlayFab plugins are installed and activated.");
		else if (ProviderType == EVyProviderType::Beamable) message = TEXT("PlayFab Provider is not available. Make sure that both the VenlyPlayFab and PlayFab plugins are installed and activated.");
		else message = TEXT("Provider Type is not available.");
	}
	else
	{
		if (ProviderType == EVyProviderType::PlayFab) message = TEXT("VenlyPlayFab Plugin active!");
		else if (ProviderType == EVyProviderType::Beamable) message = TEXT("VenlyBeamable Plugin active!");
	}
}

FString UVyEditorBPL::GetPlayFabFunctionName()
{
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	return projectSettings->PlayFabCloudFunction;
}

void UVyEditorBPL::SetPlayFabFunctionName(const FString& FunctionName)
{
	const auto projectSettings = GetMutableDefault<UVyProjectSettings>();
	projectSettings->PlayFabCloudFunction = FunctionName;
	projectSettings->SaveConfig();
}

bool UVyEditorBPL::CanAuthenticate()
{
	if (GEditor)
	{
		const auto editorSettings = GetDefault<UVyEditorSettings>();
		return !editorSettings->ClientId.IsEmpty() && !editorSettings->ClientSecret.IsEmpty();
	}

	return false;
}
