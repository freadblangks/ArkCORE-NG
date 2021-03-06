/*****************************************************************************/
/* Storm_test.cpp                         Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Test module for storm.dll (original Blizzard MPQ dynalic library          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 24.08.14  1.00  Lad  The first version of Storm_test.cpp                  */
/*****************************************************************************/

#define _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

#define STORM_ALTERNATE_NAMES
#include "storm_dll.h"                      // Header file for Storm.dll

//-----------------------------------------------------------------------------
// Main

int main()
{
    LPCSTR szArchiveName = "e:\\Multimedia\\MPQs\\1995 - Test MPQs\\MPQ_2016_v1_123.w3x";
    HANDLE hMpq = NULL;
    HANDLE hFile = NULL;
    BYTE Buffer[0x100];
    DWORD dwBytesRead = 0;

    if(StormOpenArchive(szArchiveName, 0, 0, &hMpq))
    {                             
        if(StormOpenFileEx(hMpq, "war3map.j", 0, &hFile))
        {
            dwBytesRead = StormGetFileSize(hFile, NULL);
            StormReadFile(hFile, Buffer, sizeof(Buffer), &dwBytesRead, NULL); 
            StormCloseFile(hFile);
        }

        StormCloseArchive(hMpq);
    }

    return 0;
}
