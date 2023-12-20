// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptDateTimeBPL.h"

FVyOptDateTime UVyOptDateTimeBPL::MakeOptional(FDateTime Value)
{
	FVyOptDateTime Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptDateTime UVyOptDateTimeBPL::Conv_OptionalFromValue(FDateTime Value)
{
	FVyOptDateTime Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptDateTimeBPL::HasValue(const FVyOptDateTime& Optional, FDateTime& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

FDateTime UVyOptDateTimeBPL::GetOptionalValue(const FVyOptDateTime& Optional, FDateTime DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}