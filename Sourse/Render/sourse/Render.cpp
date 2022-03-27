
#include "Render.h"
#include "MaMath.h"
#include "../sourse/primitives/ray.h"

DLLEXPORT void RND_init(_Data* Data)
{
	Data_p = Data;

}

DLLEXPORT void RND_Render()
{
	_RND_cycle* Cycle = &Data_p->RND_cycle;

	Cycle->update(&Data_p->UI.Viewport.View, Data_p->WM.win_width, Data_p->WM.win_height);

	int size = Cycle->resolution;
	if (size > 5){
		size -= 1;
	}
	glPointSize(size);
	glBegin(GL_POINTS);

	Ray ray = Ray();
	Ray ray_to_light = Ray();

	for (int x = Cycle->pxlx; x < Data_p->WM.win_width; x += Cycle->resolution) {
		Cycle->camera_ray -= Cycle->step_x;

		int i = Cycle->y_iteration_num;
		for (int y = Cycle->pxly; y < Data_p->WM.win_height; y += Cycle->resolution, i++) {
			Cycle->camera_ray -= Cycle->step_y;

			ray.Pos = Cycle->cam->CameraPos;
			ray.Dir = Cycle->camera_ray;
			ray.Dir.unitv(&ray.Dir);

			ray.shoot(&Data_p->DA_MeshObjects);


			if (ray.intersect) {

				float color = 0;

				ray_to_light.Pos = ray.intersect_p;
				ray_to_light.Dir = Data_p->Light.Dir;
				ray_to_light.Dir.invert();

				vec3f tmp = vec3f(ray.Norm);
				tmp *= 0.00001f;
				ray_to_light.Pos += tmp;
				ray_to_light.shoot(&Data_p->DA_MeshObjects);


				if (!ray_to_light.intersect) {

					vec3f point_ray = vec3f(ray.intersect_p);
					point_ray -= Data_p->Light.pos;
					color = 1.f / MATH_Power((point_ray.mod() + 1), 1);
					color = (color - (Data_p->Light.Dir * ray.Norm)) / 2.f;
				}
				else {
					color = 0.1f;
				}

				glColor3f(color, color, color);

				glVertex2d(double((x * 2.f) / Data_p->WM.win_width) - 1.f, -double((y * 2.f) / Data_p->WM.win_height) + 1.f);
			}

			//Cycle->timeout()
			if (0) {
				Cycle->y_iteration_num = i;
				Cycle->pxly = y;
				Cycle->pxlx = x;
				Cycle->cycle_complete = false;
				return;
			}
		}


		vec3f reset_ypos = vec3f(Cycle->step_y);
		reset_ypos *= i;
		Cycle->camera_ray += reset_ypos;
	}

	//printf("cycle've been completed congrats\n");
	Cycle->cycle_complete = true;
}