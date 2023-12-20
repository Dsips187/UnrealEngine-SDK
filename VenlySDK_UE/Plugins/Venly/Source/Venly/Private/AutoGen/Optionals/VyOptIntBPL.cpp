// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptIntBPL.h"

FVyOptInt UVyOptIntBPL::MakeOptional(int Value)
{
	FVyOptInt Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptInt UVyOptIntBPL::Conv_OptionalFromValue(int Value)
{
	FVyOptInt Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptIntBPL::HasValue(const FVyOptInt& Optional, int& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

int UVyOptIntBPL::GetOptionalValue(const FVyOptInt& Optional, int DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}