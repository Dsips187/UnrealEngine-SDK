// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FVenlyEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<class FUICommandList> PluginCommands;
	void OpenSdkManagerWindow() const;
	static void AddVenlyButtons(FToolBarBuilder& Builder);

	//TSharedPtr<FSlateStyleSet> Style;
};
