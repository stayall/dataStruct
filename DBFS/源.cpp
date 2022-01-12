#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"


struct VertexRecord;
struct EdgeRecord;
typedef VertexRecord* Vertex;
typedef VertexRecord* Edge;
typedef VertexRecord* Gragh;
typedef int VertexNumber;

struct VertexRecord
{
	int number;
	int weight;
	Edge next;
};


Gragh CreateGragh(int Vnumber, int Enumber);
void DFS(Gragh G, int beg, int*, int);
void DFSBegin(Gragh G, int beg, int*, int);
void BFS(Gragh G, int beg, int* Visited, int len);
void* Malloc(size_t size);
int FindIndex(Gragh G, VertexNumber Vn, int len);
void BFSBegin(Gragh G, int beg, int* Visited, int len);
int IsOverFind(int* a, int len);




int main()
{
	Gragh G;
	int Vnumber = 0, Enumber = 0;
	int *Visited, beg;

	scanf_s("%d%d", &Vnumber, &Enumber);
	G = CreateGragh(Vnumber, Enumber);

	scanf_s("%d", &beg);
	Visited = (int*)Malloc(sizeof(int) * Vnumber);
	BFSBegin(G, beg, Visited, Vnumber);

	printf("\n");

	DFSBegin(G, beg, Visited, Vnumber);
}

void* Malloc(size_t size)
{
	void *p;

	p = malloc(size);
	if (p == NULL)
	{
		exit(2);
	}

	return p;
}

Gragh CreateGragh(int Vsum, int Esum)
{
	Gragh G = NULL;
	VertexNumber Vnumber;
	VertexNumber Enumber;
	Edge E = NULL;
	int weight = 0;

	G = (Gragh)Malloc(sizeof(VertexRecord) * Vsum + 1);


	for (int i = 0; i < Vsum; i++)
	{
		scanf_s("%d", &Vnumber);
		G[i].number = Vnumber;
		G[i].weight = 0;
		G[i].next = NULL;

	}

	for (int i = 0; i < Esum; i++)
	{
		scanf_s("%d--%d", &Vnumber, &Enumber);


		

		E = (Edge)Malloc(sizeof(VertexRecord));
		int  j = -1;
		j = FindIndex(G, Vnumber, Vsum);
		if (j >= 0)
		{
			E->next = G[j].next;
			G[j].next = E;
			E->number = Enumber;
		}
		else
		{
			exit(4);
		}
	}

	return G;

}

int IsOverFind(int* a, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (a[i] == 0)
		{
			return i;
		}
	}

	return -1;
}

void DFSBegin(Gragh G, int beg, int* Visited, int len)
{
	for (int i = 0; i < len; i++)
	{
		Visited[i] = 0;
	}

	int i = FindIndex(G, beg, len);
	if (i == -1)
	{
		exit(5);
	}

	DFS(G, i, Visited, len);

	int Index = -1;
	while((Index = IsOverFind(Visited, len)) != -1)
	{
		DFS(G, Index, Visited, len);
	}


}


void DFS(Gragh G, int beg, int* Visited, int len)
{

	Visited[beg] = true;
	printf("%d ", G[beg].number);
	Vertex TmpCell = G[beg].next;
	int NextIndex = -1;


	while (TmpCell != NULL)
	{
		NextIndex = FindIndex(G, TmpCell->number, len);
		if (!Visited[NextIndex])
		{
			DFS(G, NextIndex, Visited, len);
		}
		TmpCell = TmpCell->next;
	}

}



void BFSBegin(Gragh G, int beg, int* Visited, int len)
{

	for (int i = 0; i < len; i++)
	{
		Visited[i] = 0;
	}

	int i = FindIndex(G, beg, len);
	if (i == -1)
	{
		exit(5);
	}

	BFS(G, i, Visited, len);

	int Index = -1;
	while ((Index = IsOverFind(Visited, len)) != -1)
	{
		BFS(G, Index, Visited, len);
	}
}

void BFS(Gragh G, int beg, int* Visited, int len)
{
	Queue Q = NULL;

	Q = CreateQueue(10);
	
	Vertex TmpCell = G[beg].next;
	int NextIndex = -1;

	Enqueue(beg, Q);
	Visited[beg] = true;
	printf("%d ", G[beg].number);

	while (!IsEmpty(Q))
	{
		NextIndex = FrontAndDequeu(Q);
		TmpCell = G[NextIndex].next;
		while(TmpCell != NULL)
		{
			int NewV = FindIndex(G, TmpCell->number, len);
			if (!Visited[NewV])
			{
				Enqueue(NewV, Q);
				printf("%d ", G[NewV].number);
				Visited[NewV] = true;
			}
			TmpCell = TmpCell->next;
		}
		
	}

}


int FindIndex(Gragh G, VertexNumber Vn, int len)
{
	int i = -1;
	for (i = 0; i < len; i++)
	{
		if (G[i].number == Vn)
		{
			break;
		}
	}

	return i;
}
