#pragma once

#include "CoreMinimal.h"
#include "VyOptStorage.h"
#include "AutoGen/Models/Shared/VyStorageDto.h"

#include "VyOptStorageBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptStorageBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptStorage struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional FVyStorageDto", NativeMakeFunc))
	static FVyOptStorage MakeOptional(FVyStorageDto Value);

	/**
	 * @brief Converts an FVyStorageDto into an FVyOptStorage automatically.
	 * @param Value The FVyStorageDto to convert.
	 * @return An optional with the FVyStorageDto set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptStorage Conv_OptionalFromValue(FVyStorageDto Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptStorage& Optional, FVyStorageDto& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's FVyStorageDto Value"))
	static FVyStorageDto GetOptionalValue(const FVyOptStorage& Optional, FVyStorageDto DefaultValue, bool& WasSet);
};