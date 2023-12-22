// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"

#include "VyNode_Api.generated.h"

#define LOCTEXT_NAMESPACE "VyNode_Api"

class UK2Node_CallFunction;
class UK2Node_Event;
/**
 * 
 */
UCLASS(NotBlueprintable, NotBlueprintType, Hidden)
class VENLYBLUEPRINTS_API UVyNode_Api : public UK2Node
{
	GENERATED_BODY()

public:
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual void AllocateDefaultPins() override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual FName GetCornerIcon() const override;


protected:
	virtual UClass* GetApiClass() const;
	virtual UScriptStruct* GetResponseType() const;
	virtual FName GetSelfFunctionName() const;
	virtual FName GetRequestFunctionName() const;
	virtual FName GetOnSuccessDelegateName() const;
	virtual FName GetOnFailedDelegateName() const;
	virtual FName GetOnCompleteDelegateName() const;
	virtual FName GetApiName() const;
	virtual FName GetAuthoredName() const;

	const FName OP_ExecuteRequest_OnSuccess = FName("OnSuccess");
	const FName OP_ExecuteRequest_OnFail = FName("OnFail");
	const FName OP_ExecuteRequest_OnComplete = FName("OnComplete");
	const FName OP_ExecuteRequest_Response = FName("ResponseData");

private:

	UPROPERTY()
	TArray<FString> RequestFunctionPinNames;

	UPROPERTY()
	TArray<FString> ResponseParamPinNames;

	void CreateInputPins();
	void CreateOutputPins();
	void CreateOutputEventConnection(FKismetCompilerContext& CompilerContext, const FName& EventName, const UK2Node_CallFunction* EventCallFunctionNode, const UK2Node_Event* OutputEventNode);
	static bool IgnoreInputPinPredicate(const UEdGraphNode* CustomNode, const FProperty* Param);

	inline static const FName NAME_OnCompleteNULL{TEXT("null_delegate")};
	inline static const FName NAME_Unknown{TEXT("UNKNOWN")};
	inline static const FName NAME_AuthoredName{TEXT("MyFNameActor_Tag")};
};

#undef LOCTEXT_NAMESPACE