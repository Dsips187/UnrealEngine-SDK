// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptNetworkBPL.h"

FVyOptNetwork UVyOptNetworkBPL::MakeOptional(FVyNetworkDto Value)
{
	FVyOptNetwork Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptNetwork UVyOptNetworkBPL::Conv_OptionalFromValue(FVyNetworkDto Value)
{
	FVyOptNetwork Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptNetworkBPL::HasValue(const FVyOptNetwork& Optional, FVyNetworkDto& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

FVyNetworkDto UVyOptNetworkBPL::GetOptionalValue(const FVyOptNetwork& Optional, FVyNetworkDto DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}