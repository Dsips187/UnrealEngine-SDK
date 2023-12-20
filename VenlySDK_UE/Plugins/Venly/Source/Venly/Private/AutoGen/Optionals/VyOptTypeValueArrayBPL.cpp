// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptTypeValueArrayBPL.h"

FVyOptTypeValueArray UVyOptTypeValueArrayBPL::MakeOptional(TArray<FVyTypeValueDto> Value)
{
	FVyOptTypeValueArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptTypeValueArray UVyOptTypeValueArrayBPL::Conv_OptionalFromValue(TArray<FVyTypeValueDto> Value)
{
	FVyOptTypeValueArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptTypeValueArrayBPL::HasValue(const FVyOptTypeValueArray& Optional, TArray<FVyTypeValueDto>& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

TArray<FVyTypeValueDto> UVyOptTypeValueArrayBPL::GetOptionalValue(const FVyOptTypeValueArray& Optional, TArray<FVyTypeValueDto> DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}