#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef int Position;
struct HaffTreeNode;
typedef HaffTreeNode* HaffTree;

struct HaffTreeNode
{
	Position Left;
	Position Right;
	double Weight;
	int IsKnow;
};


void InputWeight(HaffTree a, int num);
int CreateHaff(HaffTree a, int len);
int FindMinWeight(HaffTree a, int len);
int PrintQueNum(HaffTree a, int pos, Position root, int* index, int len);
void InitArray(int* index, int len);

int main()
{
	int number, length;
	Position root = 0;
	printf("权重个数: ");
	scanf("%d", &number);

	length = 2 * number - 1;
	HaffTree Haff = (HaffTree)malloc(sizeof(HaffTreeNode) * length);
	InputWeight(Haff, number);
	
	root = CreateHaff(Haff, number);

	int* index = (int*)malloc(sizeof(int) * length);
	InitArray(index, length);
	PrintQueNum(Haff, -1, --root, index, length);


}

void InitArray(int* index, int len) 
{
	for (size_t i = 0; i < len; i++)
	{
		index[i] = -1;
	}
}

void InputWeight(HaffTree a, int num)
{
	double weight;

	for (int i = 0; i < num; i++)
	{
		scanf("%lf", &weight);
		a[i].Weight = weight;
	}

}

void Init(HaffTree a, int len)
{
	for (int i = 0; i < len; i++)
	{
		a[i].IsKnow = 0;
		a[i].Left = -1;
		a[i].Right = -1;
	}
}




int FindMinWeight(HaffTree a, int len)
{
	double min = INT_MAX;
	int index = -1;

	for (size_t i = 0; i < len; i++)
	{
		
		if (a[i].IsKnow == 0 && min >= a[i].Weight)
		{
			index = i;
			min = a[i].Weight;
		}
	}

	return index;
}


int CreateHaff(HaffTree a, int len)
{
	int First, Second;

	Init(a, len);

	while (1)
	{
		First = FindMinWeight(a, len);
		a[First].IsKnow = 1;
		Second = FindMinWeight(a, len);
		a[Second].IsKnow = 1;
		if (First == -1||Second == -1)
		{
			break;
		}

		a[len].Weight = a[First].Weight + a[Second].Weight;
		a[len].IsKnow = 0;
		a[len].Left = First;
		a[len].Right = Second;
		len++;
	}

	return len;
}


int PrintQueNum(HaffTree a, int pos, Position root, int* index, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (index[i] == -1)
		{
			break;
		}
	}
	if (pos == 1)
	{
		index[i] = 1;
	}
	if (pos == 0)
	{
		index[i] = 0;
	}
	
	if (a[root].Left == -1 && a[root].Right == -1)
	{

		printf("%.3lf: ", a[root].Weight);
		for (i = 0; i < len; i++)
		{
			if (index[i] == -1)
			{
				break;
			}
			printf("%d", index[i]);
		}
		printf("\n");
		index[--i] = -1;
		return i - 1;
	}

	PrintQueNum(a, 0, a[root].Left, index, len);
	PrintQueNum(a, 1, a[root].Right, index, len);
	index[i] = -1;
}
