// Fill out your copyright notice in the Description page of Project Settings.


#include "VyCoreModels.h"

//void FVyAuthToken::DeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
//{
//	AccessToken = Bag->GetStringField(TEXT("access_token"));
//	auto expiresIn = Bag->GetIntegerField(TEXT("expires_in"));
//	AccessTokenExpire = FDateTime::UtcNow() + FTimespan::FromSeconds(expiresIn);
//}
void FVyAuthToken::PostSerialize(const TSharedRef<FJsonObject> JsonObject)
{
	ExpireTime = FDateTime::UtcNow() + FTimespan::FromSeconds(ExpiresIn);
}
