
#include "Tree.h"
using std::cout;
using std::endl;


/* Class definition */
template <class T> 
class CSearchTree : public CBinaryTree<T> {
private:

    virtual void AddLeafRecur(int iKeyNew, T tValNew, CLeaf<T>* pBegin);
    virtual void ShowSortedRecur(CLeaf<T> *pLeaf);

public:

    CSearchTree();
    ~CSearchTree();

    virtual void AddLeaf(int iKeyNew, T tValNew);
    virtual void ShowSorted();
    virtual T FindValByKey(int iKeyNew);
    

};

/*  Constructor */
template <class T> CSearchTree<T>::CSearchTree()
{

}
/* Destructor */
template <class T> CSearchTree<T>::~CSearchTree()
{

}
/* Recursive function for adding element to the tree */
template <class T> void CSearchTree<T>::AddLeafRecur( int iKeyNew, T tValNew, CLeaf<T>* pBegin)
{
    
    if(pBegin->GetKey() == 0)
    {
        pBegin->SetKey(iKeyNew);
        pBegin->SetData(tValNew);
        
    }
    else if(iKeyNew >= pBegin->GetKey())
    {
        if(pBegin->GetRight() != nullptr)
        {
            
            AddLeafRecur( iKeyNew, tValNew, pBegin->GetRight());
            
        }else
        {
            pBegin->SetRight(new CLeaf<T>( iKeyNew, tValNew, pBegin)); 
            
        }
    }
    else if(iKeyNew < pBegin->GetKey())
    {
         if(pBegin->GetLeft() != nullptr)
        {
            
            AddLeafRecur( iKeyNew, tValNew, pBegin->GetLeft());
        }else
        {
            pBegin->SetLeft(new CLeaf<T>( iKeyNew, tValNew, pBegin)); 
            
        }
    }
};

/* wrapper for add leaf */
template <class T> void CSearchTree<T>::AddLeaf( int iKeyNew, T tValNew)
{
    AddLeafRecur( iKeyNew, tValNew, this->m_pBegin);
}
/* Finding data by key */
template <class T> T CSearchTree<T>::FindValByKey(int iKeyNew)
{
    CLeaf<T> *curLeaf = this->m_pBegin;
    while(curLeaf->GetKey() != iKeyNew)
    {
        if(iKeyNew < curLeaf->GetKey())
        {
            curLeaf = curLeaf->GetLeft();
        }
        else if(iKeyNew > curLeaf->GetKey())
        {
            curLeaf = curLeaf->GetRight();
        }

        
    } 
    return curLeaf->GetData();
}
/* TODO: Finding first Key By Value */
/* Out */

/*Show Helper*/
template <class T> void CSearchTree<T>::ShowSortedRecur(CLeaf<T> *pLeaf)
{
    if(pLeaf != nullptr)
        /* visit left branch */
        if(pLeaf->GetLeft() != nullptr)
            ShowSortedRecur(pLeaf->GetLeft());

        /* visit current */
        pLeaf->ShowLeaf();

        /* visit right branch */
        if(pLeaf->GetRight() != nullptr)
            ShowSortedRecur(pLeaf->GetRight());
}
/* show wrapper */
template <class T> void CSearchTree<T>::ShowSorted()
{
    ShowSortedRecur(this->m_pBegin);
}
