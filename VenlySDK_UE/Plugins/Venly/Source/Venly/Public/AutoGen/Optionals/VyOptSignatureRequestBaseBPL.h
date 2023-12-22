#pragma once

#include "CoreMinimal.h"
#include "VyOptSignatureRequestBase.h"
#include "AutoGen/Models/Wallet/VySignatureRequestBase.h"

#include "VyOptSignatureRequestBaseBPL.generated.h"

UCLASS(BlueprintType)
class VENLY_API UVyOptSignatureRequestBaseBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* @brief Constructs an FVyOptSignatureRequestBase struct from the given value.
	*/
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Make Optional FVySignatureRequestBase", NativeMakeFunc))
	static FVyOptSignatureRequestBase MakeOptional(FVySignatureRequestBase Value);

	/**
	 * @brief Converts an FVySignatureRequestBase into an FVyOptSignatureRequestBase automatically.
	 * @param Value The FVySignatureRequestBase to convert.
	 * @return An optional with the FVySignatureRequestBase set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - String To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FVyOptSignatureRequestBase Conv_OptionalFromValue(FVySignatureRequestBase Value);

	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional.
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Optional Has Value", ExpandBoolAsExecs = "ReturnValue"))
	static bool HasValue(const FVyOptSignatureRequestBase& Optional, FVySignatureRequestBase& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Venly|Optionals", meta = (DisplayName = "Venly - Get Optional's FVySignatureRequestBase Value"))
	static FVySignatureRequestBase GetOptionalValue(const FVyOptSignatureRequestBase& Optional, FVySignatureRequestBase DefaultValue, bool& WasSet);
};