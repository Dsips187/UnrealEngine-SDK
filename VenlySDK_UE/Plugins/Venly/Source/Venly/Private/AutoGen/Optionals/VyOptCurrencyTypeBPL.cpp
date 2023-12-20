// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptCurrencyTypeBPL.h"

FVyOptCurrencyType UVyOptCurrencyTypeBPL::MakeOptional(EVyCurrencyType Value)
{
	FVyOptCurrencyType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptCurrencyType UVyOptCurrencyTypeBPL::Conv_OptionalFromValue(EVyCurrencyType Value)
{
	FVyOptCurrencyType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptCurrencyTypeBPL::HasValue(const FVyOptCurrencyType& Optional, EVyCurrencyType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyCurrencyType UVyOptCurrencyTypeBPL::GetOptionalValue(const FVyOptCurrencyType& Optional, EVyCurrencyType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}