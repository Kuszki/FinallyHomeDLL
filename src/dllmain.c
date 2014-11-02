/*********************************************

    FinallyHome DLL "main" module source

    copyright: KuszkiDevGroup

    license: GNU GPL v2

*********************************************/

#include <windows.h>

#include "dll.h"

#include "callbacks.h"
#include "rs232.h"

#define	BRATE		9600

HANDLE	g_hThread	=	NULL;
unsigned	g_uPort	=	0;

unsigned start_Listening(unsigned uPort, void* fProc)
{

	stop_Listening();

	if (RS232_OpenComport(uPort, BRATE)) return 1;

  	g_hThread = CreateThread(NULL, 0, ThreadProc, fProc, 0, NULL);

  	if (g_hThread) g_uPort = uPort;
  	else return 2;

	return 0;

}

void set_State(unsigned uDev, unsigned uSet)
{
	if (!g_uPort) return;

	LPDATA_PACK ptData = (LPDATA_PACK) malloc(sizeof(DATA_PACK));

	memset(ptData, 0, sizeof(DATA_PACK));

	ptData->cDev = uDev;
	ptData->cSet = uSet + 1;

	RS232_SendBuf(g_uPort, (unsigned char*) ptData, sizeof(DATA_PACK));
}

void get_State(unsigned uDev)
{
	set_State(uDev, 100);
}

void stop_Listening(void)
{
	if (g_hThread) TerminateThread(g_hThread, 2);
	if (g_uPort) RS232_CloseComport(g_uPort);

	g_hThread	=	NULL;
	g_uPort	=	0;
}
