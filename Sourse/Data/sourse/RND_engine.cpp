#include "RND_engine.h"

void _RND_cycle::update(_Camera* camera, int width, int height) {

	timer.reset_start();
	timer.set_timer(100.f/6);

	//if (restart) 
	{

		//printf("init cycle\n");
		cycle_complete = false;

		pxlx = 1;
		pxly = 1;
		y_iteration_num = 0;

		cam = camera;

		vec3f tmp1 = vec3f(cam->x_unit_v);
		vec3f tmp2 = vec3f(cam->y_unit_v);
		vec3f tmp3 = vec3f(cam->z_unit_v);

		tmp3 *= cam->near_plane;

		camera_ray = tmp1 += (tmp2 += tmp3);

		step_x = vec3f(cam->x_unit_v);
		step_y = vec3f(cam->y_unit_v);

		//resolution = 5;
		resolution = cam->simplify;
	
		step_x *= (resolution / width) * 2.f;
		step_y *= (resolution / height) * 2.f;

		//restart = false;
	}

}

bool _RND_cycle::timeout() {
	if (timer.timeout()) {
		printf("time out\n");
		return true;
	}
	return false;
}

_RND_cycle::_RND_cycle()
{
	resolution = 10;
	pxlx = 1;
	pxly = 1;
	y_iteration_num = 0;
	restart = true;
	cycle_complete = false;
}

_RND_cycle::~_RND_cycle()
{
}