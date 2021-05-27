#include "Edge.h"

// ----------------------------- Edge --------------------------- //

// ---------------- DAI -------------------- //

_DAI_Edge::_DAI_Edge(_DAI_Edge* lastItem, int i)
{
	DAI_Edge_prev_p = lastItem;
	DAI_Edge_index = i;
}

_DAI_Edge::~_DAI_Edge()
{
}

// ---------------- DA -------------------- //

_DA_Edges::_DA_Edges() { }

void _DA_Edges::DAI_Edge_Add()
{
	if (!DA_Edge_length)
	{
		DAP_Edge_First = new _DAI_Edge(DAP_Edge_Last, DA_Edge_length);
		DAP_Edge_Last = DAP_Edge_First;
	}
	else
	{
		DAP_Edge_Last->DAI_Edge_next_p = new _DAI_Edge(DAP_Edge_Last, DA_Edge_length);
		DAP_Edge_Last = DAP_Edge_Last->DAI_Edge_next_p;
	}
	DA_Edge_length += 1;
}

_DAI_Edge* _DA_Edges::DAI_Edge_GetItem(int index)
{
	_DAI_Edge* item = DAI_Edge_Search(index);
	DAP_Edge_Buffer = item->DAI_Edge_next_p;
	return item;
}

_DAI_Edge* _DA_Edges::DAI_Edge_Search(int index)
{
	if (!(index >= DA_Edge_length or index < 0))
	{
		if (index == 0) // Spetial case
		{
			return DAP_Edge_First;
		}
		if (index == DA_Edge_length - 1) // Spetial case
		{
			return DAP_Edge_Last;
		}
		if (DAP_Edge_Buffer)
		{
			if (index == DAP_Edge_Buffer->DAI_Edge_index)
			{
				return DAP_Edge_Buffer;
			}
		}
		if (index <= DA_Edge_length / 2) // Start with furst item
		{
			_DAI_Edge* item = DAP_Edge_First;
			while (item->DAI_Edge_index != index)
			{
				item = item->DAI_Edge_next_p;
			}
			return item;
		}
		else // last item 
		{
			_DAI_Edge* item = DAP_Edge_Last;
			while (item->DAI_Edge_index != index)
			{
				item = item->DAI_Edge_prev_p;
			}
			return item;
		}
	}
	else
	{
		return nullptr;	 //TODO make error
	}
}

void _DA_Edges::DAI_Edge_Delete(int index_start = -1, int index_end = -1)
{
	_DAI_Edge* DATempP_Edge_first;
	_DAI_Edge* DATempP_Edge_last;
	_DAI_Edge* DATempP_Edge_next;
	_DAI_Edge* DATempP_Edge_prev;
	_DAI_Edge* DATempP_Edge_del;

	if (index_start < -1 or index_end < -1) { return; }
	if (index_end >= DA_Edge_length) { index_end = DA_Edge_length - 1; }

	if (index_start == -1 and index_end == -1)
	{
		DATempP_Edge_first = DAP_Edge_First;
		DATempP_Edge_last = DAP_Edge_Last;
		index_start = 0;
		index_end = DA_Edge_length - 1;
	}
	else
	{
		DATempP_Edge_first = DAI_Edge_Search(index_start); // Worst Time(n) ~ n

		if (index_end == -1)
		{
			DATempP_Edge_last = DATempP_Edge_first;
			index_end = index_start;
		}
		else
		{	// Searching
			DATempP_Edge_last = DAI_Edge_Search(index_end);
		}
	}

	int DATemp_Edge_IndexDifference = index_end - index_start;


	if (DATempP_Edge_last and DATempP_Edge_first)
	{
		DATempP_Edge_next = DATempP_Edge_last->DAI_Edge_next_p;
		DATempP_Edge_prev = DATempP_Edge_first->DAI_Edge_prev_p;
	}
	else
	{
		DATempP_Edge_next = DATempP_Edge_prev = 0;
	}

	// Deleting Items
	DAP_Edge_Buffer = DATempP_Edge_first;
	if (DAP_Edge_Buffer)
	{
		for (int i = index_start; i <= index_end; i++)
		{
			DATempP_Edge_del = DAP_Edge_Buffer;
			DAP_Edge_Buffer = DAP_Edge_Buffer->DAI_Edge_next_p;
			delete DATempP_Edge_del;
		}
	}

	// Reconect Links
	if (DATempP_Edge_next and DATempP_Edge_prev)
	{
		DATempP_Edge_next->DAI_Edge_prev_p = DATempP_Edge_prev;
		DATempP_Edge_prev->DAI_Edge_next_p = DATempP_Edge_next;
	}
	else
	{
		if (!(DATempP_Edge_next or DATempP_Edge_prev)) // Array is completle зиро
		{
			DAP_Edge_Last = DAP_Edge_First = nullptr;
		}
		else
		{
			if (!DATempP_Edge_next)
			{
				DATempP_Edge_prev->DAI_Edge_next_p = nullptr;
				DAP_Edge_Last = DATempP_Edge_prev;
			}
			else // Here is no prev item
			{
				DATempP_Edge_next->DAI_Edge_prev_p = nullptr;
				DAP_Edge_First = DATempP_Edge_next;
			}
		}
	}

	//Changing indexes
	if (DATempP_Edge_next)
	{
		for (int i = index_end + 1; i < DA_Edge_length - 1; i++)
		{
			DATempP_Edge_next->DAI_Edge_index -= (DATemp_Edge_IndexDifference + 1);
			DATempP_Edge_next = DATempP_Edge_next->DAI_Edge_next_p;
		}
	}

	DA_Edge_length -= (DATemp_Edge_IndexDifference + 1);
}

void _DA_Edges::DA_Edge_Pop()
{
	_DAI_Edge* DATemp_Edge_previtem = DAP_Edge_Last->DAI_Edge_prev_p;
	delete DAP_Edge_Last;
	DAP_Edge_Last = DATemp_Edge_previtem;
	DATemp_Edge_previtem->DAI_Edge_next_p = 0;
	DA_Edge_length -= 1;
}

int _DA_Edges::DA_Edge_GetLength()
{
	return DA_Edge_length;
}

_DA_Edges::~_DA_Edges()
{
	DAI_Edge_Delete();
}
