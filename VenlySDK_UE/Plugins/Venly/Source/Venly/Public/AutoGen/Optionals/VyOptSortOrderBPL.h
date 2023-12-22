#pragma once

#include "CoreMinimal.h"
#include "VyOptSortOrder.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyOptSortOrderBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptSortOrderBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptSortOrder struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional EVySortOrder", NativeMakeFunc))
	static FVyOptSortOrder MakeOptional(EVySortOrder Value);

	/**
	 * @brief Converts an EVySortOrder into an FVyOptSortOrder automatically.
	 * @param Value The EVySortOrder to convert.
	 * @return An optional with the EVySortOrder set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptSortOrder Conv_OptionalFromValue(EVySortOrder Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptSortOrder& Optional, EVySortOrder& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's EVySortOrder Value"))
	static EVySortOrder GetOptionalValue(const FVyOptSortOrder& Optional, EVySortOrder DefaultValue, bool& WasSet);
};