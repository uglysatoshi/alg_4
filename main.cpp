#include "helpers.cpp"
#include "tree.cpp"

int main()
{
    int n;
    Tree tree;
    tree.RandInsert(20);
    tree.Print();
    cout << "Max node = " << tree.SearchForMax(tree.GetTreeRoot()) << endl;
    cout << "Min node = " << tree.SearchForMin(tree.GetTreeRoot()) << endl;
    cout << "Total Nodes = " << tree.TotalNodes() << endl;
    cout << "Total Leafs = " << tree.TotalLeafs() << endl;
    cout << "Height of the tree = " << tree.Height() << endl;
    tree.SearchForEqual();
    return 0;
}