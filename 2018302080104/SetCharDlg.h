#pragma once


// CSetCharDlg �Ի���

class CSetCharDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetCharDlg)

public:
	CSetCharDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CFont m_fnt;//��������
	COLORREF m_clrText;//������ɫ
	virtual ~CSetCharDlg();

// �Ի�������
	enum { IDD = IDD_CHARBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strString;
	int m_nX;
	int m_nY;
	afx_msg void OnClickedButtonFont();
};
