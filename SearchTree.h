#include <iostream>
#include "Tree.h"
using std::cout;
using std::endl;

/* class that contents sorteded arrays */
template <class T> class CSortedArr
{
public:
    /* Arrays */
    int *m_iaKeyArr;
    T *m_aArr;
    int fullness;
    CSortedArr()
    {
        this->fullness = 0;
    }

    ~CSortedArr()
    {
        if(m_aArr != nullptr)
            delete [] m_aArr;

        if(m_iaKeyArr != nullptr)
            delete [] m_iaKeyArr;
    }
};

/* Class definition */
template <class T> 
class CSearchTree : public CBinaryTree<T> {
protected:

    void AddLeafRecur(int iKeyNew, T tValNew, CLeaf<T>* pBegin);
    void ShowSortedRecur(CLeaf<T> *pLeaf) const;
    void GetSortedRecur(CSortedArr<T> *pSortedStruct, CLeaf<T> *pLeaf);

public:

    CSearchTree();
    ~CSearchTree();

    virtual void AddLeaf(int iKeyNew, T tValNew);
    void ShowSorted() const;
    void GetSortedArray(CSortedArr<T> *aSorted);
    T FindValByKey(int iKeyNew);
    

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
            pBegin->SetRight(new CLeaf<T>( iKeyNew, tValNew)); 
            
        }
    }
    else if(iKeyNew < pBegin->GetKey())
    {
         if(pBegin->GetLeft() != nullptr)
        {
            
            AddLeafRecur( iKeyNew, tValNew, pBegin->GetLeft());
        }else
        {
            pBegin->SetLeft(new CLeaf<T>( iKeyNew, tValNew)); 
            
        }
    }
};

/* wrapper for add leaf */
template <class T> void CSearchTree<T>::AddLeaf( int iKeyNew, T tValNew)
{
    AddLeafRecur( iKeyNew, tValNew, this->m_pBegin);
    this->m_iSize++;
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

/* Out */

/*Show Helper*/
template <class T> void CSearchTree<T>::ShowSortedRecur(CLeaf<T> *pLeaf) const
{
    if(pLeaf != nullptr)
    {
        /* visit left branch */
        if(pLeaf->GetLeft() != nullptr)
            ShowSortedRecur(pLeaf->GetLeft());

        /* visit current */
        pLeaf->ShowLeaf();

        /* visit right branch */
        if(pLeaf->GetRight() != nullptr)
            ShowSortedRecur(pLeaf->GetRight());
    }
}
/* show wrapper */
template <class T> void CSearchTree<T>::ShowSorted() const
{
    ShowSortedRecur(this->m_pBegin);
}

/* Getting struct with sorted arrays */
template <class T> void CSearchTree<T>::GetSortedRecur(CSortedArr<T> *pSortedStruct, CLeaf<T> *pLeaf)
{
    if(pLeaf != nullptr)
        /* visit left branch */
        if(pLeaf->GetLeft() != nullptr)
            GetSortedRecur( pSortedStruct ,pLeaf->GetLeft());

        /* visit current */
        pSortedStruct->m_iaKeyArr[pSortedStruct->fullness] = pLeaf->GetKey();
        pSortedStruct->m_aArr[pSortedStruct->fullness] = pLeaf->GetData();
        pSortedStruct->fullness++;

        /* visit right branch */
        if(pLeaf->GetRight() != nullptr)
            GetSortedRecur( pSortedStruct ,pLeaf->GetRight());
}

/* ... wrapper */
template <class T> void CSearchTree<T>::GetSortedArray( CSortedArr<T> *aSorted)
{
    aSorted->m_aArr = new T[this->m_iSize];
    aSorted->m_iaKeyArr = new int[this->m_iSize];
    aSorted->fullness = 0;
    GetSortedRecur(aSorted, this->m_pBegin);
}