#include "Tree.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
		return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}

	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
	{
		return T;
	}
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Right == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Right);
	}
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (Position)malloc(sizeof(TreeNode));
		if (T == NULL)
		{
			exit(1);
		}
		
			T->Element = X;
			T->Left = T->Right = NULL;
	}

	if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
	}

	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
	{
		return NULL;
	}

	if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
	}
	else if (T->Left && T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(TmpCell->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left)
		{
			T = T->Left;
		}
		else if (T->Right)
		{
			T = T->Right;
		}
		free(TmpCell);
	}

	return T;
}


void PreamblePrintTree(SearchTree T)
{
	if (T == NULL)
	{
		return;
	}

	printf("%c ", T->Element);
	PreamblePrintTree(T->Left);
	PreamblePrintTree(T->Right);
}

void InorderPrintTree(SearchTree T)
{
	if (T == NULL)
	{
		return;
	}
	InorderPrintTree(T->Left);
	printf("%c ", T->Element);
	InorderPrintTree(T->Right);
}
void PostfixPrintTree(SearchTree T)
{
	if (T == NULL)
	{
		return;
	}
	PostfixPrintTree(T->Left);
	PostfixPrintTree(T->Right);
	printf("%c ", T->Element);
}

void NonRecursivePreamblePrintTree(SearchTree T)
{
	Stack S = NULL;
	Position TmpCell = T;

	S = CreatStack(10);
	Push(T, S);
	while (!IsEmpty(S))
	{
		while (TmpCell)
		{
			printf("%c ", TmpCell->Element);
			Push(TmpCell->Left, S);
			TmpCell = TmpCell->Left;
		}

		Pop(S);
		if (!IsEmpty(S))
		{
			TmpCell = TopAndPop(S);
			Push(TmpCell->Right,S);
			TmpCell = TmpCell->Right;
		}

	}

	DisposeStack(S);
}

void NonRecursiveInorderPrintTree(SearchTree T)
{
	Stack S = NULL;
	Position TmpCell = T;

	S = CreatStack(10);
	Push(T, S);
	while (!IsEmpty(S))
	{
		while (TmpCell)
		{
			Push(TmpCell->Left, S);
			TmpCell = TmpCell->Left;
		}

		Pop(S);
		if (!IsEmpty(S))
		{
			TmpCell = TopAndPop(S);
			printf("%c ", TmpCell->Element);
			Push(TmpCell->Right, S);
			TmpCell = TmpCell->Right;
		}

	}

	DisposeStack(S);
}
void NonRecursivePostfixPrintTree(SearchTree T)
{
	Position TmpCell = T, Last = NULL;
	Stack S = NULL;

	S = CreatStack(10);

	Push(TmpCell, S);
	while (!IsEmpty(S))
	{
		if (TmpCell && TmpCell != Last)
		{
			Push(TmpCell, S);
			TmpCell = TmpCell->Left;
		}

		else
		{
			TmpCell = TopAndPop(S);
			if (!IsEmpty(S))
				if (TmpCell->Right && TmpCell->Right != Last)
				{
					Push(TmpCell, S);
					TmpCell = TmpCell->Right;
				}
				else 
				{ 
					printf("%c ",TmpCell->Element); 
					Last = TmpCell; 
				}
		}
	}

	DisposeStack(S);
}