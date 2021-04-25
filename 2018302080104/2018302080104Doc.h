
// 2018302080104Doc.h : CMy2018302080104Doc ��Ľӿ�
//


#pragma once


class CMy2018302080104Doc : public CDocument
{
protected: // �������л�����
	CMy2018302080104Doc();
	DECLARE_DYNCREATE(CMy2018302080104Doc)

// ����
public:
	CPoint group[100];//��������
	int PointNum;
	COLORREF m_crColor;//����ͼ����ɫ

// ����
public:
	void DDALine(CClientDC *DCPoint);//����DDA����
	void MIDLine(CClientDC *DCPoint);//�����е�ֱ�ߺ���
	void BCircle(CClientDC *DCPoint,CPoint p1,CPoint p2);// ����Bresanham����Բ
	void PNCircle(CClientDC*DCPoint,CPoint p1,CPoint p2);// ��������������Բ����
	void Bezier(CClientDC *DCPoint,int mode);//����Bezier ���ߺ���
	void Bezier_4(CClientDC *DCPoint,int mode,CPoint p1,CPoint p2,CPoint p3,CPoint p4);//���������ĸ����Ƶ�����һ�� Bezier ���ߵĺ���
	void GenerateGraph(CClientDC*DCPoint);
	void GenerateGraph2(CClientDC*DCPoint);
	void DrawGraph(CClientDC*DCPoint);
	void Symmetry(CPoint p1,CPoint p2);
	void SeedFill(CClientDC *DCPoint,CPoint p);
	void EdgeFill(CClientDC *pDC);
	void DrawWindow(CClientDC *DCPoint);
	void CohenSutherland(CClientDC *DCPoint,CPoint p1,CPoint p2);
	int encode(int x,int y);
	void PolygonCut(CClientDC *DCPoint);
	void EdgeClipping(int linecode);
	void Bsampl(CClientDC *DCPoint,int mode);
	void cutmiddle(CClientDC *DCPoint,CPoint p1,CPoint p2);
	void cutLBarsky(CClientDC *DCPoint,CPoint p1,CPoint p2);
	void Hermite(CClientDC *DCPoint,int mode);
	void BCircle(CClientDC*DCPoint,CRect *rc,CPoint p1,CPoint p2);
	void CutCircle(CClientDC *DCPoint,CPoint p1,CPoint p2);


// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy2018302080104Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSetcolor();
};
