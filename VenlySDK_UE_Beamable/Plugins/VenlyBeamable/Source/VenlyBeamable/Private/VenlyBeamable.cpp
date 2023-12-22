// Copyright Epic Games, Inc. All Rights Reserved.

#include "VenlyBeamable.h"
#include "VyProvider_Beamable.h"
#include "VyCore.h"

#define LOCTEXT_NAMESPACE "FVenlyBeamableModule"

void FVenlyBeamableModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FVenlyBeamableModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

UVyProviderBase* FVenlyBeamableModule::CreateProvider(UVyCore* Core)
{
	return NewObject<UVyProvider_Beamable>(Core);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVenlyBeamableModule, VenlyBeamable)