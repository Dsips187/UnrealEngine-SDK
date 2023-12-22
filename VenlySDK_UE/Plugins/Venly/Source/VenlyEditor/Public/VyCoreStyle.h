// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

/**
 *
 */
class FPluginStyleSet : public FSlateStyleSet
{
public:
	FPluginStyleSet(const FName& InPluginName, const FName& InStyleSetName = NAME_None);

};

/**
 *
 */
class VENLYEDITOR_API FVyCoreStyle : public FPluginStyleSet
{
public:
	FVyCoreStyle();
	virtual ~FVyCoreStyle() override;

	static FVyCoreStyle& GetRef();
	static void Destroy();

private:
	inline static TSharedPtr<FVyCoreStyle> StyleRef{nullptr};
};
