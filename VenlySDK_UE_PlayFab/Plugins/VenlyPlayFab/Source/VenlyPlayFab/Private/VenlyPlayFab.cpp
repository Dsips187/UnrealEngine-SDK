// Copyright Epic Games, Inc. All Rights Reserved.

#include "VenlyPlayFab.h"
#include "VyProvider_PlayFab.h"
#include "VyCore.h"

#define LOCTEXT_NAMESPACE "FVenlyPlayFabModule"

void FVenlyPlayFabModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FVenlyPlayFabModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

UVyProviderBase* FVenlyPlayFabModule::CreateProvider(UVyCore* Core)
{
	return NewObject<UVyProvider_PlayFab>(Core);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVenlyPlayFabModule, VenlyPlayFab)