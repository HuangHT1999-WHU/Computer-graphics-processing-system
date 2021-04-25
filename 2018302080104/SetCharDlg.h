#pragma once


// CSetCharDlg 对话框

class CSetCharDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetCharDlg)

public:
	CSetCharDlg(CWnd* pParent = NULL);   // 标准构造函数
	CFont m_fnt;//保存字体
	COLORREF m_clrText;//保存颜色
	virtual ~CSetCharDlg();

// 对话框数据
	enum { IDD = IDD_CHARBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strString;
	int m_nX;
	int m_nY;
	afx_msg void OnClickedButtonFont();
};
