#pragma once
#define DLLEXPORT __declspec(dllexport)


//#include "AppManager.h"
#include "Data.h"
#include "MaMath.h"

DLLEXPORT void OPselect(int mx, int my, int width, int height);
DLLEXPORT void RotCamera(float angel, char dir, float focusScale);
DLLEXPORT void OPSdelete();
DLLEXPORT void OPSAddcoords();

DLLEXPORT void rotObj(const char direction, float angel);

DLLEXPORT void OPS_init(_Data* Data);

DLLEXPORT void OPSclear();

DLLEXPORT void CameraMove(float displacement, const char direction);
DLLEXPORT void RotObj(float angel, char axes);
DLLEXPORT void MoveXInvert();

DLLEXPORT void MoveYInvert();

DLLEXPORT void MoveZInvert();

DLLEXPORT void MoveX();

DLLEXPORT void MoveY();

DLLEXPORT void MoveZ();

DLLEXPORT void ResetCamera();

DLLEXPORT void RelativeRotate(float rot_angel, float focusScale);