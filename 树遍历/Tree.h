

#ifndef _Tree_H

struct TreeNode;
typedef TreeNode* Position;
typedef TreeNode* SearchTree;
typedef char ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
void PreamblePrintTree(SearchTree T);
void InorderPrintTree(SearchTree T);
void PostfixPrintTree(SearchTree T);
void NonRecursivePreamblePrintTree(SearchTree T);
void NonRecursiveInorderPrintTree(SearchTree T);
void NonRecursivePostfixPrintTree(SearchTree T);


#endif // !_Tree_H

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;

};
