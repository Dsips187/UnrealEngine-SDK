// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IVyProviderModuleInterface.h"

class FVenlyPlayFabModule: public IVyProviderModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual UVyProviderBase* CreateProvider(UVyCore* Core) override;
};
