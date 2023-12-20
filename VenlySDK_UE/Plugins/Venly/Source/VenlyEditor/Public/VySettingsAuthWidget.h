// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VySettingsBaseWidget.h"
#include "VySettingsAuthWidget.generated.h"

enum class EVyEnvironment : uint8;

DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnEditorAuthComplete, bool, Success);

/**
 * 
 */
UCLASS()
class VENLYEDITOR_API UVySettingsAuthWidget : public UVySettingsBaseWidget
{
	GENERATED_BODY()
		
public:

	UFUNCTION(BlueprintCallable, Category = "Venly|Editor")
	void TryAuthenticate(const FString& ClientId, const FString& ClientSecret, EVyEnvironment Environment);

	UPROPERTY(BlueprintReadWrite)
	FVyOnEditorAuthComplete OnAuthComplete {};
};
