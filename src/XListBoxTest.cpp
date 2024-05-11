// XListBoxTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "XListBoxTest.h"
#include "XListBoxTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXListBoxTestApp

BEGIN_MESSAGE_MAP(CXListBoxTestApp, CWinApp)
	//{{AFX_MSG_MAP(CXListBoxTestApp)
	//}}AFX_MSG
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXListBoxTestApp construction

CXListBoxTestApp::CXListBoxTestApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CXListBoxTestApp object

CXListBoxTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CXListBoxTestApp initialization

BOOL CXListBoxTestApp::InitInstance()
{
#if _MFC_VER < 0x700
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#endif

	CXListBoxTestDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return FALSE;
}
