#pragma once
#include "..\mesh\Mesh.h"
#define DLLEXPORT __declspec(dllexport)
// ---------------- Object --------------------- //

class _DAI_Object
{
public:
	_Mesh Mesh;
	
	vec3f Position;
	vec3f unit_vx;
	vec3f unit_vy;
	vec3f unit_vz;

	char name = 'o';

public:
	_DAI_Object* P_Obj_next = nullptr;
	_DAI_Object* P_Obj_prev;
	int Obj_index;
public:
	_DAI_Object(_DAI_Object* obj, _DAI_Object* lastItem, int i);
	_DAI_Object(const char Objname, _DAI_Object* lastItem, int i);
	void move(vec3f *displacement);
	void rot(vec3f *axs_dir, vec3f* axs_pos, float angle);
	void scale(float factor);
	~_DAI_Object();
};

class _DA_MeshObjects
{
public:
	_DAI_Object* active = nullptr;

private:
	_DAI_Object* P_Obj_First = nullptr;
	_DAI_Object* P_Obj_Last = nullptr;
	_DAI_Object* P_Obj_buffer = nullptr;
	int CI_length = 0;

public:
	DLLEXPORT _DA_MeshObjects();
	DLLEXPORT ~_DA_MeshObjects();
	DLLEXPORT void Obj_Add(char Objname); //FIXME
	DLLEXPORT void Obj_Add(_DAI_Object* obj);
	DLLEXPORT _DAI_Object* Obj_GetItem(int index);
	DLLEXPORT void Obj_Pop();
	DLLEXPORT int Obj_GetLength();
	DLLEXPORT void Obj_Delete(int index_start, int index_end);
	_DAI_Object* Obj_Search(int index);
};
