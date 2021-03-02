
#include "Leaf.h"
/* Class definition */
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
    CLeaf<T>* GetBegin() const;
};

/* Recursive delete function for destructor */
template <class T> void CBinaryTree<T>::DeleteTree(CLeaf<T> *pLeaf)
{
    
    if (pLeaf != nullptr)
    {
        DeleteTree(pLeaf->GetLeft());

        DeleteTree(pLeaf->GetRight());
        delete pLeaf;
        pLeaf = nullptr;
    }
    //this->m_pBegin = nullptr;
    
}

/* Constructor */
template <class T> CBinaryTree<T>::CBinaryTree()
{
    this->m_pBegin = new CLeaf<T>();
}

/* Destructor */
template <class T> CBinaryTree<T>::~CBinaryTree()
{
    
    DeleteTree(m_pBegin);
}

/* Setters */
template <class T> void CBinaryTree<T>::SetBegin(CLeaf<T> pBeginNew)
{
    this->m_pBegin = new CLeaf<T>();
}

/* Getters */
template <class T> CLeaf<T>* CBinaryTree<T>::GetBegin() const
{
    return this->m_pBegin;
}