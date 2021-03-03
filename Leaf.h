#ifndef LEAF_H
#define LEAF_H



template<class T> class CLeaf
{
private:
    int m_iKey;
    T m_tData;
    int m_iHeight;
    CLeaf* m_pLeft;
    CLeaf* m_pRight;
    //CLeaf* m_pParent;

public:

    CLeaf();
    CLeaf( int iKeyNew, T tDataNew);
    CLeaf( int iKeyNew);
    //CLeaf( int iKeyNew, T tDataNew,  CLeaf* pParentNew);
    //CLeaf( int iKeyNew, CLeaf* pParentNew);
    CLeaf( CLeaf &CopyObject );
    
    ~CLeaf();

    /* Setters */
    void SetKey(int iKeyNew);
    void SetData(T tDataNew);
    void SetHeight(int iHeightNew);
    void SetLeft(CLeaf *pLeftNew);
    void SetRight(CLeaf *pRightNew);
    //void SetParent(CLeaf *pParentNew);
    
    /* Getters */
    int GetKey() const;
    T GetData () const;
    int GetHeight() const;
    CLeaf *GetLeft() const;
    CLeaf *GetRight() const;
    //CLeaf *GetParent() const;

    /* Out */
    void ShowLeaf() const;

    int Height();
    int bFactor();
    void fixheight();

};

/* Default constructor */
template <class T> CLeaf<T>::CLeaf()
{
    this->m_iKey = 0;
    this->m_tData = 0;
    this->m_iHeight = 1;
    this->m_pLeft = nullptr;
    this->m_pRight = nullptr;
    //this->m_pParent = nullptr;
} 
/* Copy constructor */
template <class T> CLeaf<T>::CLeaf( CLeaf &CopyObject )
{
    this->m_iKey = CopyObject.m_iKey;
    this->m_tData = CopyObject.m_Data;
    this->m_iHeight = CopyObject.m_iHeight;
    this->m_pLeft = CopyObject.m_pLeft;
    this->m_pRight = CopyObject.m_pRight;
    //this->m_pParent = CopyObject.m_pParent; 
}
/* Custom constructors */
template <class T> CLeaf<T>::CLeaf( int iKeyNew, T tDataNew)
{
    this->m_iKey = iKeyNew;
    this->m_tData = tDataNew;
    this->m_iHeight = 1;
    //this->m_pParent = pParentNew;
    this->m_pLeft = nullptr;
    this->m_pRight = nullptr;
}

template <class T> CLeaf<T>::CLeaf( int iKeyNew)
{
    this->m_iKey = iKeyNew;
    this->m_tData = 0;
    this->m_iHeight = 1;
    //this->m_pParent = pParentNew;
    this->m_pLeft = nullptr;
    this->m_pRight = nullptr;
}

/* Destructor */
template <class T> CLeaf<T>::~CLeaf()
{
    //delete this->m_pLeft;
    //delete this->m_pRight;
    
}

/* Defining Setters */

template <class T> void CLeaf<T>::SetKey(int iKeyNew)
{
    this->m_iKey = iKeyNew;
}

template <class T> void CLeaf<T>::SetData(T tDataNew)
{
    this->m_tData = tDataNew;
}

template <class T> void CLeaf<T>::SetHeight(int iHeightNew)
{
    this->m_iHeight = iHeightNew;
}

template <class T> void CLeaf<T>::SetLeft(CLeaf *pLeftNew)
{
    this->m_pLeft = pLeftNew;
}

template <class T> void CLeaf<T>::SetRight(CLeaf *pRightNew)
{
    this->m_pRight = pRightNew;
}
/*
template <class T> void CLeaf<T>::SetParent(CLeaf *pParentNew)
{
    this->m_pParent = pParentNew;
}
*/
/* Defining Getters */
template <class T> int CLeaf<T>::GetKey () const
{
    return this->m_iKey;
}

template <class T> T CLeaf<T>::GetData () const
{
    return this->m_tData;
}

template <class T> int CLeaf<T>::GetHeight() const
{
    return this->m_iHeight;
}

template<class T> CLeaf<T> *CLeaf<T>::GetLeft() const
{
    return this->m_pLeft;
}

template <class T> CLeaf<T> *CLeaf<T>::GetRight() const
{
    return this->m_pRight;
}
/*
template <class T> CLeaf<T> *CLeaf<T>::GetParent() const
{
    return this->m_pParent;
}
*/
/* Out */
template <class T> void CLeaf<T>::ShowLeaf() const
{
    std::cout << "Key: " << m_iKey
              << " Data: " << m_tData << std::endl;
}

/* Height helpers */

template <class T> int CLeaf<T>::Height()
{
    return (this) ? this->GetHeight() : 0;
}

template <class T> int CLeaf<T>::bFactor()
{
    return this->GetRight()->Height() - this->GetLeft()->Height();
}

template <class T> void CLeaf<T>::fixheight()
{
    int hl = this->GetLeft()->Height();
    int hr = this->GetRight()->Height();
    this->SetHeight( ((hl > hr) ? hl : hr) + 1);
}

#endif
