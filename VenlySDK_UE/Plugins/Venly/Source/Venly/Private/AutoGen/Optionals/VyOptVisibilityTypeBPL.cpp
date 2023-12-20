// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptVisibilityTypeBPL.h"

FVyOptVisibilityType UVyOptVisibilityTypeBPL::MakeOptional(EVyVisibilityType Value)
{
	FVyOptVisibilityType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptVisibilityType UVyOptVisibilityTypeBPL::Conv_OptionalFromValue(EVyVisibilityType Value)
{
	FVyOptVisibilityType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptVisibilityTypeBPL::HasValue(const FVyOptVisibilityType& Optional, EVyVisibilityType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyVisibilityType UVyOptVisibilityTypeBPL::GetOptionalValue(const FVyOptVisibilityType& Optional, EVyVisibilityType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}