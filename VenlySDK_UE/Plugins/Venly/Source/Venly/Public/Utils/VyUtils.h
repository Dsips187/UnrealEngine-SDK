// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

namespace VyUtils
{
	void VENLY_API ParseJWT(const FString& Token, bool& hasWalletApiAccess, bool& hasNftApiAccess, bool& hasMarketApiAccess);

	template<typename EnumType>
	FString EnumToString(const EnumType EnumeratorValue)
	{
		auto fullType = UEnum::GetValueAsString(EnumeratorValue);
		int32 scopePos{};
		if (fullType.FindLastChar(':', scopePos))
		{
			fullType.RemoveAt(0, scopePos + 1);
		}

		return fullType;
	}

	template<typename EnumType>
	bool TryStringToEnum(const FName& EnumeratorValue, EnumType& OutParam)
	{
		auto EnumIndex = StaticEnum<EnumType>()->GetValueByName(EnumeratorValue);
		if (EnumIndex == INDEX_NONE) return false;

		OutParam = (EnumType)EnumIndex;
		return true;
	}

	template<typename EnumType>
	bool TryStringToEnum(const FString& EnumeratorValue, EnumType& OutParam)
	{
		return TryStringToEnum(FName(EnumeratorValue), OutParam);
	}

	template<typename EnumType>
	bool TryJsonValueToEnum(TSharedPtr<FJsonValue> JsonValue, EnumType& OutParam)
	{
		FString enumeratorValue;
		if(JsonValue->TryGetString(enumeratorValue))
		{
			return TryStringToEnum(enumeratorValue, OutParam);
		}

		return false;
	}
}