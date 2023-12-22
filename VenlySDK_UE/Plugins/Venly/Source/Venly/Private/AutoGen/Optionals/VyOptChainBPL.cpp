// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptChainBPL.h"

FVyOptChain UVyOptChainBPL::MakeOptional(EVyChain Value)
{
	FVyOptChain Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptChain UVyOptChainBPL::Conv_OptionalFromValue(EVyChain Value)
{
	FVyOptChain Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptChainBPL::HasValue(const FVyOptChain& Optional, EVyChain& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyChain UVyOptChainBPL::GetOptionalValue(const FVyOptChain& Optional, EVyChain DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}