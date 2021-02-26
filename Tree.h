#include "Leaf.h"

template <class T> class CBinaryTree
{
protected:
    CLeaf<T> *m_pBegin;
    void DeleteTree(CLeaf<T> *pLeaf);
private:
    
    
public:
    CBinaryTree();
    ~CBinaryTree();

    void SetBegin(CLeaf<T> pBeginNew);
    CLeaf<T> GetBegin() const;
};

