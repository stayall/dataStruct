#pragma once
#ifndef _Stack_H
#define MinStackSize 5
#define EmptyTOS 0

struct StackRecord;
typedef StackRecord* Stack;
typedef char ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreatStack(int MaxElement);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);


struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};

#endif // !_Stack_H
