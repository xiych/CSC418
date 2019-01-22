#include "viewing_ray.h"


void viewing_ray(
  const Camera & camera,
  const int i,//height
  const int j, //width
  const int width,//image width nx
  const int height, //image height ny
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    ray.origin = camera.e;
    double u = 0.0;
    double v = 0.0;
    double w = 0.0;
    double cwidth = camera.width;
    double cheight = camera.height;
    u = cwidth * (j+1/2)/width - cwidth/2;
    v = cheight * (i+1/2)/height - cheight/2;
    ray.direction = u * camera.u - v * camera.v - (camera.d) * camera.w;
  ////////////////////////////////////////////////////////////////////////////
}

