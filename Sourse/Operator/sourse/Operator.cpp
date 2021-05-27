#include "Operator.h"

_Data* Data_p;

DLLEXPORT void OPS_init(_Data* Data)
{
	Data_p = Data;
}

DLLEXPORT void OPselect(int mx, int my, int width, int height)
{
	_Camera* cam = &Data_p->UI.Viewport.View;
	Ray ray = Ray();
	ray.Pos = cam->CameraPos;

	vec3f tmp = vec3f(cam->z_unit_v);
	tmp *= cam->near_plane;
	ray.Dir += tmp;

	tmp = cam->x_unit_v;
	tmp *= (width / 2.f - mx) / (width / 2.f);
	ray.Dir += tmp;

	tmp = cam->y_unit_v;
	tmp *= (-height / 2.f + my) / (height / 2.f);
	ray.Dir += tmp;

	ray.Dir.unitv(&ray.Dir);
	ray.shoot(&Data_p->DA_MeshObjects);
	Data_p->DA_MeshObjects.active = ray.obj;
}

DLLEXPORT void OPSAddcoords()
{
	if (!Data_p->DA_MeshObjects.Obj_GetLength())
	{

		{
			float init_val[3]{ 0, 0, 0 };

			Data_p->DA_MeshObjects.Obj_Add('cube');
			_DAI_Object* Obj = Data_p->DA_MeshObjects.Obj_GetItem(0);

			

			for (int i = 0; i < 8; i++)
			{
				Obj->Mesh.DA_Vertices->Vertex_Add(init_val);
				if (i < 4) {
					Obj->Mesh.DA_Vertices->Vrt_GetItem(i)->vec.y = 1;
				}

			}

			Obj->Mesh.DA_Vertices->Vrt_GetItem(1)->vec.x = 1;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(2)->vec.x = 1;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(5)->vec.x = 1;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(6)->vec.x = 1;

			Obj->Mesh.DA_Vertices->Vrt_GetItem(2)->vec.z = 1;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(3)->vec.z = 1;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(6)->vec.z = 1;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(7)->vec.z = 1;

			for (int i = 0; i < 8; i++)
			{
				Obj->Mesh.DA_Vertices->Vrt_GetItem(i)->vec.x -= 0.5f;
				Obj->Mesh.DA_Vertices->Vrt_GetItem(i)->vec.y -= 0.5f;
				Obj->Mesh.DA_Vertices->Vrt_GetItem(i)->vec.z -= 0.5f;
			}



			for (int i = 0; i < 12; i++)
			{
				Obj->Mesh.DA_Trigs->DAI_Trig_Add();
			}


			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(0)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(0);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(0)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(0)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(1)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(0);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(1)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(1)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(3);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(2)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(0);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(2)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(3);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(2)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(7);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(3)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(0);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(3)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(7);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(3)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(4);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(4)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(4);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(4)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(6);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(4)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(5);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(5)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(4);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(5)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(7);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(5)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(6);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(6)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(4);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(6)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(6)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(0);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(7)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(4);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(7)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(5);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(7)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(8)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(8)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(6);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(8)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(9)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(9)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(5);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(9)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(6);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(10)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(10)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(7);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(10)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(3);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(11)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(11)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(6);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(11)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(7);
		}

		{
			float init_val[3]{ 0, 0, 0 };

			Data_p->DA_MeshObjects.Obj_Add('plan');
			_DAI_Object* Obj = Data_p->DA_MeshObjects.Obj_GetItem(1);

			Obj->unit_vx.assing(1.f, 0.0f, 0.0f);
			Obj->unit_vy.assing(0.0f, 1.0f, 0.0f);
			Obj->unit_vz.assing(0.0f, 0.0f, 1.0f);

			for (int i = 0; i < 4; i++)
			{
				Obj->Mesh.DA_Vertices->Vertex_Add(init_val);
			}

			float size = 2;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(0)->vec.y = size;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(1)->vec.y = size;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(2)->vec.y = -size;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(3)->vec.y = -size;

			Obj->Mesh.DA_Vertices->Vrt_GetItem(0)->vec.x = -size;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(1)->vec.x = size;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(2)->vec.x = -size;
			Obj->Mesh.DA_Vertices->Vrt_GetItem(3)->vec.x = size;


			Obj->Mesh.DA_Trigs->DAI_Trig_Add();
			Obj->Mesh.DA_Trigs->DAI_Trig_Add();

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(0)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(0);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(0)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(0)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);

			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(1)->v1 = Obj->Mesh.DA_Vertices->Vrt_GetItem(3);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(1)->v2 = Obj->Mesh.DA_Vertices->Vrt_GetItem(1);
			Obj->Mesh.DA_Trigs->DAI_Trig_GetItem(1)->v3 = Obj->Mesh.DA_Vertices->Vrt_GetItem(2);
		}

		Data_p->Light.Dir.x = -1.f;
		Data_p->Light.Dir.y = -2;
		Data_p->Light.Dir.z = -3;
		Data_p->Light.Dir.unitv(&Data_p->Light.Dir);

		Data_p->Light.pos.x = 3;
		Data_p->Light.pos.y = 3;
		Data_p->Light.pos.z = 4;
	}
}

DLLEXPORT void rotObj(const char direction, float angel)
{
	_DAI_Object* Obj = Data_p->DA_MeshObjects.Obj_GetItem(1);
	int len = Obj->Mesh.DA_Vertices->Vertices_GetLength();

	switch (direction)
	{
	case 'x':
		for (int pnt = 0; pnt < len; pnt++)
		{
			MATH_RotateXAroundCenter(&(Obj->Mesh.DA_Vertices->Vrt_GetItem(pnt)->vec.x), angel);
		}
		break;
	case 'y':
		for (int pnt = 0; pnt < len; pnt++)
		{
			MATH_RotateYAroundCenter(&(Obj->Mesh.DA_Vertices->Vrt_GetItem(pnt)->vec.x), angel);
		}
		break;
	case 'z':
		for (int pnt = 0; pnt < len; pnt++)
		{
			MATH_RotateZAroundCenter(&(Obj->Mesh.DA_Vertices->Vrt_GetItem(pnt)->vec.x), angel);
		}
		break;
	}
}

DLLEXPORT void RelativeRotate(float rot_angel, float focusScale) //FIXME
{

	_DAI_Object* Obj = Data_p->DA_MeshObjects.Obj_GetItem(1);
	int len = Obj->Mesh.DA_Vertices->Vertices_GetLength();

	float Copy[3]{ 1, -1, -1 };

	MATH_MakeUnitVector(Copy);

	for (int pnt = 0; pnt < len; pnt++)
	{
		//MATH_RotateArbAxes(&(Data_p->UI.Viewport.View.z_unit_v.x), &(Obj->Mesh.DA_Vertices->Vrt_GetItem(pnt)->vec.x), rot_angel);
	}
}

DLLEXPORT void OPSdelete()
{	
	if (Data_p->DA_MeshObjects.active) {
		int del_idx = Data_p->DA_MeshObjects.active->Obj_index;
		Data_p->DA_MeshObjects.Obj_Delete(del_idx, del_idx);
		Data_p->DA_MeshObjects.active = nullptr;
	}
}

DLLEXPORT void OPSclear()
{
	Data_p->DA_MeshObjects.Obj_Delete(-1, -1);
	Data_p->DA_MeshObjects.active = nullptr;
}

DLLEXPORT void ResetCamera()
{
	_Camera* cam = &Data_p->UI.Viewport.View;
	cam->x_unit_v.assing(0.93f, -0.34f, 0.01);
	cam->y_unit_v.assing(-.11f, -.25f, 0.95f);
	cam->z_unit_v.assing(-0.33f, -0.9f, -.27f);
	cam->CameraPos.assing(1.88f, 3.95f, 1.58);
	cam->FocalPoint.assing(0.5f, 0.5f, 0.5f);
}

//DLLEXPORT void RotCamera(float angel, char axes, float focusScale)

DLLEXPORT void RotCamera(float angel, char axes, float focusScale) //TODO: replace with orbital rotate
{
	_Camera* cam = &Data_p->UI.Viewport.View;
	MATH_VectorDifference(&(cam->CameraPos.x), &(cam->CameraPos.x), &(cam->FocalPoint.x));

	float vec[3]{ 0,0,0 };
	switch (axes)
	{
	case 'x':

		MATH_RotateArbAxes(&(cam->x_unit_v.x), vec, &(cam->y_unit_v.x), angel);
		MATH_RotateArbAxes(&(cam->x_unit_v.x), vec, &(cam->z_unit_v.x), angel);
		MATH_RotateArbAxes(&(cam->x_unit_v.x), vec, &(cam->CameraPos.x), angel);

		break;

	case 'y':

		MATH_RotateZAroundCenter(&(cam->x_unit_v.x), angel);
		MATH_RotateZAroundCenter(&(cam->y_unit_v.x), angel);
		MATH_RotateZAroundCenter(&(cam->z_unit_v.x), angel);
		MATH_RotateZAroundCenter(&(cam->CameraPos.x), angel);

		break;

	case 'z':
		MATH_RotateArbAxes(&(cam->z_unit_v.x), vec, &(cam->x_unit_v.x), angel);
		MATH_RotateArbAxes(&(cam->z_unit_v.x), vec, &(cam->y_unit_v.x), angel);
		MATH_RotateArbAxes(&(cam->z_unit_v.x), vec, &(cam->CameraPos.x), angel);

		break;
	}

	MATH_VectorSum(&(cam->CameraPos.x), &(cam->CameraPos.x), &(cam->FocalPoint.x));
}

DLLEXPORT void RotObj(float angel, char axes) //TODO: replace with orbital rotate
{

	switch (axes)
	{
	case 'x':
		//MATH_RotateArbAxes(&(Data_p->UI.Viewport.View.x_unit_v.x), &(Data_p->Light.Dir.x), angel);
		break;

	case 'y':
		//MATH_RotateArbAxes(&(Data_p->UI.Viewport.View.y_unit_v.x), &(Data_p->Light.Dir.x), angel);
		break;

	case 'z':
		//MATH_RotateArbAxes(&(Data_p->UI.Viewport.View.z_unit_v.x), &(Data_p->Light.Dir.x), angel);
		break;
	}
}

DLLEXPORT void CameraMove(float displacement, const char direction)
{
	_Camera* cam = &Data_p->UI.Viewport.View;
	float h = float(Data_p->WM.win_height);
	float w = float(Data_p->WM.win_width);
	float Movefactor = 0;
	if (h > w)
	{
		Movefactor = (w / h) * 10;
	}
	else
	{
		Movefactor = (h / w) * 10;
	}
	float displV[3];
	float distance[3];
	MATH_VectorDifference(distance, &(cam->CameraPos.x), &(cam->FocalPoint.x));
	distance[0] = MATH_VectorMagnetude(distance);

	switch (direction)
	{
	case 'x':
		displacement *= distance[0] / Movefactor;
		MATH_CopyVector(displV, &(cam->x_unit_v.x));
		MATH_ScalarMultiplication(displV, displacement);
		MATH_VectorSum(&(cam->FocalPoint.x), &(cam->FocalPoint.x), displV);
		break;
	case 'y':
		displacement *= distance[0] / Movefactor;
		MATH_CopyVector(displV, &(cam->y_unit_v.x));
		MATH_ScalarMultiplication(displV, displacement);
		MATH_VectorSum(&(cam->FocalPoint.x), &(cam->FocalPoint.x), displV);
		break;
	case 'z':

		displacement *= (distance[0] / 3);
		MATH_CopyVector(displV, &(cam->z_unit_v.x));
		MATH_ScalarMultiplication(displV, displacement);
		break;
	}
	MATH_VectorSum(&(cam->CameraPos.x), &(cam->CameraPos.x), displV);
}

// ------------------- trash --------------- //
/*
DLLEXPORT void MoveYInvert()
{
	if (Data_p->DA_MeshObjects.Obj_GetLength() and Data_p->DA_MeshObjects.Obj_GetItem(0)->Mesh.DA_Vertices->Vertices_GetLength())
	{
		//Data_p->DA_Collection.operator[](0)->Position[0] += 0.1;
		Data_p->UI.Viewport.View.CameraPos[1] -= float(0.001);
	}
}
DLLEXPORT void MoveY()
{
	if (Data_p->DA_MeshObjects.Obj_GetLength() and Data_p->DA_MeshObjects.Obj_GetItem(0)->Mesh.DA_Vertices->Vertices_GetLength())
	{
		//Data_p->DA_Collection.operator[](0)->Position[0] -= 0.1;
		Data_p->UI.Viewport.View.CameraPos[1] += float(0.001);
	}
}
DLLEXPORT void MoveZInvert()
{
	if (Data_p->DA_MeshObjects.Obj_GetLength() and Data_p->DA_MeshObjects.Obj_GetItem(0)->Mesh.DA_Vertices->Vertices_GetLength())
	{
		//Data_p->DA_Collection.operator[](0)->Position[1] += 0.1;
		Data_p->UI.Viewport.View.CameraPos[2] -= float(0.001);
	}
}
DLLEXPORT void MoveZ()
{
	if (Data_p->DA_MeshObjects.Obj_GetLength() and Data_p->DA_MeshObjects.Obj_GetItem(0)->Mesh.DA_Vertices->Vertices_GetLength())
	{
		//Data_p->DA_Collection.operator[](0)->Position[1] -= 0.1;
		Data_p->UI.Viewport.View.CameraPos[2] += float(0.001);
	}
}
DLLEXPORT void MoveXInvert()
{
	if (Data_p->DA_MeshObjects.Obj_GetLength() and Data_p->DA_MeshObjects.Obj_GetItem(0)->Mesh.DA_Vertices->Vertices_GetLength())
	{
		//Data_p->DA_Collection.operator[](0)->Position[2] += 0.1;
		Data_p->UI.Viewport.View.CameraPos[0] -= float(0.001);
	}
}
DLLEXPORT void MoveX()
{
	if (Data_p->DA_MeshObjects.Obj_GetLength() and Data_p->DA_MeshObjects.Obj_GetItem(0)->Mesh.DA_Vertices->Vertices_GetLength())
	{
		//Data_p->DA_Collection.operator[](0)->Position[2] -= 0.1;
		Data_p->UI.Viewport.View.CameraPos[0] += float(0.001);
	}
}
*/
