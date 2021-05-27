#pragma once

#define DLLEXPORT __declspec(dllexport)
/*
	DA: DynArray
	DAI: DynArray Item
	DAI: DynArray Pointer
	DAIP: DynArray Item Pointer
	DAITemp... : DynArray Pointer Temporary something
	DAITemp... : DynArray Item Temporary something
*/

// ----------------------------- DynArrayItem --------------------------

class _DAI_
{
public:
	//TODO: add atributes to Object
public:
	_DAI_* DAI_next_p = nullptr;
	_DAI_* DAI_prev_p;
	int DAI_index;

public:
	_DAI_(_DAI_* lastItem, int i);
	~_DAI_();
};

// ----------------------------- DynArrayHead --------------------------

class _DA_
{
private:
	_DAI_* DAP_First = nullptr;
	_DAI_* DAP_Last = nullptr;
	_DAI_* DAP_Buffer = nullptr;
	int DA_length = 0;

public:
	DLLEXPORT _DA_();
	DLLEXPORT ~_DA_();
	DLLEXPORT void DAI_Add(char Objname); //FIXME
	DLLEXPORT _DAI_* DAI_GetItem(int index);
	DLLEXPORT void DA_Pop();
	DLLEXPORT int DA_GetLength();
	DLLEXPORT void DAI_Delete(int index_start, int index_end);
	_DAI_* DAI_Search(int index);
};
