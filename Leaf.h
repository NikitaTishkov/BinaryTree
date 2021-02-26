template<class T> class CLeaf
{
private:
    T m_tData;
    CLeaf* m_pLeft;
    CLeaf* m_pRight;
    CLeaf* m_pParent;

public:

    CLeaf();
    CLeaf(T tDataNew,  CLeaf* pParentNew);
    CLeaf( CLeaf &CopyObject );
    
    ~CLeaf();

    /* Setters */
    void SetData(T tDataNew);
    void SetLeft(CLeaf *pLeftNew);
    void SetRight(CLeaf *pRightNew);
    void SetParent(CLeaf *pParentNew);
    
    /* Getters */

    T GetData () const;
    CLeaf *GetLeft() const;
    CLeaf *GetRight() const;
    CLeaf *GetParent() const;


};