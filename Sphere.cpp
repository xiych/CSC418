#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    double t0 = 0.0;
    double t1 = 0.0;
    Eigen::Vector3d L = ray.origin - center;
    float a = ray.direction.dot(ray.direction);
    float b = 2 * ray.direction.dot (L);
    float c = L.dot(L) - radius * radius;
    float discriminant = b*b - 4*a*c;
    if(discriminant<0)
        return false;
    else if(discriminant == 0)
        t0 = t1 = -(0.5*b)/a;
    else{
        t0 = (-b+sqrt(discriminant))/(2*a);
        t1 = (-b-sqrt(discriminant))/(2*a);
    }
    if(t0>t1)
        std::swap(t0,t1);
    if(t0 < min_t){
        t0 = t1;
        if(t0 < min_t)
            return false;
    }
    
    t=t0;//choose closer one
    //point
    Eigen::Vector3d p;
    p = ray.origin + t * ray.direction;
    //normal at point of intersection
    n = (p - center) / radius;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

