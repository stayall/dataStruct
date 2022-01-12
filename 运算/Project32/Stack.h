#ifndef _Stack_H

#define MinStackSize 5
#define EmptyTOS 0


struct StackRecord;
typedef StackRecord* Stack;
typedef int ElementType;

int IsFull(Stack S);
int IsEmpty(Stack S);
Stack CreatStack(int MaxElments);
void DisposeStack(Stack S);
void Push(ElementType x, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif // !_Stack_H


struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};