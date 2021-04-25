
// 2018302080104Doc.h : CMy2018302080104Doc 类的接口
//


#pragma once


class CMy2018302080104Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy2018302080104Doc();
	DECLARE_DYNCREATE(CMy2018302080104Doc)

// 特性
public:
	CPoint group[100];//定义数组
	int PointNum;
	COLORREF m_crColor;//保存图形颜色

// 操作
public:
	void DDALine(CClientDC *DCPoint);//定义DDA函数
	void MIDLine(CClientDC *DCPoint);//定义中点直线函数
	void BCircle(CClientDC *DCPoint,CPoint p1,CPoint p2);// 定义Bresanham生成圆
	void PNCircle(CClientDC*DCPoint,CPoint p1,CPoint p2);// 定义正负法生成圆函数
	void Bezier(CClientDC *DCPoint,int mode);//定义Bezier 曲线函数
	void Bezier_4(CClientDC *DCPoint,int mode,CPoint p1,CPoint p2,CPoint p3,CPoint p4);//声明根据四个控制点生成一段 Bezier 曲线的函数
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


// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy2018302080104Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSetcolor();
};
