// LineNumberOptions.cpp : implementation file
//

#include "stdafx.h"
#include "xlistboxtest.h"
#include "LineNumberOptions.h"
#include "EnableGroupboxControls.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineNumberOptions dialog

BEGIN_MESSAGE_MAP(CLineNumberOptions, CDialog)
	//{{AFX_MSG_MAP(CLineNumberOptions)
	ON_BN_CLICKED(IDC_LINE_NUMBERS, OnLineNumbers)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CLineNumberOptions::CLineNumberOptions(CWnd* pParent /*=NULL*/)
	: CDialog(CLineNumberOptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineNumberOptions)
	m_bLineNumbers = FALSE;
	//}}AFX_DATA_INIT
	m_nGutterWidth = 5;
	m_rgbLinenoColor = RGB(80,80,80);
	m_rgbGutterColor = RGB(245,245,245);
}

void CLineNumberOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineNumberOptions)
	DDX_Control(pDX, IDC_LINENO_COLOR, m_btnLinenoColor);
	DDX_Control(pDX, IDC_GUTTER_COLOR, m_btnGutterColor);
	DDX_Check(pDX, IDC_LINE_NUMBERS, m_bLineNumbers);
	//}}AFX_DATA_MAP

	DDX_ColourPicker(pDX, IDC_LINENO_COLOR, m_rgbLinenoColor);
	DDX_ColourPicker(pDX, IDC_GUTTER_COLOR, m_rgbGutterColor);
}

/////////////////////////////////////////////////////////////////////////////
// CLineNumberOptions message handlers

BOOL CLineNumberOptions::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*) GetDlgItem(IDC_GUTTER_WIDTH_SPIN);
	ASSERT(pSpin);
	pSpin->SetRange32(1, 9);
	pSpin->SetPos(m_nGutterWidth);

	CEdit *pEdit = (CEdit *) GetDlgItem(IDC_GUTTER_WIDTH);
	pEdit->LimitText(1);
	
	OnLineNumbers();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLineNumberOptions::OnOK() 
{
	UpdateData(TRUE);

	CString s = _T("");
	CEdit *pEdit = (CEdit *) GetDlgItem(IDC_GUTTER_WIDTH);
	pEdit->GetWindowText(s);
	m_nGutterWidth = _ttoi(s);
	if (m_nGutterWidth == 0)
		m_nGutterWidth = 1;

	CDialog::OnOK();
}

void CLineNumberOptions::OnLineNumbers()
{
	UpdateData(TRUE);
	EnableGroupboxControls(::GetDlgItem(m_hWnd, IDC_STATICGB), m_bLineNumbers);
}
