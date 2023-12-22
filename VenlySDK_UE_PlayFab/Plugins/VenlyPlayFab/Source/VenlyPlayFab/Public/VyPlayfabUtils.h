// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogVenlyPlayFab, Log, All);

namespace PlayFab
{
	namespace CloudScriptModels
	{
		struct FExecuteFunctionResult;
	}

	struct FPlayFabCppError;
}

struct FVyResponseContext;

namespace VyPlayFabUtils
{
	FVyResponseContext PlayFabErrorToResponseContext(const PlayFab::FPlayFabCppError& error);
	FVyResponseContext CloudScriptResultToResponseContext(const PlayFab::CloudScriptModels::FExecuteFunctionResult& result);
}
