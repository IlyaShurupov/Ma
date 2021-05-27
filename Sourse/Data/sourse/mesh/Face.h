#pragma once
#define DLLEXPORT __declspec(dllexport)

#include "Trig.h"

// ----------------------------- Face --------------------------- //

// ----------------------------- DynArrayItem --------------------------

class _DAI_Face_
{
public:
	_DAI_Trig* DAI_Trig_Left = nullptr;
	_DAI_Trig* DAI_Trig_Right = nullptr;

public:
	_DAI_Face_* DAI_Face_next_p = nullptr;
	_DAI_Face_* DAI_Face_prev_p;
	int DAI_Face_index;

public:
	_DAI_Face_(_DAI_Face_* lastItem, int i);
	~_DAI_Face_();
};

// ----------------------------- DynArrayHead --------------------------

class _DA_Faces
{
private:
	_DAI_Face_* DAP_Face_First = nullptr;
	_DAI_Face_* DAP_Face_Last = nullptr;
	_DAI_Face_* DAP_Face_Buffer = nullptr;
	int DA_Faces_length = 0;

public:
	DLLEXPORT _DA_Faces();
	DLLEXPORT ~_DA_Faces();
	DLLEXPORT void DAI_Face_Add(char Objname); //FIXME
	DLLEXPORT _DAI_Face_* DAI_Face_GetItem(int index);
	DLLEXPORT void DA_Face_Pop();
	DLLEXPORT int DA_Faces_GetLength();
	DLLEXPORT void DAI_Face_Delete(int index_start, int index_end);
	_DAI_Face_* DAI_Face_Search(int index);
};
