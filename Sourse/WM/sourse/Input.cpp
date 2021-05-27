#include "Input.h"

WM_EV_Input::WM_EV_Input()
{
	for (int i = 0; i < 120; i++) {
		(&MOUSE_BUTTON_1)[i] = false;
	}
}

WM_EV_Input::~WM_EV_Input()
{
}

void WM_EV_Input::update()
{

}
