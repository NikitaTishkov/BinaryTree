#include "Leaf.h"

/* Default constructor */
template <class T> CLeaf<T>::CLeaf()
{
    this->m_Data = NULL;
    this->m_pLeft = nullptr;
    this->m_pRight = nullptr;
    this->m_pParent = nullptr;
} 
/* Copy constructor */
template <class T> CLeaf<T>::CLeaf( CLeaf &CopyObject )
{
    this->m_Data = CopyObject.m_Data;
    this->m_pLeft = CopyObject.m_pLeft;
    this->m_pRight = CopyObject.m_pRight;
    this->m_pParent = CopyObject.m_pParent; 
}
/* Custom constructor */
template <class T> CLeaf<T>::CLeaf(T DataNew,  CLeaf* pParentNew)
{
    this->m_iData = DataNew;
    this->m_pParent = pParentNew;
    this->m_pLeft = nullptr;
    this->m_pRight = nullptr;
}

/* Destructor */
template <class T> CLeaf<T>::~CLeaf()
{
    delete this->m_pLeft;
    delete this->m_pRight;
    delete this->m_pParent;
}

/* Defining Setters */
template <class T> void CLeaf<T>::SetData(T DataNew)
{
    this->m_Data = DataNew;
}

template <class T> void CLeaf<T>::SetLeft(CLeaf *pLeftNew)
{
    this->m_pLeft = pLeftNew;
}

template <class T> void CLeaf<T>::SetRight(CLeaf *pRightNew)
{
    this->m_pRight = pRightNew;
}

template <class T> void CLeaf<T>::SetParent(CLeaf *pParentNew)
{
    this->m_pParent = pParentNew;
}

/* Defining Getters */
template <class T> T CLeaf<T>::GetData () const
{
    return this->m_Data;
}

template<class T> CLeaf<T> *CLeaf<T>::GetLeft() const
{
    return this->m_pLeft;
}

template <class T> CLeaf<T> *CLeaf<T>::GetRight() const
{
    return this->m_pRight;
}

template <class T> CLeaf<T> *CLeaf<T>::GetParent() const
{
    return this->m_pParent;
}


