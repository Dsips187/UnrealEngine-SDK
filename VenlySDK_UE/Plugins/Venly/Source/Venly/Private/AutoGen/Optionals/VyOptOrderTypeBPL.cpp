// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptOrderTypeBPL.h"

FVyOptOrderType UVyOptOrderTypeBPL::MakeOptional(EVyOrderType Value)
{
	FVyOptOrderType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptOrderType UVyOptOrderTypeBPL::Conv_OptionalFromValue(EVyOrderType Value)
{
	FVyOptOrderType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptOrderTypeBPL::HasValue(const FVyOptOrderType& Optional, EVyOrderType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyOrderType UVyOptOrderTypeBPL::GetOptionalValue(const FVyOptOrderType& Optional, EVyOrderType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}