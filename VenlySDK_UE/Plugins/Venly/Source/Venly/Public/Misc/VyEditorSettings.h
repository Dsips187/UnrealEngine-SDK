// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Models/VyCoreModels.h"
#include "Engine/DeveloperSettings.h"
#include "VyEditorSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Editor, defaultconfig, meta=(DisplayName="Venly"))
class VENLY_API UVyEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	virtual FName GetContainerName() const override { return FName("Editor"); }
	virtual FName GetSectionName() const override { return FName("Venly"); }
	virtual FName GetCategoryName() const override { return FName("Plugins"); }

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Dev Mode")
	FString ClientId;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Dev Mode", meta=(PasswordField=true))
	FString ClientSecret;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General")
	bool HasWalletApiAccess;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General")
	bool HasNftApiAccess;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General")
	bool HasMarketApiAccess;
};
