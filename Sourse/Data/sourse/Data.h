#pragma once

#include "objects/DT_Object.h"

#include "primitives/timer.h"
#include "primitives/ray.h"
#include "RND_engine.h"
#include <GLFW/glfw3.h> // Get rid of this some time

// ------------------Struct Data------------------------ //

struct _WinManager //HMMM structs
{
	GLFWwindow* window_p = NULL;
	GLFWwindow* win_current_P = NULL;

	int win_xpos = 0;
	int win_ypos = 0;
	int win_width = 0;
	int win_height = 0;

	double mouse_x = 0;
	double mouse_y = 0;
	double mouse_befor_x = 0;
	double mouse_befor_y = 0;


	int eventID = 0;
	int action = 0;


	bool of = 1;
	//bool start = true;
	//float FocusFactor = 0.5;
	bool relesse = false;
};

struct _FPS
{
	int fps_val = 0;
	float time_LoopIn = 0;
	float time_LoopOut = 0;
};

struct _AppManager
{
	_FPS FPS;
	float total_memory = 0;
};

struct _Gizmo
{
	float Gizmo_Position[3]{ 0, 0, 0 };
	float Scale = 1;
};

struct _3DViewport
{
	float Position[3]{ 0, 0, 0 };
	float width = 0;
	float hiegth = 0;
	_Camera View;
	_Gizmo Gizmo;
	float* depth_buff = nullptr;
};

struct _UI
{
	_3DViewport Viewport;
};

struct _Light
{
	int index = 0;
	vec3f Dir;
	vec3f pos;
};

struct _Data
{	
	_UI UI;
	_RND_cycle RND_cycle;
	_AppManager APM;
	_WinManager WM;
	_DA_MeshObjects DA_MeshObjects;   
	_Light Light;
};
