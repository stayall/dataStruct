#ifndef _LIST_H

#define NotKnown 0;
#define IsKnown 1;
#define Number 10
struct ListNode;
typedef ListNode* Position;
typedef Position List;
typedef int ElementType;

int IsNull(List L);
List CreateList();
void InsertPos(ElementType element, List L, int i);
void Insert(ElementType element, List L, Position P);
void DeleteList(List L);
void DeletePos(int i, List L);
Position Find(ElementType elm, List L);
void Print(List L);


struct ListNode
{
	Position next;
	bool IsFound;
};

#endif // !_LIST_H

