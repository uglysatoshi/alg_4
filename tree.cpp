#include "helpers.h"

// Конструктор древа
Tree :: Tree()
{
    root = NULL; // передача NULL корню дерева для исключения проблем
}

// Деструктор древа
Tree :: ~Tree()
{
    ClearTree();
}

// Функция для создания узла древа
TNode* Tree :: CreateTreeElement(int value)
{
    TNode* node = new TNode;
    node -> data = value;
    node -> pLeft = NULL;
    node -> pRight = NULL;
    node ->pPrev = NULL;
    return node;
}

// Рекурсиваная функция ввода в древо
TNode* Tree :: RecursionInsert(TNode* node, int value)
{
    if (node == NULL)
    {
        node = CreateTreeElement(value);
    }
    else 
    {
        if (node -> data < value)
        {
            node -> pRight = RecursionInsert(node -> pRight, value);
            node ->pRight -> pPrev = node;
        }
        else 
        {
            node -> pLeft = RecursionInsert(node -> pLeft, value);
            node -> pLeft -> pPrev = node;
        }
    }
    return node;
}

// Функция для передачи значения после отработки рекурсивной функции
void Tree :: Insert(int value)
{
    if (!(Search(value)))
        return;
    root = RecursionInsert(root, value);

}

// Рекурсивная функция поиска по древу
TNode* Tree :: RecursionSearch(TNode* node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }
    else 
    {
        if(node -> data == value)
        {
            return node;
        }
        else
        {
            if(node -> data < value)
            {
                return RecursionSearch(node -> pRight, value);
            }
            else
            {
                return RecursionSearch(node -> pLeft, value);
            }
        }
    }
}

// Функция для передачи значения после отработки рекурсивной функции
bool Tree :: Search(int value)
{
    TNode* res = RecursionSearch(root, value);
    return res == NULL;
}

// Функция заполнения дерева случайными значениями
void Tree :: RandInsert(int value)
{
    srand(500);
    for (int i = 0; i < value; i++)
    {
        Insert(rand()%200);
    }
}

// Функция конечного вывода
void Tree :: Print()
{
    RecursionPrint(root, 0);
}

// Рекурсивная функция печати по древу
void Tree :: RecursionPrint(TNode* node, int padding)
{
    if (node != NULL && node -> data != 0)
    {
        cout << setw(padding) << ' ' << setw(0) << " [" << node -> data << "] " << endl;
        padding += 2;
        RecursionPrint(node -> pLeft, padding);
        RecursionPrint(node -> pRight, padding);
    }
}

// Функция выдачи ссылки на корень древа
TNode* Tree :: GetTreeRoot()
{
    return root;
}


// Рекурсивная функция удаления с перестройкой
TNode* Tree :: RemoveByValueRecursion(TNode* node, int value)
{
    if (node == NULL)
        return NULL;
    TNode* temp = node; // задание временной переменной для передачи
                        // и последующего удаления
    if (node -> data == value)
    {
        if (node -> pLeft ==  NULL && node -> pRight == NULL) // 1) Если нет потомков
        {
            node = NULL;
            delete temp;
        }
        else
        {
            if(node -> pLeft == NULL && node -> pRight != NULL) // 2) Имеется потомок справа
            {
                node -> pRight -> pPrev = node -> pPrev;
                node =  node -> pRight;
                delete temp;
            }
            else
            {
                if(node -> pLeft != NULL && node -> pRight == NULL) // 2) Имеется потомок слева
                {
                    node -> pLeft -> pPrev = node -> pPrev;
                    node = node -> pRight;
                    delete temp;
                }
                else  // 3) Имеется оба потомка
                {
                    int NextData = NextNode(value);
                    node -> data = NextData;
                    RemoveMin();
                }
                    
            }
        }
    }
    else
    {
        if (node -> data < value)
        {
            node -> pRight = RemoveByValueRecursion(node -> pRight, value);
        }
        else 
        {
            node -> pLeft = RemoveByValueRecursion(node -> pLeft, value);
        }
    }
    return node;
}



// Функция передачи конечного значения после удаления элемента
// и перестройки дерева
void Tree :: RemoveByValue(int value)
{
    root = RemoveByValueRecursion(root, value);
}

// Функция поиска элемента больше минимального
int Tree :: NextNode(int value)
{
    TNode* d = RecursionSearch(root, value);
    if (d == NULL)
        return -1;
    else    
        return NextNodeRecursion(d);
}

// Рекурсивная функция поиска элемента больше минимального
int Tree :: NextNodeRecursion(TNode* node)
{
    if (node == NULL)
        return -1;
    if (node -> pRight != NULL)
        return SearchForMin(node -> pRight);
    else
    {
        TNode* prev = node -> pPrev;
        TNode* curr = node;

        while((prev != NULL) && curr == prev -> pRight)
        {
            curr = prev;
            prev = curr -> pPrev;
        }
        if (prev == NULL)
            return -1;
        else 
            return prev -> data;
    }
}

// Функция поиска элемента меньше максимального
int Tree :: PreNode(int value)
{
    TNode* temp = RecursionSearch(root, value);
    if (temp == NULL)
        return -1;
    else   
        return PreNodeRecursion(temp);
}

// Функция поиска элемента меньше максимального
int Tree :: PreNodeRecursion(TNode* node)
{
    if (node == NULL)
        return -1;
    if (node -> pLeft != NULL)
        return SearchForMax(node -> pLeft);
    else
    {
        TNode* prev = node -> pPrev;
        TNode* curr = node;

        while((prev != NULL) && curr == prev -> pLeft)
        {
            curr = prev;
            prev = curr -> pPrev;
        }
        if (prev == NULL)
            return -1;
        else 
            return prev -> data;
    }
}

// Рекурсивная функция поиска минимального значения
int Tree :: SearchForMinRecursion(TNode* node)
{
    if (node == NULL)
        return -1;
    else 
    {
        if (node -> pLeft == NULL)
            return node -> data;
        else
            return SearchForMinRecursion(node -> pLeft);
    }
}

// Функция выводящая минимальноное значение древа
int Tree :: SearchForMin(TNode* node)
{
    return SearchForMinRecursion(root); 
}

// Рекурсивная функция поиска максимального значения
int Tree :: SearchForMaxRecursion(TNode* node)
{
    if (node == NULL)
        return -1;
    else 
    {
        if(node -> pRight == NULL)
            return node -> data;
        else 
            return SearchForMaxRecursion(node -> pRight);
    }
}

// Функция выводящая 
int Tree :: SearchForMax(TNode* node)
{
    return SearchForMaxRecursion(root); 
}

// Функция удаления минимального значения древа
void Tree :: RemoveMin()
{
    root = RemoveMinRecursion(root);
}

// Рекурсивная функция поиска и удаления минимального значения древа
TNode* Tree :: RemoveMinRecursion(TNode* node)
{
    TNode* temp = node;
    if (node == NULL)
        return NULL;
    else 
    {
        if (node -> pLeft == NULL)
        {
            if(node -> pLeft == NULL && node -> pRight != NULL)
            {
                node -> pRight -> pPrev = node -> pPrev;
                node =  node -> pRight;
                delete temp;
            }
            else
            {
                node = NULL;
                delete temp;
            }
        }
        else
           node -> pLeft = RemoveMinRecursion(node -> pLeft);
    }
    return node;
}

int Tree :: TotalNodesRecursion(TNode* node)
{
    if(node == NULL)
        return 0;
    int LeftSide = TotalNodesRecursion(node -> pLeft);
    int RightSide = TotalNodesRecursion(node -> pRight);
    return 1 + LeftSide + RightSide; // Выводим значение двух счетчиков + учитываем корень
}

int Tree :: TotalNodes()
{
    return TotalNodesRecursion(root);
}

int Tree :: TotalLeafs()
{
    return TotalLeafsRecursion(root);
}

int Tree :: TotalLeafsRecursion(TNode* node)
{
    if (node == NULL)
        return 0;
    if (node -> pLeft == NULL && node -> pRight == NULL)
        return 1;
    else    
        return TotalLeafsRecursion(node -> pLeft) + TotalLeafsRecursion(node ->pRight);
}

int Tree :: Extent(int value)
{
    TNode* temp = RecursionSearch(root, value);
    if (temp == NULL)
        return -1;
    else
    {
        if(temp -> pRight == NULL && temp -> pLeft == NULL)
            return 0;
        else
        {
            if(temp -> pLeft != NULL && temp -> pRight != NULL)
                return 2;
            else
                return 1;
        }
    }
    
}

int Tree :: Level(int value)
{
    TNode* temp = RecursionSearch(root, value);
    if (temp == NULL)
        return -1;
    int cnt = 0;
    while(temp -> pPrev != NULL)
    {
        cnt ++;
        temp = temp -> pPrev;
    }
    return cnt;
}

int Tree :: HeightRecursion(TNode* node)
{
    if(node == NULL)
        return -1;
    int LeftSide = HeightRecursion(node -> pLeft);
    int RightSide = HeightRecursion(node -> pRight);
    int res;
    if(RightSide > LeftSide)
        res = RightSide;
    else
        res = LeftSide;
    return 1 + res;
}

int Tree :: Height()
{
    return HeightRecursion(root);
}

bool Tree :: AnyTreeSearchRecursion(TNode* node, int value)
{
    if (node == NULL)
        return 0;
    if (node -> data == value)
        return 1;
    bool LeftSide = AnyTreeSearchRecursion(node -> pLeft, value);
    bool RightSide = AnyTreeSearchRecursion(node -> pRight, value);
    return (LeftSide or RightSide);
}

bool Tree :: AnyTreeSearch(int value)
{
    return AnyTreeSearchRecursion(root, value);
} 

void Tree :: ClearBranch(int value)
{
    TNode* temp = RecursionSearch(root, value);
    if (temp == NULL)
        return;
    TNode* p = temp -> pPrev;
    if (p != NULL)
    {
        if (temp -> data > value)
            p -> pRight = NULL;
        else 
            p -> pLeft = NULL;
    }       
    ClearTreeBranchRecursion(temp);
    temp = NULL;
}

void Tree :: ClearTreeBranchRecursion(TNode* node)
{
    if (node == NULL)
        return;
    ClearTreeBranchRecursion(node -> pLeft);
    ClearTreeBranchRecursion(node -> pRight);
    delete node;
}

void Tree :: ClearTree()
{
    ClearTreeBranchRecursion(root);
    root = NULL;
}

void Tree :: WidthIteration(TNode* node)
{
    Queue queue;
    queue.push(node);
    while(queue.GetSize() != 0)
    {
        TNode* temp = queue.pop();
        cout << temp -> data << ' ';
        if(temp -> pLeft)
            queue.push(temp -> pLeft);
        if(temp ->pRight)
            queue.push(temp -> pRight);   
    }
    cout << endl;
} 

void Tree :: Width() {WidthIteration(root);}

void Tree :: DepthIteration(TNode* node)
{
    Stack stack;
    while((stack.GetSize() != 0) or node != NULL)
    {
        if (node != NULL)
        {
            stack.push(node);
            node = node -> pLeft;
        }
        else
        {
            node = stack.pop();
            cout << node -> data << ' ';
            node = node -> pRight;
        }
    }
    cout << endl;
}

void Tree :: Depth() {DepthIteration(root);}

int Tree :: SearchForEqual()
{
    if(SearchForEqualRecursion(root) > 0)
        cout << "Древо имеет одинаковые элементы" << endl;
    else
        cout << "Дерево не имеет одинаковых элементов" << endl;
}

int Tree :: SearchForEqualRecursion(TNode* node)
{
    if (node == NULL)
        return NULL;
    if(Search(node -> data))
        return node -> data;
    else
    {
        SearchForEqualRecursion(node -> pRight);
        SearchForEqualRecursion(node -> pLeft);
    }
}