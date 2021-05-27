#pragma once
#define DLLEXPORT __declspec(dllexport)

#include "Edge.h"

// ----------------------------- Trig --------------------------- //

class _DAI_Trig
{
public:
	_DAI_Vertex* v1;
	_DAI_Vertex* v2;
	_DAI_Vertex* v3;

public:
	_DAI_Trig* DAI_Trig_next_p = nullptr;
	_DAI_Trig* DAI_Trig_prev_p;
	int DAI_Trig_index;

public:
	_DAI_Trig(_DAI_Trig* lastItem, int i);
	void norm(vec3f * vec);
	~_DAI_Trig();
};

class _DA_Trigs
{
private:
	_DAI_Trig* DAP_Trig_First = nullptr;
	_DAI_Trig* DAP_Trig_Last = nullptr;
	_DAI_Trig* DAP_Trig_Buffer = nullptr;
	int DA_Trigs_length = 0;

public:
	DLLEXPORT _DA_Trigs();
	DLLEXPORT ~_DA_Trigs();
	DLLEXPORT void DAI_Trig_Add();
	DLLEXPORT _DAI_Trig* DAI_Trig_GetItem(int index);
	DLLEXPORT void DA_Trig_Pop();
	DLLEXPORT int DA_Trigs_GetLength();
	DLLEXPORT void DAI_Trig_Delete(int index_start, int index_end);
	_DAI_Trig* DAI_Trig_Search(int index);
};


