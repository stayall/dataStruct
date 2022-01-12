
#ifndef _Stack_H

#define MinStackSize 5
#define EmptyTOS 0

struct TreeNode;
typedef TreeNode* Position;
struct StackRecord;
typedef StackRecord* Stack;
typedef Position ElementType1;

int IsFull(Stack S);
int IsEmpty(Stack S);
Stack CreatStack(int MaxElments);
void DisposeStack(Stack S);
void Push(ElementType1 x, Stack S);
ElementType1 Top(Stack S);
void Pop(Stack S);
ElementType1 TopAndPop(Stack S);

#endif // !_Stack_H


struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType1* Array;
};