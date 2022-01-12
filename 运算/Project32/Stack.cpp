#include "Stack.h"
#include <stdlib.h>

int IsEmpty(Stack S)
{
	return S->TopOfStack == 0;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity;
}

void MakeEmpty(Stack S);

Stack CreatStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize)
	{
		exit(1);
	}

	S = (Stack)malloc(sizeof(StackRecord));
	if (S == NULL)
	{
		exit(2);
	}

	S->Array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
	if (S == NULL)
	{
		exit(3);
	}
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{
		exit(4);
	}
	else
	{
		S->Array[++S->TopOfStack] = X;
	}
}
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];

	exit(5);

	//return 0;
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		exit(6);
	else
	{
		S->TopOfStack--;
	}

}
ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];

	exit(7);

	//return 0;
}
