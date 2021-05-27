#pragma once

#define API_TITLE "MA"
#define API_HEIGHT 400
#define API_WIDTH 800
#define API_SWAPINTERVAL 10
#define DLLEXPORT __declspec(dllexport)

#include "Data.h"
#include <GLFW/glfw3.h> 

DLLEXPORT void WM_Init(_Data* Data);
DLLEXPORT bool WM_input();
DLLEXPORT void WM_output();
DLLEXPORT bool WM_close_command();
DLLEXPORT void WM_CloseWindow();

bool event_evaluete();

void on_key(GLFWwindow* window, int key, int scancode, int action, int mods);
void on_mouse(GLFWwindow* window, int button, int action, int mods);
void window_transform(GLFWwindow* window);
