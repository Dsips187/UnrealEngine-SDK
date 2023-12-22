// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptTokenDestinationArrayBPL.h"

FVyOptTokenDestinationArray UVyOptTokenDestinationArrayBPL::MakeOptional(TArray<FVyTokenDestinationDto> Value)
{
	FVyOptTokenDestinationArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptTokenDestinationArray UVyOptTokenDestinationArrayBPL::Conv_OptionalFromValue(TArray<FVyTokenDestinationDto> Value)
{
	FVyOptTokenDestinationArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptTokenDestinationArrayBPL::HasValue(const FVyOptTokenDestinationArray& Optional, TArray<FVyTokenDestinationDto>& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

TArray<FVyTokenDestinationDto> UVyOptTokenDestinationArrayBPL::GetOptionalValue(const FVyOptTokenDestinationArray& Optional, TArray<FVyTokenDestinationDto> DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}