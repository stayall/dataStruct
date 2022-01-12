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
	int i;
	List L;
	Position P;

	L = (List)malloc(sizeof(ListNode) * (Number + 1));
	if (L == NULL)
	{
		exit(0);
	}

	P = L;
	for ( i = 0; i < Number; i++)
	{
		P[i].IsFound = NotKnown;
		
	}
	return L;
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







void Print(List L)
{
	Position P;

	P = L;
	for (int i = 0; i < Number; i++)
	{
		if (P[i].IsFound == 0)
		{
			printf_s("%d, ", i + 1);
		}
	}
}


