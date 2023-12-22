// Copyright Epic Games, Inc. All Rights Reserved.

#include "Venly.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "IVyProviderModuleInterface.h"

#define LOCTEXT_NAMESPACE "FVenlyModule"

void FVenlyModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FVenlyModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVenlyModule, Venly)