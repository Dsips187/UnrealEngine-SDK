// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptFulfillmentStateBPL.h"

FVyOptFulfillmentState UVyOptFulfillmentStateBPL::MakeOptional(EVyFulfillmentState Value)
{
	FVyOptFulfillmentState Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptFulfillmentState UVyOptFulfillmentStateBPL::Conv_OptionalFromValue(EVyFulfillmentState Value)
{
	FVyOptFulfillmentState Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptFulfillmentStateBPL::HasValue(const FVyOptFulfillmentState& Optional, EVyFulfillmentState& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyFulfillmentState UVyOptFulfillmentStateBPL::GetOptionalValue(const FVyOptFulfillmentState& Optional, EVyFulfillmentState DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}