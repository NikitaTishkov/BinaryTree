#include <iostream>
#include "SearchTree.h"

using std::cout;
using std::endl;

int main()
{
    CSearchTree<double> MyTree;
    int array[10] = {15, 13, 19, 6, 14, 18, 3, 17, 16, 11};
    double data[10] = {27.3, 26, 23, 32, 53, 456, 43, 43, 43, 10};
    for(int i = 0; i < 10; i++)
    {
        MyTree.AddLeaf( array[i], data[i]);
    }

    MyTree.ShowSorted();

    cout << "find 13: " << MyTree.FindValByKey(13) << endl;

    /*
    cout << MyTree.GetBegin()->GetKey() << endl;
    cout << MyTree.GetBegin()->GetData() << endl;

    cout << MyTree.GetBegin()->GetRight()->GetKey() << endl;
    cout << MyTree.GetBegin()->GetRight()->GetData() << endl;

    cout << MyTree.GetBegin()->GetLeft()->GetKey() << endl;
    cout << MyTree.GetBegin()->GetLeft()->GetData() << endl;

    cout << MyTree.GetBegin()->GetRight()->GetLeft()->GetKey() << endl;
    cout << MyTree.GetBegin()->GetRight()->GetLeft()->GetData() << endl;

    cout << MyTree.GetBegin()->GetLeft()->GetLeft()->GetRight()->GetKey() << endl;
    cout << MyTree.GetBegin()->GetLeft()->GetLeft()->GetRight()->GetData() << endl;*/
    return 0;
}