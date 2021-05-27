#pragma once
#define DLLEXPORT __declspec(dllexport)

#include "Data.h"


DLLEXPORT void RND_init(_Data* Data);
DLLEXPORT void RND_Render();