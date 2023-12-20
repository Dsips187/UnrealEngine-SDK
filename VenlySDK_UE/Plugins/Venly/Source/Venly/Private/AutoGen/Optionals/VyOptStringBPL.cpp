// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptStringBPL.h"

FVyOptString UVyOptStringBPL::MakeOptional(FString Value)
{
	FVyOptString Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptString UVyOptStringBPL::Conv_OptionalFromValue(FString Value)
{
	FVyOptString Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptStringBPL::HasValue(const FVyOptString& Optional, FString& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

FString UVyOptStringBPL::GetOptionalValue(const FVyOptString& Optional, FString DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}