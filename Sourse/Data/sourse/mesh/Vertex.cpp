#include "Vertex.h"

// ----------------------------- Vertex --------------------------- //

_DAI_Vertex::_DAI_Vertex(_DAI_Vertex* lastItem, int i, float init_val[3])
{
	P_Vrtx_prev = lastItem;
	Vrtx_index = i;
	vec.x = init_val[0];
	vec.y = init_val[1];
	vec.z = init_val[2];
}

_DAI_Vertex::_DAI_Vertex(_DAI_Vertex* lastItem, int i, _DAI_Vertex* vert)
{
	P_Vrtx_prev = lastItem;
	Vrtx_index = i;
	vec = vert->vec;
}

_DAI_Vertex::_DAI_Vertex(_DAI_Vertex* lastItem, int i)
{
	P_Vrtx_prev = lastItem;
	Vrtx_index = i;
	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
}

_DAI_Vertex::~_DAI_Vertex()
{
}

_DA_Vertices::_DA_Vertices() { }

void _DA_Vertices::Vertex_Add(float init_val[3])
{
	if (!Vrtx_length)
	{
		P_Vrtx_First = new _DAI_Vertex(P_Vrtx_Last, Vrtx_length, init_val);
		P_Vrtx_Last = P_Vrtx_First;
	}
	else
	{
		P_Vrtx_Last->P_Vrtx_next = new _DAI_Vertex(P_Vrtx_Last, Vrtx_length, init_val);
		P_Vrtx_Last = P_Vrtx_Last->P_Vrtx_next;
	}
	Vrtx_length += 1;
}

void _DA_Vertices::Vertex_Add()
{
	if (!Vrtx_length)
	{
		P_Vrtx_First = new _DAI_Vertex(P_Vrtx_Last, Vrtx_length);
		P_Vrtx_Last = P_Vrtx_First;
	}
	else
	{
		P_Vrtx_Last->P_Vrtx_next = new _DAI_Vertex(P_Vrtx_Last, Vrtx_length);
		P_Vrtx_Last = P_Vrtx_Last->P_Vrtx_next;
	}
	Vrtx_length += 1;
}

void _DA_Vertices::Vertex_Add(_DAI_Vertex *vert)
{
	if (!Vrtx_length)
	{
		P_Vrtx_First = new _DAI_Vertex(P_Vrtx_Last, Vrtx_length, vert);
		P_Vrtx_Last = P_Vrtx_First;
	}
	else
	{
		P_Vrtx_Last->P_Vrtx_next = new _DAI_Vertex(P_Vrtx_Last, Vrtx_length, vert);
		P_Vrtx_Last = P_Vrtx_Last->P_Vrtx_next;
	}
	Vrtx_length += 1;
}

_DAI_Vertex* _DA_Vertices::Vrt_GetItem(int index)
{
	_DAI_Vertex* item = Vertex_Search(index);
	P_Vrtx_buffer = item->P_Vrtx_next;
	return item;
}

_DAI_Vertex* _DA_Vertices::Vertex_Search(int index)
{
	if (!(index >= Vrtx_length or index < 0))
	{
		if (index == 0) // Spetial case
		{
			return P_Vrtx_First;
		}
		if (index == Vrtx_length - 1) // Spetial case
		{
			return P_Vrtx_Last;
		}
		if (P_Vrtx_buffer)
		{
			if (index == P_Vrtx_buffer->Vrtx_index)
			{
				return P_Vrtx_buffer;
			}
		}
		if (index <= Vrtx_length / 2) // Start with furst item
		{
			_DAI_Vertex* item = P_Vrtx_First;
			while (item->Vrtx_index != index)
			{
				item = item->P_Vrtx_next;
			}
			return item;
		}
		else // last item 
		{
			_DAI_Vertex* item = P_Vrtx_Last;
			while (item->Vrtx_index != index)
			{
				item = item->P_Vrtx_prev;
			}
			return item;
		}
	}
	else
	{
		return nullptr;	 //TODO make error
	}
}

void _DA_Vertices::Vertex_Delete(int index_start = -1, int index_end = -1)
{
	_DAI_Vertex* TP_Trig_First;
	_DAI_Vertex* TP_Trig_Last;
	_DAI_Vertex* TP_Trig_next;
	_DAI_Vertex* TP_Trig_prev;
	_DAI_Vertex* TP_Trig_del;

	if (index_start < -1 or index_end < -1) { return; }
	if (index_end >= Vrtx_length) { index_end = Vrtx_length - 1; }

	if (index_start == -1 and index_end == -1)
	{
		TP_Trig_First = P_Vrtx_First;
		TP_Trig_Last = P_Vrtx_Last;
		index_start = 0;
		index_end = Vrtx_length - 1;
	}
	else
	{
		TP_Trig_First = Vertex_Search(index_start); // Worst Time(n) ~ n

		if (index_end == -1)
		{
			TP_Trig_Last = TP_Trig_First;
			index_end = index_start;
		}
		else
		{	// Searching
			TP_Trig_Last = Vertex_Search(index_end);
		}
	}

	int index_difference = index_end - index_start;


	if (TP_Trig_Last and TP_Trig_First)
	{
		TP_Trig_next = TP_Trig_Last->P_Vrtx_next;
		TP_Trig_prev = TP_Trig_First->P_Vrtx_prev;
	}
	else
	{
		TP_Trig_next = TP_Trig_prev = 0;
	}

	// Deleting Items
	P_Vrtx_buffer = TP_Trig_First;
	if (P_Vrtx_buffer)
	{
		for (int i = index_start; i <= index_end; i++)
		{
			TP_Trig_del = P_Vrtx_buffer;
			P_Vrtx_buffer = P_Vrtx_buffer->P_Vrtx_next;
			delete TP_Trig_del;
		}
	}

	// Reconect Links
	if (TP_Trig_next and TP_Trig_prev)
	{
		TP_Trig_next->P_Vrtx_prev = TP_Trig_prev;
		TP_Trig_prev->P_Vrtx_next = TP_Trig_next;
	}
	else
	{
		if (!(TP_Trig_next or TP_Trig_prev)) // Array is completle зиро
		{
			P_Vrtx_Last = P_Vrtx_First = nullptr;
		}
		else
		{
			if (!TP_Trig_next)
			{
				TP_Trig_prev->P_Vrtx_next = nullptr;
				P_Vrtx_Last = TP_Trig_prev;
			}
			else // Here is no prev item
			{
				TP_Trig_next->P_Vrtx_prev = nullptr;
				P_Vrtx_First = TP_Trig_next;
			}
		}
	}

	//Changing indexes
	if (TP_Trig_next)
	{
		for (int i = index_end + 1; i < Vrtx_length - 1; i++)
		{
			TP_Trig_next->Vrtx_index -= (index_difference + 1);
			TP_Trig_next = TP_Trig_next->P_Vrtx_next;
		}
	}

	Vrtx_length -= (index_difference + 1);
}

void _DA_Vertices::Vertex_Pop()
{
	_DAI_Vertex* prev_item = P_Vrtx_Last->P_Vrtx_prev;
	delete P_Vrtx_Last;
	P_Vrtx_Last = prev_item;
	prev_item->P_Vrtx_next = 0;
	Vrtx_length -= 1;
}

int _DA_Vertices::Vertices_GetLength()
{
	return Vrtx_length;
}

_DA_Vertices::~_DA_Vertices() { Vertex_Delete(); }


