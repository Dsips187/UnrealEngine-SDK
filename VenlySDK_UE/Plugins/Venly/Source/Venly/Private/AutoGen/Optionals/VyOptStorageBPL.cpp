// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptStorageBPL.h"

FVyOptStorage UVyOptStorageBPL::MakeOptional(FVyStorageDto Value)
{
	FVyOptStorage Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptStorage UVyOptStorageBPL::Conv_OptionalFromValue(FVyStorageDto Value)
{
	FVyOptStorage Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptStorageBPL::HasValue(const FVyOptStorage& Optional, FVyStorageDto& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

FVyStorageDto UVyOptStorageBPL::GetOptionalValue(const FVyOptStorage& Optional, FVyStorageDto DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}