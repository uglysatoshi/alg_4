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
    protected:
        TNode* RecursionSearch(TNode* node, int value);
        TNode* RecursionInsert(TNode* node, int value);
        TNode* RemoveByValueRecursion(TNode* node, int value);
        TNode* RemoveMinRecursion(TNode* node);
        void ClearTreeRecursion(TNode* node);
        int TotalLeafsRecursion(TNode* node);
        int TotalNodesRecursion(TNode* node);
        int NextNodeRecursion(TNode* node);
        int PreNodeRecursion(TNode* node);
        int SearchForMaxRecursion(TNode* node);
        int SearchForMinRecursion(TNode* node);
        int HeightRecursion(TNode* node);
        void DepthIteration(TNode* node);
        void WidthIteration(TNode* node);
        void RecursionPrint(TNode* node, int padding);
        int SearchForEqualRecursion(TNode* node);
        bool AnyTreeSearchRecursion(TNode* node, int value);
    public:
        TNode* GetTreeRoot();
        TNode* CreateTreeElement(int value); 
        void ClearTree();
        void ClearBranch(int value);
        int TotalLeafs();
        int TotalNodes();
        int SearchForMax(TNode* node);
        int SearchForMin(TNode* node);
        int NextNode(int value);
        int PreNode(int value);
        int Extent(int value);
        int Level(int value);
        int Height();
        void Insert(int value);
        void RemoveByValue(int value);
        void RandInsert(int value);
        void RemoveMin();
        void Print();
        void Depth();
        void Width();
        int SearchForEqual();
        bool Search(int value);
        bool AnyTreeSearch(int value);
        Tree();
        ~Tree();
};

#endif