// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptFulfillmentTypeBPL.h"

FVyOptFulfillmentType UVyOptFulfillmentTypeBPL::MakeOptional(EVyFulfillmentType Value)
{
	FVyOptFulfillmentType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptFulfillmentType UVyOptFulfillmentTypeBPL::Conv_OptionalFromValue(EVyFulfillmentType Value)
{
	FVyOptFulfillmentType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptFulfillmentTypeBPL::HasValue(const FVyOptFulfillmentType& Optional, EVyFulfillmentType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyFulfillmentType UVyOptFulfillmentTypeBPL::GetOptionalValue(const FVyOptFulfillmentType& Optional, EVyFulfillmentType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}