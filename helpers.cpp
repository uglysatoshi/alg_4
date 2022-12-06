#include "helpers.h"

Stack :: Stack()
{
    head = nullptr;
    Size = 0;
}

Stack :: ~Stack()
{
    while(Size)
        pop();
}

void Stack :: push(TNode* node)
{
    head = new SNode(node);
    Size++;
}

TNode* Stack :: pop()
{
    if (head == nullptr)
        return NULL;
    TNode* out = head -> data;
    SNode* temp = head;
    head = head -> pNext;
    delete temp;
    Size--;
    return out;
}

int Stack :: GetSize() {return Size;}

// ----

Queue :: Queue()
{
    head = nullptr;
    last = nullptr;
    Size = 0;
}

Queue :: ~Queue()
{

}

int Queue :: GetSize(){return Size;}

void Queue :: push(TNode* node)
{
    QNode *temp = new QNode(node); 
    if (head == nullptr)
    {
        head = temp;
        last = temp;
        Size ++;
        return;
    }
    else
    {
        last -> pNext = temp;
        temp -> pPrev = last;
        last = temp;
    }
    Size ++;
}

TNode* Queue :: pop()
{
    if (last == nullptr)
        return NULL;
    TNode* out = head -> data;
    QNode* temp = head;
    head = head -> pNext;
    delete temp;
    Size--;
    return out;
}