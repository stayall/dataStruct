#include "list.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

int IsNull(List L)
{
	int IsNull = 1;

	if (L != NULL)
	{
		IsNull = 0;
	}
	return IsNull;
}

List CreateList()
{
	List L;

	L = (List)malloc(sizeof(ListNode));
	if (IsNull(L))
	{
		exit(0);
	}
	L->next = NULL;

	return L;
}
void Insert(ElementType elmement, List L, Position P)
{
	Position NewCell;

	NewCell = (Position)malloc(sizeof(ListNode));
	if (IsNull(NewCell))
	{
		exit(0);
	}

	NewCell->next = P->next;
	P->next = NewCell;
	NewCell->element = elmement;
}

void DeleteList(List L)
{
	Position P, TmpCell;

	P = L->next;
	while (P)
	{
		TmpCell = P;
		P = P->next;
		free(TmpCell);
	}
	free(L);

	exit(0);
}

Position Find(ElementType elm, List L)
{
	Position P;

	if (IsNull(L))
	{
		exit(0);
	}

	P = L->next;
	while (P && P->element != elm)
	{
		P = P->next;
	}

	return P;
}

static Position Move(int i, List L)
{
	Position P;

	if (IsNull(L))
	{
		exit(0);
	}

	P = L;
	while (--i >= 1)
	{
		if (IsNull(P))
		{
			exit(0);
		}

		P = P->next;
	}

	return P;
}

void InsertPos(ElementType element, List L, int i)
{
	Position P;

	P = Move(i, L);
	if (IsNull(P))
	{
		exit(0);
	}

	Insert(element, L, P);
}


void Print(List L)
{
	Position P;

	if (IsNull(L))
	{
		exit(0);
	}

	P = L->next;
	while (P)
	{
		printf("%d ", P->element);
		P = P->next;
	}

}

void DeletePos(int i, List L)
{
	Position P, TmpCell;

	P = Move(i - 1, L);
	TmpCell = P->next;
	if (TmpCell == NULL)
	{
		exit(0);
	}
	P->next = TmpCell->next;
	free(TmpCell);
}