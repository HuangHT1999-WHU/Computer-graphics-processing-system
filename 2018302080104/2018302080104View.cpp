
// 2018302080104View.cpp : CMy2018302080104View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2018302080104.h"
#endif

#include "2018302080104Doc.h"
#include "2018302080104View.h"
#include "SetCharDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CMFCStatusBar m_wndStatusBar;

// CMy2018302080104View

IMPLEMENT_DYNCREATE(CMy2018302080104View, CView)

BEGIN_MESSAGE_MAP(CMy2018302080104View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2018302080104View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_DDALINE, &CMy2018302080104View::OnDrawDdaline)
	ON_COMMAND(ID_DRAW_BCIRCLE, &CMy2018302080104View::OnDrawBcircle)
	ON_COMMAND(ID_DRAW_PNCIRCLE, &CMy2018302080104View::OnDrawPncircle)
	ON_COMMAND(ID_CURVE_BEZIER, &CMy2018302080104View::OnCurveBezier)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(SetChar, &CMy2018302080104View::OnSetchar)
	ON_COMMAND(ID_TRANS_MOVE, &CMy2018302080104View::OnTransMove)
	ON_COMMAND(ID_TRANS_SYMMETRY, &CMy2018302080104View::OnTransSymmetry)
	ON_COMMAND(ID_FILL_SEED, &CMy2018302080104View::OnFillSeed)
	ON_COMMAND(ID_FILL_EDGE, &CMy2018302080104View::OnFillEdge)
	ON_COMMAND(ID_FILL_SCANLINE, &CMy2018302080104View::OnFillScanline)
	ON_COMMAND(ID_CUT_CS, &CMy2018302080104View::OnCutCs)
	ON_COMMAND(ID_CUT_POLYGON, &CMy2018302080104View::OnCutPolygon)
	ON_COMMAND(ID_DRAW_MIDLINE, &CMy2018302080104View::OnDrawMidline)
	ON_COMMAND(ID_CURVE_BSAMPLE, &CMy2018302080104View::OnCurveBsample)
	ON_COMMAND(ID_TRANS_ROTATE, &CMy2018302080104View::OnTransRotate)
	ON_COMMAND(ID_TRANS_ZOOM, &CMy2018302080104View::OnTransZoom)
	ON_COMMAND(ID_CUT_MIDDLE, &CMy2018302080104View::OnCutMiddle)
	ON_COMMAND(ID_CUT_LIANG, &CMy2018302080104View::OnCutLiang)
	ON_COMMAND(ID_CURVE_HERMITE, &CMy2018302080104View::OnCurveHermite)
	ON_COMMAND(clear, &CMy2018302080104View::OnClear)
	ON_COMMAND(CircleCut, &CMy2018302080104View::OnCirclecut)
END_MESSAGE_MAP()

// CMy2018302080104View ����/����

CMy2018302080104View::CMy2018302080104View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2018302080104View::~CMy2018302080104View()
{
}

BOOL CMy2018302080104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2018302080104View ����

void CMy2018302080104View::OnDraw(CDC* /*pDC*/)
{
	CMy2018302080104Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2018302080104View ��ӡ


void CMy2018302080104View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2018302080104View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2018302080104View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2018302080104View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMy2018302080104View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2018302080104View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2018302080104View ���

#ifdef _DEBUG
void CMy2018302080104View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2018302080104View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2018302080104Doc* CMy2018302080104View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2018302080104Doc)));
	return (CMy2018302080104Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2018302080104View ��Ϣ�������

//��������Ӧ����
void CMy2018302080104View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2018302080104Doc *pDoc=GetDocument(); //����ĵ���ָ��
	CClientDC ht(this); //���嵱ǰ��ͼ�豸
	if(MenuID==1){ //DDAֱ��
		if(PressNum==0){ //��һ�ΰ�������һ�㱣�����ĵ���������
		pDoc->group[PressNum]=point;
		mPointOrign=point;
		mPointOld=point;//��¼��һ��
		PressNum++;
		SetCapture();
		}
		else if(PressNum==1){ //�ڶ��ΰ��������ڶ��㣬���ĵ��໭��
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//������Ƥ��
			ht.LineTo(point);
			pDoc->group[PressNum]=point;
			PressNum=0; //����ͼ
			pDoc->DDALine(&ht);
			ReleaseCapture();
		}
	}

	if(MenuID==2){//�е�ֱ���㷨
		if(PressNum==0){ //��һ�ΰ�������һ�㱣�����ĵ���������
		pDoc->group[PressNum]=point;
		mPointOrign=point;
		mPointOld=point;//��¼��һ��
		PressNum++;
		SetCapture();
		}
		else if(PressNum==1){ //�ڶ��ΰ��������ڶ��㣬���ĵ��໭��
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//������Ƥ��
			ht.LineTo(point);
			pDoc->group[PressNum]=point;
			PressNum=0; //����ͼ
			pDoc->MIDLine(&ht);
			ReleaseCapture();
		}
	}

	if(MenuID==3||MenuID==4||MenuID==40){//BresenhamԲ��������Բ
		if(PressNum==0){//��һ�ΰ�������һ�㱣����mPointOrign
			pDoc->group[PressNum]=point;
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//��¼��һ��
			SetCapture();
		}
		else if(PressNum==1&&MenuID==3){//�ڶ��ΰ��������ĵ���BresenhamԲ��Բ����ͼ
			PressNum=0;
			pDoc->BCircle(&ht,mPointOrign,point);ReleaseCapture();
		}
		else if(PressNum==1&&MenuID==4){//�ڶ��ΰ��������ĵ�����������Բ����ͼ
			PressNum=0;
			pDoc->PNCircle(&ht,mPointOrign,point);ReleaseCapture();
		}
		else if(PressNum==1&&MenuID==40)//Բ�ü�
		{
			//pDoc->group[PressNum]=point;
			PressNum=0;
			pDoc->CutCircle(&ht,mPointOrign,point);
			ReleaseCapture();
		}
	}

	if(MenuID==5||MenuID==26||MenuID==34){//Bezier���ߡ�B�������ߡ�Hermite����ѡ�㲢��ʮ�ֱ�־
		pDoc->group[pDoc->PointNum++]=point;
		ht.MoveTo(point.x-5,point.y);
		ht.LineTo(point.x+5,point.y);
		ht.MoveTo(point.x,point.y-5);
		ht.LineTo(point.x,point.y+5);
		SetCapture();
		PressNum=1;
	}

	if(MenuID==6&&PressNum==0){//�ڿ��Ƶ������У����Ѱ��
		for(int i=0;i<pDoc->PointNum;i++){
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5)&&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)){
				SaveNumber=i;
				PressNum=1;
			}
		}
	}

	if(MenuID==27&&PressNum==0){//�ڿ��Ƶ������У����Ѱ��
		for(int i=0;i<pDoc->PointNum;i++){
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5)&&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)){
				SaveNumber=i;
				PressNum=1;
			}
		}
	}

	if(MenuID==35&&PressNum==0){//�ڿ��Ƶ������У����Ѱ��
		for(int i=0;i<pDoc->PointNum;i++){
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5)&&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)){
				SaveNumber=i;
				PressNum=1;
			}
		}
	}

	if(MenuID==11){
		//ƽ��
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//��¼��һ��
			SetCapture();
		}
		else if(PressNum==1){//�������������ƽ����
			for(int i=0;i<pDoc->PointNum;i++){//����ƽ����������ͼ������
				pDoc->group[i].x+=point.x-mPointOrign.x;
				pDoc->group[i].y+=point.y-mPointOrign.y;
			}
			ht.DPtoLP(&point);
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//������Ƥ��
			ht.LineTo(point);
			pDoc->DrawGraph(&ht);//������ͼ��
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==30){
		//��ת
		double pai=3.1415926;
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//��¼��һ��
			SetCapture();
		}
		else if(PressNum==1){//���������������ת�Ƕȡ�
			double dx=point.x-mPointOrign.x;
			double dy=-(point.y-mPointOrign.y);
			double k=dy/dx;
			double a;//��ת��

			//����ֱ�ߵ�б��ȷ����ת�ǣ�ͳһ��˳ʱ����ת��
			if(dx>0&&dy>0){
				a=2*pai-atan(k);//˳ʱ����תa(���)����һ����
			}
			else if(dx>0&&dy<0){
				a=atan(-k);//��ʱ����תa(���)����������
			}
			else if(dx<0&&dy>0){
				a=2*pai-(pai-atan(-k));//˳ʱ����תa(�۽�)���ڶ�����
			}
			else if(dx<0&&dy<0){
				a=pai-atan(k);//��ʱ����תa(�۽�)����������
			}

			//��ת��ʽΪrotateX=cos(a)*sourceX+sin(a)*sourceY��rotateY=-sin(a)*sourceX+cos(a)*sourceY
			for(int i=0;i<pDoc->PointNum;i++){
				pDoc->group[i].x=cos(a)*pDoc->group[i].x+sin(a)*pDoc->group[i].y;
				pDoc->group[i].y=-sin(a)*pDoc->group[i].x+cos(a)*pDoc->group[i].y;
			}
			ht.DPtoLP(&point);
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//������Ƥ��
			ht.LineTo(point);
			pDoc->DrawGraph(&ht);//������ͼ��
			ReleaseCapture();
			PressNum=0;
		}
	}
	
	if(MenuID==31){
		//����
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//��¼��һ��
			SetCapture();
		}
		else if(PressNum==1){//�������������ƽ����
			int dx=point.x-mPointOrign.x;
			int dy=point.y-mPointOrign.y;
			
			//����ֱ�ߵ�б��ȷ�����ű�����d>0Ϊ�Ŵ�d<0Ϊ��С
			//����ƽ����������ͼ������
			pDoc->group[0].x-=(dx/2);
			pDoc->group[0].y+=(dy/2);
			pDoc->group[1].x+=(dx/2);
			pDoc->group[1].y+=(dy/2);
			pDoc->group[2].x+=(dx/2);
			pDoc->group[2].y-=(dy/2);
			pDoc->group[3].x-=(dx/2);
			pDoc->group[3].y-=(dy/2);
			pDoc->group[4].x-=(dx/2);
			pDoc->group[4].y+=(dy/2);

			ht.DPtoLP(&point);
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//������Ƥ��
			ht.LineTo(point);
			pDoc->DrawGraph(&ht);//������ͼ��
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==15){//�ԳƱ任
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//��¼��һ��
			SetCapture();
		}
		else if(PressNum==1){
			pDoc->Symmetry(mPointOrign,point);//���жԳƱ任
			pDoc->DrawGraph(&ht);//������ͼ��
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==20){//�������:���߽�
		if(PressNum==0){
			mPointOrign=point;
			mPointOld=point;
			mPointOld1=point;//��¼��һ��
			PressNum++;
			SetCapture();
		}
		else{
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//������Ƥ��
			ht.LineTo(point);
			pDoc->group[0]=mPointOrign;//����DDAֱ�ߺ������߽�
			pDoc->group[1]=point;
			pDoc->DDALine(&ht);
			mPointOrign=point;
			mPointOld=point;
			PressNum++;
		}
	}

	if(MenuID==21){//ȷ�����ӵ㣬���
		pDoc->SeedFill(&ht,point);
		PressNum=0;MenuID=20;//���þ������������ʽ
	}

	if((MenuID==22||MenuID==23||MenuID==25)){//��Ե���ѡ�����ɨ��������㷨������βü�����
		pDoc->group[PressNum++]=point;
		pDoc->PointNum++;
		mPointOrign=point;
		mPointOld=point;
		SetCapture();
	}

	if(MenuID==24){//Cohen-sutherland�ü��㷨
		if(PressNum==0){
			mPointOrign=point;
			mPointOld=point;
			PressNum++;
			SetCapture();
		}
		else{
			pDoc->CohenSutherland(&ht,mPointOrign,point);
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==32){//�е�ü��㷨
		if(PressNum==0){
			mPointOrign=point;
			mPointOld=point;
			PressNum++;
			SetCapture();
		}
		else{
			pDoc->cutmiddle(&ht,mPointOrign,point);
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==33){//���Ѷ�-Barsky �㷨
		if(PressNum==0){
			mPointOrign=point;
			mPointOld=point;
			PressNum++;
			SetCapture();
		}
		else{
			pDoc->cutmiddle(&ht,mPointOrign,point);
			ReleaseCapture();
			PressNum=0;
		}
	}


	CView::OnLButtonDown(nFlags, point);
}

//����Ҽ���Ӧ����
void CMy2018302080104View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC ht(this); //���嵱ǰ��ͼ�豸
	OnPrepareDC(&ht);
	ht.DPtoLP(&point);

	if(MenuID==5&&pDoc->PointNum>3){
		pDoc->Bezier(&ht,1);//����Bezier����
		MenuID=6; //������Ĳ�����Ϊ�޸Ŀ��Ƶ�λ��
		PressNum=0;
	}

	if(MenuID==6&&PressNum==1){
		PressNum=0;
	}

	if(MenuID==26&&pDoc->PointNum>4){
		pDoc->Bsampl(&ht,1);//����B��������
		MenuID=27; //������Ĳ�����Ϊ�޸Ŀ��Ƶ�λ��
		PressNum=0;
	}
	if(MenuID==27&&PressNum==1){
		PressNum=0;
	}

	if(MenuID==34&&pDoc->PointNum>4){
		pDoc->Hermite(&ht,1);//����Hermite����
		MenuID=35; //������Ĳ�����Ϊ�޸Ŀ��Ƶ�λ��
		PressNum=0;
	}
	if(MenuID==35&&PressNum==1){
		PressNum=0;
	}

	if(MenuID==20&&PressNum>0){//�������ѡ�����
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//������Ƥ��
		ht.LineTo(point);
		pDoc->group[0]=mPointOld1;//��ն����
		pDoc->group[1]=mPointOrign;
		pDoc->DDALine(&ht);
		PressNum=0;MenuID=21;//�ı������ʽΪ���ӵ�ѡȡ
		ReleaseCapture();
	}

	if(MenuID==22){//��Ե���ѡ�����
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//������Ƥ��
		ht.LineTo(point);
		pDoc->group[PressNum]=pDoc->group[0];
		pDoc->PointNum++;
		ht.MoveTo(pDoc->group[PressNum-1]);
		ht.LineTo(pDoc->group[0]);
		for(int i=0;i<PressNum;i++){
			ht.LineTo(pDoc->group[i+1]);
		}
		pDoc->EdgeFill(&ht);
		PressNum=0;pDoc->PointNum=0;
		ReleaseCapture();
	}

	if(MenuID==23){
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//������Ƥ��
		ht.LineTo(point);
		pDoc->group[PressNum]=pDoc->group[0];//��ն����
		ht.MoveTo(pDoc->group[PressNum-1]);//����
		ht.LineTo(pDoc->group[0]);
		for(int i=0;i<PressNum;i++){//����
			ht.LineTo(pDoc->group[i+1]);
		}
		CPen pen(PS_SOLID,1,pDoc->m_crColor);//���ö���α߽���ɫ�������ʣ�
		CPen*pOldPen=ht.SelectObject(&pen);
		CBrush brush(pDoc->m_crColor); //���ö���������ɫ������ˢ��
		CBrush*pOldBrush=ht.SelectObject(&brush);
		ht.SetROP2(R2_COPYPEN); //����ֱ�ӻ���ʽ
		ht.Polygon(pDoc->group,PressNum);//���ö����ɨ������亯��
		ht.SelectObject(pOldPen);//�ָ�ϵͳ�Ļ��ʡ���ˢ��ɫ����
		ht.SelectObject(pOldBrush);
		PressNum=0;pDoc->PointNum=0;//��ʼ��������Ϊ��һ�β�����׼��
		ReleaseCapture();
	}

	if(MenuID==25){//����βü�
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//������Ƥ��
		ht.LineTo(point);
		pDoc->group[PressNum]=pDoc->group[0];//����һ��������Ϊ���һ������
		pDoc->PointNum=PressNum; //��¼��������
		ht.MoveTo(pDoc->group[PressNum-1]);
		ht.LineTo(pDoc->group[0]);
		pDoc->PolygonCut(&ht);
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}


	CView::OnRButtonDown(nFlags, point);
}

//����ƶ���Ӧ����
void CMy2018302080104View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	int xx,yy;
	char p1[20];
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDC.DPtoLP(&point);
	pDC.SetROP2(R2_NOT);//�������ʽ
	xx=point.x; yy = point.y; //ȡ��������Ϣ
	sprintf(p1,"%4d",xx); //ת��Ϊ�ַ���
	m_wndStatusBar.SetPaneText(2,LPCTSTR(p1),TRUE); //�ڵ�2��������ʾx����
	sprintf(p1,"%4d",yy); //ת��Ϊ�ַ���
	m_wndStatusBar.SetPaneText(3,LPCTSTR(p1),TRUE); //�ڵ�3��������ʾy����
	
	//��Ƥ�����
	if((MenuID==1||MenuID==2||MenuID==11||MenuID==15||MenuID==20||MenuID==22||MenuID==23||MenuID==24||MenuID==25||MenuID==30||MenuID==31||MenuID==32||MenuID==33)&&PressNum>0){
		//DDAֱ�ߡ��е�ֱ���㷨��ƽ�ơ���ת�����š��Գơ�������䡢��Ե��䡢ɨ������䡢Cohen-sutherland�ü��㷨������βü����е�ü���Barsky�ü�
		if(mPointOld!=point){
			pDC.MoveTo(mPointOrign);
			pDC.LineTo(mPointOld);//������
			pDC.MoveTo(mPointOrign);
			pDC.LineTo(point);//������
			mPointOld=point;
		} 
	}

	if((MenuID==3||MenuID==4||MenuID==40)&&PressNum==1){
		pDC.SelectStockObject(NULL_BRUSH);//������Բ
		if(mPointOld!=point){
			int r=(int)sqrt(((mPointOrign.x-mPointOld.x)*(mPointOrign.x-mPointOld.x)+(mPointOrign.y-mPointOld.y)*(mPointOrign.y-mPointOld.y))*1.0);
			pDC.Ellipse(mPointOrign.x-r,mPointOrign.y- r,mPointOrign.x+r,mPointOrign.y+r);//����Բ
			r=(int)sqrt(((mPointOrign.x-point.x)*(mPointOrign.x-point.x) + (mPointOrign.y-point.y)*(mPointOrign.y-point.y))*1.0);
			pDC.Ellipse(mPointOrign.x-r,mPointOrign.y- r,mPointOrign.x+r,mPointOrign.y+r);//����Բ
			mPointOld=point;
		} 
	}

	if((MenuID==6)&&PressNum>0){
		if(pDoc->group[SaveNumber]!=point){
			//��ʮ�ֱ�־
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y);
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5);
			pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5);
			pDoc->Bezier(&pDC,1);//����ʮ�ֱ�־�;���
			pDC.MoveTo(point.x-5,point.y);
			pDC.LineTo(point.x+5,point.y);
			pDC.MoveTo(point.x,point.y-5);
			pDC.LineTo(point.x,point.y+5);
			pDoc->group[SaveNumber]=point;//��¼�¿��Ƶ�
			pDoc->Bezier(&pDC,1);//��ʮ�ֱ�־��������
		}
	}
	if((MenuID==27)&&PressNum>0){
		if(pDoc->group[SaveNumber]!=point){
			//��ʮ�ֱ�־
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y);
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5);
			pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5);
			pDoc->Bsampl(&pDC,1);//����ʮ�ֱ�־�;���
			pDC.MoveTo(point.x-5,point.y);
			pDC.LineTo(point.x+5,point.y);
			pDC.MoveTo(point.x,point.y-5);
			pDC.LineTo(point.x,point.y+5);
			pDoc->group[SaveNumber]=point;//��¼�¿��Ƶ�
			pDoc->Bsampl(&pDC,1);//��ʮ�ֱ�־��������
		}
	}

	if((MenuID==35)&&PressNum>0){
		if(pDoc->group[SaveNumber]!=point){
			//��ʮ�ֱ�־
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y);
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5);
			pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5);
			pDoc->Hermite(&pDC,1);//����ʮ�ֱ�־�;���
			pDC.MoveTo(point.x-5,point.y);
			pDC.LineTo(point.x+5,point.y);
			pDC.MoveTo(point.x,point.y-5);
			pDC.LineTo(point.x,point.y+5);
			pDoc->group[SaveNumber]=point;//��¼�¿��Ƶ�
			pDoc->Hermite(&pDC,1);//��ʮ�ֱ�־��������
		}
	}
	

	CView::OnMouseMove(nFlags, point);
}

//������˫���¼�
void CMy2018302080104View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDC.DPtoLP(&point);
	pDC.SetROP2(R2_NOT);//�������ʽ

	if(MenuID==6){
		for(int i=0;i<pDoc->PointNum;i++){//�������й�꣬����ʮ�ֱ�־
			pDC.MoveTo(pDoc->group[i].x-5,pDoc->group[i].y);
			pDC.LineTo(pDoc->group[i].x+5,pDoc->group[i].y);
			pDC.MoveTo(pDoc->group[i].x,pDoc->group[i].y-5);
			pDC.LineTo(pDoc->group[i].x,pDoc->group[i].y+5);
		}
		pDoc->Bezier(&pDC,0);//����Bezier����
		MenuID=5; //������Ĳ����Ļ�Bezier���߷�ʽ
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}

	if(MenuID==27){
		for(int i=0;i<pDoc->PointNum;i++){//�������й�꣬����ʮ�ֱ�־
			pDC.MoveTo(pDoc->group[i].x-5,pDoc->group[i].y);
			pDC.LineTo(pDoc->group[i].x+5,pDoc->group[i].y);
			pDC.MoveTo(pDoc->group[i].x,pDoc->group[i].y-5);
			pDC.LineTo(pDoc->group[i].x,pDoc->group[i].y+5);
		}
		pDoc->Bsampl(&pDC,0);//����B��������
		MenuID=26; //������Ĳ����Ļ�B�������ߺ�����ʽ
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}

	if(MenuID==35){
		for(int i=0;i<pDoc->PointNum;i++){//�������й�꣬����ʮ�ֱ�־
			pDC.MoveTo(pDoc->group[i].x-5,pDoc->group[i].y);
			pDC.LineTo(pDoc->group[i].x+5,pDoc->group[i].y);
			pDC.MoveTo(pDoc->group[i].x,pDoc->group[i].y-5);
			pDC.LineTo(pDoc->group[i].x,pDoc->group[i].y+5);
		}
		pDoc->Hermite(&pDC,0);//����Hermite����
		MenuID=26; //������Ĳ����Ļ�Hermite���ߺ�����ʽ
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CMy2018302080104View::OnDrawDdaline()
{
	// TODO: �ڴ���������������
	PressNum=0; 
	MenuID=1;
}


void CMy2018302080104View::OnDrawBcircle()
{
	// TODO: �ڴ���������������
	PressNum=0;
	MenuID=3;
}


void CMy2018302080104View::OnDrawPncircle()
{
	// TODO: �ڴ���������������
	PressNum=0;MenuID=4;
}


void CMy2018302080104View::OnCurveBezier()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	pDoc->PointNum=0;//��ʼ��
	PressNum=0;MenuID=5;
}



void CMy2018302080104View::OnSetchar()
{
	// TODO: �ڴ���������������
	CDC *pDC=GetDC();
	CSetCharDlg dlg;
	if(dlg.DoModal()==IDOK){
		CFont*pfntOld=pDC->SelectObject(&dlg.m_fnt);//���������
		pDC->SetTextColor(dlg.m_clrText);//������ɫ
		pDC->TextOut(dlg.m_nX,dlg.m_nY,dlg.m_strString);//������Ļ��
		pDC->SelectObject(pfntOld);//��ԭ������
	}
	ReleaseDC(pDC);
}


void CMy2018302080104View::OnTransMove()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//�����ĵ��ຯ������Ļ������ͼ��
	PressNum=0; MenuID=11;
}


void CMy2018302080104View::OnTransSymmetry()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);
	PressNum=0;MenuID=15;
}


void CMy2018302080104View::OnFillSeed()
{
	// TODO: �ڴ���������������
	PressNum=0;MenuID=20;
}


void CMy2018302080104View::OnFillEdge()
{
	// TODO: �ڴ���������������
	PressNum=0;MenuID=22;
}


void CMy2018302080104View::OnFillScanline()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	pDoc->PointNum=0;//ʵ���ϲ���Ҫ�ñ�������Ϊ�˽����Ե���Ĳ��ֹ��ܣ����Ե��䱣��һ��
	PressNum=0;MenuID=23;
}


void CMy2018302080104View::OnCutCs()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=24;
}


void CMy2018302080104View::OnCutPolygon()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=25;
}


void CMy2018302080104View::OnDrawMidline()
{
	// TODO: �ڴ���������������
	PressNum=0; 
	MenuID=2;
}


void CMy2018302080104View::OnCurveBsample()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	pDoc->PointNum=0;//��ʼ��
	PressNum=0;MenuID=26;
}


void CMy2018302080104View::OnTransRotate()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph2(&pDC);//�����ĵ��ຯ������Ļ������ͼ��
	PressNum=0; MenuID=30;
}


void CMy2018302080104View::OnTransZoom()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph2(&pDC);//�����ĵ��ຯ������Ļ������ͼ��
	PressNum=0; MenuID=31;
}


void CMy2018302080104View::OnCutMiddle()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=32;
}


void CMy2018302080104View::OnCutLiang()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=33;
}


void CMy2018302080104View::OnCurveHermite()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	pDoc->PointNum=0;//��ʼ��
	PressNum=0;MenuID=34;
}


void CMy2018302080104View::OnClear()
{
	// TODO: �ڴ���������������
	RedrawWindow();
}


void CMy2018302080104View::OnCirclecut()
{
	// TODO: �ڴ���������������
	CMy2018302080104Doc *pDoc=GetDocument();//����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=40;
}
