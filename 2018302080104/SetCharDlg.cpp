// SetCharDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2018302080104.h"
#include "SetCharDlg.h"
#include "afxdialogex.h"


// CSetCharDlg �Ի���

IMPLEMENT_DYNAMIC(CSetCharDlg, CDialogEx)

CSetCharDlg::CSetCharDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetCharDlg::IDD, pParent)
{

	m_strString = _T("");
	m_nX = 0;
	m_nY = 0;
	m_clrText=RGB(0,0,0);
}

CSetCharDlg::~CSetCharDlg()
{
}

void CSetCharDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_EDIT_CHAR, m_strString);
	DDX_Text(pDX, ID_EDIT_X, m_nX);
	DDX_Text(pDX, ID_EDIT_Y, m_nY);
}


BEGIN_MESSAGE_MAP(CSetCharDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Font, &CSetCharDlg::OnClickedButtonFont)
END_MESSAGE_MAP()


// CSetCharDlg ��Ϣ�������


void CSetCharDlg::OnClickedButtonFont()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFontDialog dlg;
	if(dlg.DoModal()==IDOK){
		m_fnt.DeleteObject();
		LOGFONT LogFnt;
		dlg.GetCurrentFont(&LogFnt);//������ѡ����
		m_fnt.CreateFontIndirect(&LogFnt);//������ѡ����
		m_clrText=dlg.GetColor();//�����ѡ��ɫ
	}
}
