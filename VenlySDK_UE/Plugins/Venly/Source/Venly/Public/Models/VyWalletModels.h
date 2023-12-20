// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "VyWalletModels.generated.h"

//USTRUCT(BlueprintType)
//struct FVyQuery_GetWallets: public FVyQuery
//{
//	GENERATED_BODY();
//
//	UPROPERTY(BlueprintReadWrite, meta = (PropertyName = "includeBalance")) FVyOptionalBool IncludeBalance;
//	UPROPERTY(BlueprintReadWrite, meta = (PropertyName = "address")) FVyOptionalString Address;
//
//	virtual bool HasQueryLUT() const override { return true; }
//	virtual const TMap<FName, FName>& GetQueryLUT() const override
//	{
//		static const TMap<FName, FName> LUT_Names = {
//		{TEXT("IncludeBalance"), TEXT("includeBalance")},
//		{TEXT("Address"), TEXT("address")}
//		};
//
//		return LUT_Names;
//	}
//};



//USTRUCT(BlueprintType)
//struct FVyWallet
//{
//	GENERATED_BODY();
//
//	UPROPERTY(BlueprintReadOnly) FString Id;
//	UPROPERTY(BlueprintReadOnly) FString Address;
//	UPROPERTY(BlueprintReadOnly) FString Identifier;
//};


//USTRUCT(BlueprintType)
//struct FVyCreateWalletRequest: public FVyDTO
//{
//	GENERATED_BODY();
//	UPROPERTY(BlueprintReadWrite, meta=(PropertyName="description")) FString Description;
//	UPROPERTY(BlueprintReadWrite, meta = (PropertyName = "identifier", Optional)) FVyOptionalString Identifier;
//	UPROPERTY(BlueprintReadWrite, meta = (PropertyName = "pincode")) FString Pin;
//	UPROPERTY(BlueprintReadWrite, meta = (PropertyName = "walletType")) EVyWalletType Type;
//	UPROPERTY(BlueprintReadWrite, meta = (PropertyName = "secretType")) EVyChain Chain;
//
//	virtual bool HasPropertyLUT() const override { return true; }
//	virtual const TMap<FName, FName>& GetPropertyLUT() const override
//	{
//		static const TMap<FName, FName> LUT_Names = {
//		{TEXT("Description"), TEXT("description")},
//		{TEXT("Pin"), TEXT("pincode")},
//		{TEXT("Type"), TEXT("walletType")},
//		{TEXT("Chain"), TEXT("secretType")}
//		};
//
//		return LUT_Names;
//	}
//};

//USTRUCT(BlueprintType)
//struct FGetWalletResponse : public FVyApiResponse
//{
//	GENERATED_BODY();
//	UPROPERTY(BlueprintReadOnly) FVyWallet Result;
//};

//USTRUCT(BlueprintType)
//struct FCreateWalletResponse : public FVyApiResponse
//{
//	GENERATED_BODY();
//	UPROPERTY(BlueprintReadOnly) FVyWallet Result;
//};

//USTRUCT(BlueprintType)
//struct FGetWalletsResponse : public FVyApiResponse
//{
//	GENERATED_BODY();
//	UPROPERTY(BlueprintReadOnly) TArray<FVyWallet> Result;
//};



//UDELEGATE(BlueprintAuthorityOnly)
//DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGetWalletComplete, FGetWalletResponse, Result);

//UDELEGATE(BlueprintAuthorityOnly)
//DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGetWalletsComplete, FGetWalletsResponse, Result);

//UDELEGATE(BlueprintAuthorityOnly)
//DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCreateWalletComplete, FCreateWalletResponse, Result);