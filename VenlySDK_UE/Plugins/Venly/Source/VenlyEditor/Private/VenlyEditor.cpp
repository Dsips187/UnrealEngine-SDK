// Copyright Epic Games, Inc. All Rights Reserved.

#include "VenlyEditor.h"

#include "EditorUtilitySubsystem.h"
#include "VyEditorCommands.h"
#include "VyCoreStyle.h"

#include "EditorUtilityWidgetBlueprint.h"
#include "LevelEditor.h"
#include "Utils/VyLoggerDefines.h"

#define LOCTEXT_NAMESPACE "FVenlyEditorModule"

void FVenlyEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	//Style = MakeShareable(new FVyCoreStyle());
	FSlateStyleRegistry::RegisterSlateStyle(FVyCoreStyle::GetRef());

	FVyEditorCommands::Register();
	PluginCommands = MakeShareable(new FUICommandList);
	PluginCommands->MapAction(
		FVyEditorCommands::Get().OpenSdkManagerCommand,
		FExecuteAction::CreateRaw(this, &FVenlyEditorModule::OpenSdkManagerWindow)
	);

	auto& levelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedPtr<FExtender> newToolbarExtender = MakeShareable<FExtender>(new FExtender);
	newToolbarExtender->AddToolBarExtension("ProjectSettings", EExtensionHook::Before, PluginCommands, FToolBarExtensionDelegate::CreateStatic(&FVenlyEditorModule::AddVenlyButtons));
	levelEditorModule.GetToolBarExtensibilityManager()->AddExtender(newToolbarExtender);
}

void FVenlyEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FSlateStyleRegistry::UnRegisterSlateStyle(FVyCoreStyle::GetRef());
	FVyCoreStyle::Destroy();
}

void FVenlyEditorModule::OpenSdkManagerWindow() const
{
	//const TSoftObjectPtr<UWidgetBlueprint> widgetReference = FSoftObjectPath(TEXT("/Script/Blutility.EditorUtilityWidgetBlueprint'/Venly/Editor/EWBP_VenlyManager.EWBP_VenlyManager'"));
	//const auto widgetBlueprint = widgetReference.LoadSynchronous();

	//UObject* widgetBlueprint = UEditorAssetLibrary::LoadAsset(FString(TEXT("EditorUtilityWidgetBlueprint'/Venly/Editor/EWBP_VenlyManager.EWBP_VenlyManager'")));
	const FSoftObjectPath widgetAssetPath(TEXT("EditorUtilityWidgetBlueprint'/Venly/Editor/EWBP_VenlyManager.EWBP_VenlyManager'"));
	UObject* widgetBlueprint = widgetAssetPath.TryLoad();
	if (IsValid(widgetBlueprint))
	{
		if (UEditorUtilityWidgetBlueprint* editorWidgetBlueprint = Cast<UEditorUtilityWidgetBlueprint>(widgetBlueprint))
		{
			const auto editorUtilitySubSystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
			auto editorWidget = editorUtilitySubSystem->SpawnAndRegisterTab(editorWidgetBlueprint);
		}
	}
	else
	{
		UE_LOG(LogVenlyEditor, Error, TEXT("Editor Utiltity Blueprint (EWBP_VenlyManger) could not be found..."))
	}
}

void FVenlyEditorModule::AddVenlyButtons(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FVyEditorCommands::Get().OpenSdkManagerCommand, NAME_None,
		LOCTEXT("Venly", "Venly"), LOCTEXT("VenlyTooltip", "Opens the Venly SDK Manager"), 
		FSlateIcon(FName(TEXT("Venly")), FName(TEXT("VenlyLogo_Purple"))));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVenlyEditorModule, VenlyEditor)