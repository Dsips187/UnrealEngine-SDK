#pragma once

#include "CoreMinimal.h"
#include "VyOptChain.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyOptChainBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptChainBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptChain struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional EVyChain", NativeMakeFunc))
	static FVyOptChain MakeOptional(EVyChain Value);

	/**
	 * @brief Converts an EVyChain into an FVyOptChain automatically.
	 * @param Value The EVyChain to convert.
	 * @return An optional with the EVyChain set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptChain Conv_OptionalFromValue(EVyChain Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptChain& Optional, EVyChain& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's EVyChain Value"))
	static EVyChain GetOptionalValue(const FVyOptChain& Optional, EVyChain DefaultValue, bool& WasSet);
};