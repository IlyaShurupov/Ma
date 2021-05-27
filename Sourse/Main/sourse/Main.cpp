
#include "AppManager.h"
#include "WM.h"
#include "Render.h"
#include "Data.h"
#include "Math.h"
#include "Operator.h"

#include <windows.h>

/*
	keymap
	rotate
	move
	gizmo
	fbuffer
	outline
	matrices
*/

int main()
{

	_Data DATA;
	APM_OnStart(&DATA.APM);

	printf("Fuuuuuck here ");

	{
		
		OPS_init(&DATA);
		WM_Init(&DATA);
		RND_init(&DATA);

		ResetCamera();
		OPSAddcoords();

		while (!WM_close_command())
		{
			APM_LoopIn();

			if (WM_input() || !DATA.RND_cycle.cycle_complete)
			{
				//RND_Render();
				WM_output();
			}

			APM_LoopOut();
		}

		WM_CloseWindow();
	}

	APM_OnEnd();
}