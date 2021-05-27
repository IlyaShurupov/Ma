#pragma once
#define DLLEXPORT __declspec(dllexport)
#include "..\primitives\vec3f.h"

// ---------------- Vrts ----------------------- //
class _DAI_Vertex
{
public:
	vec3f vec;
public:
	_DAI_Vertex(_DAI_Vertex* prevItem, int i, float init_val[3]);
	_DAI_Vertex(_DAI_Vertex* prevItem, int i, _DAI_Vertex* vert);
	_DAI_Vertex(_DAI_Vertex* prevItem, int i);
	~_DAI_Vertex();
public: //TODO: make privat
	_DAI_Vertex* P_Vrtx_next = nullptr;
	_DAI_Vertex* P_Vrtx_prev;
	int Vrtx_index;
};

class _DA_Vertices
{
public:
	//TODO: add methods for Vrt

private:
	_DAI_Vertex* P_Vrtx_First = nullptr;
	_DAI_Vertex* P_Vrtx_Last = nullptr;
	_DAI_Vertex* P_Vrtx_buffer = nullptr;
	int Vrtx_length = 0;

public:
	_DA_Vertices();
	~_DA_Vertices();
	DLLEXPORT void Vertex_Add(float init_val[3]);
	DLLEXPORT void Vertex_Add();
	DLLEXPORT void Vertex_Add(_DAI_Vertex * vert);
	DLLEXPORT _DAI_Vertex* Vrt_GetItem(int index);
	DLLEXPORT void Vertex_Pop();
	DLLEXPORT int Vertices_GetLength();
	DLLEXPORT void Vertex_Delete(int index_start, int index_end);
	_DAI_Vertex* Vertex_Search(int index);
};
