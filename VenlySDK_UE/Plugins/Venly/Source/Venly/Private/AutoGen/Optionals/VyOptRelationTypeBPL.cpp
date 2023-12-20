// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptRelationTypeBPL.h"

FVyOptRelationType UVyOptRelationTypeBPL::MakeOptional(EVyRelationType Value)
{
	FVyOptRelationType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptRelationType UVyOptRelationTypeBPL::Conv_OptionalFromValue(EVyRelationType Value)
{
	FVyOptRelationType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptRelationTypeBPL::HasValue(const FVyOptRelationType& Optional, EVyRelationType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyRelationType UVyOptRelationTypeBPL::GetOptionalValue(const FVyOptRelationType& Optional, EVyRelationType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}