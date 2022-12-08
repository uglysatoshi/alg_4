#ifndef TREE
#define TREE

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// Узел дерева
class TNode 
{
    public:
        int data; // значение узла
        TNode *pRight; // указатель на правый элемент
        TNode *pLeft; // указатель на левый элемент
        TNode *pPrev; // Указатель на предыдущий элемент

};

// Дерево
class Tree
{  
    private:
        TNode *root; // корень дерева

        // Рекурсивные функции 
        TNode* RecursionSearch(TNode* node, int value); 
        TNode* RecursionInsert(TNode* node, int value);
        TNode* RemoveByValueRecursion(TNode* node, int value);
        TNode* RemoveMinRecursion(TNode* node);
        void ClearTreeBranchRecursion(TNode* node);
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
        TNode* CreateTreeElement(int value);  // Создание элемента 
        void ClearTree(); // Функция очистки дерева
        void ClearBranch(int value); // Функция очистки ветви
        int TotalLeafs(); // Функция подсчета листьев
        int TotalNodes();  // Функция подсчета узлов
        int SearchForMax(TNode* node); // Функция нахождения максимального элемента
        int SearchForMin(TNode* node); // Функция нахождения минимального элемента
        int NextNode(int value); // Функция нахождения элемента меньше  
        int PreNode(int value); // Функция нахождения элемента больше 
        int Extent(int value); // Функция определения степени элемента
        int Level(int value); // Функция определения уровня элмента
        int Height(); // Функция нахождения высоты дерева
        void Insert(int value); // Функция ввода в дерево
        void RemoveByValue(int value); // Функция удаления элемента по значению
        void RandInsert(int value); // Функция ввода псевдо-случайных значений в древо
        void RemoveMin(); // Функция удаления минимального элемента
        void Print(); // Вывод дерева
        void Depth(); // Функция обхода в глубину
        void Width(); // Функция обхода в ширину
        int SearchForEqual(); // Функция поиска одинаковых значений
        bool Search(int value); // Функция поиска по БДП
        bool AnyTreeSearch(int value); // Функиц поиска по любому дереву
        Tree(); // конструктор 
        ~Tree(); // деструктор
};

#endif