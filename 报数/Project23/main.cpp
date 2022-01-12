#include "list.h"
#include <stdio.h>

int main()
{
	List L;
	int  n, m;

	scanf_s("%d", &m);
	L = CreateList(m);

	scanf_s("%d", &n);
	DeleteIndex(m, n, L);
}