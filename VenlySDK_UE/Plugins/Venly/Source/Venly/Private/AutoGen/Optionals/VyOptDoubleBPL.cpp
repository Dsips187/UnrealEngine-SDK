// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptDoubleBPL.h"

FVyOptDouble UVyOptDoubleBPL::MakeOptional(double Value)
{
	FVyOptDouble Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptDouble UVyOptDoubleBPL::Conv_OptionalFromValue(double Value)
{
	FVyOptDouble Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptDoubleBPL::HasValue(const FVyOptDouble& Optional, double& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

double UVyOptDoubleBPL::GetOptionalValue(const FVyOptDouble& Optional, double DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}