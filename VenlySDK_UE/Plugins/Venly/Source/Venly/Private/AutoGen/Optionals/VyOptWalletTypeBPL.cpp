// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptWalletTypeBPL.h"

FVyOptWalletType UVyOptWalletTypeBPL::MakeOptional(EVyWalletType Value)
{
	FVyOptWalletType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptWalletType UVyOptWalletTypeBPL::Conv_OptionalFromValue(EVyWalletType Value)
{
	FVyOptWalletType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptWalletTypeBPL::HasValue(const FVyOptWalletType& Optional, EVyWalletType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyWalletType UVyOptWalletTypeBPL::GetOptionalValue(const FVyOptWalletType& Optional, EVyWalletType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}