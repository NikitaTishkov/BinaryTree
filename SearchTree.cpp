#include "SearchTree.h"

template <class T> CSearchTree<T>::CSearchTree()
{
    CBinaryTree<T>();
    
}

template <class T> CSearchTree<T>::~CSearchTree()
{
    ~CBinaryTree();
}

template <class T> void CSearchTree<T>::AddLeaf(T ValNew)
{
    /* TODO: Making AddLeaf() */
    CLeaf<T> *pCur = this->m_pBegin;

    while(true)
    {
        if(ValNew >= pCur->GetData())
        {

        }
    }
}

/* TODO: Create FindVal() */