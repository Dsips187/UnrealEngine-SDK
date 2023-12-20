// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VyEditorBPL.generated.h"

enum class EVyProviderType : uint8;
enum class EVyEnvironment : uint8;

/**
 * 
 */
UCLASS()
class VENLYEDITOR_API UVyEditorBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, category="Venly|Editor")
	static FString GetClientId();

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static FString GetClientSecret();

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static void SetProviderType(EVyProviderType ProviderType);

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static EVyProviderType GetProviderType();

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static EVyEnvironment GetEnvironment();

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static FString BuildRealmString();

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static FString ValidateProviderType(EVyProviderType ProviderType);

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static void ValidateProviderType2(EVyProviderType ProviderType, UPARAM(ref) bool& isValid, UPARAM(ref) FString& message);

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static FString GetPlayFabFunctionName();

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static void SetPlayFabFunctionName(const FString& FunctionName);

	UFUNCTION(BlueprintCallable, category = "Venly|Editor")
	static bool CanAuthenticate();
};
