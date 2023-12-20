// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptBoolBPL.h"

FVyOptBool UVyOptBoolBPL::MakeOptional(bool Value)
{
	FVyOptBool Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptBool UVyOptBoolBPL::Conv_OptionalFromValue(bool Value)
{
	FVyOptBool Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptBoolBPL::HasValue(const FVyOptBool& Optional, bool& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

bool UVyOptBoolBPL::GetOptionalValue(const FVyOptBool& Optional, bool DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}