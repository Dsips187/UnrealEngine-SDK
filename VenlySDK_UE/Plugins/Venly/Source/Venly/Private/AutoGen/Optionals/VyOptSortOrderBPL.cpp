// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptSortOrderBPL.h"

FVyOptSortOrder UVyOptSortOrderBPL::MakeOptional(EVySortOrder Value)
{
	FVyOptSortOrder Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptSortOrder UVyOptSortOrderBPL::Conv_OptionalFromValue(EVySortOrder Value)
{
	FVyOptSortOrder Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptSortOrderBPL::HasValue(const FVyOptSortOrder& Optional, EVySortOrder& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVySortOrder UVyOptSortOrderBPL::GetOptionalValue(const FVyOptSortOrder& Optional, EVySortOrder DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}