// Fill out your copyright notice in the Description page of Project Settings.


#include "VyCoreStyle.h"

#include "Styling/SlateTypes.h"
#include "Styling/CoreStyle.h"
#include "EditorStyleSet.h"
#include "Interfaces/IPluginManager.h"

FPluginStyleSet::FPluginStyleSet(const FName& InPluginName, const FName& InStyleSetName)
	: FSlateStyleSet(InStyleSetName == NAME_None ? InPluginName : FName(*(InPluginName.ToString() + TEXT(".") + InStyleSetName.ToString())))
{
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName.ToString());
	check(Plugin.IsValid());

	SetContentRoot(Plugin->GetContentDir());
	SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

FVyCoreStyle::FVyCoreStyle() : FPluginStyleSet(TEXT("Venly"))
{
	Set("VenlyLogoIcon_White", new FSlateImageBrush(RootToContentDir(TEXT("Icons/VenlyIcon_White32x32.png")), Icon16x16));
	Set("VenlyLogo_Purple", new FSlateImageBrush(RootToContentDir(TEXT("Icons/VenlyIcon.png")), Icon40x40));
}

FVyCoreStyle::~FVyCoreStyle()
{
}

FVyCoreStyle& FVyCoreStyle::GetRef()
{
	if(!StyleRef.IsValid())
	{
		StyleRef = MakeShareable(new FVyCoreStyle);
	}

	return *StyleRef.Get();
}

void FVyCoreStyle::Destroy()
{
	if(StyleRef.IsValid())
		StyleRef.Reset();
}
