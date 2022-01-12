#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Stack S;
	int StackSize, condition;
	char c;

	printf_s("����ջ��С(��С��5)-> ");
	scanf_s("%d", &StackSize);
	printf_s("\n");

	S = CreatStack(StackSize);
	getchar();

	while ((c = getchar()) != '\n')
	{
		if (c == '(' || c == '{' || c == '<')
			Push(c, S);
		if (c == ')' || c == '}' || c == '>')
		{
			if (IsEmpty(S))
			{
				Push(c, S);
				break;
			}
			char tmp = Top(S);
			if (c == ')' && tmp != '(')
				break;
			if (c == '}' && tmp != '{')
				break;
			if (c == '>' && tmp != '<')
				break;
			Pop(S);
		}
	}
	if (IsEmpty(S))
	{
		printf("ƥ��");
	}
	else
	{
		printf("��ƥ��");
	}
}