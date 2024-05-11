// XListBoxTestDlg.h : header file
//

#ifndef XLISTBOXTESTDLG_H
#define XLISTBOXTESTDLG_H

#include "XListBox.h"
#include "ColorPickerCB.h"

/////////////////////////////////////////////////////////////////////////////
// CXListBoxTestDlg dialog

class CXListBoxTestDlg : public CDialog
{
// Construction
public:
	CXListBoxTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CXListBoxTestDlg)
	enum { IDD = IDD_XLISTBOXTEST_DIALOG };
	CEdit			m_Edit;
	CColorPickerCB	m_Text;
	CColorPickerCB	m_Background;
	CXListBox		m_List;
	int				m_nBackground;
	int				m_nText;
	CString			m_strText;
	BOOL			m_bLineNumbers;
	BOOL			m_bLogFile;
	int				m_nUseColor;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXListBoxTestDlg)
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON			m_hIcon;
	CString			m_strLogFile;
	CToolTipCtrl	m_ToolTips;
	int				m_nGutterWidth;
	COLORREF		m_rgbLinenoColor;
	COLORREF		m_rgbGutterColor;

	int GetRandomColor(int n);

	// Generated message map functions
	//{{AFX_MSG(CXListBoxTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddString();
	afx_msg void OnLineNumbers();
	afx_msg void OnLogFile();
	afx_msg void OnLineNumberOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif //XLISTBOXTESTDLG_H
