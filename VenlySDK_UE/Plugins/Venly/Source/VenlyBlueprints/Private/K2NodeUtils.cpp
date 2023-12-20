// Fill out your copyright notice in the Description page of Project Settings.


#include "K2NodeUtils.h"
#include "K2Node_CallFunction.h"
#include "K2Node_BreakStruct.h"
#include "K2Node_Event.h"
#include "KismetCompiler.h"

#define LOCTEXT_NAMESPACE "K2NodeUtils"

UK2Node_CallFunction* K2NodeUtils::CreateCallFunctionNode(UEdGraphNode* Node, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph,
	FName FunctionName, UClass* UClass)
{
	UK2Node_CallFunction* CallFunctionNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(Node, SourceGraph);
	CallFunctionNode->FunctionReference.SetExternalMember(FunctionName, UClass);
	CallFunctionNode->AllocateDefaultPins();
	return CallFunctionNode;
}

UK2Node_Event* K2NodeUtils::CreateEventNodeForDelegate(UEdGraphNode* Node, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph, const FString& DelegateName)
{
	// Adds the event node to the graph.
	UK2Node_Event* EventNode = CompilerContext.SpawnIntermediateEventNode<UK2Node_Event>(Node, nullptr, SourceGraph);

	// To ensure uniqueness per graph we use the owner custom node's name in this node as well.
	const auto EventNodeName = FString::Printf(TEXT("%sHandler_%s_%s"), *DelegateName, *SourceGraph->GetName(), *Node->GetName());
	EventNode->CustomFunctionName = FName(*EventNodeName);

	// When wrapping a Custom Event node that expects a certain Dynamic Delegate, you need to pass in "DelegateName__DelegateSignature".
	// The line below is from the Input node.
	// 
	//	InputActionEvent->EventReference.SetExternalDelegateMember(FName(TEXT("InputActionHandlerDynamicSignature__DelegateSignature")));
	//
	// This just makes a UK2Node_Event with the signature of the given delegate as the output pins.
	EventNode->EventReference.SetExternalDelegateMember(FName(*FString::Printf(TEXT("%s__DelegateSignature"), *DelegateName)));

	// Calling this builds the node pins correctly based on the given Delegate Signature
	EventNode->AllocateDefaultPins();
	// Return the node
	return EventNode;
}

UK2Node_BreakStruct* K2NodeUtils::CreateBreakStructNode(UEdGraphNode* CustomNode,
	FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph, const UEdGraphSchema_K2* K2Schema,
	UScriptStruct* const StructToBreak, UEdGraphPin* StructInputPin)
{
	UK2Node_BreakStruct* BreakStructNode = CompilerContext.SpawnIntermediateNode<UK2Node_BreakStruct>(CustomNode, SourceGraph);
	BreakStructNode->StructType = StructToBreak;
	BreakStructNode->bMadeAfterOverridePinRemoval = true;
	BreakStructNode->AllocateDefaultPins();

	// Connect the Result pin to the break pin	
	const auto bConnectedBreakPins = K2Schema->TryCreateConnection(StructInputPin, BreakStructNode->FindPin(StructToBreak->GetFName()));
	check(bConnectedBreakPins)

	return BreakStructNode;
}

#undef LOCTEXT_NAMESPACE
