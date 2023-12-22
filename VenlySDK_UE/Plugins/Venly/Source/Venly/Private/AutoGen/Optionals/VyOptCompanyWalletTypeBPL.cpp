// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptCompanyWalletTypeBPL.h"

FVyOptCompanyWalletType UVyOptCompanyWalletTypeBPL::MakeOptional(EVyCompanyWalletType Value)
{
	FVyOptCompanyWalletType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptCompanyWalletType UVyOptCompanyWalletTypeBPL::Conv_OptionalFromValue(EVyCompanyWalletType Value)
{
	FVyOptCompanyWalletType Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptCompanyWalletTypeBPL::HasValue(const FVyOptCompanyWalletType& Optional, EVyCompanyWalletType& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

EVyCompanyWalletType UVyOptCompanyWalletTypeBPL::GetOptionalValue(const FVyOptCompanyWalletType& Optional, EVyCompanyWalletType DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}