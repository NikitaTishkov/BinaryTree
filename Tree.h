#include "Leaf.h"

template <class T> class CBinaryTree
{
private:
    CLeaf<T> *m_pBegin;
    void DeleteTree(CLeaf<T> *pLeaf);
public:
    CBinaryTree();
    ~CBinaryTree();

    void SetBegin(CLeaf<T> pBeginNew);
    CLeaf<T> GetBegin() const;

    virtual bool AddLeaf() = 0;
    


};

