
#include "Trig.h"

// ----------------------------- Trig --------------------------- //

// ---------------- DAI -------------------- //

_DAI_Trig::_DAI_Trig(_DAI_Trig* lastItem, int i)
{
	DAI_Trig_prev_p = lastItem;
	DAI_Trig_index = i;
}

void _DAI_Trig::norm(vec3f* vec)
{
	vec3f vec1 = vec3f(v2->vec);
	vec3f vec2 = vec3f(v3->vec);

	vec1 -= v1->vec;
	vec2 -= v1->vec;

	vec1.cross(&vec2, vec);
	*vec /= vec->mod();
}

_DAI_Trig::~_DAI_Trig()
{
}

// ---------------- DA -------------------- //

_DA_Trigs::_DA_Trigs() { }

void _DA_Trigs::DAI_Trig_Add()
{
	if (!DA_Trigs_length)
	{
		DAP_Trig_First = new _DAI_Trig(DAP_Trig_Last, DA_Trigs_length);
		DAP_Trig_Last = DAP_Trig_First;
	}
	else
	{
		DAP_Trig_Last->DAI_Trig_next_p = new _DAI_Trig(DAP_Trig_Last, DA_Trigs_length);
		DAP_Trig_Last = DAP_Trig_Last->DAI_Trig_next_p;
	}
	DA_Trigs_length += 1;
}

_DAI_Trig* _DA_Trigs::DAI_Trig_GetItem(int index)
{
	_DAI_Trig* item = DAI_Trig_Search(index);
	DAP_Trig_Buffer = item->DAI_Trig_next_p;
	return item;
}

_DAI_Trig* _DA_Trigs::DAI_Trig_Search(int index)
{
	if (!(index >= DA_Trigs_length or index < 0))
	{
		if (index == 0) // Spetial case
		{
			return DAP_Trig_First;
		}
		if (index == DA_Trigs_length - 1) // Spetial case
		{
			return DAP_Trig_Last;
		}
		if (DAP_Trig_Buffer)
		{
			if (index == DAP_Trig_Buffer->DAI_Trig_index)
			{
				return DAP_Trig_Buffer;
			}
		}
		if (index <= DA_Trigs_length / 2) // Start with furst item
		{
			_DAI_Trig* item = DAP_Trig_First;
			while (item->DAI_Trig_index != index)
			{
				item = item->DAI_Trig_next_p;
			}
			return item;
		}
		else // last item 
		{
			_DAI_Trig* item = DAP_Trig_Last;
			while (item->DAI_Trig_index != index)
			{
				item = item->DAI_Trig_prev_p;
			}
			return item;
		}
	}
	else
	{
		return nullptr;	 //TODO make error
	}
}

void _DA_Trigs::DAI_Trig_Delete(int index_start = -1, int index_end = -1)
{
	_DAI_Trig* DATempP_Trig_first;
	_DAI_Trig* DATempP_Trig_last;
	_DAI_Trig* DATempP_Trig_next;
	_DAI_Trig* DATempP_Trig_prev;
	_DAI_Trig* DATempP_Trig_del;

	if (index_start < -1 or index_end < -1) { return; }
	if (index_end >= DA_Trigs_length) { index_end = DA_Trigs_length - 1; }

	if (index_start == -1 and index_end == -1)
	{
		DATempP_Trig_first = DAP_Trig_First;
		DATempP_Trig_last = DAP_Trig_Last;
		index_start = 0;
		index_end = DA_Trigs_length - 1;
	}
	else
	{
		DATempP_Trig_first = DAI_Trig_Search(index_start); // Worst Time(n) ~ n

		if (index_end == -1)
		{
			DATempP_Trig_last = DATempP_Trig_first;
			index_end = index_start;
		}
		else
		{	// Searching
			DATempP_Trig_last = DAI_Trig_Search(index_end);
		}
	}

	int DATemp_Trig_IndexDifference = index_end - index_start;


	if (DATempP_Trig_last and DATempP_Trig_first)
	{
		DATempP_Trig_next = DATempP_Trig_last->DAI_Trig_next_p;
		DATempP_Trig_prev = DATempP_Trig_first->DAI_Trig_prev_p;
	}
	else
	{
		DATempP_Trig_next = DATempP_Trig_prev = 0;
	}

	// Deleting Items
	DAP_Trig_Buffer = DATempP_Trig_first;
	if (DAP_Trig_Buffer)
	{
		for (int i = index_start; i <= index_end; i++)
		{
			DATempP_Trig_del = DAP_Trig_Buffer;
			DAP_Trig_Buffer = DAP_Trig_Buffer->DAI_Trig_next_p;
			delete DATempP_Trig_del;
		}
	}

	// Reconect Links
	if (DATempP_Trig_next and DATempP_Trig_prev)
	{
		DATempP_Trig_next->DAI_Trig_prev_p = DATempP_Trig_prev;
		DATempP_Trig_prev->DAI_Trig_next_p = DATempP_Trig_next;
	}
	else
	{
		if (!(DATempP_Trig_next or DATempP_Trig_prev)) // Array is completle зиро
		{
			DAP_Trig_Last = DAP_Trig_First = nullptr;
		}
		else
		{
			if (!DATempP_Trig_next)
			{
				DATempP_Trig_prev->DAI_Trig_next_p = nullptr;
				DAP_Trig_Last = DATempP_Trig_prev;
			}
			else // Here is no prev item
			{
				DATempP_Trig_next->DAI_Trig_prev_p = nullptr;
				DAP_Trig_First = DATempP_Trig_next;
			}
		}
	}

	//Changing indexes
	if (DATempP_Trig_next)
	{
		for (int i = index_end + 1; i < DA_Trigs_length - 1; i++)
		{
			DATempP_Trig_next->DAI_Trig_index -= (DATemp_Trig_IndexDifference + 1);
			DATempP_Trig_next = DATempP_Trig_next->DAI_Trig_next_p;
		}
	}

	DA_Trigs_length -= (DATemp_Trig_IndexDifference + 1);
}

void _DA_Trigs::DA_Trig_Pop()
{
	_DAI_Trig* DATemp_Trig_previtem = DAP_Trig_Last->DAI_Trig_prev_p;
	delete DAP_Trig_Last;
	DAP_Trig_Last = DATemp_Trig_previtem;
	DATemp_Trig_previtem->DAI_Trig_next_p = 0;
	DA_Trigs_length -= 1;
}

int _DA_Trigs::DA_Trigs_GetLength()
{
	return DA_Trigs_length;
}

_DA_Trigs::~_DA_Trigs()
{
	DAI_Trig_Delete();
}

