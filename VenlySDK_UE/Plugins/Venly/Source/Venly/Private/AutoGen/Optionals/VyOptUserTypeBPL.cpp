// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptUserTypeBPL.h"

FVyOptUserType UVyOptUserTypeBPL::MakeOptional(EVyUserType Value)
{
	FVyOptUserType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptUserType UVyOptUserTypeBPL::Conv_OptionalFromValue(EVyUserType Value)
{
	FVyOptUserType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptUserTypeBPL::HasValue(const FVyOptUserType& Optional, EVyUserType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyUserType UVyOptUserTypeBPL::GetOptionalValue(const FVyOptUserType& Optional, EVyUserType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}