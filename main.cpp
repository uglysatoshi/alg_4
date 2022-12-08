#include "helpers.cpp"
#include "tree.cpp"

int main()
{
    Tree tree;
    tree.RandInsert(15);
    tree.Print();
    int n;
    cout << "Введите значение одной из вершин дерева: "; cin >> n; 

    if (tree.Search(n))
        cout << "Вершина найдена!" << endl;
    else 
        cout << "Вершина не найдена!" << endl;
    
    cout << "В дереве находится " << tree.TotalNodes() << " узлов" << endl;
    cout << "В дереве находится " << tree.TotalLeafs() << " листьев" << endl;
    cout << "Степень вершины " << n << ": " << tree.Extent(n) << endl;
    cout << "Уровень вершины " << n << ": " << tree.Level(n) << endl;
    cout << "Высота дерева: " << tree.Height() << endl;
    cout << "Поиск переменной " << n << ": " << endl;

    if (tree.AnyTreeSearch(n))
        cout << "Вершина найдена!" << endl;
    else 
        cout << "Вершина не найдена!" << endl;
    
    cout << "Итеративный обход дерева в глубину:" << endl;
    tree.Depth();
    cout << "Итеративный обход дерева в ширину: " << endl;
    tree.Width();
    cout << "Поиск одинаковых элементов: " << endl;
    tree.SearchForEqual();
    cout << "Удаление элемента [" << n << "]" << endl;
    tree.RemoveByValue(n);
    cout << "Вывод дерева после удаления элемента [" << n << "]" << endl;
    tree.Print();
    cout << "Введите новый элемент n: "; cin >> n;
    cout << "Вывод дерева после удаления поддрева от элемента [" << n << "]" << endl; 
    tree.ClearBranch(n);
    tree.Print();
    cout << "Удаление дерева и выход из программы" << endl;
    return 0;
}