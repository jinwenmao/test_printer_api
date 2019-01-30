// test_printer_api.h : main header file for the TEST_PRINTER_API application
//

#if !defined(AFX_TEST_PRINTER_API_H__FE8C9DDE_7820_45F6_B779_D6B28B88C37F__INCLUDED_)
#define AFX_TEST_PRINTER_API_H__FE8C9DDE_7820_45F6_B779_D6B28B88C37F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_printer_apiApp:
// See test_printer_api.cpp for the implementation of this class
//

class CTest_printer_apiApp : public CWinApp
{
public:
	CTest_printer_apiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_printer_apiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_printer_apiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_PRINTER_API_H__FE8C9DDE_7820_45F6_B779_D6B28B88C37F__INCLUDED_)
