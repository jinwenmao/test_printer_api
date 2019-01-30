// stdafx.cpp : source file that includes just the standard includes
//	test_printer_api.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <WINSPOOL.H>


 LPDEVMODE GetLandscapeDevMode(HWND hWnd, char *pDevice)
   {
 
   HANDLE      hPrinter;
   LPDEVMODE   pDevMode;
   DWORD       dwNeeded, dwRet;
 
   /* Start by opening the printer */ 
   if (!OpenPrinter(pDevice, &hPrinter, NULL))
       return NULL;
 
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
   if (pDevMode->dmFields & DM_ORIENTATION)
   {
       /* If the printer supports paper orientation, set it.*/ 
       pDevMode->dmOrientation = DMORIENT_LANDSCAPE;
   }
 
   if (pDevMode->dmFields & DM_DUPLEX)
    {
       /* If it supports duplex printing, use it. */ 
       pDevMode->dmDuplex = DMDUP_HORIZONTAL;
   }
 
   /*
    * Step 3:
    * Merge the new settings with the old.
    * This gives the driver an opportunity to update any private
    * portions of the DevMode structure.
    */ 
    dwRet = DocumentProperties(hWnd,
       hPrinter,
       pDevice,
       pDevMode,       /* Reuse our buffer for output. */ 
       pDevMode,       /* Pass the driver our changes. */ 
       DM_IN_BUFFER |  /* Commands to Merge our changes and */ 
       DM_OUT_BUFFER); /* write the result. */ 
 
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