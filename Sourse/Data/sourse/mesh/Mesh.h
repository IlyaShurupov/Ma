#pragma once

#include "Vertex.h"
#include "Edge.h"
#include "Trig.h"
#include "Face.h"

/* --------------------------- Mesh -------------------------------- */

struct _Mesh
{
	_DA_Vertices* DA_Vertices = nullptr;
	_DA_Edges* DA_Edges = nullptr;
	_DA_Trigs* DA_Trigs = nullptr;
	_DA_Faces* DA_Faces = nullptr;
};
