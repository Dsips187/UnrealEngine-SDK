// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//template< typename T >
//FString EnumToString(T EnumValue)
//{
//	static_assert(TIsUEnumClass< T >::Value, "'T' template parameter to EnumToString must be a valid UEnum");
//	return StaticEnum< T >()->GetNameStringByIndex(static_cast<int32>(EnumValue));
//}

UENUM(BlueprintType)
enum class EVyHttpContentType
{
	None,
	Json,
	Form
};

UENUM(BlueprintType)
enum class EVyRequestState
{
	None,
	Initiating,
	Processing,
	Queued,
	Complete
};

UENUM(BlueprintType)
enum class EVyEnvironment : uint8
{
	Sandbox,
	Production
};

UENUM(BlueprintType)
enum class EVyApiEndpoint
{
	None,
	Auth,
	Wallet,
	Nft,
	Market,
	Extension
};

UENUM(BlueprintType)
enum class EVyProviderType : uint8
{
	None,
	DevMode,
	PlayFab,
	Beamable,
	Custom
};