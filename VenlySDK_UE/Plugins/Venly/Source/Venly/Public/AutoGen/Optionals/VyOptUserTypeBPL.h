#pragma once

#include "CoreMinimal.h"
#include "VyOptUserType.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyOptUserTypeBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptUserTypeBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptUserType struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional EVyUserType", NativeMakeFunc))
	static FVyOptUserType MakeOptional(EVyUserType Value);

	/**
	 * @brief Converts an EVyUserType into an FVyOptUserType automatically.
	 * @param Value The EVyUserType to convert.
	 * @return An optional with the EVyUserType set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptUserType Conv_OptionalFromValue(EVyUserType Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptUserType& Optional, EVyUserType& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's EVyUserType Value"))
	static EVyUserType GetOptionalValue(const FVyOptUserType& Optional, EVyUserType DefaultValue, bool& WasSet);
};