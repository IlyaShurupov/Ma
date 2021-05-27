#pragma once

#define DLLEXPORT __declspec(dllexport)

#include "Data.h"


DLLEXPORT void APM_OnStart(_AppManager *);

DLLEXPORT void APM_OnEnd();

DLLEXPORT void APM_LoopIn();

DLLEXPORT void APM_LoopOut();
