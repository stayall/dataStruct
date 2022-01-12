#include "Stack.h"  
#include <stdio.h>
void OperateOfPriority(int a, Stack OperateS, Stack NumberS);
int Operate(int a, int b, int c);


int main()
{

	Stack NumberS, OperateS;
	char operate;
	int next_number;

	NumberS = CreatStack(10);
	OperateS = CreatStack(10);
	int LastIsNumber = 0;


	while( (operate = getchar()) != '\n')
	{
		if (operate == ' ')
		{
			continue;
		}
		
		if (operate == '+' || operate == '-' || operate == '*' || operate == '/' || operate == '(' || operate == ')')
		{
			LastIsNumber =  0;
			OperateOfPriority(operate, OperateS, NumberS);
		}
		else
		{
			if (LastIsNumber == 1)
			{
				int LastNumber = TopAndPop(NumberS);
				Push((operate - '0') + LastNumber * 10, NumberS);
			}
			else
			{
				LastIsNumber = 1;
				Push(operate - '0', NumberS);
			}
		}

	}

	int op;
	while (!IsEmpty(OperateS))
	{
		op = TopAndPop(OperateS);
		Push(Operate(TopAndPop(NumberS), op, TopAndPop(NumberS)), NumberS);
	}
	printf("%d", Top(NumberS));
}

int Operate(int a, int b, int c)
{
	int ret = 0;
	if (b == '+')
		ret = a + c;

	if(b == '-')
		ret = a - c;

	if(b == '*')
		ret = a * c;

	if(b == '/')
		ret = a / c;

	return ret;
}

void OperateOfPriority(int a, Stack OperateS, Stack NumberS)
{
	int op;
	while (!IsEmpty(OperateS))
	{
		if (Top(OperateS) == '(')
		{
			if (a == ')')
				Pop(OperateS);
			break;
		}


		if (a == '+' || a == '-')
		{
			op = TopAndPop(OperateS);
			Push(Operate(TopAndPop(NumberS), op, TopAndPop(NumberS)), NumberS);
		}


		if (a == '*' || a == '/')
		{
			op = Top(OperateS);
			if (op == '+' || op == '-')
			{
				break;
			}
			else
			{
				Pop(OperateS);
				Push(Operate(TopAndPop(NumberS), op, TopAndPop(NumberS)), NumberS);
			}
		}


		if (a == ')')
		{
				op = TopAndPop(OperateS);
				Push(Operate(TopAndPop(NumberS), op, TopAndPop(NumberS)), NumberS);
		}

		if (a == '(')
		{
			break;
		}
	}
	if(a != ')')
		Push(a, OperateS);
}