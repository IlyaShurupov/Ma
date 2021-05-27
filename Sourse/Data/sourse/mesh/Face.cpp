#include "Face.h"

// ----------------------------- Face --------------------------- //

// ---------------- DAI -------------------- //

_DAI_Face_::_DAI_Face_(_DAI_Face_* lastItem, int i)
{
	DAI_Face_prev_p = lastItem;
	DAI_Face_index = i;
}

_DAI_Face_::~_DAI_Face_()
{
}

// ---------------- DA -------------------- //

_DA_Faces::_DA_Faces() { }

void _DA_Faces::DAI_Face_Add(char Objname)
{
	if (!DA_Faces_length)
	{
		DAP_Face_First = new _DAI_Face_(DAP_Face_Last, DA_Faces_length);
		DAP_Face_Last = DAP_Face_First;
	}
	else
	{
		DAP_Face_Last->DAI_Face_next_p = new _DAI_Face_(DAP_Face_Last, DA_Faces_length);
		DAP_Face_Last = DAP_Face_Last->DAI_Face_next_p;
	}
	DA_Faces_length += 1;
}

_DAI_Face_* _DA_Faces::DAI_Face_GetItem(int index)
{
	_DAI_Face_* item = DAI_Face_Search(index);
	DAP_Face_Buffer = item->DAI_Face_next_p;
	return item;
}

_DAI_Face_* _DA_Faces::DAI_Face_Search(int index)
{
	if (!(index >= DA_Faces_length or index < 0))
	{
		if (index == 0) // Spetial case
		{
			return DAP_Face_First;
		}
		if (index == DA_Faces_length - 1) // Spetial case
		{
			return DAP_Face_Last;
		}
		if (DAP_Face_Buffer)
		{
			if (index == DAP_Face_Buffer->DAI_Face_index)
			{
				return DAP_Face_Buffer;
			}
		}
		if (index <= DA_Faces_length / 2) // Start with furst item
		{
			_DAI_Face_* item = DAP_Face_First;
			while (item->DAI_Face_index != index)
			{
				item = item->DAI_Face_next_p;
			}
			return item;
		}
		else // last item 
		{
			_DAI_Face_* item = DAP_Face_Last;
			while (item->DAI_Face_index != index)
			{
				item = item->DAI_Face_prev_p;
			}
			return item;
		}
	}
	else
	{
		return nullptr;	 //TODO make error
	}
}

void _DA_Faces::DAI_Face_Delete(int index_start = -1, int index_end = -1)
{
	_DAI_Face_* DATempP_Face_first;
	_DAI_Face_* DATempP_Face_last;
	_DAI_Face_* DATempP_Face_next;
	_DAI_Face_* DATempP_Face_prev;
	_DAI_Face_* DATempP_Face_del;

	if (index_start < -1 or index_end < -1) { return; }
	if (index_end >= DA_Faces_length) { index_end = DA_Faces_length - 1; }

	if (index_start == -1 and index_end == -1)
	{
		DATempP_Face_first = DAP_Face_First;
		DATempP_Face_last = DAP_Face_Last;
		index_start = 0;
		index_end = DA_Faces_length - 1;
	}
	else
	{
		DATempP_Face_first = DAI_Face_Search(index_start); // Worst Time(n) ~ n

		if (index_end == -1)
		{
			DATempP_Face_last = DATempP_Face_first;
			index_end = index_start;
		}
		else
		{	// Searching
			DATempP_Face_last = DAI_Face_Search(index_end);
		}
	}

	int DATemp_IndexDifference = index_end - index_start;


	if (DATempP_Face_last and DATempP_Face_first)
	{
		DATempP_Face_next = DATempP_Face_last->DAI_Face_next_p;
		DATempP_Face_prev = DATempP_Face_first->DAI_Face_prev_p;
	}
	else
	{
		DATempP_Face_next = DATempP_Face_prev = 0;
	}

	// Deleting Items
	DAP_Face_Buffer = DATempP_Face_first;
	if (DAP_Face_Buffer)
	{
		for (int i = index_start; i <= index_end; i++)
		{
			DATempP_Face_del = DAP_Face_Buffer;
			DAP_Face_Buffer = DAP_Face_Buffer->DAI_Face_next_p;
			delete DATempP_Face_del;
		}
	}

	// Reconect Links
	if (DATempP_Face_next and DATempP_Face_prev)
	{
		DATempP_Face_next->DAI_Face_prev_p = DATempP_Face_prev;
		DATempP_Face_prev->DAI_Face_next_p = DATempP_Face_next;
	}
	else
	{
		if (!(DATempP_Face_next or DATempP_Face_prev)) // Array is completle зиро
		{
			DAP_Face_Last = DAP_Face_First = nullptr;
		}
		else
		{
			if (!DATempP_Face_next)
			{
				DATempP_Face_prev->DAI_Face_next_p = nullptr;
				DAP_Face_Last = DATempP_Face_prev;
			}
			else // Here is no prev item
			{
				DATempP_Face_next->DAI_Face_prev_p = nullptr;
				DAP_Face_First = DATempP_Face_next;
			}
		}
	}

	//Changing indexes
	if (DATempP_Face_next)
	{
		for (int i = index_end + 1; i < DA_Faces_length - 1; i++)
		{
			DATempP_Face_next->DAI_Face_index -= (DATemp_IndexDifference + 1);
			DATempP_Face_next = DATempP_Face_next->DAI_Face_next_p;
		}
	}

	DA_Faces_length -= (DATemp_IndexDifference + 1);
}

void _DA_Faces::DA_Face_Pop()
{
	_DAI_Face_* DATemp_Face_previtem = DAP_Face_Last->DAI_Face_prev_p;
	delete DAP_Face_Last;
	DAP_Face_Last = DATemp_Face_previtem;
	DATemp_Face_previtem->DAI_Face_next_p = 0;
	DA_Faces_length -= 1;
}

int _DA_Faces::DA_Faces_GetLength()
{
	return DA_Faces_length;
}

_DA_Faces::~_DA_Faces()
{
	DAI_Face_Delete();
}