// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptContractInputArrayBPL.h"

FVyOptContractInputArray UVyOptContractInputArrayBPL::MakeOptional(TArray<FVyContractInputDto> Value)
{
	FVyOptContractInputArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptContractInputArray UVyOptContractInputArrayBPL::Conv_OptionalFromValue(TArray<FVyContractInputDto> Value)
{
	FVyOptContractInputArray Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptContractInputArrayBPL::HasValue(const FVyOptContractInputArray& Optional, TArray<FVyContractInputDto>& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

TArray<FVyContractInputDto> UVyOptContractInputArrayBPL::GetOptionalValue(const FVyOptContractInputArray& Optional, TArray<FVyContractInputDto> DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}