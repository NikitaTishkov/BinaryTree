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
    
    if(pLeaf->GetLeft() == nullptr && pLeaf->GetRight() == nullptr)
    {
        bStatus = true;
        delete pLeaf;
    }
    if(pLeaf->GetLeft() != nullptr && !bStatus)
    {
        DeleteTree(pLeaf->GetLeft());
    }
    if(pLeaf->GetRight() != nullptr && !bStatus)
    {
        DeleteTree(pLeaf->GetRight());
    }

    if(bStatus && pLeaf->GetParent() != nullptr)
    {
        DeleteTree(pLeaf->GetParent());
    }
    
    
    
}




int main()
{

}