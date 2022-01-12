
#ifndef _Queue_h
#define MinQueueSize 5


struct QueueRecord;
typedef QueueRecord* Queue;
typedef int ElementType;

int IsFull(Queue Q);
int IsEmpty(Queue Q);
Queue CreateQueue(int MaxElements);
void MakeEmpty(Queue Q);
void DisposeQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeu(Queue Q);

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int size;
	ElementType* Array;
};

#endif // !_Queue_h
