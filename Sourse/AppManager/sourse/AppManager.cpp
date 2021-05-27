

#define DBG_NEW new ( _CLIENT_BLOCK , __FILE__ , __LINE__ )
#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define _CRTDBG_MAP_ALLOC

#include "AppManager.h"

//#include <stdlib.h>
//#include <crtdbg.h>


#include <stdio.h>

_AppManager* APM_p;

DLLEXPORT void APM_OnStart(_AppManager* APM)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	APM_p = APM;
	
}

DLLEXPORT void APM_OnEnd()
{
	_CrtDumpMemoryLeaks();
}

DLLEXPORT void APM_LoopIn()
{
	APM_p->FPS.time_LoopIn = float(clock());	
}

DLLEXPORT void APM_LoopOut()
{
	APM_p->FPS.time_LoopOut = float(clock());
	float wait_time_ms = 100/6 - (APM_p->FPS.time_LoopOut - APM_p->FPS.time_LoopIn);
	if (wait_time_ms > 0)
	{
		Sleep(DWORD(wait_time_ms));
	}
	else
	{
		//printf("FPS is less than 60\n");
	}
}

DLLEXPORT bool APM_allocateMem()
{
	return 1;
}