#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    double denominator = 0.0;
    //q = n transpose * point
    denominator = normal.dot(ray.direction);
    if(abs(denominator) > 0.0001){ //
        t = (point - ray.origin).dot(normal) / denominator;
        if (t >= min_t){
            //normal at the intersection point
            n = normal;
            return true;
        }
    }
    
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

