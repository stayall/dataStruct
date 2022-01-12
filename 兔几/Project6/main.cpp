#include "list.h"
#include <stdio.h>

int main()
{
	List L;
	int i, step, pos;
	Position P;

	L = CreateList();


	i = 0;
	step = 1;
	pos = 0;
	P = L;
	while (i <= 100)
	{
		P[pos % 10].IsFound = IsKnown;
		step += 1;
		pos += step;
		++i;
	}
	
	Print(L);
}