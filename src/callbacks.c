/*********************************************

    FinallyHome DLL "callback" module source

    copyright: KuszkiDevGroup

    license: GNU GPL v2

*********************************************/

#include <windows.h>

#include "dll.h"

#include "callbacks.h"
#include "rs232.h"

extern unsigned g_uPort;

DWORD WINAPI ThreadProc(LPVOID pvArgs)
{

	CALLBACK_PROC	fProc	=	(CALLBACK_PROC) pvArgs;
	LPDATA_PACK	ptData	=	(LPDATA_PACK) malloc(sizeof(DATA_PACK));
	unsigned		uBytes	=	0;

	if (!fProc) return 1;

	while (1){

		memset(ptData, 0, sizeof(DATA_PACK));

		unsigned uBytes = RS232_PollComport(g_uPort, (unsigned char*) ptData, sizeof(DATA_PACK));

		if (uBytes == sizeof(DATA_PACK)) fProc(ptData->cDev, ptData->cSet - 1);

		Sleep(100);

	}

	return 0;

}
