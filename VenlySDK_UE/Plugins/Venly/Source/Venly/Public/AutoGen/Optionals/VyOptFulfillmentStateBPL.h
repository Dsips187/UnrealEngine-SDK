#pragma once

#include "CoreMinimal.h"
#include "VyOptFulfillmentState.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyOptFulfillmentStateBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptFulfillmentStateBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptFulfillmentState struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional EVyFulfillmentState", NativeMakeFunc))
	static FVyOptFulfillmentState MakeOptional(EVyFulfillmentState Value);

	/**
	 * @brief Converts an EVyFulfillmentState into an FVyOptFulfillmentState automatically.
	 * @param Value The EVyFulfillmentState to convert.
	 * @return An optional with the EVyFulfillmentState set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptFulfillmentState Conv_OptionalFromValue(EVyFulfillmentState Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptFulfillmentState& Optional, EVyFulfillmentState& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's EVyFulfillmentState Value"))
	static EVyFulfillmentState GetOptionalValue(const FVyOptFulfillmentState& Optional, EVyFulfillmentState DefaultValue, bool& WasSet);
};