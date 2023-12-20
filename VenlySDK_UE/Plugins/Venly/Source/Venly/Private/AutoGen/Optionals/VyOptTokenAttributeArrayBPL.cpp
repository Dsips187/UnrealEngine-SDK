// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptTokenAttributeArrayBPL.h"

FVyOptTokenAttributeArray UVyOptTokenAttributeArrayBPL::MakeOptional(TArray<FVyTokenAttributeDto> Value)
{
	FVyOptTokenAttributeArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptTokenAttributeArray UVyOptTokenAttributeArrayBPL::Conv_OptionalFromValue(TArray<FVyTokenAttributeDto> Value)
{
	FVyOptTokenAttributeArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptTokenAttributeArrayBPL::HasValue(const FVyOptTokenAttributeArray& Optional, TArray<FVyTokenAttributeDto>& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

TArray<FVyTokenAttributeDto> UVyOptTokenAttributeArrayBPL::GetOptionalValue(const FVyOptTokenAttributeArray& Optional, TArray<FVyTokenAttributeDto> DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}