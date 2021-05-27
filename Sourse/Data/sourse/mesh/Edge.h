#pragma once
#define DLLEXPORT __declspec(dllexport)

#include "Vertex.h"

// ----------------------------- Edge --------------------------- //

class _DAI_Edge
{
public:
	_DAI_Vertex* DAI_Vrt_Head;
	_DAI_Vertex* DAI_Vrt_Tail;

public:
	_DAI_Edge* DAI_Edge_next_p = nullptr;
	_DAI_Edge* DAI_Edge_prev_p;
	int DAI_Edge_index;

public:
	_DAI_Edge(_DAI_Edge* lastItem, int i);
	~_DAI_Edge();
};

class _DA_Edges
{
private:
	_DAI_Edge* DAP_Edge_First = nullptr;
	_DAI_Edge* DAP_Edge_Last = nullptr;
	_DAI_Edge* DAP_Edge_Buffer = nullptr;
	int DA_Edge_length = 0;

public:
	DLLEXPORT _DA_Edges();
	DLLEXPORT ~_DA_Edges();
	DLLEXPORT void DAI_Edge_Add();
	DLLEXPORT _DAI_Edge* DAI_Edge_GetItem(int index);
	DLLEXPORT void DA_Edge_Pop();
	DLLEXPORT int DA_Edge_GetLength();
	DLLEXPORT void DAI_Edge_Delete(int index_start, int index_end);
	_DAI_Edge* DAI_Edge_Search(int index);
};
