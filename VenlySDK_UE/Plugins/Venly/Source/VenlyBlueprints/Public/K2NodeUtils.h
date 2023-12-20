// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define LOCTEXT_NAMESPACE "K2NodeUtils"
#include "EdGraphSchema_K2.h"

class UK2Node_BreakStruct;
class UK2Node_Event;
class UK2Node_CallFunction;

namespace K2NodeUtils
{
	/**
	* @brief Utility that creates a call function node targeting a specific UClass's UFunction.
	*/
	UK2Node_CallFunction* CreateCallFunctionNode(UEdGraphNode* Node, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph, FName FunctionName, UClass* UClass);

	/**
	 * @brief Utility that creates a correctly configured event node for the given delegate name.
	 */
	UK2Node_Event* CreateEventNodeForDelegate(UEdGraphNode* Node, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph, const FString& DelegateName);

	/**
	 * @brief Utility that creates a correctly configured BreakStruct not for a given UStruct.
	 */
	UK2Node_BreakStruct* CreateBreakStructNode(UEdGraphNode* CustomNode,
		FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph, const UEdGraphSchema_K2* K2Schema,
		UScriptStruct* const StructToBreak, UEdGraphPin* StructInputPin);
}

#undef LOCTEXT_NAMESPACE
