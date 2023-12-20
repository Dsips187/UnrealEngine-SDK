// Fill out your copyright notice in the Description page of Project Settings.


#include "VySettingsAuthWidget.h"

#include "VyAuthAPI.h"
#include "Misc/VyProjectSettings.h"
#include "Misc/VyEditorSettings.h"

void UVySettingsAuthWidget::TryAuthenticate(const FString& ClientId, const FString& ClientSecret,
	EVyEnvironment Environment)
{
	//Store new settings
	const auto projectSettings = GetMutableDefault<UVyProjectSettings>();
	projectSettings->Environment = Environment;
	projectSettings->SaveConfig();

	const auto editorSettings = GetMutableDefault<UVyEditorSettings>();
	editorSettings->ClientId = ClientId;
	editorSettings->ClientSecret = ClientSecret;
	editorSettings->SaveConfig();

	//Perform Auth
	FVyOnGetAuthTokenComplete handler{};
	handler.BindLambda([this](FVyGetAuthTokenResponse Response)
		{
			if(Response.Success)
			{
				const auto editorSettings = GetMutableDefault<UVyEditorSettings>();
				VyUtils::ParseJWT(Response.Result.Token, editorSettings->HasWalletApiAccess, editorSettings->HasNftApiAccess, editorSettings->HasMarketApiAccess);
				editorSettings->SaveConfig();
			}

			auto _ = OnAuthComplete.ExecuteIfBound(Response.Success);
		});

	UVyAuthAPI::Get()->CPP_GetAuthToken(ClientId, ClientSecret, Environment, handler);
}
