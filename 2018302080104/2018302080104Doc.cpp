
// 2018302080104Doc.cpp : CMy2018302080104Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2018302080104.h"
#endif

#include "2018302080104Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy2018302080104Doc

IMPLEMENT_DYNCREATE(CMy2018302080104Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy2018302080104Doc, CDocument)
	ON_COMMAND(SetColor, &CMy2018302080104Doc::OnSetcolor)
END_MESSAGE_MAP()


// CMy2018302080104Doc ����/����

CMy2018302080104Doc::CMy2018302080104Doc()
{
	// TODO: �ڴ����һ���Թ������
	m_crColor=RGB(0,0,0);
}

CMy2018302080104Doc::~CMy2018302080104Doc()
{
}

BOOL CMy2018302080104Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy2018302080104Doc ���л�

void CMy2018302080104Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy2018302080104Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMy2018302080104Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy2018302080104Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy2018302080104Doc ���

#ifdef _DEBUG
void CMy2018302080104Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2018302080104Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy2018302080104Doc ����

//DDA����ֱ���㷨�����
void CMy2018302080104Doc::DDALine(CClientDC *DCPoint)
{
	int x,x0,y0,x1,y1,flag;
	float m,y;
	DCPoint->SetROP2(R2_COPYPEN);//��ͼ����Ϊֱ�ӻ�
	//ֱ�߶˵������ȷ��������group[0]��group[1]
	x0=group[0].x; y0=group[0].y;
	x1=group[1].x; y1=group[1].y;
	if(x0==x1&&y0==y1)return;
	if(x0==x1)//��ֱ��
	{
		if(y0>y1){
			x=y0;y0=y1;y1=x;
		}
		for(x=y0;x<=y1;x++){
			DCPoint->SetPixel(x0,x,m_crColor);
		}
		return;
	}
	if(y0==y1)//ˮƽ��
	{
		if(x0>x1){
			x=x0;x0=x1;x1=x;
		}
		for(x=x0;x<=x1;x++){
			DCPoint->SetPixel(x,y0,m_crColor);
		}
		return;
	}
	if(x0>x1){
		//������ʼ����ֹ��
		x=x0;x0=x1;x1=x;
		y=y0;y0=y1;y1=y;
	}
	flag=0;
	if(x1-x0>y1-y0&&y1-y0>0)flag=1;
	if(x1-x0>y0-y1&&y0-y1>0)
	{
		flag=2;y0=-y0;y1=-y1;
	}
	if(y1-y0>x1-x0)
	{
		flag=3;x=x0;x0=y0;y0=x;x=x1;x1=y1;y1=x;
	}
	if(y0-y1>x1-x0)
	{
		flag=4;x=x0;x0=-y0;y0=x;x=x1;x1=-y1;y1=x;
	}
	m=(float)(y1-y0)/(float)(x1-x0);
	for(x=x0,y=(float)y0;x<=x1;x++,y=y+m)
	{
		if(flag==1)DCPoint->SetPixel(x,int(y),m_crColor);
		if(flag==2)DCPoint->SetPixel(x,-int(y),m_crColor);
		if(flag==3)DCPoint->SetPixel(int(y),x,m_crColor);
		if(flag==4)DCPoint->SetPixel(int(y),-x,m_crColor);
	}
}

//�е�ֱ���㷨�����
void CMy2018302080104Doc::MIDLine(CClientDC *DCPoint){
	int x,x0,y0,x1,y1;
	float y;
	
	DCPoint->SetROP2(R2_COPYPEN);//��ͼ����Ϊֱ�ӻ�
	//ֱ�߶˵������ȷ��������group[0]��group[1]
	x0=group[0].x; y0=group[0].y;
	x1=group[1].x; y1=group[1].y;

	int flag;

	if(x0==x1&&y0==y1)return;
	if(x0==x1)//��ֱ��
	{
		if(y0>y1){
			x=y0;y0=y1;y1=x;
		}
		for(x=y0;x<=y1;x++){
			DCPoint->SetPixel(x0,x,m_crColor);
		}
		return;
	}
	if(y0==y1)//ˮƽ��
	{
		if(x0>x1){
			x=x0;x0=x1;x1=x;
		}
		for(x=x0;x<=x1;x++){
			DCPoint->SetPixel(x,y0,m_crColor);
		}
		return;
	}

	if(x0>x1){
		//������ʼ����ֹ��
		x=x0;x0=x1;x1=x;
		y=y0;y0=y1;y1=y;
	}

	flag=0;
	if(x1-x0>y1-y0&&y1-y0>0){
		flag=1;x=x0;y=y0;
	}
	if(x1-x0>y0-y1&&y0-y1>0)
	{
		flag=2;y0=-y0;y1=-y1;
	}
	if(y1-y0>x1-x0&&x1-x0>0)
	{
		flag=3;x=x0;x0=y0;y0=x;x=x1;x1=y1;y1=x;
	}
	if(y0-y1>x1-x0&&x1-x0>0)
	{
		flag=4;x=x0;x0=-y0;y0=x;x=x1;x1=-y1;y1=x;
	}

	float dy=y1-y0;
	int dx=x1-x0;
	float d=dx-(2*dy);
	float d1=(-2)*dy;
	float d2=2*(dx-dy);

	for(x=x0,y=y0;x<=x1;x++){
		if(flag==1){
			if(d<=0){
				y++;
				d+=d2;
				DCPoint->SetPixel(x,int(y),m_crColor);
			}
			else{
				d+=d1;
				DCPoint->SetPixel(x,int(y),m_crColor);
			}
		}
		if(flag==2){
			if(d<=0){
				y++;
				d+=d2;
				DCPoint->SetPixel(x,-int(y),m_crColor);
			}
			else{
				d+=d1;
				DCPoint->SetPixel(x,-int(y),m_crColor);
			}
		}
		if(flag==3){
			if(d<=0){
				y++;
				d+=d2;
				DCPoint->SetPixel(int(y),x,m_crColor);
			}
			else{
				d+=d1;
				DCPoint->SetPixel(int(y),x,m_crColor);
			}
		}
		if(flag==4){
			if(d<=0){
				y++;
				d+=d2;
				DCPoint->SetPixel(int(y),-x,m_crColor);
			}
			else{
				d+=d1;
				DCPoint->SetPixel(int(y),-x,m_crColor);
			}
		}
	}
}

//BresenhamԲ�㷨�����
void CMy2018302080104Doc::BCircle(CClientDC *DCPoint,CPoint p1,CPoint p2){
	int r,d,x,y,x0,y0;
	DCPoint->SetROP2(R2_COPYPEN);//R2_COPYPEN��������Ϊ�ʵ���ɫ
	r=(int)sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))*1.0);
	x=0;y=r;d=3-2*r;x0=p1.x;y0=p1.y;
	while(x<y||x==y){
		DCPoint->SetPixel(x+x0,y+y0,m_crColor);
		DCPoint->SetPixel(-x+x0,y+y0,m_crColor);
		DCPoint->SetPixel(x+x0,-y+y0,m_crColor);
		DCPoint->SetPixel(-x+x0,-y+y0,m_crColor);
		DCPoint->SetPixel(y+x0,x+y0,m_crColor);
		DCPoint->SetPixel(-y+x0,x+y0,m_crColor);
		DCPoint->SetPixel(y+x0,-x+y0,m_crColor);
		DCPoint->SetPixel(-y+x0,-x+y0,m_crColor);
		x=x+1;
		if(d<0||d==0){
			d=d+4*x+6;
		}
		else{
			y=y-1;d=d+4*(x-y)+10;
		}
	}
}

//������Բ�㷨�����
void CMy2018302080104Doc::PNCircle(CClientDC*DCPoint,CPoint p1,CPoint p2){
	int r,d,x,y,x0,y0;
	DCPoint->SetROP2(R2_COPYPEN);//��ͼ����Ϊֱ�ӻ�
	r=(int)sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))*1.0);
	d=0;x0=p1.x;y0=p1.y;x=x0;y=y0+r;
	while(y>y0){
		DCPoint->SetPixel(x,y,m_crColor);
		DCPoint->SetPixel(-x+2*x0,y,m_crColor);
		DCPoint->SetPixel(x,-y+2*y0,m_crColor);
		DCPoint->SetPixel(-x+2*x0,-y+2*y0,m_crColor);
		if(d<0){
			x++;d=d+2*(x-x0)+1;
		}
		else{
			y--;d=d-2*(y-y0)+1;
		}
	}
}

//Bezier �����㷨�����
void CMy2018302080104Doc::Bezier(CClientDC *DCPoint,int mode){
	CPoint p[1000];//����һ������洢������Bezier���߿��Ƶ�
	int i,j;
	i=0;j=0;
	p[i++]=group[j++];//�Ƚ���1��2�ŵ��������
	p[i++]=group[j++];
	while(j<=PointNum-2){//�����桢ż�ŵ㣬���ɲ���������
		p[i++]=group[j++];
		p[i].x=(group[j].x+group[j-1].x)/2;
		p[i++].y=(group[j].y+group[j-1].y)/2;
		p[i++]=group[j++];
	}
	for(j=0;j<i-3;j+=3){//���Ƶ���飬�ֱ����ɸ�������
		Bezier_4(DCPoint,mode,p[j],p[j+1],p[j+2],p[j+3]);
	}
}

//�����ĸ����Ƶ�����һ�� Bezier ���ߵ��㷨�����
void CMy2018302080104Doc::Bezier_4(CClientDC *DCPoint,int mode,CPoint p1,CPoint p2,CPoint p3,CPoint p4){
	int i,n;
	CPoint p;
	double t1,t2,t3,t4,dt;
	CPen pen; n=10;
	if(mode){//mode=1ʱ�������ʽ���ɲ����ĺ�ɫ���ߣ����ڵ�����״
		DCPoint->SetROP2(R2_NOT);//R2_NOT��������Ϊ��Ļ��ɫ�ķ�ɫ
		pen.CreatePen(PS_DASH,1,RGB(0,0,0));//��ɫ����
	}
	else{//mode=0ʱ������ɫ����ʽ����
		DCPoint->SetROP2(R2_COPYPEN);
		pen.CreatePen(PS_SOLID,1,m_crColor);
	}
	CPen *pOldPen=DCPoint->SelectObject(&pen);
	dt=1.0/n;//����t�ļ������10�Σ�����10��ֱ�߱�ʾһ������
	DCPoint->MoveTo(p1);//�Ƶ����
	for(i=1;i<=n;i++){//��Bezier�������̼��������ϵȼ����10����
		t1=(1.0-i*dt)*(1.0-i*dt)*(1.0-i*dt); //����(1-t)3
		t2=i*dt*(1.0-i*dt)*(1.0-i*dt); //����t(1-t)2
		t3=i*dt*i*dt*(1.0-i*dt); //����t2(1-t)
		t4=i*dt*i*dt*i*dt; //����t3

		p.x=(int)(t1*p1.x+3*t2*p2.x+3*t3*p3.x+t4*p4.x);
		p.y=(int)(t1*p1.y+3*t2*p2.y+3*t3*p3.y+t4*p4.y);
		DCPoint->LineTo(p);
	}
	DCPoint->SelectObject(pOldPen);
}

//B���������㷨�����
void CMy2018302080104Doc::Bsampl(CClientDC *DCPoint,int mode){
	CPoint p[1000];//����һ������洢������Bezier���߿��Ƶ�
	int i,j;
	i=0;j=0;
	while(j<=PointNum){//�����桢ż�ŵ㣬���ɲ���������
		p[i++]=group[j++];
	}

	float t, t2, t3, xt, yt;
	int x,y;
	int rate = 100;
	
	CPen pen;
	if(mode){//mode=1ʱ�������ʽ���ɲ����ĺ�ɫ���ߣ����ڵ�����״
		DCPoint->SetROP2(R2_NOT);//R2_NOT��������Ϊ��Ļ��ɫ�ķ�ɫ
		pen.CreatePen(PS_DASH,1,RGB(0,0,0));//��ɫ����
	}
	else{//mode=0ʱ������ʽ����
		DCPoint->SetROP2(R2_COPYPEN);
		pen.CreatePen(PS_SOLID,1,m_crColor);
	}
	CPen *pOldPen=DCPoint->SelectObject(&pen);

	float x0=(p[0].x+4*p[1].x+p[2].x)/6.0;
	float y0=(p[0].y+4*p[1].y+p[2].y)/6.0;
	DCPoint->MoveTo(x0,y0);

	for(j=1;j<PointNum-2;j+=1){//���Ƶ���飬�ֱ����ɸ�������
		for (t = 0; t <= 1; t += 1.0 / rate){
			t2 = t*t;
			t3 = t*t*t;
			xt = ((1 - 3 * t + 3 * t2 - t3)*p[j-1].x + (4 - 6 * t2 + 3 * t3)*p[j].x + (1 + 3 * t + 3 * t2 - 3 * t3)*p[j+1].x + t3*p[j+2].x) / 6;
			yt = ((1 - 3 * t + 3 * t2 - t3)*p[j-1].y + (4 - 6 * t2 + 3 * t3)*p[j].y + (1 + 3 * t + 3 * t2 - 3 * t3)*p[j+1].y + t3*p[j+2].y) / 6;
			x = (int)(xt);
			y = (int)(yt);
			/*if (t == 0){
				DCPoint->MoveTo(x,y);
			}*/
			DCPoint->LineTo(x,y);
		}
	}
	DCPoint->SelectObject(pOldPen);
}

//Hermite�����㷨�����
void CMy2018302080104Doc::Hermite(CClientDC *DCPoint,int mode){
	CPoint p[1000];//����һ������洢������Hermite���߿��Ƶ�
	int i,j;
	i=0;j=0;
	while(j<=PointNum){
		p[i++]=group[j++];
	}
	CPen pen;
	if(mode){//mode=1ʱ�������ʽ���ɲ����ĺ�ɫ���ߣ����ڵ�����״
		DCPoint->SetROP2(R2_NOT);//R2_NOT��������Ϊ��Ļ��ɫ�ķ�ɫ
		pen.CreatePen(PS_DASH,1,RGB(0,0,0));//��ɫ����
	}
	else{//mode=0ʱ������ʽ����
		DCPoint->SetROP2(R2_COPYPEN);
		pen.CreatePen(PS_SOLID,1,m_crColor);
	}
	CPen *pOldPen=DCPoint->SelectObject(&pen);
	 

	//��һ�ַ�����ʹ��4����
	//double t1,t2,t3,t4;
	//int n=10;//����t�ļ������10�Σ�����10��ֱ�߱�ʾһ������
	//for(j=0;j<i-3;j+=3){//���Ƶ���飬�ֱ����ɸ�������
	//	int dt=1.0/n;
	//	DCPoint->MoveTo(p[j]);//�Ƶ����
	//	for(i=1;i<=n;i++){//��Hermite�������̼��������ϵȼ����10����
	//		t1 = -9 * (i*dt)*(i*dt)*(i*dt) / 2 + 9 * (i*dt)*(i*dt) - 11 * i*dt / 2 + 1;
	//		t2 = 27 * (i*dt)*(i*dt)*(i*dt) / 2 - 45 * (i*dt)*(i*dt) / 2 + 9 * i*dt;
	//		t3 = -27 * (i*dt)*(i*dt)*(i*dt) / 2 + 18 * (i*dt)*(i*dt) - 9 * i*dt / 2;
	//		t4 = 9 * (i*dt)*(i*dt)*(i*dt) / 2 - 9 * (i*dt)*(i*dt) / 2 + i*dt;

	//		int px=(int)(t1*p[j].x+t2*p[j+1].x+t3*p[j+2].x+t4*p[j+3].x);
	//		int py=(int)(t1*p[j].y+t2*p[j+1].y+t3*p[j+2].y+t4*p[j+3].y);
	//		DCPoint->LineTo(px,py);
	//	}
	//}

	//����һ�ַ�����ʹ�����˵�����˵�ķ���
	for (int j = 0; j < i - 2; j++) {//���Ƶ���飬�ֱ����ɸ�������
		
		DCPoint->MoveTo(p[j]);//�Ƶ����

		int a[4][4] =
		{
			{ 2,-2,1,1 },
			{ -3,3,-2,-1 },
			{ 0,0,1,0 },
			{ 1,0,0,0 }
		};

		double b[4][2] = {
			{ p[j].x,p[j].y },
			{ p[j+1].x,p[j+1].y },
			{ p[j+1].x - p[j].x,p[j+1].y - p[j].y },
			{ p[j+2].x - p[j+1].x,p[j+2].y - p[j+1].y }
		};

		double u = 0.0;
		double result[4][2] = { 0 };
		for (int i = 0; i<2; i++)
		{
			for (int j = 0; j<4; j++)
			{
				for (int k = 0; k<4; k++)
				{
					result[j][i] += a[j][k] * b[k][i];
				}
			}
		}

		DCPoint->MoveTo(p[j]);
		for (u = 0.0; u <= 1; u += 1.0 / 100)
		{
			int x = (int)(pow(u, 3)*result[0][0] + pow(u, 2)*result[1][0] + u*result[2][0] + result[3][0]);
			int y = (int)(pow(u, 3)*result[0][1] + pow(u, 2)*result[1][1] + u*result[2][1] + result[3][1]);

			DCPoint->LineTo(x, y);
		}		
	}
	DCPoint->SelectObject(pOldPen);
	pen.DeleteObject();
}

//�����ַ�������ɫѡ������
void CMy2018302080104Doc::OnSetcolor()
{
	// TODO: �ڴ���������������
	CColorDialog dlg(m_crColor);//�����Ի�����󣬲�����Ĭ����ɫΪ��һ��ѡ�����ɫ
	if(dlg.DoModal()==IDOK){
		m_crColor=dlg.GetColor();
	}
}

//ͼ��ƽ��-׼�����ݱ����
void CMy2018302080104Doc::GenerateGraph(CClientDC *pDC){
	//ͼ������׼������һ������������ʾƽ��Ч��
	group[0].x=100;group[0].y=100;
	group[1].x=200;group[1].y=100;
	group[2].x=200;group[2].y=200;
	group[3].x=100;group[3].y=200;
	group[4].x=100;group[4].y=100;
	PointNum=5;
	DrawGraph(pDC);//��ͼ��
}

//ͼ����ת-׼�����ݱ����
void CMy2018302080104Doc::GenerateGraph2(CClientDC *pDC){
	//ͼ������׼������һ������������ʾƽ��Ч��
	group[0].x=400;group[0].y=400;
	group[1].x=500;group[1].y=400;
	group[2].x=500;group[2].y=500;
	group[3].x=400;group[3].y=500;
	group[4].x=400;group[4].y=400;
	PointNum=5;
	DrawGraph(pDC);//��ͼ��
}

//ͼ��任-����ͼ�α����
void CMy2018302080104Doc::DrawGraph(CClientDC *pDC) {
	int i;
	CPen pen,*pOldPen;
	pDC->SetROP2(R2_COPYPEN);
	pen.CreatePen(PS_SOLID,1,RGB(255,0,255));
	pOldPen=pDC->SelectObject(&pen);
	pDC->MoveTo(group[0]);
	for(i=1;i<PointNum;i++){
		pDC->LineTo(group[i]);
	}
	pDC->SelectObject(pOldPen);
}

//�ԳƱ任�����
void CMy2018302080104Doc::Symmetry(CPoint p1,CPoint p2){
	float a[3][3],b[3][3],c[3][3]={NULL};
	float sa,ca,x,y;
	int i;
	ca=(p2.x-p1.x)/sqrt(((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y))*1.0);//cos�� 
	sa=(p2.y-p1.y)/sqrt(((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y))*1.0);//sin��

	c[0][0]=1;c[0][1]=0;c[0][2]=-p1.x;//����1
	c[1][0]=0;c[1][1]=1;c[1][2]=-p1.y; 
	c[2][0]=0;c[2][1]=0;c[2][2]=1;

	b[0][0]=ca;b[0][1]=sa;b[0][2]=0;//����2 
	b[1][0]=-sa;b[1][1]=ca;b[1][2]=0;
	b[2][0]=0;b[2][1]=0;b[2][2]=1;

	a[0][0]=b[0][0]*c[0][0]+b[0][1]*c[1][0]+b[0][2]*c[2][0];//����1��2�ϲ�
	a[0][1]=b[0][0]*c[0][1]+b[0][1]*c[1][1]+b[0][2]*c[2][1];
	a[0][2]=b[0][0]*c[0][2]+b[0][1]*c[1][2]+b[0][2]*c[2][2];
	a[1][0]=b[1][0]*c[0][0]+b[1][1]*c[1][0]+b[1][2]*c[2][0];
	a[1][1]=b[1][0]*c[0][1]+b[1][1]*c[1][1]+b[1][2]*c[2][1];
	a[1][2]=b[1][0]*c[0][2]+b[1][1]*c[1][2]+b[1][2]*c[2][2];
	a[2][0]=b[2][0]*c[0][0]+b[2][1]*c[1][0]+b[2][2]*c[2][0];
	a[2][1]=b[2][0]*c[0][1]+b[2][1]*c[1][1]+b[2][2]*c[2][1];
	a[2][2]=b[2][0]*c[0][2]+b[2][1]*c[1][2]+b[2][2]*c[2][2];
	
	b[0][0]=1;b[0][1]=0;b[0][2]=0;//����3 
	b[1][0]=0;b[1][1]=-1;b[1][2]=0;
	b[2][0]=0;b[2][1]=0;b[2][2]=1;

	c[0][0]=b[0][0]*a[0][0]+b[0][1]*a[1][0]+b[0][2]*a[2][0];//����1��2��3 �ϲ�
	c[0][1]=b[0][0]*a[0][1]+b[0][1]*a[1][1]+b[0][2]*a[2][1];
	c[0][2]=b[0][0]*a[0][2]+b[0][1]*a[1][2]+b[0][2]*a[2][2];
	c[1][0]=b[1][0]*a[0][0]+b[1][1]*a[1][0]+b[1][2]*a[2][0];
	c[1][1]=b[1][0]*a[0][1]+b[1][1]*a[1][1]+b[1][2]*a[2][1];
	c[1][2]=b[1][0]*a[0][2]+b[1][1]*a[1][2]+b[1][2]*a[2][2];
	c[2][0]=b[2][0]*a[0][0]+b[2][1]*a[1][0]+b[2][2]*a[2][0];
	c[2][1]=b[2][0]*a[0][1]+b[2][1]*a[1][1]+b[2][2]*a[2][1];
	c[2][2]=b[2][0]*a[0][2]+b[2][1]*a[1][2]+b[2][2]*a[2][2];

	b[0][0]=ca;b[0][1]=-sa;b[0][2]=0;//����4 
	b[1][0]=sa;b[1][1]=ca;b[1][2]=0;
	b[2][0]=0;b[2][1]=0;b[2][2]=1;

	a[0][0]=b[0][0]*c[0][0]+b[0][1]*c[1][0]+b[0][2]*c[2][0];//����1��2��3��4�ϲ�
	a[0][1]=b[0][0]*c[0][1]+b[0][1]*c[1][1]+b[0][2]*c[2][1];
	a[0][2]=b[0][0]*c[0][2]+b[0][1]*c[1][2]+b[0][2]*c[2][2];
	a[1][0]=b[1][0]*c[0][0]+b[1][1]*c[1][0]+b[1][2]*c[2][0];
	a[1][1]=b[1][0]*c[0][1]+b[1][1]*c[1][1]+b[1][2]*c[2][1];
	a[1][2]=b[1][0]*c[0][2]+b[1][1]*c[1][2]+b[1][2]*c[2][2];
	a[2][0]=b[2][0]*c[0][0]+b[2][1]*c[1][0]+b[2][2]*c[2][0];
	a[2][1]=b[2][0]*c[0][1]+b[2][1]*c[1][1]+b[2][2]*c[2][1];
	a[2][2]=b[2][0]*c[0][2]+b[2][1]*c[1][2]+b[2][2]*c[2][2];

	b[0][0]=1;b[0][1]=0;b[0][2]=p1.x;//����5 
	b[1][0]=0;b[1][1]=1;b[1][2]=p1.y; 
	b[2][0]=0;b[2][1]=0;b[2][2]=1;

	c[0][0]=b[0][0]*a[0][0]+b[0][1]*a[1][0]+b[0][2]*a[2][0];//���о���ϲ�
	c[0][1]=b[0][0]*a[0][1]+b[0][1]*a[1][1]+b[0][2]*a[2][1];
	c[0][2]=b[0][0]*a[0][2]+b[0][1]*a[1][2]+b[0][2]*a[2][2];
	c[1][0]=b[1][0]*a[0][0]+b[1][1]*a[1][0]+b[1][2]*a[2][0];
	c[1][1]=b[1][0]*a[0][1]+b[1][1]*a[1][1]+b[1][2]*a[2][1];
	c[1][2]=b[1][0]*a[0][2]+b[1][1]*a[1][2]+b[1][2]*a[2][2];
	c[2][0]=b[2][0]*a[0][0]+b[2][1]*a[1][0]+b[2][2]*a[2][0];
	c[2][1]=b[2][0]*a[0][1]+b[2][1]*a[1][1]+b[2][2]*a[2][1];
	c[2][2]=b[2][0]*a[0][2]+b[2][1]*a[1][2]+b[2][2]*a[2][2];

	for(i=0;i<PointNum;i++){//���ø��Ͼ��������ͼ�ε�������б任
		x=c[0][0]*group[i].x+c[0][1]*group[i].y+c[0][2];
		y=c[1][0]*group[i].x+c[1][1]*group[i].y+c[1][2];
		group[i].x=x;
		group[i].y=y;
	}
}

//�����������
void CMy2018302080104Doc::SeedFill(CClientDC *pDC,CPoint seedpoint){
	int savex,xleft,xright,pflag,x,y,num;
	CPoint stack_ptr[200];//��ջ
	pDC->SetROP2(R2_COPYPEN);//��ͼ����Ϊֱ�ӻ�
	num=0;//numΪ��ջ�е�������
	stack_ptr[num++]=seedpoint;
	while(num>0){
		x=stack_ptr[--num].x;y=stack_ptr[num].y;
		pDC->SetPixel(x,y,m_crColor);
		savex=x;x++;
		while(pDC->GetPixel(x,y)!=m_crColor){//������䣬ֱ���߽�
			pDC->SetPixel(x++,y,m_crColor);
		}
		xright=x-1;x=savex-1;
		while(pDC->GetPixel(x,y)!=m_crColor){//������䣬ֱ���߽�
			pDC->SetPixel(x--,y,m_crColor);
		}
		xleft=x+1;x=xleft;y++;//��ɨ������һ������δ�������
		pflag=1;
		while(x<xright){
			if(pDC->GetPixel(x,y)!=m_crColor&&pflag==1){
				//�߽��ĵ�һ��δ�����������
				stack_ptr[num].x=x;
				stack_ptr[num++].y=y;
				x++;
			}
			if(pDC->GetPixel(x,y)==m_crColor){
				pflag=1;//pflag=1��ʾ��������߽�
			}
			else{
				pflag=0;//pflag=0��ʾδ�������
			}
			x++;
		}
		x=xleft;y-=2; //��ɨ������һ������δ�������
		pflag=1;
		while(x<xright){
			if(pDC->GetPixel(x,y)!=m_crColor&&pflag==1){
				stack_ptr[num].x=x;
				stack_ptr[num++].y=y;
				x++;
			}
			if(pDC->GetPixel(x,y)==m_crColor){
				pflag=1;
			}
			else{
				pflag=0;
			}
			x++;
		}
	}
}

//��Ե�������
void CMy2018302080104Doc::EdgeFill(CClientDC *pDC){
	int i,xr,x1,y1,x2,y2,y;
	float m,x;
	CPen pen;
	pen.CreatePen(PS_SOLID,1,m_crColor);//ȷ�������ɫ���ɸ���ɫ�뱳��ɫ����϶���
	pDC->SetROP2(R2_XORPEN);//��ͼ����Ϊ���
	CPen*pOldPen=pDC->SelectObject(&pen);
	xr=0;
	for(i=0;i<PointNum;i++){//�ҳ��߽���ұ߽����
		if(xr<group[i].x)xr=group[i].x;
	}
	for(i=0;i<PointNum-1;i++){
		x1=group[i].x;x2=group[i+1].x;//ȡһ����
		y1=group[i].y;y2=group[i+1].y;
		if(y1!=y2){
			if(y1>y2){//ȷ����x1,y1��Ϊ�¶˵�
				y=y1;y1=y2;y2=y;
				y=x1;x1=x2;x2=y;
			}
			m=(float)(x2-x1)/(float)(y2-y1);x=x1;//mΪ����ɨ����֮��ߵ�x����
			for(y=y1+1;y<=y2;y++){
				x+=m;//ȷ����Ե��
				pDC->MoveTo((int)x,y);//�ӱ�Ե��һֱ�����߽���Ҷ�
				pDC->LineTo(xr,y);
			}
		}
	}
	pDC->SelectObject(pOldPen);
}


// Cohen-Sutherland �㷨�ü������
//����Ĵ��ڲ������ţ�����ֻҪ�ڱ�ʹ��ǰ���弴��
#define XMIN 100
#define XMAX 400
#define YMIN 100
#define YMAX 300
#define LEFT 1//����ļ�����������
#define RIGHT 2
#define BOTTOM 4
#define TOP 8


//Cohen-Sutherland �㷨�ü������
//DrawWindow
void CMy2018302080104Doc::DrawWindow(CClientDC *pDC){
	CPen pen;
	pen.CreatePen(PS_SOLID,2,RGB(0,0,255));
	CPen *pOldPen=pDC->SelectObject(&pen);pDC->SetROP2(R2_COPYPEN);
	pDC->MoveTo(XMIN,YMIN);
	pDC->LineTo(XMAX,YMIN);
	pDC->LineTo(XMAX,YMAX);
	pDC->LineTo(XMIN,YMAX);
	pDC->LineTo(XMIN,YMIN);
	pDC->SelectObject(pOldPen);
}
//CohenSutherland
void CMy2018302080104Doc::CohenSutherland(CClientDC *pDC,CPoint p1,CPoint p2){
	int code1,code2,code,x,y,x1,y1,x2,y2;
	pDC->SetROP2(R2_COPYPEN);
	CPen Pen;
	Pen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	CPen*OldPen=pDC->SelectObject(&Pen);
	x1=p1.x;y1=p1.y;
	x2=p2.x;y2=p2.y;
	code1=encode(x1,y1);//�Զ˵����
	code2=encode(x2,y2);
	while(code1!=0||code2!=0){
		if((code1&code2)!=0){return;}//��ȫ���ɼ�
		code=code1;
		if(code1==0){code=code2;}
		if((LEFT&code)!=0){//���߶��봰����ߵĽ���
			x=XMIN;
			y=y1+(y2-y1)*(x-x1)/(x2-x1);
		}
		else if((RIGHT&code)!=0){//���߶��봰���ұߵĽ���
			x=XMAX;
			y=y1+(y2-y1)*(x-x1)/(x2-x1);
		}
		else if((BOTTOM&code)!=0){//���߶��봰�ڵױߵĽ���
			y=YMIN;
			x=x1+(x2-x1)*(y-y1)/(y2-y1);
		}
		else if((TOP&code)!=0){//���߶��봰�ڶ��ߵĽ���
			y=YMAX;
			x=x1+(x2-x1)*(y-y1)/(y2-y1);
		}
		if(code==code1){
			x1=x;y1=y;code1=encode(x,y);
		}
		else{
			x2=x;y2=y;code2=encode(x,y);
		}
	}
	pDC->MoveTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->SelectObject(OldPen);
}
//encode
int CMy2018302080104Doc::encode(int x,int y){
	int c;
	c=0;
	if(x<XMIN){c=c+LEFT;}
	else if(x>XMAX){c=c+RIGHT;}
	if(y<YMIN){c=c+BOTTOM;}
	else if(y>YMAX){c=c+TOP;}
	return c;
}

//����βü������
//����βü�-PolygonCut()
void CMy2018302080104Doc::PolygonCut(CClientDC*pDC){
	CPen pen;
	pen.CreatePen(0,2,RGB(255,0,0));
	CPen*OldPen=pDC->SelectObject(&pen);pDC->SetROP2(R2_COPYPEN);
	EdgeClipping(0); //�õ�һ�����ڱ߽��вü�
	EdgeClipping(1); //�õڶ������ڱ߽��вü�
	EdgeClipping(2); //�õ��������ڱ߽��вü�
	EdgeClipping(3); //�õ��������ڱ߽��вü�
	pDC->MoveTo(group[0]);//���Ʋü������
	for(int i=1;i<=PointNum;i++){
		pDC->LineTo(group[i]);
	}
	pDC->SelectObject(OldPen);
}
//����βü�-EdgeClipping()
void CMy2018302080104Doc::EdgeClipping(int linecode){
	float x,y;
	int n,i,number1;
	CPoint q[200];
	number1=0;
	if(linecode==0){//x=XMIN
		for(n=0;n<PointNum;n++){
			if(group[n].x<XMIN&&group[n+1].x<XMIN){//���⣬�����
			}
			if(group[n].x>=XMIN&&group[n+1].x>=XMIN){//���������
				q[number1++]=group[n+1];
			}
			if(group[n].x>=XMIN&&group[n+1].x<XMIN){//���⣬�������
				y=group[n].y+(float)(group[n+1].y-group[n].y)/(float)(group[n+1].x-group[n].x)*(float)(XMIN-group[n].x);
				q[number1].x=XMIN;
				q[number1++].y=(int)y;
			}
			if(group[n].x<XMIN&&group[n+1].x>=XMIN){//���������㡢���
				y=group[n].y+(float)(group[n+1].y-group[n].y)/(float)(group[n+1].x-group[n].x)*(float)(XMIN-group[n].x);
				q[number1].x=XMIN;
				q[number1++].y=(int)y;
				q[number1++]=group[n+1];
			}
		}
		for(i=0;i<number1;i++){
			group[i]=q[i];
		}
		group[number1]=q[0];
		PointNum=number1;number1=0;
	}
	if(linecode==1){//y=YMAX
		for(n=0;n<PointNum;n++){
			if(group[n].y>=YMAX&&group[n+1].y>=YMAX){//���⣬�����
			}
			if(group[n].y<YMAX&&group[n+1].y<YMAX){//���������
				q[number1++]=group[n+1];
			}
			if(group[n].y<YMAX&&group[n+1].y>=YMAX){//���⣬�������
				x=group[n].x+(float)(group[n+1].x-group[n].x)/(float)(group[n+1].y-group[n].y)*(float)(YMAX-group[n].y);
				q[number1].x=(int)x;
				q[number1++].y=YMAX;
			}
			if(group[n].y>=YMAX&&group[n+1].y<YMAX){//���������㡢���
				x=group[n].x+(float)(group[n+1].x-group[n].x)/(float)(group[n+1].y-group[n].y)*(float)(YMAX-group[n].y);
				q[number1].x=(int)x;
				q[number1++].y=YMAX;
				q[number1++]=group[n+1];
			}
		}
		for(i=0;i<number1;i++){
			group[i]=q[i];
		}
		group[number1]=q[0];
		PointNum=number1;number1=0;
	}
	if(linecode==2){//x=XMAX
		for(n=0;n<PointNum;n++){
			if(group[n].x>=XMAX&&group[n+1].x>=XMAX){//���⣬�����
			}
			if(group[n].x<XMAX&&group[n+1].x<XMAX){//���������
				q[number1++]=group[n+1];
			}
			if(group[n].x<XMAX&&group[n+1].x>=XMAX){//���⣬�������
				y=group[n].y+(float)(group[n+1].y-group[n].y)/(float)(group[n+1].x-group[n].x)*(float)(XMAX-group[n].x);
				q[number1].x=XMAX;
				q[number1++].y=(int)y;
			}
			if(group[n].x>=XMAX&&group[n+1].x<XMAX){//���������㡢���
				y=group[n].y+(float)(group[n+1].y-group[n].y)/(float)(group[n+1].x-group[n].x)*(float)(XMAX-group[n].x);
				q[number1].x=XMAX;
				q[number1++].y=(int)y;
				q[number1++]=group[n+1];
			}
		}
		for(i=0;i<number1;i++){
			group[i]=q[i];
		}
		group[number1]=q[0];
		PointNum=number1;number1=0;
	}
	if(linecode==3){//y=YMIN
		for(int n=0;n<PointNum;n++){
			if(group[n].y<YMIN&&group[n+1].y<YMIN){//���⣬�����
			}
			if(group[n].y>=YMIN&&group[n+1].y>=YMIN){//���������
				q[number1++]=group[n+1];
			}
			if(group[n].y>=YMIN&&group[n+1].y<YMIN){//���⣬�������
				x=group[n].x+(float)(group[n+1].x-group[n].x)/(float)(group[n+1].y-group[n].y)*(float)(YMIN-group[n].y);
				q[number1].x=(int)x;
				q[number1++].y=YMIN;
			}
			if(group[n].y<YMIN&&group[n+1].y>=YMIN){//���������㡢���
				x=group[n].x+(float)(group[n+1].x-group[n].x)/(float)(group[n+1].y-group[n].y)*(float)(YMIN-group[n].y);
				q[number1].x=(int)x;
				q[number1++].y=YMIN;
				q[number1++]=group[n+1];
			}
		}
		for(i=0;i<number1;i++){
			group[i]=q[i];
		}
		group[number1]=q[0];
		PointNum=number1;number1=0;
	}
}

//�е�ָ�ü��㷨�����
void CMy2018302080104Doc::cutmiddle(CClientDC *pDC,CPoint p1,CPoint p2){
	int x,y,x1,y1,x2,y2,flag,code1,code2;
	int xmid,ymid,codem;
	int xa,xb,ya,yb;
	pDC->SetROP2(R2_COPYPEN);
	CPen Pen;
	Pen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	CPen*OldPen=pDC->SelectObject(&Pen);
	x1=p1.x;y1=p1.y;//������߶����
	x2=p2.x;y2=p2.y;//������߶��յ�
	code1=encode(x1,y1);//�Զ˵����
	code2=encode(x2,y2);
	if(code1==0&&code2==0){
		//ͬʱΪ0,�ڴ����ڲ������òü�
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);
		pDC->SelectObject(OldPen);
	}
	else if((code1&code2)!=0){
		//����ͬʱ�ڴ����ⲿͬ��
		//һ��&��λ������������ҵ���˼
		return;
	}
	else{
		//��p1������Ѱ�Ҿ���p1����Ŀɼ��㣬��Ϊxa,ya
		for(;;){
			xmid=(x1+x2)/2;
			ymid=(y1+y2)/2;
			codem=encode(xmid,ymid);
			if((codem==0)||((codem&code2)!=0)){
				//�е��ڴ����ڲ�
				x2=xmid;
				y2=ymid;
			}
			else if((codem&code1)!=0){
				//�е��p1ͬʱ�ڴ����ⲿͬ��
				x1=xmid;
				y1=ymid;
			}
			code1=encode(x1,y1);
			code2=encode(x2,y2);
			if((abs(x1-x2)<=1)&&(abs(y1-y2)<=1)){
				xa=x1;
				ya=y1;
				break;
			}
		}
		//��������p1,p2����p2������Ѱ�Ҿ���p2����Ŀɼ��㣬��Ϊxb,yb
		x1=p1.x;y1=p1.y;//������߶����
		x2=p2.x;y2=p2.y;//������߶��յ�
		code1=encode(x1,y1);//�Զ˵����
		code2=encode(x2,y2);
		for(;;){
			xmid=(x1+x2)/2;
			ymid=(y1+y2)/2;
			codem=encode(xmid,ymid);
			if((codem==0)||((codem&code1)!=0)){
				//�е��ڴ����ڲ�
				x1=xmid;
				y1=ymid;
			}
			else if((codem&code2)!=0){
				//�е��p2ͬʱ�ڴ����ⲿͬ��
				x2=xmid;
				y2=ymid;
			}
			code1=encode(x1,y1);
			code2=encode(x2,y2);
			if((abs(x1-x2)<=1)&&(abs(y1-y2)<=1)){
				xb=x2;
				yb=y2;
				break;
			}
		}
		pDC->MoveTo(xa,ya);
		pDC->LineTo(xb,yb);
		pDC->SelectObject(OldPen);
	}
}

//���Ѷ�-Barsky�ü��㷨�����
int clipTest(float p,float q,float *u1,float *u2) {
	//flagΪ��־������0����ʾ������1����ʾ�ɼ���
	int flag=1;
	float r;
	if(p<0.0){
		r=q/p;
		if(r>*u2)
		flag=0;
		else if(r>*u1) 
		*u1=r; //u1ȡ"����"���������ֵ
	}
	else if(p>0.0) {
		r=q/p;
		if(r<*u1){flag=0;}
		else if(r<*u2){*u2=r;} //u2ȡ"�뿪" �����С����ֵ
	}
	else if(q<0.0){flag=0;} //p=0����q<0��ƽ���ڱ߽磬�����ڽ������
	return(flag);
}
void CMy2018302080104Doc::cutLBarsky(CClientDC *pDC,CPoint p1,CPoint p2){
	int x,y,x1,y1,x2,y2;
	int xa,xb,ya,yb;
	pDC->SetROP2(R2_COPYPEN);
	CPen Pen;
	Pen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	CPen*OldPen=pDC->SelectObject(&Pen);
	
	x1=p1.x;y1=p1.y;//������߶����
	x2=p2.x;y2=p2.y;//������߶��յ�
	float dx=x2-x1;
	float dy=y2-y1;

	int Xbegin,Xend,Ybegin,Yend;
	if(dx>=0){
		Xbegin=XMAX;
		Xend=XMIN;
	}
	else{
		Xbegin=XMIN;
		Xend=XMAX;
	}
	if(dy>=0){
		Ybegin=YMAX;
		Yend=YMIN;
	}
	else{
		Ybegin=YMIN;
		Yend=YMAX;
	}

	float u1=0.0,u2=1.0;
	if(clipTest(-dx,x1-XMIN,&u1,&u2)){
		if(clipTest(dx,XMAX-x1,&u1,&u2)){ 
			if(clipTest(-dy,y1-YMIN,&u1,&u2)){
				if(clipTest(dy,YMAX-y1,&u1,&u2)){
					if(u2<1.0){
						x2=x1+u2*dx; //ͨ��u2��òü����p2�˵�
						y2=y1+u2*dy;
					}
					if(u1>0.0){
						x1=x1+u1*dx; //ͨ��u1��òü����p1�˵�
						y1=y1+u1*dy;
					}
					pDC->MoveTo(x1,y1);
					pDC->LineTo(x2,y2);
					pDC->SelectObject(OldPen);
				}
			}
		}
	}
}


void CMy2018302080104Doc::BCircle(CClientDC *DCPoint,CRect *rc,CPoint p1,CPoint p2)
{
	int r,d,x,y,x0,y0;
	DCPoint->SetROP2(R2_COPYPEN);//��ͼ����Ϊֱ�ӻ�
	r=(int)sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))*1.0);
	x=0;y=r;d=3-2*r;x0=p1.x;y0=p1.y;
	while(x<y||x==y){
		if(rc->PtInRect(CPoint(x+x0,y+y0)))
			DCPoint->SetPixel(x+x0,y+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(-x+x0,y+y0)))
			DCPoint->SetPixel(-x+x0,y+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(x+x0,-y+y0)))
			DCPoint->SetPixel(x+x0,-y+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(-x+x0,-y+y0)))
			DCPoint->SetPixel(-x+x0,-y+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(y+x0,x+y0)))
			DCPoint->SetPixel(y+x0,x+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(-y+x0,x+y0)))
			DCPoint->SetPixel(-y+x0,x+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(y+x0,-x+y0)))
			DCPoint->SetPixel(y+x0,-x+y0,RGB(255,0,0));
		if(rc->PtInRect(CPoint(-y+x0,-x+y0)))
			DCPoint->SetPixel(-y+x0,-x+y0,RGB(255,0,0));

		x=x+1;
		if(d<0||d==0){
			d=d+4*x+6;
		}
		else{
			y=y-1;
			d=d+4*(x-y)+10;
		}
	}
}

void CMy2018302080104Doc::CutCircle(CClientDC *DCPoint,CPoint p1,CPoint p2)
{
	CRect rc(XMIN,YMIN,XMAX,YMAX);
	BCircle((CClientDC *)(DCPoint),&rc,p1,p2);
}


