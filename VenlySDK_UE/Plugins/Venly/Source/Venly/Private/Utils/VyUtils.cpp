// Fill out your copyright notice in the Description page of Project Settings.

#include "VyUtils.h"
#include "Utils/VyLoggerDefines.h"

namespace VyUtils
{
	void ParseJWT(const FString& Token, bool& hasWalletApiAccess, bool& hasNftApiAccess, bool& hasMarketApiAccess)
	{
		hasWalletApiAccess = false;
		hasNftApiAccess = false;
		hasMarketApiAccess = false;

		//Select Payload
		FString splitRest{}, splitRight{}, jwtPayload{};
		Token.Split(TEXT("."), &splitRest, &splitRight);
		splitRight.Split(TEXT("."), &jwtPayload, &splitRest);
		jwtPayload += TEXT("==");

		//Decode
		FString jwtPayloadJsonStr{};
		FBase64::Decode(jwtPayload, jwtPayloadJsonStr);

		//Parse
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(jwtPayloadJsonStr);
		if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
		{
			UE_LOG(LogVenly, Warning, TEXT("Failed to retrieve realm access information from JWT..."))
			return;
		}

		//Retrieve Roles
		const TSharedPtr< FJsonObject >* realmObj;
		if(!JsonObject->TryGetObjectField(TEXT("realm_access"), realmObj))
		{
			UE_LOG(LogVenly, Warning, TEXT("Failed to retrieve realm access information from JWT... (\'realm_access\' not found)"))
			return;
		}

		TArray<FString> rolesArr;
		if(!realmObj->Get()->TryGetStringArrayField(TEXT("roles"), rolesArr))
		{
			UE_LOG(LogVenly, Warning, TEXT("Failed to retrieve realm access information from JWT... (\'realm_access.roles[]\' not found)"))
			return;
		}

		//Market & NFT access
		for(auto role : rolesArr)
		{
			if (role.StartsWith(TEXT("NFT"))) hasNftApiAccess = true;
			else if (role.StartsWith(TEXT("Market"))) hasMarketApiAccess = true;
		}

		//Wallet access
		FString scope;
		if(!JsonObject->TryGetStringField(TEXT("scope"), scope))
		{
			UE_LOG(LogVenly, Warning, TEXT("Failed to retrieve realm access information from JWT... (\'scope\' not found)"))
			return;
		}

		if(scope.Contains(TEXT("view:wallets")))
		{
			hasWalletApiAccess = true;
		}
	}
}
