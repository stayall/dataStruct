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


	printf("µ›πÈœ»–Ú: ");
	PreamblePrintTree(T);
	printf("\n");

	printf("µ›πÈ÷––Ú: ");
	InorderPrintTree(T);
	printf("\n");

	printf("µ›πÈ∫Û–Ú: ");
	PostfixPrintTree(T);
	printf("\n");

	printf("∑«µ›πÈœ»–Ú: ");
	NonRecursivePreamblePrintTree(T);
	printf("\n");

	printf("∑«µ›πÈ÷––Ú: ");
	NonRecursiveInorderPrintTree(T);
	printf("\n");

	printf("∑«µ›πÈ∫Û–Ú: ");
	NonRecursivePostfixPrintTree(T);;
	printf("\n");



}