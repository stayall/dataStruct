#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List CreateList(int n)
{
	List L;
	Position NewCell, P;
	int i;

	L = (List)malloc(sizeof(ListNode));
	if (L == NULL)
	{
		exit(0);
	}

	P = L;
	P->index = 1;
	for (i = 1; i < n; i++)
	{
		NewCell = (Position)malloc(sizeof(ListNode));
		NewCell->index = P->index + 1;
		P->next = NewCell;
		P = NewCell;
	}
	P->next = L;

	return P;
}

Position MovePro(int n, List L)
{
	Position P;
	int i;

	if (L == NULL)
	{
		exit(0);
	}

	P = L;
	i = 0;
	while (i < n - 1 )
	{
		P = P->next;
		i++;
	}
	return P;
}

void DeleteIndex(int m, int n, List L)
{
	Position P, TmpCell;
	int i;

	if (L == NULL)
	{
		exit(0);
	}


	P = L;
	i = 0;
	while (i < m)
	{
		P = MovePro(n, P);
		{
			TmpCell = P->next;
			P->next = TmpCell->next;
			printf_s("%d, ", TmpCell->index);
			free(TmpCell);
			i++;
		}
	}
}