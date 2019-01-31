// stdafx.cpp : source file that includes just the standard includes
//	test_printer_api.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <WINSPOOL.H>
//Winspool.h

 LPDEVMODE GetLandscapeDevMode(HWND hWnd, char *pDevice)
   {
 
   HANDLE      hPrinter;
   LPDEVMODE   pDevMode;
   DWORD       dwNeeded, dwRet;
 
   PRINTER_DEFAULTSA temp;
   temp.pDatatype = NULL;
   temp.pDevMode = NULL;
   temp.DesiredAccess = PRINTER_ALL_ACCESS;
	   //PRINTER_ACCESS_ADMINISTER | PRINTER_ACCESS_USE;
	   //PRINTER_ALL_ACCESS;
   /* Start by opening the printer */ 
   if (!OpenPrinter(pDevice, &hPrinter, &temp))
       return NULL;
//OpenPrinter2

///test by jwm
  //GetPrinter(hPrinter, 2, IntPtr.Zero, 0, out nBytesNeeded);
   DWORD lnBytesNeeded;
   GetPrinter(hPrinter,2,NULL,NULL,&lnBytesNeeded);
   LPBYTE  prtInfo = new BYTE[lnBytesNeeded];
    PRINTER_INFO_2 * linfo ;
   GetPrinter(hPrinter,2,prtInfo,lnBytesNeeded,&lnBytesNeeded);
	linfo = (PRINTER_INFO_2 *)prtInfo;
  

   
   ///end test by jwm
   


   /*
    * Step 1:
    * Allocate a buffer of the correct size.
    */ 
   dwNeeded = DocumentProperties(hWnd,
       hPrinter,       /* Handle to our printer. */ 
       pDevice,        /* Name of the printer. */ 
       NULL,           /* Asking for size, so */ 
       NULL,           /* these are not used. */ 
       0);             /* Zero returns buffer size. */ 
   pDevMode = (LPDEVMODE)malloc(dwNeeded);
 
   /*
    * Step 2:
    * Get the default DevMode for the printer and
    * modify it for your needs.
    */ 
   dwRet = DocumentProperties(hWnd,
       hPrinter,
       pDevice,
       pDevMode,       /* The address of the buffer to fill. */ 
       NULL,           /* Not using the input buffer. */ 
       DM_OUT_BUFFER); /* Have the output buffer filled. */ 
   if (dwRet != IDOK)
   {
       /* If failure, cleanup and return failure. */ 
       free(pDevMode);
       ClosePrinter(hPrinter);
       return NULL;
   }
 
   /*
        * Make changes to the DevMode which are supported.
    */ 
//    if (pDevMode->dmFields & DM_ORIENTATION)
//    {
//        /* If the printer supports paper orientation, set it.*/ 
//        pDevMode->dmOrientation = DMORIENT_LANDSCAPE;
//    }

//    if(linfo->pDevMode->dmFields & DM_ORIENTATION)
//    {
// 	   linfo->pDevMode->dmOrientation = DMORIENT_LANDSCAPE;
//    }
 
  // linfo->pDevMode->dmPaperSize =DMPAPER_A5;
 //  linfo->pDevMode->dmPaperWidth = 2100;
 //  linfo->pDevMode->dmPaperLength = 1480;
//    if (pDevMode->dmFields & DM_DUPLEX)
//     {
//        /* If it supports duplex printing, use it. */ 
//        pDevMode->dmDuplex = DMDUP_HORIZONTAL;
//    }
//    pDevMode->dmPaperSize = 9;
//    pDevMode->dmPaperWidth = 2100;
//    pDevMode->dmPaperLength = 2970;
 
   /*
    * Step 3:
    * Merge the new settings with the old.
    * This gives the driver an opportunity to update any private
    * portions of the DevMode structure.
    */ 
    dwRet = DocumentProperties(hWnd,
       hPrinter,
       pDevice,
       linfo->pDevMode,       /* Reuse our buffer for output. */ 
       linfo->pDevMode,       /* Pass the driver our changes. */ 
       DM_IN_BUFFER |  /* Commands to Merge our changes and */ 
       DM_OUT_BUFFER); /* write the result. */ 

linfo->pSecurityDescriptor = NULL;
	SetPrinter(hPrinter,2,(LPBYTE)linfo,0);
   /* Finished with the printer */ 
   ClosePrinter(hPrinter);
 
   if (dwRet != IDOK)
   {
       /* If failure, cleanup and return failure. */ 
       free(pDevMode);
       return NULL;
   }
 
   /* Return the modified DevMode structure. */ 
   return pDevMode;
 
   }
// --------------------- 
// 作者：hjfjoy 
// 来源：CSDN 
// 原文：https://blog.csdn.net/hjfjoy/article/details/4250164 
// 版权声明：本文为博主原创文章，转载请附上博文链接！





// // Specify the limited management permission.
// PRINTER_DEFAULTS defaults = {};
// defaults.DesiredAccess = PRINTER_ACCESS_MANAGE_LIMITED;
// 
// // Open a printer to which the user has no administrative rights.
// HANDLE printer = nullptr;
// assert(!OpenPrinter2(L QueueWithNoAdminRights , // Queue name
//                      &printer,                  // Printer handle
//                      &defaults,                 // Printer defaults
//                      nullptr));                 // Printer options
// 
// assert(GetLastError() == ERROR_ACCESS_DENIED);
// 
// if (printer)
// {
//     ClosePrinter(printer);
// }