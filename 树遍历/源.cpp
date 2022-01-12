#include "Tree.h"
#include "Stack.h"
#include <stdio.h>

int main()
{
	char c = 0;
	SearchTree T = NULL;
	Stack S;

	MakeEmpty(T);

	while ((c = getchar()) != '\n')
	{
		T = Insert(c, T);
	}


	printf("�ݹ�����: ");
	PreamblePrintTree(T);
	printf("\n");

	printf("�ݹ�����: ");
	InorderPrintTree(T);
	printf("\n");

	printf("�ݹ����: ");
	PostfixPrintTree(T);
	printf("\n");

	printf("�ǵݹ�����: ");
	NonRecursivePreamblePrintTree(T);
	printf("\n");

	printf("�ǵݹ�����: ");
	NonRecursiveInorderPrintTree(T);
	printf("\n");

	printf("�ǵݹ����: ");
	NonRecursivePostfixPrintTree(T);;
	printf("\n");



}