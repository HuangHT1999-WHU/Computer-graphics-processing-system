
// 2018302080104View.cpp : CMy2018302080104View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMy2018302080104View 构造/析构

CMy2018302080104View::CMy2018302080104View()
{
	// TODO: 在此处添加构造代码

}

CMy2018302080104View::~CMy2018302080104View()
{
}

BOOL CMy2018302080104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2018302080104View 绘制

void CMy2018302080104View::OnDraw(CDC* /*pDC*/)
{
	CMy2018302080104Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2018302080104View 打印


void CMy2018302080104View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2018302080104View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2018302080104View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2018302080104View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CMy2018302080104View 诊断

#ifdef _DEBUG
void CMy2018302080104View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2018302080104View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2018302080104Doc* CMy2018302080104View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2018302080104Doc)));
	return (CMy2018302080104Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2018302080104View 消息处理程序

//鼠标左键响应函数
void CMy2018302080104View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2018302080104Doc *pDoc=GetDocument(); //获得文档类指针
	CClientDC ht(this); //定义当前绘图设备
	if(MenuID==1){ //DDA直线
		if(PressNum==0){ //第一次按键将第一点保留在文档类数组中
		pDoc->group[PressNum]=point;
		mPointOrign=point;
		mPointOld=point;//记录第一点
		PressNum++;
		SetCapture();
		}
		else if(PressNum==1){ //第二次按键保留第二点，用文档类画线
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//擦除橡皮筋
			ht.LineTo(point);
			pDoc->group[PressNum]=point;
			PressNum=0; //程序画图
			pDoc->DDALine(&ht);
			ReleaseCapture();
		}
	}

	if(MenuID==2){//中点直线算法
		if(PressNum==0){ //第一次按键将第一点保留在文档类数组中
		pDoc->group[PressNum]=point;
		mPointOrign=point;
		mPointOld=point;//记录第一点
		PressNum++;
		SetCapture();
		}
		else if(PressNum==1){ //第二次按键保留第二点，用文档类画线
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//擦除橡皮筋
			ht.LineTo(point);
			pDoc->group[PressNum]=point;
			PressNum=0; //程序画图
			pDoc->MIDLine(&ht);
			ReleaseCapture();
		}
	}

	if(MenuID==3||MenuID==4||MenuID==40){//Bresenham圆或正负法圆
		if(PressNum==0){//第一次按键将第一点保留在mPointOrign
			pDoc->group[PressNum]=point;
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//记录第一点
			SetCapture();
		}
		else if(PressNum==1&&MenuID==3){//第二次按键调用文档类Bresenham圆画圆程序画图
			PressNum=0;
			pDoc->BCircle(&ht,mPointOrign,point);ReleaseCapture();
		}
		else if(PressNum==1&&MenuID==4){//第二次按键调用文档类正负法画圆程序画图
			PressNum=0;
			pDoc->PNCircle(&ht,mPointOrign,point);ReleaseCapture();
		}
		else if(PressNum==1&&MenuID==40)//圆裁剪
		{
			//pDoc->group[PressNum]=point;
			PressNum=0;
			pDoc->CutCircle(&ht,mPointOrign,point);
			ReleaseCapture();
		}
	}

	if(MenuID==5||MenuID==26||MenuID==34){//Bezier曲线、B样条曲线、Hermite曲线选点并做十字标志
		pDoc->group[pDoc->PointNum++]=point;
		ht.MoveTo(point.x-5,point.y);
		ht.LineTo(point.x+5,point.y);
		ht.MoveTo(point.x,point.y-5);
		ht.LineTo(point.x,point.y+5);
		SetCapture();
		PressNum=1;
	}

	if(MenuID==6&&PressNum==0){//在控制点数组中，逐个寻找
		for(int i=0;i<pDoc->PointNum;i++){
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5)&&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)){
				SaveNumber=i;
				PressNum=1;
			}
		}
	}

	if(MenuID==27&&PressNum==0){//在控制点数组中，逐个寻找
		for(int i=0;i<pDoc->PointNum;i++){
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5)&&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)){
				SaveNumber=i;
				PressNum=1;
			}
		}
	}

	if(MenuID==35&&PressNum==0){//在控制点数组中，逐个寻找
		for(int i=0;i<pDoc->PointNum;i++){
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5)&&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)){
				SaveNumber=i;
				PressNum=1;
			}
		}
	}

	if(MenuID==11){
		//平移
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//记录第一点
			SetCapture();
		}
		else if(PressNum==1){//根据两点间距计算平移量
			for(int i=0;i<pDoc->PointNum;i++){//根据平移量计算新图形坐标
				pDoc->group[i].x+=point.x-mPointOrign.x;
				pDoc->group[i].y+=point.y-mPointOrign.y;
			}
			ht.DPtoLP(&point);
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//擦除橡皮筋
			ht.LineTo(point);
			pDoc->DrawGraph(&ht);//生成新图形
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==30){
		//旋转
		double pai=3.1415926;
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//记录第一点
			SetCapture();
		}
		else if(PressNum==1){//根据两点间距计算旋转角度‘
			double dx=point.x-mPointOrign.x;
			double dy=-(point.y-mPointOrign.y);
			double k=dy/dx;
			double a;//旋转角

			//根据直线的斜率确定旋转角，统一到顺时针旋转上
			if(dx>0&&dy>0){
				a=2*pai-atan(k);//顺时针旋转a(锐角)，第一象限
			}
			else if(dx>0&&dy<0){
				a=atan(-k);//逆时针旋转a(锐角)，第四象限
			}
			else if(dx<0&&dy>0){
				a=2*pai-(pai-atan(-k));//顺时针旋转a(钝角)，第二象限
			}
			else if(dx<0&&dy<0){
				a=pai-atan(k);//逆时针旋转a(钝角)，第三象限
			}

			//旋转公式为rotateX=cos(a)*sourceX+sin(a)*sourceY；rotateY=-sin(a)*sourceX+cos(a)*sourceY
			for(int i=0;i<pDoc->PointNum;i++){
				pDoc->group[i].x=cos(a)*pDoc->group[i].x+sin(a)*pDoc->group[i].y;
				pDoc->group[i].y=-sin(a)*pDoc->group[i].x+cos(a)*pDoc->group[i].y;
			}
			ht.DPtoLP(&point);
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//擦除橡皮筋
			ht.LineTo(point);
			pDoc->DrawGraph(&ht);//生成新图形
			ReleaseCapture();
			PressNum=0;
		}
	}
	
	if(MenuID==31){
		//缩放
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//记录第一点
			SetCapture();
		}
		else if(PressNum==1){//根据两点间距计算平移量
			int dx=point.x-mPointOrign.x;
			int dy=point.y-mPointOrign.y;
			
			//根据直线的斜率确定缩放比例，d>0为放大，d<0为缩小
			//根据平移量计算新图形坐标
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
			ht.MoveTo(mPointOrign);//擦除橡皮筋
			ht.LineTo(point);
			pDoc->DrawGraph(&ht);//生成新图形
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==15){//对称变换
		if(PressNum==0){
			PressNum++;
			mPointOrign=point;
			mPointOld=point;//记录第一点
			SetCapture();
		}
		else if(PressNum==1){
			pDoc->Symmetry(mPointOrign,point);//进行对称变换
			pDoc->DrawGraph(&ht);//生成新图形
			ReleaseCapture();
			PressNum=0;
		}
	}

	if(MenuID==20){//种子填充:画边界
		if(PressNum==0){
			mPointOrign=point;
			mPointOld=point;
			mPointOld1=point;//记录第一点
			PressNum++;
			SetCapture();
		}
		else{
			ht.SetROP2(R2_NOT);
			ht.MoveTo(mPointOrign);//擦除橡皮筋
			ht.LineTo(point);
			pDoc->group[0]=mPointOrign;//借助DDA直线函数画边界
			pDoc->group[1]=point;
			pDoc->DDALine(&ht);
			mPointOrign=point;
			mPointOld=point;
			PressNum++;
		}
	}

	if(MenuID==21){//确定种子点，填充
		pDoc->SeedFill(&ht,point);
		PressNum=0;MenuID=20;//设置决定顶点操作方式
	}

	if((MenuID==22||MenuID==23||MenuID==25)){//边缘填充选顶点和扫描线填充算法、多边形裁剪共用
		pDoc->group[PressNum++]=point;
		pDoc->PointNum++;
		mPointOrign=point;
		mPointOld=point;
		SetCapture();
	}

	if(MenuID==24){//Cohen-sutherland裁剪算法
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

	if(MenuID==32){//中点裁剪算法
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

	if(MenuID==33){//梁友栋-Barsky 算法
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

//鼠标右键响应函数
void CMy2018302080104View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC ht(this); //定义当前绘图设备
	OnPrepareDC(&ht);
	ht.DPtoLP(&point);

	if(MenuID==5&&pDoc->PointNum>3){
		pDoc->Bezier(&ht,1);//绘制Bezier函数
		MenuID=6; //将下面的操作改为修改控制点位置
		PressNum=0;
	}

	if(MenuID==6&&PressNum==1){
		PressNum=0;
	}

	if(MenuID==26&&pDoc->PointNum>4){
		pDoc->Bsampl(&ht,1);//绘制B样条函数
		MenuID=27; //将下面的操作改为修改控制点位置
		PressNum=0;
	}
	if(MenuID==27&&PressNum==1){
		PressNum=0;
	}

	if(MenuID==34&&pDoc->PointNum>4){
		pDoc->Hermite(&ht,1);//绘制Hermite函数
		MenuID=35; //将下面的操作改为修改控制点位置
		PressNum=0;
	}
	if(MenuID==35&&PressNum==1){
		PressNum=0;
	}

	if(MenuID==20&&PressNum>0){//种子填充选点结束
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//擦除橡皮筋
		ht.LineTo(point);
		pDoc->group[0]=mPointOld1;//封闭多边形
		pDoc->group[1]=mPointOrign;
		pDoc->DDALine(&ht);
		PressNum=0;MenuID=21;//改变操作方式为种子点选取
		ReleaseCapture();
	}

	if(MenuID==22){//边缘填充选点结束
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//擦除橡皮筋
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
		ht.MoveTo(mPointOrign);//擦除橡皮筋
		ht.LineTo(point);
		pDoc->group[PressNum]=pDoc->group[0];//封闭多边形
		ht.MoveTo(pDoc->group[PressNum-1]);//擦除
		ht.LineTo(pDoc->group[0]);
		for(int i=0;i<PressNum;i++){//擦除
			ht.LineTo(pDoc->group[i+1]);
		}
		CPen pen(PS_SOLID,1,pDoc->m_crColor);//设置多边形边界颜色（即画笔）
		CPen*pOldPen=ht.SelectObject(&pen);
		CBrush brush(pDoc->m_crColor); //设置多边形填充颜色（即画刷）
		CBrush*pOldBrush=ht.SelectObject(&brush);
		ht.SetROP2(R2_COPYPEN); //设置直接画方式
		ht.Polygon(pDoc->group,PressNum);//调用多边形扫描线填充函数
		ht.SelectObject(pOldPen);//恢复系统的画笔、画刷颜色设置
		ht.SelectObject(pOldBrush);
		PressNum=0;pDoc->PointNum=0;//初始化参数，为下一次操作做准备
		ReleaseCapture();
	}

	if(MenuID==25){//多边形裁剪
		ht.SetROP2(R2_NOT);
		ht.MoveTo(mPointOrign);//擦除橡皮筋
		ht.LineTo(point);
		pDoc->group[PressNum]=pDoc->group[0];//将第一个顶点作为最后一个顶点
		pDoc->PointNum=PressNum; //记录顶点数量
		ht.MoveTo(pDoc->group[PressNum-1]);
		ht.LineTo(pDoc->group[0]);
		pDoc->PolygonCut(&ht);
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}


	CView::OnRButtonDown(nFlags, point);
}

//鼠标移动响应函数
void CMy2018302080104View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	int xx,yy;
	char p1[20];
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDC.DPtoLP(&point);
	pDC.SetROP2(R2_NOT);//设置异或方式
	xx=point.x; yy = point.y; //取出坐标信息
	sprintf(p1,"%4d",xx); //转化为字符串
	m_wndStatusBar.SetPaneText(2,LPCTSTR(p1),TRUE); //在第2个区域显示x坐标
	sprintf(p1,"%4d",yy); //转化为字符串
	m_wndStatusBar.SetPaneText(3,LPCTSTR(p1),TRUE); //在第3个区域显示y坐标
	
	//橡皮筋操作
	if((MenuID==1||MenuID==2||MenuID==11||MenuID==15||MenuID==20||MenuID==22||MenuID==23||MenuID==24||MenuID==25||MenuID==30||MenuID==31||MenuID==32||MenuID==33)&&PressNum>0){
		//DDA直线、中点直线算法、平移、旋转、缩放、对称、种子填充、边缘填充、扫描线填充、Cohen-sutherland裁剪算法、多边形裁剪、中点裁减、Barsky裁剪
		if(mPointOld!=point){
			pDC.MoveTo(mPointOrign);
			pDC.LineTo(mPointOld);//擦旧线
			pDC.MoveTo(mPointOrign);
			pDC.LineTo(point);//画新线
			mPointOld=point;
		} 
	}

	if((MenuID==3||MenuID==4||MenuID==40)&&PressNum==1){
		pDC.SelectStockObject(NULL_BRUSH);//画空心圆
		if(mPointOld!=point){
			int r=(int)sqrt(((mPointOrign.x-mPointOld.x)*(mPointOrign.x-mPointOld.x)+(mPointOrign.y-mPointOld.y)*(mPointOrign.y-mPointOld.y))*1.0);
			pDC.Ellipse(mPointOrign.x-r,mPointOrign.y- r,mPointOrign.x+r,mPointOrign.y+r);//擦旧圆
			r=(int)sqrt(((mPointOrign.x-point.x)*(mPointOrign.x-point.x) + (mPointOrign.y-point.y)*(mPointOrign.y-point.y))*1.0);
			pDC.Ellipse(mPointOrign.x-r,mPointOrign.y- r,mPointOrign.x+r,mPointOrign.y+r);//画新圆
			mPointOld=point;
		} 
	}

	if((MenuID==6)&&PressNum>0){
		if(pDoc->group[SaveNumber]!=point){
			//画十字标志
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y);
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5);
			pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5);
			pDoc->Bezier(&pDC,1);//擦除十字标志和旧线
			pDC.MoveTo(point.x-5,point.y);
			pDC.LineTo(point.x+5,point.y);
			pDC.MoveTo(point.x,point.y-5);
			pDC.LineTo(point.x,point.y+5);
			pDoc->group[SaveNumber]=point;//记录新控制点
			pDoc->Bezier(&pDC,1);//画十字标志和新曲线
		}
	}
	if((MenuID==27)&&PressNum>0){
		if(pDoc->group[SaveNumber]!=point){
			//画十字标志
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y);
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5);
			pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5);
			pDoc->Bsampl(&pDC,1);//擦除十字标志和旧线
			pDC.MoveTo(point.x-5,point.y);
			pDC.LineTo(point.x+5,point.y);
			pDC.MoveTo(point.x,point.y-5);
			pDC.LineTo(point.x,point.y+5);
			pDoc->group[SaveNumber]=point;//记录新控制点
			pDoc->Bsampl(&pDC,1);//画十字标志和新曲线
		}
	}

	if((MenuID==35)&&PressNum>0){
		if(pDoc->group[SaveNumber]!=point){
			//画十字标志
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y);
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5);
			pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5);
			pDoc->Hermite(&pDC,1);//擦除十字标志和旧线
			pDC.MoveTo(point.x-5,point.y);
			pDC.LineTo(point.x+5,point.y);
			pDC.MoveTo(point.x,point.y-5);
			pDC.LineTo(point.x,point.y+5);
			pDoc->group[SaveNumber]=point;//记录新控制点
			pDoc->Hermite(&pDC,1);//画十字标志和新曲线
		}
	}
	

	CView::OnMouseMove(nFlags, point);
}

//鼠标左键双击事件
void CMy2018302080104View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDC.DPtoLP(&point);
	pDC.SetROP2(R2_NOT);//设置异或方式

	if(MenuID==6){
		for(int i=0;i<pDoc->PointNum;i++){//消除所有光标，绘制十字标志
			pDC.MoveTo(pDoc->group[i].x-5,pDoc->group[i].y);
			pDC.LineTo(pDoc->group[i].x+5,pDoc->group[i].y);
			pDC.MoveTo(pDoc->group[i].x,pDoc->group[i].y-5);
			pDC.LineTo(pDoc->group[i].x,pDoc->group[i].y+5);
		}
		pDoc->Bezier(&pDC,0);//绘制Bezier函数
		MenuID=5; //将下面的操作改回Bezier曲线方式
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}

	if(MenuID==27){
		for(int i=0;i<pDoc->PointNum;i++){//消除所有光标，绘制十字标志
			pDC.MoveTo(pDoc->group[i].x-5,pDoc->group[i].y);
			pDC.LineTo(pDoc->group[i].x+5,pDoc->group[i].y);
			pDC.MoveTo(pDoc->group[i].x,pDoc->group[i].y-5);
			pDC.LineTo(pDoc->group[i].x,pDoc->group[i].y+5);
		}
		pDoc->Bsampl(&pDC,0);//绘制B样条函数
		MenuID=26; //将下面的操作改回B样条曲线函数方式
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}

	if(MenuID==35){
		for(int i=0;i<pDoc->PointNum;i++){//消除所有光标，绘制十字标志
			pDC.MoveTo(pDoc->group[i].x-5,pDoc->group[i].y);
			pDC.LineTo(pDoc->group[i].x+5,pDoc->group[i].y);
			pDC.MoveTo(pDoc->group[i].x,pDoc->group[i].y-5);
			pDC.LineTo(pDoc->group[i].x,pDoc->group[i].y+5);
		}
		pDoc->Hermite(&pDC,0);//绘制Hermite函数
		MenuID=26; //将下面的操作改回Hermite曲线函数方式
		PressNum=0;
		pDoc->PointNum=0;
		ReleaseCapture();
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CMy2018302080104View::OnDrawDdaline()
{
	// TODO: 在此添加命令处理程序代码
	PressNum=0; 
	MenuID=1;
}


void CMy2018302080104View::OnDrawBcircle()
{
	// TODO: 在此添加命令处理程序代码
	PressNum=0;
	MenuID=3;
}


void CMy2018302080104View::OnDrawPncircle()
{
	// TODO: 在此添加命令处理程序代码
	PressNum=0;MenuID=4;
}


void CMy2018302080104View::OnCurveBezier()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	pDoc->PointNum=0;//初始化
	PressNum=0;MenuID=5;
}



void CMy2018302080104View::OnSetchar()
{
	// TODO: 在此添加命令处理程序代码
	CDC *pDC=GetDC();
	CSetCharDlg dlg;
	if(dlg.DoModal()==IDOK){
		CFont*pfntOld=pDC->SelectObject(&dlg.m_fnt);//保存旧字体
		pDC->SetTextColor(dlg.m_clrText);//设置颜色
		pDC->TextOut(dlg.m_nX,dlg.m_nY,dlg.m_strString);//画到屏幕上
		pDC->SelectObject(pfntOld);//还原旧字体
	}
	ReleaseDC(pDC);
}


void CMy2018302080104View::OnTransMove()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//调用文档类函数在屏幕上生成图形
	PressNum=0; MenuID=11;
}


void CMy2018302080104View::OnTransSymmetry()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);
	PressNum=0;MenuID=15;
}


void CMy2018302080104View::OnFillSeed()
{
	// TODO: 在此添加命令处理程序代码
	PressNum=0;MenuID=20;
}


void CMy2018302080104View::OnFillEdge()
{
	// TODO: 在此添加命令处理程序代码
	PressNum=0;MenuID=22;
}


void CMy2018302080104View::OnFillScanline()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	pDoc->PointNum=0;//实际上不需要该变量，但为了借鉴边缘填充的部分功能，与边缘填充保持一致
	PressNum=0;MenuID=23;
}


void CMy2018302080104View::OnCutCs()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=24;
}


void CMy2018302080104View::OnCutPolygon()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=25;
}


void CMy2018302080104View::OnDrawMidline()
{
	// TODO: 在此添加命令处理程序代码
	PressNum=0; 
	MenuID=2;
}


void CMy2018302080104View::OnCurveBsample()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	pDoc->PointNum=0;//初始化
	PressNum=0;MenuID=26;
}


void CMy2018302080104View::OnTransRotate()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph2(&pDC);//调用文档类函数在屏幕上生成图形
	PressNum=0; MenuID=30;
}


void CMy2018302080104View::OnTransZoom()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph2(&pDC);//调用文档类函数在屏幕上生成图形
	PressNum=0; MenuID=31;
}


void CMy2018302080104View::OnCutMiddle()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=32;
}


void CMy2018302080104View::OnCutLiang()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=33;
}


void CMy2018302080104View::OnCurveHermite()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	pDoc->PointNum=0;//初始化
	PressNum=0;MenuID=34;
}


void CMy2018302080104View::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	RedrawWindow();
}


void CMy2018302080104View::OnCirclecut()
{
	// TODO: 在此添加命令处理程序代码
	CMy2018302080104Doc *pDoc=GetDocument();//获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum=0;MenuID=40;
}
