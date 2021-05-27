#include "DynArray.h"

// ---------------- DAI -------------------- //

_DAI_::_DAI_(_DAI_* lastItem, int i)
{
	DAI_prev_p = lastItem;
	DAI_index = i;
}

_DAI_::~_DAI_()
{
}

// ---------------- DA -------------------- //

_DA_::_DA_() { }

void _DA_::DAI_Add(char Objname)
{
	if (!DA_length)
	{
		DAP_First = new _DAI_(DAP_Last, DA_length);
		DAP_Last = DAP_First;
	}
	else
	{
		DAP_Last->DAI_next_p = new _DAI_(DAP_Last, DA_length);
		DAP_Last = DAP_Last->DAI_next_p;
	}
	DA_length += 1;
}

_DAI_* _DA_::DAI_GetItem(int index)
{
	_DAI_* item = DAI_Search(index);
	DAP_Buffer = item->DAI_next_p;
	return item;
}

_DAI_* _DA_::DAI_Search(int index)
{
	if (!(index >= DA_length or index < 0)) 
	{
		if (index == 0) // Spetial case
		{
			return DAP_First;
		}
		if (index == DA_length - 1) // Spetial case
		{
			return DAP_Last;
		}
		if (DAP_Buffer)
		{
			if (index == DAP_Buffer->DAI_index)
			{
				return DAP_Buffer;
			}
		}
		if (index <= DA_length / 2) // Start with furst item
		{
			_DAI_* item = DAP_First;
			while (item->DAI_index != index)
			{
				item = item->DAI_next_p;
			}
			return item;
		}
		else // last item 
		{
			_DAI_* item = DAP_Last;
			while (item->DAI_index != index)
			{
				item = item->DAI_prev_p;
			}
			return item;
		}
	}
	else
	{
		return nullptr;	 //TODO make error
	}
}

void _DA_::DAI_Delete(int index_start = -1, int index_end = -1)
{
	_DAI_* DATempP_first;
	_DAI_* DATempP_last;
	_DAI_* DATempP_next;
	_DAI_* DATempP_prev;
	_DAI_* DATempP_del;

	if (index_start < -1 or index_end < -1) { return; }
	if (index_end >= DA_length) { index_end = DA_length - 1; }

	if (index_start == -1 and index_end == -1)
	{
		DATempP_first = DAP_First;
		DATempP_last = DAP_Last;
		index_start = 0;
		index_end = DA_length - 1;
	}
	else
	{
		DATempP_first = DAI_Search(index_start); // Worst Time(n) ~ n

		if (index_end == -1)
		{
			DATempP_last = DATempP_first;
			index_end = index_start;
		}
		else
		{	// Searching
			DATempP_last = DAI_Search(index_end);
		}
	}

	int DATemp_IndexDifference = index_end - index_start;


	if (DATempP_last and DATempP_first)
	{
		DATempP_next = DATempP_last->DAI_next_p;
		DATempP_prev = DATempP_first->DAI_prev_p;
	}
	else
	{
		DATempP_next = DATempP_prev = 0;
	}

	// Deleting Items
	DAP_Buffer = DATempP_first;
	if (DAP_Buffer)
	{
		for (int i = index_start; i <= index_end; i++)
		{
			DATempP_del = DAP_Buffer;
			DAP_Buffer = DAP_Buffer->DAI_next_p;
			delete DATempP_del;
		}
	}

	// Reconect Links
	if (DATempP_next and DATempP_prev)
	{
		DATempP_next->DAI_prev_p = DATempP_prev;
		DATempP_prev->DAI_next_p = DATempP_next;
	}
	else
	{
		if (!(DATempP_next or DATempP_prev)) // Array is completle зиро
		{
			DAP_Last = DAP_First = nullptr;
		}
		else
		{
			if (!DATempP_next)
			{
				DATempP_prev->DAI_next_p = nullptr;
				DAP_Last = DATempP_prev;
			}
			else // Here is no prev item
			{
				DATempP_next->DAI_prev_p = nullptr;
				DAP_First = DATempP_next;
			}
		}
	}

	//Changing indexes
	if (DATempP_next)
	{
		for (int i = index_end + 1; i < DA_length - 1; i++)
		{
			DATempP_next->DAI_index -= (DATemp_IndexDifference + 1);
			DATempP_next = DATempP_next->DAI_next_p;
		}
	}

	DA_length -= (DATemp_IndexDifference + 1);
}

void _DA_::DA_Pop()
{
	_DAI_* DATemp_previtem = DAP_Last->DAI_prev_p;
	delete DAP_Last;
	DAP_Last = DATemp_previtem;
	DATemp_previtem->DAI_next_p = 0;
	DA_length -= 1;
}

int _DA_::DA_GetLength()
{
	return DA_length;
}

_DA_::~_DA_()
{
	DAI_Delete();
}