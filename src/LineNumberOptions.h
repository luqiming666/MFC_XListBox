// LineNumberOptions.h : header file
//

#ifndef LINENUMBEROPTIONS_H
#define LINENUMBEROPTIONS_H

#include "XColourPicker.h"

/////////////////////////////////////////////////////////////////////////////
// CLineNumberOptions dialog

class CLineNumberOptions : public CDialog
{
// Construction
public:
	CLineNumberOptions(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLineNumberOptions)
	enum { IDD = IDD_LINE_NUMBERS };
	CXColourPicker	m_btnLinenoColor;
	CXColourPicker	m_btnGutterColor;
	BOOL			m_bLineNumbers;
	//}}AFX_DATA
	int				m_nGutterWidth;
	COLORREF		m_rgbLinenoColor;
	COLORREF		m_rgbGutterColor;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineNumberOptions)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLineNumberOptions)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnLineNumbers();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif //LINENUMBEROPTIONS_H
