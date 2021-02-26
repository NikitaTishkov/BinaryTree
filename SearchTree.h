#include "Tree.h"

template <class T> class CSearchTree: public CBinaryTree
{
private:
    
public:

    CSearchTree();
    ~CSearchTree();

    virtual void AddLeaf(T ValNew);
    virtual void FindVal(T Val);
    

};


