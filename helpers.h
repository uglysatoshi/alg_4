#ifndef HELPERS
#define HELPERS

#include "tree.h"

// Нода стэка
class SNode
{
    public:
        TNode* data;
        SNode* pNext;
        SNode(TNode* node = NULL, SNode* pNext = nullptr)
        {
            this -> data = node;
            this -> pNext = pNext;
        }
};

// Стэк
class Stack
{
    private:
        int Size;
        SNode* head;
    public:
        Stack();
        ~Stack();
        void push(TNode* node);
        TNode* pop();
        int GetSize();
};

// Нода очереди
class QNode
{   
    public:
        TNode* data;
        QNode* pNext;
        QNode* pPrev;
        QNode(TNode* node = NULL, QNode* pNext = nullptr)
        {
            this -> data = node;
            this -> pNext = pNext;
        };
};

// Очередь
class Queue
{
    private:
        int Size;
        QNode *head;
        QNode *last;
    public:    
        Queue();
        ~Queue();
        void push(TNode* node);
        TNode* pop();
        int GetSize();
};


#endif 