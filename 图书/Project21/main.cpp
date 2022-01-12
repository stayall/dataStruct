#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	List L;
	int Condition, pos;
	ElementType elm;

	L = CreateList();

	while (true)
	{
		printf_s("1.Insert\n");
		printf_s("2.Print\n");
		printf_s("3.DeleteElement\n");
		printf_s("4.exit\n");
		scanf_s("%d", &Condition);

		switch (Condition)
		{
		case 1:
			scanf_s("%d%d", &pos, &elm);
			InsertPos(elm, L, pos);
			break;
		case 2:
			Print(L);
			system("PAUSE");
			break;
		case 3:
			scanf_s("%d", &pos);
			DeletePos(pos, L);
			break;
		case 4:
			DeleteList(L);
			break;
		}
		system("cls");
	}
}

