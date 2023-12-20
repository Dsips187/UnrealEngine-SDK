// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"

enum class EVyApiEndpoint;
struct FVyRequestContext;
struct FVyQuery;

typedef TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> TUnrealRequestPtr;
/**
 * 
 */
class VENLY_API VyRequestUtils
{
public:
	VyRequestUtils(){};
	~VyRequestUtils(){};

	//URL
	static FString ResolveEndpointURL(const FVyRequestContext& Context);

	//QUERY
	template<typename TQueryType>
	static void FVyQueryToString(const TQueryType* InStruct, FString& OutQueryString)
	{
		static_assert(TIsDerivedFrom<TQueryType, FVyQuery>::Value, "TQueryType must be a FVyQuery type.");
		FVyQueryToString(TQueryType::StaticStruct(), InStruct, OutQueryString);
	}

	static void FVyQueryToString(const UStruct* QueryStructDefinition, const void* QueryStruct, FString& OutQueryString);

	//HTTP
	static TUnrealRequestPtr CreateHttpRequest(FVyRequestContext& Context);

private:

	static TMap<EVyApiEndpoint, FString> SandboxURLs;
	static TMap<EVyApiEndpoint, FString> ProductionURLs;
};
