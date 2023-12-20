// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoGen/Optionals/VyOptSignatureRequestBaseBPL.h"

FVyOptSignatureRequestBase UVyOptSignatureRequestBaseBPL::MakeOptional(FVySignatureRequestBase Value)
{
	FVyOptSignatureRequestBase Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

FVyOptSignatureRequestBase UVyOptSignatureRequestBaseBPL::Conv_OptionalFromValue(FVySignatureRequestBase Value)
{
	FVyOptSignatureRequestBase Optional;
	Optional.Val = Value;
	Optional.IsSet = true;
	return Optional;
}

bool UVyOptSignatureRequestBaseBPL::HasValue(const FVyOptSignatureRequestBase& Optional, FVySignatureRequestBase& Value)
{
	Value = Optional.Val;
	return Optional.IsSet;
}

FVySignatureRequestBase UVyOptSignatureRequestBaseBPL::GetOptionalValue(const FVyOptSignatureRequestBase& Optional, FVySignatureRequestBase DefaultValue, bool& WasSet)
{
	WasSet = Optional.IsSet;
	return WasSet ? Optional.Val : DefaultValue;
}