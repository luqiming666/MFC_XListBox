// XListBoxTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "XListBoxTest.h"
#include "XListBoxTestDlg.h"
#include "about.h"
#include "LineNumberOptions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//=============================================================================	
BEGIN_MESSAGE_MAP(CXListBoxTestDlg, CDialog)
//=============================================================================	
	//{{AFX_MSG_MAP(CXListBoxTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_STRING, OnAddString)
	ON_BN_CLICKED(IDC_LOG_FILE, OnLogFile)
	ON_BN_CLICKED(IDC_LINE_NUMBER_OPTIONS, OnLineNumberOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//=============================================================================	
CXListBoxTestDlg::CXListBoxTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXListBoxTestDlg::IDD, pParent)
//=============================================================================	
{
	//{{AFX_DATA_INIT(CXListBoxTestDlg)
	m_nBackground = 1;		// white
	m_nText = 0;			// black
	m_strText = _T("This is a sample string");
	m_bLineNumbers = FALSE;
	m_bLogFile = FALSE;
	m_nUseColor = 1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strLogFile = _T("XListBoxTest.log");
	m_nGutterWidth = 5;
	m_rgbLinenoColor = RGB(80,80,80);
	m_rgbGutterColor = RGB(245,245,245);
}

//=============================================================================	
void CXListBoxTestDlg::DoDataExchange(CDataExchange* pDX)
//=============================================================================	
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXListBoxTestDlg)
	DDX_Control(pDX, IDC_STRING, m_Edit);
	DDX_Control(pDX, IDC_TEXT_COLOR, m_Text);
	DDX_Control(pDX, IDC_BACKGROUND_COLOR, m_Background);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_CBIndex(pDX, IDC_BACKGROUND_COLOR, m_nBackground);
	DDX_CBIndex(pDX, IDC_TEXT_COLOR, m_nText);
	DDX_Text(pDX, IDC_STRING, m_strText);
	DDX_Check(pDX, IDC_LOG_FILE, m_bLogFile);
	DDX_Radio(pDX, IDC_RADIO_COLOR, m_nUseColor);
	//}}AFX_DATA_MAP
}

//=============================================================================	
BOOL CXListBoxTestDlg::OnInitDialog()
//=============================================================================	
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		pSysMenu->DeleteMenu(SC_MAXIMIZE, MF_BYCOMMAND);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_List.SetContextMenuId(IDR_XLISTBOX);

	// create tooltips
	m_ToolTips.Create(this, TTS_ALWAYSTIP);
	::SendMessage(m_ToolTips.m_hWnd, TTM_SETMAXTIPWIDTH, 0, SHRT_MAX);
	//m_ToolTips.AddTool(GetDlgItem(IDC_LINE_NUMBERS), _T("Enables display of line numbers"));
	CString s = _T("");
	s.Format(_T("Writes listbox strings to %s"), m_strLogFile);
	m_ToolTips.AddTool(GetDlgItem(IDC_LOG_FILE), s);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

//=============================================================================	
void CXListBoxTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
//=============================================================================	
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

//=============================================================================	
void CXListBoxTestDlg::OnPaint() 
//=============================================================================	
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//=============================================================================	
HCURSOR CXListBoxTestDlg::OnQueryDragIcon()
//=============================================================================	
{
	return (HCURSOR) m_hIcon;
}

//=============================================================================	
void CXListBoxTestDlg::OnAddString() 
//=============================================================================	
{
	UpdateData(TRUE);

	if ((m_nUseColor == 0) && (m_nText == m_nBackground))
	{
		AfxMessageBox(_T("The text color and the background color you selected\r\n")
					  _T("are the same.  Please choose different colors."));
		m_Text.SetFocus();
		return;
	}

	if (m_strText.IsEmpty())
	{
		AfxMessageBox(_T("Please enter a text string."));
		m_Edit.SetFocus();
		return;
	}

	if (m_nUseColor)
	{
		int nText = m_nText;
		int nBackground = m_nBackground;
		while ((nText == nBackground) || 
			   (nText == m_nText) || 
			   (nBackground == m_nBackground))
		{
			nText = GetRandomColor(nText);
			nBackground = GetRandomColor(nBackground);
		}
		m_nText = nText;
		m_nBackground = nBackground;

		UpdateData(FALSE);
	}

	TRACE(_T("using text=%d  background=%d\n"), m_nText, m_nBackground);

	int index = 0;

#if 0  // -----------------------------------------------------------
	index = m_List.GetTopIndex();

	if (index != LB_ERR)
	{
		m_List.SetTextColor(index+1, CXListBox::Red);
		m_List.SetBackgroundColor(index+1, CXListBox::White);
	}
#endif // -----------------------------------------------------------

	index = m_List.AddLine((CXListBox::Color)m_nText, 
						   (CXListBox::Color)m_nBackground, 
						   m_strText);

	ASSERT(index != LB_ERR);

	if (index != LB_ERR)
	{
		// verify colors

		int nText = m_List.GetTextColor(index);
		int nBackground = m_List.GetBackgroundColor(index);

		TRACE(_T("from XListBox:  text=%d  background=%d\n"), nText, nBackground);

		if ((nText != m_nText) || (nBackground != m_nBackground))
		{
			ASSERT(FALSE);
		}
	}
}

//=============================================================================	
int CXListBoxTestDlg::GetRandomColor(int n) 
//=============================================================================	
{
	DWORD dwTicks = GetTickCount();
	int rc = (int) dwTicks & 0xFF;
	rc += 3*n;
	return (int) rc & 0xF;
}

//=============================================================================	
void CXListBoxTestDlg::OnLogFile() 
//=============================================================================	
{
	UpdateData(TRUE);
	if (m_bLogFile)
		m_List.SetLogFile(m_strLogFile);
	else
		m_List.SetLogFile(_T(""));
}

//=============================================================================
BOOL CXListBoxTestDlg::PreTranslateMessage(MSG* pMsg) 
//=============================================================================
{
	if ((pMsg->hwnd == 0) || !IsWindow(pMsg->hwnd))
		return TRUE;

	m_ToolTips.RelayEvent(pMsg);

	if ((pMsg->hwnd == 0) || !IsWindow(pMsg->hwnd))
		return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}

//=============================================================================	
void CXListBoxTestDlg::OnLineNumberOptions() 
//=============================================================================	
{
	CLineNumberOptions dlg;

	dlg.m_bLineNumbers   = m_bLineNumbers;
	dlg.m_nGutterWidth   = m_nGutterWidth;
	dlg.m_rgbLinenoColor = m_rgbLinenoColor;
	dlg.m_rgbGutterColor = m_rgbGutterColor;

	if (dlg.DoModal())
	{
		m_bLineNumbers   = dlg.m_bLineNumbers;
		m_List.EnableLineNumbers(m_bLineNumbers);

		if (m_bLineNumbers)
		{
			m_nGutterWidth   = dlg.m_nGutterWidth;
			m_rgbLinenoColor = dlg.m_rgbLinenoColor;
			m_rgbGutterColor = dlg.m_rgbGutterColor;
			m_List.SetGutterWidth(m_nGutterWidth);
			m_List.SetLineNoColor(m_rgbLinenoColor);
			m_List.SetGutterColor(m_rgbGutterColor);
		}

		m_List.RedrawWindow();
	}
}
