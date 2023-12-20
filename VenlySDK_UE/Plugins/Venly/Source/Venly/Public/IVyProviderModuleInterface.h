// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Providers\VyProviderBase.h"

class UVyCore;

class VENLY_API IVyProviderModuleInterface : public IModuleInterface
{
public:
	virtual ~IVyProviderModuleInterface(){}
	virtual UVyProviderBase* CreateProvider(UVyCore* Core)
	{
		return nullptr;
	}
};
