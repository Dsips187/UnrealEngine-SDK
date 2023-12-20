// Fill out your copyright notice in the Description page of Project Settings.


#include "VyProviderManager.h"

#include "IVyProviderModuleInterface.h"
#include "VyCore.h"
#include "VyEnums.h"
#include "VyProvider_DevMode.h"
#include "Utils/VyUtils.h"

void UVyProviderManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UVyProviderManager::EndPlay()
{
	CustomProvider = nullptr;
}

bool UVyProviderManager::IsProviderAvailable(EVyProviderType ProviderType) const
{
	FString tempStr;
	return IsProviderAvailable(ProviderType, tempStr);
}

bool UVyProviderManager::IsProviderAvailable(EVyProviderType ProviderType, FString& errorMsg) const
{
	errorMsg.Empty();

	switch (ProviderType) {
	case EVyProviderType::None: return true;
	case EVyProviderType::Custom: 
	{
		if (CustomProvider == nullptr)
		{
			errorMsg = FString::Printf(TEXT("An implementation for ProviderType \'%s\' is not yet bound. (Use UVyProviderManager::BindCustomProvider(...))"), *VyUtils::EnumToString(ProviderType));
			return false;
		}

		return true;
	}
	case EVyProviderType::PlayFab: return DoesExternalProviderExist(ProviderType, NAME_VenlyPlayFabModule.ToString(), errorMsg);
	case EVyProviderType::Beamable: return DoesExternalProviderExist(ProviderType, NAME_VenlyBeamableModule.ToString(), errorMsg);
	case EVyProviderType::DevMode:
	{
		if (!GIsEditor)
		{
			errorMsg = FString::Printf(TEXT("ProviderType \'%s\' can only be used inside the Editor."), *VyUtils::EnumToString(ProviderType));
		}

		return GIsEditor;
	}
	}

	return false;
}

bool UVyProviderManager::DoesExternalProviderExist(EVyProviderType ProviderType, const FString& ModuleName, FString& errorMsg) const
{
	const bool moduleExists = FModuleManager::Get().ModuleExists(*ModuleName);
	if (!moduleExists)
	{
		errorMsg = FString::Printf(TEXT("ProviderType \'%s\' is not available. Required Plugin \'%s\' is not active and/or found."), *VyUtils::EnumToString(ProviderType), *ModuleName);
	}
	return moduleExists;
}

UVyProviderBase* UVyProviderManager::CreateProvider(EVyProviderType ProviderType, UVyCore* BackendCore, FString& errorMsg) const
{
	errorMsg.Empty();

	//Check if Provider is Available
	if (!IsProviderAvailable(ProviderType, errorMsg)) return nullptr;

	switch (ProviderType)
	{
	case EVyProviderType::None: return nullptr;
	case EVyProviderType::Custom: return CustomProvider;
	case EVyProviderType::PlayFab: return CreateExternalProvider(BackendCore, NAME_VenlyPlayFabModule, errorMsg);
	case EVyProviderType::Beamable: return CreateExternalProvider(BackendCore, NAME_VenlyBeamableModule, errorMsg);
	case EVyProviderType::DevMode: {
		if (GIsEditor) return NewObject<UVyProvider_DevMode>(BackendCore);
		else return nullptr;
	}
	}

	errorMsg = FString::Printf(TEXT("Unknown ProviderType \'%s\'"), *VyUtils::EnumToString(ProviderType));
	return nullptr;
}

void UVyProviderManager::BindCustomProvider(UVyProviderBase* _CustomProvider)
{
	if (CustomProvider != nullptr)
	{
		CustomProvider->Deinitialize();
		CustomProvider->MarkAsGarbage();
	}

	CustomProvider = _CustomProvider;
}

UVyProviderBase* UVyProviderManager::CreateExternalProvider(UVyCore* BackendCore, const FName& ModuleName, FString& errorMsg) const
{
	const auto providerModule = FModuleManager::Get().LoadModule(ModuleName, ELoadModuleFlags::LogFailures);
	if (providerModule == nullptr) {
		errorMsg = FString::Printf(TEXT("Module \'%s\' could not be loaded..."), *ModuleName.ToString());
		return nullptr;
	}

	const auto providerInterface = dynamic_cast<IVyProviderModuleInterface*>(providerModule);
	if (providerInterface == nullptr) {
		errorMsg = FString::Printf(TEXT("Failed to cast \'%s\' ModuleInterface to VyProviderModuleInterface..."), *ModuleName.ToString());
		return nullptr;
	}

	return providerInterface->CreateProvider(BackendCore);
}