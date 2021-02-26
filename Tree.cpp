#include "Tree.h"

template <class T> CBinaryTree<T>::CBinaryTree()
{
    this->m_pBegin = new CLeaf<T>();
}

template <class T> CBinaryTree<T>::~CBinaryTree()
{
    
    DeleteTree(this->m_pBegin);
}

template <class T> void CBinaryTree<T>::SetBegin(CLeaf<T> pBeginNew)
{
    this->m_pBegin = new CLeaf<T>();
}

template <class T> void CBinaryTree<T>::DeleteTree(CLeaf<T> *pLeaf)
{
    bool bStatus = false;
    
    if(pLeaf->m_pLeft == nullptr && pLeaf->m_pRight == nullptr)
    {
        bStatus = true;
        delete pLeaf;
    }
    if(pLeaf->m_pLeft != nullptr && !bStatus)
    {
        DeleteTree(pLeaf->m_pLeft);
    }
    if(pLeaf->m_pRight != nullptr && !bStatus)
    {
        DeleteTree(pLeaf->m_pRight);
    }

    if(bStatus && pLeaf->m_pParent != nullptr)
    {
        DeleteTree(pLeaf->m_pParent);
    }
    
    
    
}




int main()
{

}