#pragma once

#include "CoreMinimal.h"
#include "VyOptTokenDestinationArray.h"
#include "AutoGen/Models/Nft/VyTokenDestinationDto.h"

#include "VyOptTokenDestinationArrayBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptTokenDestinationArrayBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptTokenDestinationArray struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional TArray<FVyTokenDestinationDto>", NativeMakeFunc))
	static FVyOptTokenDestinationArray MakeOptional(TArray<FVyTokenDestinationDto> Value);

	/**
	 * @brief Converts an TArray<FVyTokenDestinationDto> into an FVyOptTokenDestinationArray automatically.
	 * @param Value The TArray<FVyTokenDestinationDto> to convert.
	 * @return An optional with the TArray<FVyTokenDestinationDto> set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptTokenDestinationArray Conv_OptionalFromValue(TArray<FVyTokenDestinationDto> Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptTokenDestinationArray& Optional, TArray<FVyTokenDestinationDto>& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's TArray<FVyTokenDestinationDto> Value"))
	static TArray<FVyTokenDestinationDto> GetOptionalValue(const FVyOptTokenDestinationArray& Optional, TArray<FVyTokenDestinationDto> DefaultValue, bool& WasSet);
};