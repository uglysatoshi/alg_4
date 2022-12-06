#ifndef TREE
#define TREE

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class TNode
{
    public:
        int data;
        TNode *pRight;
        TNode *pLeft;
        TNode *pPrev;

};

class Tree
{  
    private:
        TNode *root; 
    public:
        TNode* GetTreeRoot();
        TNode* RecursionSearch(TNode* node, int value);
        TNode* CreateTreeElement(int value); 
        TNode* RecursionInsert(TNode* node, int value);
        TNode* RemoveByValueRecursion(TNode* node, int value);
        TNode* RemoveMinRecursion(TNode* node);
        void ClearTreeRecursion(TNode* node);
        void ClearTree();
        void ClearBranch(int value);
        int TotalLeafsRecursion(TNode* node);
        int TotalLeafs();
        int TotalNodesRecursion(TNode* node);
        int TotalNodes();
        int NextNodeRecursion(TNode* node);
        int PreNodeRecursion(TNode* node);
        int SearchForMaxRecursion(TNode* node);
        int SearchForMax(TNode* node);
        int SearchForMinRecursion(TNode* node);
        int SearchForMin(TNode* node);
        int NextNode(int value);
        int PreNode(int value);
        int Extent(int value);
        int Level(int value);
        int HeightRecursion(TNode* node);
        int Height();
        void Insert(int value);
        void RemoveByValue(int value);
        void RandInsert(int value);
        void RemoveMin();
        void Print();
        void Depth();
        void DepthIteration(TNode* node);
        void Width();
        void WidthIteration(TNode* node);
        void RecursionPrint(TNode* node, int padding);
        int SearchForEqualRecursion(TNode* node);
        int SearchForEqual();
        bool Search(int value);
        bool AnyTreeSearchRecursion(TNode* node, int value);
        bool AnyTreeSearch(int value);
        Tree();
        ~Tree();
};

#endif