// test_printer_apiDlg.h : header file
//

#if !defined(AFX_TEST_PRINTER_APIDLG_H__FC4A0A2D_BEBC_47E7_AE30_968009C793F4__INCLUDED_)
#define AFX_TEST_PRINTER_APIDLG_H__FC4A0A2D_BEBC_47E7_AE30_968009C793F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_printer_apiDlg dialog

class CTest_printer_apiDlg : public CDialog
{
// Construction
public:
	CTest_printer_apiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_printer_apiDlg)
	enum { IDD = IDD_TEST_PRINTER_API_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_printer_apiDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_printer_apiDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_PRINTER_APIDLG_H__FC4A0A2D_BEBC_47E7_AE30_968009C793F4__INCLUDED_)
