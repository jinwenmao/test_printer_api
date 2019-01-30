; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTest_printer_apiDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test_printer_api.h"

ClassCount=4
Class1=CTest_printer_apiApp
Class2=CTest_printer_apiDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TEST_PRINTER_API_DIALOG

[CLS:CTest_printer_apiApp]
Type=0
HeaderFile=test_printer_api.h
ImplementationFile=test_printer_api.cpp
Filter=N

[CLS:CTest_printer_apiDlg]
Type=0
HeaderFile=test_printer_apiDlg.h
ImplementationFile=test_printer_apiDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=test_printer_apiDlg.h
ImplementationFile=test_printer_apiDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEST_PRINTER_API_DIALOG]
Type=1
Class=CTest_printer_apiDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_TEST,button,1342242816

