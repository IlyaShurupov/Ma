#include "DT_Object.h"
#include "Math.h"

// ---------------- _DAI_ -------------------- //

_DAI_Object::_DAI_Object(_DAI_Object* obj, _DAI_Object* lastItem, int i)
{
	P_Obj_prev = lastItem;
	Obj_index = i;

	Mesh.DA_Vertices = new _DA_Vertices;
	Mesh.DA_Trigs = new _DA_Trigs;

	for (int i = 0; i < obj->Mesh.DA_Vertices->Vertices_GetLength(); i++) {
		Mesh.DA_Vertices->Vertex_Add();
		_DAI_Vertex *vert1 = Mesh.DA_Vertices->Vrt_GetItem(i);
		_DAI_Vertex* vert2 = obj->Mesh.DA_Vertices->Vrt_GetItem(i);
		vert1->vec = vert2->vec;
	}

	for (int i = 0; i < obj->Mesh.DA_Trigs->DA_Trigs_GetLength(); i++) {
		Mesh.DA_Trigs->DAI_Trig_Add();
		_DAI_Trig* trig1 = Mesh.DA_Trigs->DAI_Trig_GetItem(i);
		_DAI_Trig* trig2 = obj->Mesh.DA_Trigs->DAI_Trig_GetItem(i);
		trig1->v1 = trig2->v1;
		trig1->v2 = trig2->v2;
		trig1->v3 = trig2->v3;
	}

	vec3f displ = vec3f(0.5f, 0.5f, 0.5f);

	Position = obj->Position;
	Position += displ;
	unit_vx = obj->unit_vx;
	unit_vy = obj->unit_vy;
	unit_vz = obj->unit_vz;

	name = obj->name + 'a';
}

_DAI_Object::_DAI_Object(char Objname, _DAI_Object* lastItem, int i)
{
	Position.assing(0.0f, 0.0f, 0.0f);
	unit_vx.assing(1.f, 0.0f, 0.0f);
	unit_vy.assing(0.0f, 1.0f, 0.0f);
	unit_vz.assing(0.0f, 0.0f, 1.0f);

	name = Objname;
	P_Obj_prev = lastItem;
	Obj_index = i;
	Mesh.DA_Vertices = new _DA_Vertices; //TODO Obj item type init val
	Mesh.DA_Trigs = new _DA_Trigs;
}

void _DAI_Object::rot(vec3f* axs_dir, vec3f* axs_pos, float angle)
{
	printf("");
	for (int i = 0; i < 3; i++) {
		(&unit_vx)[i] += Position;
		vec3f* vec = &(&unit_vx)[i];
		MATH_RotateArbAxes(&axs_dir->x, &axs_pos->x, &((&unit_vx)[i].x), angle);
		(&unit_vx)[i] -= Position;
	}
}

void _DAI_Object::scale(float factor)
{
	unit_vx *= factor;
	unit_vy *= factor;
	unit_vz *= factor;
}

void _DAI_Object::move(vec3f* displacement)
{
	Position += displacement;
}

_DAI_Object::~_DAI_Object()
{
	Mesh.DA_Vertices->~_DA_Vertices();
} //FIXME delete item

// ---------------- _DA_Obj -------------------- //

_DA_MeshObjects::_DA_MeshObjects() { }

void _DA_MeshObjects::Obj_Add(char Objname)
{
	if (!CI_length)
	{
		P_Obj_First = new _DAI_Object(Objname, P_Obj_Last, CI_length);
		P_Obj_Last = P_Obj_First;
	}
	else
	{
		P_Obj_Last->P_Obj_next = new _DAI_Object(Objname, P_Obj_Last, CI_length);
		P_Obj_Last = P_Obj_Last->P_Obj_next;
	}
	CI_length += 1;
}

void _DA_MeshObjects::Obj_Add(_DAI_Object *obj)
{
	if (!CI_length)
	{
		P_Obj_First = new _DAI_Object(obj, P_Obj_Last, CI_length);
		P_Obj_Last = P_Obj_First;
	}
	else
	{
		P_Obj_Last->P_Obj_next = new _DAI_Object(obj, P_Obj_Last, CI_length);
		P_Obj_Last = P_Obj_Last->P_Obj_next;
	}
	CI_length += 1;
}

_DAI_Object* _DA_MeshObjects::Obj_GetItem(int index)
{
	_DAI_Object* item = Obj_Search(index);
	P_Obj_buffer = item->P_Obj_next;
	return item;
}

_DAI_Object* _DA_MeshObjects::Obj_Search(int index)
{
	if (!(index >= CI_length or index < 0)) //HMMM check bounds and maybe add DAH_Middel item
	{
		if (index == 0) // Spetial case
		{
			return P_Obj_First;
		}
		if (index == CI_length - 1) // Spetial case
		{
			return P_Obj_Last;
		}
		if (P_Obj_buffer)
		{
			if (index == P_Obj_buffer->Obj_index)
			{
				return P_Obj_buffer;
			}
		}
		if (index <= CI_length / 2) // Start with furst item
		{
			_DAI_Object* item = P_Obj_First;
			while (item->Obj_index != index)
			{
				item = item->P_Obj_next;
			}
			return item;
		}
		else // last item 
		{
			_DAI_Object* item = P_Obj_Last;
			while (item->Obj_index != index)
			{
				item = item->P_Obj_prev;
			}
			return item;
		}
	}
	else
	{
		return nullptr;	 //TODO make error
	}
}

void _DA_MeshObjects::Obj_Delete(int index_start = -1, int index_end = -1)
{
	_DAI_Object* TP_Obj_First;
	_DAI_Object* TP_Obj_Last;
	_DAI_Object* TP_Obj_next;
	_DAI_Object* TP_Obj_prev;
	_DAI_Object* TP_Obj_del;

	if (index_start < -1 or index_end < -1) { return; }
	if (index_end >= CI_length) { index_end = CI_length - 1; }

	if (index_start == -1 and index_end == -1)
	{
		TP_Obj_First = P_Obj_First;
		TP_Obj_Last = P_Obj_Last;
		index_start = 0;
		index_end = CI_length - 1;
	}
	else
	{
		TP_Obj_First = Obj_Search(index_start); // Worst Time(n) ~ n

		if (index_end == -1)
		{
			TP_Obj_Last = TP_Obj_First;
			index_end = index_start;
		}
		else
		{	// Searching
			TP_Obj_Last = Obj_Search(index_end);
		}
	}

	int index_difference = index_end - index_start;


	if (TP_Obj_Last and TP_Obj_First)
	{
		TP_Obj_next = TP_Obj_Last->P_Obj_next;
		TP_Obj_prev = TP_Obj_First->P_Obj_prev;
	}
	else
	{
		TP_Obj_next = TP_Obj_prev = 0;
	}

	// Deleting Items
	P_Obj_buffer = TP_Obj_First;
	if (P_Obj_buffer)
	{
		for (int i = index_start; i <= index_end; i++)
		{
			TP_Obj_del = P_Obj_buffer;
			P_Obj_buffer = P_Obj_buffer->P_Obj_next;
			delete TP_Obj_del;
		}
	}

	// Reconect Links
	if (TP_Obj_next and TP_Obj_prev)
	{
		TP_Obj_next->P_Obj_prev = TP_Obj_prev;
		TP_Obj_prev->P_Obj_next = TP_Obj_next;
	}
	else
	{
		if (!(TP_Obj_next or TP_Obj_prev)) // Array is completle зиро
		{
			P_Obj_Last = P_Obj_First = nullptr;
		}
		else
		{
			if (!TP_Obj_next)
			{
				TP_Obj_prev->P_Obj_next = nullptr;
				P_Obj_Last = TP_Obj_prev;
			}
			else // Here is no prev item
			{
				TP_Obj_next->P_Obj_prev = nullptr;
				P_Obj_First = TP_Obj_next;
			}
		}
	}

	//Changing indexes
	if (TP_Obj_next)
	{
		for (int i = index_end + 1; i < CI_length - 1; i++)
		{
			TP_Obj_next->Obj_index -= (index_difference + 1);
			TP_Obj_next = TP_Obj_next->P_Obj_next;
		}
	}

	CI_length -= (index_difference + 1);
}

void _DA_MeshObjects::Obj_Pop()
{
	_DAI_Object* prev_item = P_Obj_Last->P_Obj_prev;
	delete P_Obj_Last;
	P_Obj_Last = prev_item;
	prev_item->P_Obj_next = 0;
	CI_length -= 1;
}

int _DA_MeshObjects::Obj_GetLength()
{
	return CI_length;
}

_DA_MeshObjects::~_DA_MeshObjects()
{
	Obj_Delete();
}
