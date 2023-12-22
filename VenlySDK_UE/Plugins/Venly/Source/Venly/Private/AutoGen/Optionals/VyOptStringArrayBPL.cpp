// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptStringArrayBPL.h"

FVyOptStringArray UVyOptStringArrayBPL::MakeOptional(TArray<FString> Value)
{
	FVyOptStringArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptStringArray UVyOptStringArrayBPL::Conv_OptionalFromValue(TArray<FString> Value)
{
	FVyOptStringArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptStringArrayBPL::HasValue(const FVyOptStringArray& Optional, TArray<FString>& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

TArray<FString> UVyOptStringArrayBPL::GetOptionalValue(const FVyOptStringArray& Optional, TArray<FString> DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}