#include "Queue.h"
#include <stdlib.h>


int IsFull(Queue Q)
{
	return Q->size == Q->Capacity;
}
int IsEmpty(Queue Q)
{
	return Q->size == 0;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;

	if (MaxElements < MinQueueSize)
	{
		exit(1);
	}

	Q = (Queue)malloc(sizeof(QueueRecord));
	if (Q == NULL)
	{
		exit(2);
	}

	Q->Array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
	if (Q->Array == NULL)
	{
		exit(2);
	}
	Q->Capacity = MaxElements;
	MakeEmpty(Q);

	return Q;
}

void MakeEmpty(Queue Q)
{
	Q->Front = 1;
	Q->Rear = 0;
	Q->size = 0;
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

static int Succ(int Vaule, Queue Q)
{
	if (++Vaule == Q->Capacity)
		Vaule = 0;
	return Vaule;
}


void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		exit(4);
	}
	else
	{
		Q->size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
	

}

ElementType Front(Queue Q)
{
	if (!IsEmpty(Q))
		return Q->Array[Q->Front];
	exit(3);
	//return 0;
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		exit(3);
	else
	{
		Q->size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

ElementType FrontAndDequeu(Queue Q)
{
	ElementType tmp;
	
	if (!IsEmpty(Q))
	{
		tmp = Q->Array[Q->Front];
		Q->size--;
		Q->Front = Succ(Q->Front, Q);
		return tmp;
	}
	exit(3);
	//return 0;
}