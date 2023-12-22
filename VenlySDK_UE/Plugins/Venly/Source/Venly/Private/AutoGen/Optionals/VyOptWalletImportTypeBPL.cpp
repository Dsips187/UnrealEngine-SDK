// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptWalletImportTypeBPL.h"

FVyOptWalletImportType UVyOptWalletImportTypeBPL::MakeOptional(EVyWalletImportType Value)
{
	FVyOptWalletImportType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptWalletImportType UVyOptWalletImportTypeBPL::Conv_OptionalFromValue(EVyWalletImportType Value)
{
	FVyOptWalletImportType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptWalletImportTypeBPL::HasValue(const FVyOptWalletImportType& Optional, EVyWalletImportType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyWalletImportType UVyOptWalletImportTypeBPL::GetOptionalValue(const FVyOptWalletImportType& Optional, EVyWalletImportType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}