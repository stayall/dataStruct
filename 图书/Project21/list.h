#ifndef _LIST_H

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
	ElementType element;
	Position next;
};

#endif // !_LIST_H

