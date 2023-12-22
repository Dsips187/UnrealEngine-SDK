// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "JsonObjectConverter.h"

namespace VyJsonUtils
{
	/**
 * Converts from a Json Object to a UStruct, using importText
 *
 * @param JsonObject Json Object to copy data out of
 * @param StructDefinition UStruct definition that is looked over for properties
 * @param OutStruct The UStruct instance to copy in to
 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
 * @param SkipFlags Skip properties that match any of these flags
 * @param bStrictMode Whether to strictly check the json attributes
 * @param OutFailReason Reason of the failure if any
 *
 * @return False if any properties matched but failed to deserialize
 */
	bool VENLY_API JsonObjectToUStruct(const TSharedRef<FJsonObject>& JsonObject, const UStruct* StructDefinition, void* OutStruct, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false, FText* OutFailReason = nullptr);

	/**
	 * Templated version of JsonObjectToUStruct
	 *
	 * @param JsonObject Json Object to copy data out of
	 * @param OutStruct The UStruct instance to copy in to
	 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip properties that match any of these flags
	 * @param bStrictMode Whether to strictly check the json attributes
	 * @param OutFailReason Reason of the failure if any
	 *
	 * @return False if any properties matched but failed to deserialize
	 */
	template<typename OutStructType>
	bool JsonObjectToUStruct(const TSharedRef<FJsonObject>& JsonObject, OutStructType* OutStruct, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false, FText* OutFailReason = nullptr)
	{
		return JsonObjectToUStruct(JsonObject, OutStructType::StaticStruct(), OutStruct, CheckFlags, SkipFlags, bStrictMode, OutFailReason);
	}

	/**
* Converts from an array of json values to an array of UStructs.
*
* @param JsonArray Array containing json values to convert.
* @param OutStructArray The UStruct array to copy in to
* @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
* @param SkipFlags Skip properties that match any of these flags.
* @param bStrictMode Whether to strictly check the json attributes
*
* @return False if any of the matching elements are not an object, or if one of the matching elements could not be converted to the specified UStruct type.
*/
	template<typename OutStructType>
	bool JsonArrayToUStruct(const TArray<TSharedPtr<FJsonValue>>& JsonArray, TArray<OutStructType>* OutStructArray, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false)
	{
		OutStructArray->SetNum(JsonArray.Num());
		for (int32 i = 0; i < JsonArray.Num(); ++i)
		{
			const auto& Value = JsonArray[i];
			if (Value->Type != EJson::Object)
			{
				UE_LOG(LogJson, Warning, TEXT("JsonArrayToUStruct - Array element [%i] was not an object."), i);
				return false;
			}
			if (!JsonObjectToUStruct(Value->AsObject().ToSharedRef(), OutStructType::StaticStruct(), &(*OutStructArray)[i], CheckFlags, SkipFlags, bStrictMode))
			{
				UE_LOG(LogJson, Warning, TEXT("JsonArrayToUStruct - Unable to convert element [%i]."), i);
				return false;
			}
		}
		return true;
	}

	//DESERIALIZATION
	//***************

	/**
	 * Converts from a json string containing an object to a UStruct
	 *
	 * @param JsonString String containing JSON formatted data.
	 * @param OutStruct The UStruct instance to copy in to
	 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip properties that match any of these flags
	 * @param bStrictMode Whether to strictly check the json attributes
	 *
	 * @return False if any properties matched but failed to deserialize
	 */
	template<typename OutStructType>
	bool JsonObjectStringToUStruct(const FString& JsonString, OutStructType* OutStruct, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false)
	{
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(JsonString);
		if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
		{
			UE_LOG(LogJson, Warning, TEXT("JsonObjectStringToUStruct - Unable to parse json=[%s]"), *JsonString);
			return false;
		}
		if (!JsonObjectToUStruct(JsonObject.ToSharedRef(), OutStruct, CheckFlags, SkipFlags, bStrictMode))
		{
			UE_LOG(LogJson, Warning, TEXT("JsonObjectStringToUStruct - Unable to deserialize. json=[%s]"), *JsonString);
			return false;
		}
		return true;
	}

	/**
	* Converts from a json string containing an array to an array of UStructs
	*
	* @param JsonString String containing JSON formatted data.
	* @param OutStructArray The UStruct array to copy in to
	* @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	* @param SkipFlags Skip properties that match any of these flags.
	* @param bStrictMode Whether to strictly check the json attributes
	*
	* @return False if any properties matched but failed to deserialize.
	*/
	template<typename OutStructType>
	bool JsonArrayStringToUStruct(const FString& JsonString, TArray<OutStructType>* OutStructArray, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false)
	{
		TArray<TSharedPtr<FJsonValue> > JsonArray;
		TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(JsonString);
		if (!FJsonSerializer::Deserialize(JsonReader, JsonArray))
		{
			UE_LOG(LogJson, Warning, TEXT("JsonArrayStringToUStruct - Unable to parse. json=[%s]"), *JsonString);
			return false;
		}
		if (!JsonArrayToUStruct(JsonArray, OutStructArray, CheckFlags, SkipFlags, bStrictMode))
		{
			UE_LOG(LogJson, Warning, TEXT("JsonArrayStringToUStruct - Error parsing one of the elements. json=[%s]"), *JsonString);
			return false;
		}
		return true;
	}

	/**
	 * Converts a set of json attributes (possibly from within a JsonObject) to a UStruct, using importText
	 *
	 * @param JsonAttributes Json Object to copy data out of
	 * @param StructDefinition UStruct definition that is looked over for properties
	 * @param OutStruct The UStruct instance to copy in to
	 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip properties that match any of these flags
	 * @param bStrictMode Whether to strictly check the json attributes
	 * @param OutFailReason Reason of the failure if any
	 *
	 * @return False if any properties matched but failed to deserialize
	 */
	bool JsonAttributesToUStruct(const TMap< FString, TSharedPtr<FJsonValue> >& JsonAttributes, const UStruct* StructDefinition, void* OutStruct, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false, FText* OutFailReason = nullptr);

	bool JsonValueToFPropertyWithContainer(const TSharedPtr<FJsonValue>& JsonValue, FProperty* Property, void* OutValue, const UStruct* ContainerStruct, void* Container, int64 CheckFlags, int64 SkipFlags, const bool bStrictMode, FText* OutFailReason);
	bool JsonAttributesToUStructWithContainer(const TMap< FString, TSharedPtr<FJsonValue> >& JsonAttributes, const UStruct* StructDefinition, void* OutStruct, const UStruct* ContainerStruct, void* Container, int64 CheckFlags, int64 SkipFlags, const bool bStrictMode, FText* OutFailReason);
	bool ConvertScalarJsonValueToFPropertyWithContainer(const TSharedPtr<FJsonValue>& JsonValue, FProperty* Property, void* OutValue, const UStruct* ContainerStruct, void* Container, int64 CheckFlags, int64 SkipFlags, const bool bStrictMode, FText* OutFailReason);


	/**
	 * Converts a single JsonValue to the corresponding FProperty (this may recurse if the property is a UStruct for instance).
	 *
	 * @param JsonValue The value to assign to this property
	 * @param Property The FProperty definition of the property we're setting.
	 * @param OutValue Pointer to the property instance to be modified.
	 * @param CheckFlags Only convert sub-properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip sub-properties that match any of these flags
	 * @param bStrictMode Whether to strictly check the json attributes
	 * @param OutFailReason Reason of the failure if any
	 *
	 * @return False if the property failed to serialize
	 */
	bool JsonValueToUProperty(const TSharedPtr<FJsonValue>& JsonValue, FProperty* Property, void* OutValue, int64 CheckFlags = 0, int64 SkipFlags = 0, const bool bStrictMode = false, FText* OutFailReason = nullptr);

	/* * Converts from a FProperty to a Json Value using exportText
	 *
	 * @param Property			The property to export
	 * @param Value				Pointer to the value of the property
	 * @param CheckFlags		Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags			Skip properties that match any of these flags
	 * @param ExportCb Optional callback to override export behavior, if this returns null it will fallback to the default
	 * @param OuterProperty		If applicable, the Array/Set/Map Property that contains this property
	 *
	 * @return					The constructed JsonValue from the property
	 */
	TSharedPtr<FJsonValue> UPropertyToJsonValue(FProperty* Property, const void* Value, int64 CheckFlags = 0, int64 SkipFlags = 0, FProperty* OuterProperty = nullptr);


	//SERIALIZATION
	//*************

	/**
	 * Converts from a UStruct to a json string containing an object, using exportText
	 *
	 * @param StructDefinition UStruct definition that is looked over for properties
	 * @param Struct The UStruct instance to copy out of
	 * @param OutJsonString resulting JSON after serializing the ustruct
	 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip properties that match any of these flags
	 * @param Indent How many tabs to add to the json serializer
	 * @param bPrettyPrint Option to use pretty print (e.g., adds line endings) or condensed print
	 *
	 * @return False if any properties failed to write
	 */
	bool VENLY_API UStructToJsonObjectString(const UStruct* StructDefinition, const void* Struct, FString& OutJsonString, int64 CheckFlags = 0, int64 SkipFlags = 0, int32 Indent = 0, bool bPrettyPrint = true);

	/**
	 * Templated version; Converts from a UStruct to a json string containing an object, using exportText
	 *
	 * @param InStruct The UStruct instance to copy out of
	 * @param OutJsonString Json Object to be filled in with data from the ustruct
	 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip properties that match any of these flags
	 * @param Indent How many tabs to add to the json serializer
	 * @param bPrettyPrint Option to use pretty print (e.g., adds line endings) or condensed print
	 *
	 * @return False if any properties failed to write
	 */
	template<typename InStructType>
	bool UStructToJsonObjectString(const InStructType& InStruct, FString& OutJsonString, int64 CheckFlags = 0, int64 SkipFlags = 0, int32 Indent = 0, bool bPrettyPrint = true)
	{
		return UStructToJsonObjectString(InStructType::StaticStruct(), &InStruct, OutJsonString, CheckFlags, SkipFlags, Indent, bPrettyPrint);
	}

	bool VENLY_API UStructToJsonObject(const UStruct* StructDefinition, const void* Struct, TSharedRef<FJsonObject> OutJsonObject, int64 CheckFlags = 0, int64 SkipFlags = 0);

	/**
	 * Converts from a UStruct to a set of json attributes (possibly from within a JsonObject)
	 *
	 * @param StructDefinition UStruct definition that is looked over for properties
	 * @param Struct The UStruct instance to copy out of
	 * @param OutJsonAttributes Map of attributes to copy in to
	 * @param CheckFlags Only convert properties that match at least one of these flags. If 0 check all properties.
	 * @param SkipFlags Skip properties that match any of these flags
	 *
	 * @return False if any properties failed to write
	 */
	bool UStructToJsonAttributes(const UStruct* StructDefinition, const void* Struct, TMap< FString, TSharedPtr<FJsonValue> >& OutJsonAttributes, int64 CheckFlags = 0, int64 SkipFlags = 0);

	template <typename TInnerType, typename TStructType>
	std::enable_if_t<TIsTArray<TStructType>::Value, bool>
		DeserializeToUStruct(const FString& JsonString, TStructType& OutStruct)
	{
		return JsonArrayStringToUStruct<TInnerType>(JsonString, &OutStruct);
	}

	template <typename TInnerType, typename TStructType>
	std::enable_if_t<!TIsTArray<TStructType>::Value, bool>
		DeserializeToUStruct(const FString& JsonString, TStructType& OutStruct)
	{
		return JsonObjectStringToUStruct(JsonString, &OutStruct);
	}
}