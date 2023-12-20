// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptContractOutputArrayBPL.h"

FVyOptContractOutputArray UVyOptContractOutputArrayBPL::MakeOptional(TArray<FVyContractOutputDto> Value)
{
	FVyOptContractOutputArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptContractOutputArray UVyOptContractOutputArrayBPL::Conv_OptionalFromValue(TArray<FVyContractOutputDto> Value)
{
	FVyOptContractOutputArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptContractOutputArrayBPL::HasValue(const FVyOptContractOutputArray& Optional, TArray<FVyContractOutputDto>& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

TArray<FVyContractOutputDto> UVyOptContractOutputArrayBPL::GetOptionalValue(const FVyOptContractOutputArray& Optional, TArray<FVyContractOutputDto> DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}