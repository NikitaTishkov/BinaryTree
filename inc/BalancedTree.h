#include "SearchTree.h"

template <class T> class CBalancedTree : public CSearchTree<T>
{
protected:
    CLeaf<T> *RotateRight(CLeaf<T> *pLeaf);
    CLeaf<T> *RotateLeft(CLeaf<T> *pLeaf);
    


public:
    CBalancedTree();
    ~CBalancedTree();

    CLeaf<T> *Balance(CLeaf<T> *pLeaf);

    CLeaf<T> *AddLeafRecur( CLeaf<T> *pLeaf, int iKeyNew, T tDataNew);

    void AddLeaf( int iKeyNew, T tDataNew);
    
};

/* Constructors */
template <class T> CBalancedTree<T>::CBalancedTree()
{

}

/* Destructor */
template <class T> CBalancedTree<T>::~CBalancedTree()
{
}

template <class T> CLeaf<T>* CBalancedTree<T>::RotateRight(CLeaf<T> *pLeaf)
{
    CLeaf<T> *pTemp = pLeaf->GetLeft();
    pLeaf->SetLeft(pTemp->GetRight());
    pTemp->SetRight(pLeaf);
    pLeaf->fixheight();
    pTemp->fixheight();
    return pTemp;
}

template <class T> CLeaf<T>* CBalancedTree<T>::RotateLeft(CLeaf<T> *pLeaf)
{
    CLeaf<T> *pTemp = pLeaf->GetRight();
    pLeaf->SetRight(pTemp->GetLeft());
    pTemp->SetLeft(pLeaf);
    pLeaf->fixheight();
    pTemp->fixheight();
    return pTemp;
}

/* Balance */
template <class T> CLeaf<T>* CBalancedTree<T>::Balance(CLeaf<T> *pLeaf)
{
    pLeaf->fixheight();
    if( pLeaf->bFactor() == 2)
    {
        if( pLeaf->GetRight()->bFactor() < 0 )
            pLeaf->SetRight(RotateRight(pLeaf->GetRight()));

        return RotateLeft(pLeaf);
    }
    if( pLeaf->bFactor() == -2 )
    {
        if( pLeaf->GetLeft()->bFactor() > 0 )
            pLeaf->SetLeft(RotateLeft(pLeaf->GetLeft()));

        return RotateRight(pLeaf);
    }
    return pLeaf;
}

/* Insert */

template <class T> CLeaf<T>* CBalancedTree<T>::AddLeafRecur( CLeaf<T> *pLeaf, int iKeyNew, T tDataNew)
{
    if( !pLeaf ) 
        return new CLeaf<T>(iKeyNew, tDataNew);
    
    if ( pLeaf->GetKey() == 0 )

        return new CLeaf<T>( iKeyNew, tDataNew);
    
    if (iKeyNew < pLeaf->GetKey())
        pLeaf->SetLeft(AddLeafRecur(pLeaf->GetLeft(), iKeyNew, tDataNew));
    else
        pLeaf->SetRight(AddLeafRecur(pLeaf->GetRight(), iKeyNew, tDataNew));

    return Balance(pLeaf);
}

template <class T> void CBalancedTree<T>::AddLeaf( int iKeyNew, T tDataNew)
{
    this->SetBegin(AddLeafRecur(this->GetBegin(), iKeyNew, tDataNew));
}