#pragma once

#include "primitives/vec3f.h"
#include "primitives/timer.h"
#include <stdio.h>

struct _Camera
{
	vec3f CameraPos = vec3f(0, 2, 0);
	vec3f x_unit_v = vec3f(1, 0, 0);
	vec3f y_unit_v = vec3f(0, 0, 1);
	vec3f z_unit_v = vec3f(0, -1, 0);
	vec3f FocalPoint = vec3f(0.5f, 0.f, 0.5f);
	float near_plane = 2.f;
	float simplify = 10;
};


class _RND_cycle
{
public:
	_Time timer;

	float resolution;
	int pxlx, pxly;
	bool restart;
	bool cycle_complete;
	int y_iteration_num;

	_Camera* cam = nullptr;
	vec3f step_y;
	vec3f step_x;
	vec3f camera_ray;

	_RND_cycle();
	~_RND_cycle();
	bool timeout();
	void update(_Camera* cam, int w, int h);

private:

};