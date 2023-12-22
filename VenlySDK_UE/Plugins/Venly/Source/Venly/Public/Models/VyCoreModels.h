// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "VyEnums.h"
#include "Utils/VyJsonUtils.h"
#include "Utils/VyUtils.h"
#include "Utils/VyRequestUtils.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "VyCoreModels.generated.h"

typedef int64 FVyRequestId;

USTRUCT(BlueprintType)
struct FVyQuery
{
	GENERATED_BODY();

	virtual ~FVyQuery() = default;
	virtual bool HasQueryLUT() const { return false; }
	virtual const TMap<FName, FName>& GetQueryLUT() const { return EmptyQueryLUT; }
	FString GetQueryName(const FProperty* Property) const
	{
		if(HasQueryLUT())
		{
			const auto propName = Property->GetFName();
			const auto lut = GetQueryLUT();
			if(lut.Contains(propName))
			{
				return lut[propName].ToString();
			}
		}

		auto authoredName = Property->GetAuthoredName();
		authoredName[0] = FChar::ToLower(authoredName[0]);
		return authoredName;
	}

private:
	inline static const TMap<FName, FName> EmptyQueryLUT{};
};

USTRUCT(BlueprintType)
struct FVyDTO
{
	GENERATED_BODY()
	virtual ~FVyDTO() = default;

	virtual void PostSerialize(const TSharedRef<FJsonObject> JsonObject) {}

	virtual bool HasPropertyLUT() const { return false; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const { return EmptyNamesLUT; }

	FString GetJsonPropertyName(const FProperty* Property) const
	{
		if(HasPropertyLUT())
		{
			const auto Lut = GetPropertyLUT();
			const auto PropName = Property->GetFName();
			if (Lut.Contains(PropName))
				return Lut[PropName].ToString();
		}

		auto authoredName = Property->GetAuthoredName();
		authoredName[0] = FChar::ToLower(authoredName[0]);
		return authoredName;
	}

private:
	inline static const TMap<FName, FName> EmptyNamesLUT{};
};

USTRUCT(BlueprintType, meta=(VyPostSerialize))
struct FVyAuthToken : public FVyDTO
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Token {};
	UPROPERTY(VisibleDefaultsOnly, Category = "Venly") int32 ExpiresIn {-1};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FDateTime ExpireTime {FDateTime::MinValue() };

	bool IsValid() const
	{
		return ExpireTime > FDateTime::UtcNow();
	}

	virtual VENLY_API void PostSerialize(const TSharedRef<FJsonObject> JsonObject) override;
	virtual VENLY_API bool HasPropertyLUT() const override { return true; }
	virtual VENLY_API const TMap<FName, FName>& GetPropertyLUT() const override
	{
		static const TMap<FName, FName> LUT_Names = {
		{TEXT("Token"), TEXT("access_token")},
		{TEXT("ExpiresIn"), TEXT("expires_in")}
		};

		return LUT_Names;
	}
};

USTRUCT(BlueprintType)
struct FVyResponseContext
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") int32 Code {-1};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Content {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool IsContentEnveloped{ false };
};

USTRUCT(BlueprintType)
struct FVyHttpMethod
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Method {};
};

USTRUCT(BlueprintType)
struct FVyRequestData : public FVyDTO
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Environment {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Uri {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FVyHttpMethod Method {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Endpoint {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") int32 EndPointHash {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool IsResponseEnveloped{};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FVyOptString QueryString {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString ContentType {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FVyOptString ContentStr {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FVyOptString SelectPropertyName {};
};

USTRUCT(BlueprintType)
struct FVyRequestContext
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") int64 Id {-1};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") EVyRequestState State {EVyRequestState::None};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") EVyApiEndpoint ApiEndpoint { EVyApiEndpoint::None };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Route{};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Verb {TEXT("GET") };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Query{};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Content{};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") int32 EndpointId {-1};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") EVyHttpContentType ContentType { EVyHttpContentType::None };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool RequiresAuth {true};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool ResponseEnveloped {true};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString SelectPropertyName{};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool UseSelectProperty {false};

	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool UsePreferredEnvironment{ false };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") EVyEnvironment PreferredEnvironment { EVyEnvironment::Sandbox };

	FVyRequestContext(FString _Verb, EVyApiEndpoint _ApiEndpoint, FString _Route, bool _RequiresAuth, bool _ResponseEnveloped, int32 _EndpointId = -1)
	{
		Id = -1;
		State = EVyRequestState::None;
		Verb = _Verb;
		ApiEndpoint = _ApiEndpoint;
		Route = _Route;
		RequiresAuth = _RequiresAuth;
		ResponseEnveloped = _ResponseEnveloped;
		EndpointId = _EndpointId;

		Query.Empty();
		Content.Empty();
		ContentType = EVyHttpContentType::None;
	}

	FVyRequestContext()
	{
	}

	void SetEndpointId(int32 _EndpointId)
	{
		EndpointId = _EndpointId;
	}

	void SetPreferredEnvironment(EVyEnvironment Environment)
	{
		UsePreferredEnvironment = true;
		PreferredEnvironment = Environment;
	}

	void AddFormContent(const TMap<FString, FString>& formData)
	{
		ContentType = EVyHttpContentType::Form;

		Content = TEXT("");
		bool isFirst = true;
		for (auto kvp : formData)
		{
			if (!isFirst) Content += TEXT("&");
			Content += FString::Printf(TEXT("%s=%s"), *kvp.Key, *kvp.Value);

			isFirst = false;
		}
	}

	template<typename TStructType>
	void AddJsonContent(const TStructType& data)
	{
		ContentType = EVyHttpContentType::Json;
		VyJsonUtils::UStructToJsonObjectString(data, Content);
	}

	template<typename TQueryType>
	void AddQuery(const TQueryType* InStruct)
	{
		VyRequestUtils::FVyQueryToString(InStruct, Query);
	}

	void SelectProperty(FString PropertyName)
	{
		UseSelectProperty = true;
		SelectPropertyName = PropertyName;
	}

	static FVyRequestContext PUT(EVyApiEndpoint apiEndpoint, const FString& route, bool bResponseEnveloped = true, bool bRequiresAuth = true)
	{
		return CREATE(TEXT("PUT"), apiEndpoint, route, bResponseEnveloped, bRequiresAuth);
	}

	static FVyRequestContext GET(EVyApiEndpoint apiEndpoint, const FString& route, bool bResponseEnveloped = true, bool bRequiresAuth = true)
	{
		return CREATE(TEXT("GET"), apiEndpoint, route, bResponseEnveloped, bRequiresAuth);
	}

	static FVyRequestContext POST(EVyApiEndpoint apiEndpoint, const FString& route, bool bResponseEnveloped = true, bool bRequiresAuth = true)
	{
		return CREATE(TEXT("POST"), apiEndpoint, route, bResponseEnveloped, bRequiresAuth);
	}

	static FVyRequestContext PATCH(EVyApiEndpoint apiEndpoint, const FString& route, bool bResponseEnveloped = true, bool bRequiresAuth = true)
	{
		return CREATE(TEXT("PATCH"), apiEndpoint, route, bResponseEnveloped, bRequiresAuth);
	}

	static FVyRequestContext DELETE(EVyApiEndpoint apiEndpoint, const FString& route, bool bResponseEnveloped = true, bool bRequiresAuth = true)
	{
		return CREATE(TEXT("DELETE"), apiEndpoint, route, bResponseEnveloped, bRequiresAuth);
	}

	FVyRequestData ToRequestData(EVyEnvironment Environment = EVyEnvironment::Sandbox)
	{
		FVyRequestData reqData{};
		reqData.Uri = Route;
		reqData.EndPointHash = -1;
		reqData.Method = FVyHttpMethod{ Verb };
		reqData.Endpoint = VyUtils::EnumToString(ApiEndpoint);
		reqData.IsResponseEnveloped = ResponseEnveloped;
		reqData.ContentType = VyUtils::EnumToString(ContentType);
		reqData.Environment = Environment == EVyEnvironment::Sandbox ? TEXT("staging") : TEXT("production"); //todo: fix
		if(ContentType != EVyHttpContentType::None)
		{
			reqData.ContentStr = FVyOptString{ Content };
		}

		if(!Query.IsEmpty())
		{
			reqData.QueryString = FVyOptString{ Query };
		}

		if(UseSelectProperty)
		{
			reqData.SelectPropertyName = FVyOptString{ SelectPropertyName };
		}


		return reqData;
	}

private:
	static FVyRequestContext CREATE(FString verb, EVyApiEndpoint apiEndpoint, const FString& route, bool bResponseEnveloped = true, bool bRequiresAuth = true)
	{
		return FVyRequestContext(verb, apiEndpoint, route, bRequiresAuth, bResponseEnveloped);
	}
};

USTRUCT(BlueprintType)
struct FVyExtensionRequestContext
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString ExtensionName;
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FVyRequestContext BaseRequest;

	FVyExtensionRequestContext(){}
	FVyExtensionRequestContext(const FString& _ExtensionName)
	{
		ExtensionName = _ExtensionName;
		BaseRequest = FVyRequestContext::GET(EVyApiEndpoint::Extension, _ExtensionName);
	}

	static FVyExtensionRequestContext Create(const FString& _ExtensionName) 
	{
		return FVyExtensionRequestContext(_ExtensionName);
	}

	template<typename TStructType>
	void AddJsonContent(const TStructType& data)
	{
		BaseRequest.AddJsonContent(data);
	}
};


USTRUCT(BlueprintType)
struct FVyResponseError
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Code {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Message {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString TraceCode {};
};

USTRUCT(BlueprintType)
struct FVyApiResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool Success{ false };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") TArray<FVyResponseError> Errors {};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FVyResponseContext ResponseContext {};
};

USTRUCT(BlueprintType)
struct FVyServerResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool Success{ false };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString Data{};
	UPROPERTY(BlueprintReadOnly, Category = "Venly") int StatusCode{ -1 };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") FString ErrorMessage { };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool IsRawResponse{ false };
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool IsDataEncoded{ false };
};

USTRUCT(BlueprintType)
struct FVyApiUnitResponse : public FVyApiResponse
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FVyResponseTrait_VariantResult
{
	GENERATED_BODY()
};

DECLARE_DELEGATE_OneParam(FVyOnComplete_ResponseContext, FVyResponseContext);
DECLARE_DELEGATE_OneParam(FVyOnComplete, FVyApiUnitResponse)

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE(FVyOnSuccessBP);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE(FVyOnFailBP);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCompleteBP, FVyApiUnitResponse, Result);