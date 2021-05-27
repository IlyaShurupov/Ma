
#include "WM.h"

#include <cstdio>
#include <GLFW/glfw3.h> 
#include "Math.h"
#include "Render.h"
#include "Operator.h"
#include "KeyConfig.h"

_WinManager* WM_p;
_Data* Data_p;

DLLEXPORT bool WM_close_command()
{
	return WM_p->of;
}

DLLEXPORT void WM_CloseWindow()
{
	glfwTerminate();
	OPSclear();
}

// --------------------------------------- //

DLLEXPORT bool WM_input()
{
	{
		glfwGetWindowSize(WM_p->window_p, &WM_p->win_width, &WM_p->win_height);
		glfwGetWindowPos(WM_p->window_p, &WM_p->win_xpos, &WM_p->win_ypos);
		glfwGetCursorPos(WM_p->window_p, &WM_p->mouse_x, &WM_p->mouse_y);
		glfwPollEvents();
		WM_p->of = glfwWindowShouldClose(WM_p->window_p);
	}

	bool answ = event_evaluete();

	WM_p->mouse_befor_y = WM_p->mouse_y;
	WM_p->mouse_befor_x = WM_p->mouse_x; //FIXME: wtf

	return answ;
}

bool event_evaluete() //FIXME: wtf
{

	_DAI_Object* obj = Data_p->DA_MeshObjects.active;
	_Camera* cam = &Data_p->UI.Viewport.View;

	float disply;
	float displx;
	displx = (WM_p->mouse_x - WM_p->mouse_befor_x) / 100;
	disply = (WM_p->mouse_y - WM_p->mouse_befor_y) / 100;

	if (WM_p->action == GLFW_RELEASE)
	{
		if (!WM_p->relesse) {
			WM_p->relesse = true;
		}
		return 0;
	}
	/*
	else if (WM_p->relesse) {

		if (WM_p->eventID == GLFW_KEY_D) {

			if (obj) {
				printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
				Data_p->DA_MeshObjects.Obj_Add(obj);
				return 1;
			}
		}
		WM_p->relesse = false;
	}
	*/
	else 
	{
		WM_p->relesse = false;

		if (WM_p->eventID == GLFW_KEY_D) {

			if (obj) {
				printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
				Data_p->DA_MeshObjects.Obj_Add(obj);
				return 1;
			}
		}

		if (WM_p->eventID == EV_CAMERA_MOVE)
		{
			CameraMove(disply, 'y');
			CameraMove(displx, 'x');
		}
		if (WM_p->eventID == EV_CAMERA_ZOOM)
		{
			CameraMove(-disply, 'z');
		}
		if (WM_p->eventID == EV_CAMERA_ROTATE)
		{
			RotCamera(disply, 'x', 2);
			RotCamera(-displx, 'y', 2);
		}

		if (WM_p->eventID == EV_SELECT)
		{
			int my = WM_p->win_height - WM_p->mouse_y;
			printf("selected\n");
			OPselect(WM_p->mouse_x, my, WM_p->win_width, WM_p->win_height);
		}

		if (WM_p->eventID == EV_ROTATE) {

			if (obj) {
				vec3f tmp = vec3f(cam->x_unit_v);
				//tmp.invert();
				tmp *= -1;
				obj->rot(&tmp, &obj->Position, disply);
				obj->rot(&cam->y_unit_v, &obj->Position, displx);
			}
		}

		if (WM_p->eventID == EV_MOVE) {

			if (obj) {
				vec3f displst = vec3f(cam->x_unit_v);
				displst *= -displx;
				obj->move(&displst);

				displst = cam->y_unit_v;
				displst *= -disply;
				obj->move(&displst);
			}
		}

		if (WM_p->eventID == EV_SCALE) {
			if (obj) {
				obj->scale(1 + displx);
			}
		}

		if (WM_p->eventID == EV_CLEAR_ALL and WM_p->action == 1) { OPSclear(); }
		if (WM_p->eventID == EV_DELETE and WM_p->action == 1) { OPSdelete(); printf("del dat shit\n"); }
		if (WM_p->eventID == EV_ADD and WM_p->action == 1) { OPSAddcoords(); }

		if (WM_p->eventID == EV_DECREASE_RESOLUTION) {
			Data_p->UI.Viewport.View.simplify += 2;
			printf("EV_DECREASE_RESOLUTION\n");
		}
		if (WM_p->eventID == EV_INCREASE_RESOLUTION) {
			Data_p->UI.Viewport.View.simplify -= 2;
			printf("EV_INCREASE_RESOLUTION\n");
		}


		//if (WM_p->eventID == GLFW_KEY_Y) { rotObj('y', 0.1f); }
		//if (WM_p->eventID == GLFW_KEY_Z) { rotObj('z', 0.1f); }
		//if (WM_p->eventID == GLFW_KEY_G) { RelativeRotate(0.1f, 2); }
		//if (WM_p->eventID == GLFW_KEY_H) { RotCamera(0.005f, 'z', 2); }
		//if (WM_p->eventID == GLFW_KEY_J) { RotCamera(0.005f, 'x', 2); }//HMM: why so small
		//if (WM_p->eventID == GLFW_KEY_R) { ResetCamera(); }

		Data_p->RND_cycle.restart = true;
		return 1;
	}
}

DLLEXPORT void WM_output()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0.0f, 0.0f, Data_p->WM.win_width, Data_p->WM.win_height);

	RND_Render();

	glEnd();

	glfwSwapBuffers(Data_p->WM.window_p);
}

// --------------------------------------- //

DLLEXPORT void WM_Init(_Data* Data)
{
	Data_p = Data;
	WM_p = &Data_p->WM;
	if (WM_p->of)
	{
		glfwInit();

		WM_p->window_p = glfwCreateWindow(API_WIDTH, API_WIDTH, "Ma", NULL, NULL);
		//glfwMaximizeWindow(WM_p->window_p);
		glfwMakeContextCurrent(WM_p->window_p);
		glfwSetKeyCallback(WM_p->window_p, on_key);
		glfwSetMouseButtonCallback(WM_p->window_p, on_mouse);
		glfwSetWindowRefreshCallback(WM_p->window_p, window_transform);
		//glfwSetWindowPosCallback(WM.window_p, window_transform); 

		WM_p->of = 0;
	}
}

void window_transform(GLFWwindow* window)
{
	WM_p->eventID = WINDOW_TRANSFORM;
}
void on_key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	WM_p->eventID = key;
	WM_p->action = action;
}
void on_mouse(GLFWwindow* window, int button, int action, int mods)
{
	WM_p->eventID = button;
	WM_p->action = action;
}