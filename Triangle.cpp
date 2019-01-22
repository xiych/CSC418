#include "Triangle.h"
#include "Ray.h"
#include <tuple>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    Eigen::Vector3d a = std::get<0>(corners);
    Eigen::Vector3d b = std::get<1>(corners);
    Eigen::Vector3d c = std::get<2>(corners);
    Eigen::Vector3d ba = b - a;
    Eigen::Vector3d cb = c - b;
    Eigen::Vector3d ca = c - a;
    Eigen::Vector3d p;
    //compute normal
    //reference to: https://courses.cs.washington.edu/courses/cse457/07sp/lectures/triangle_intersection.pdf
    
    //Vector3d N;
    n = ba.cross(ca);
    //check if ray is parallel to the plane
    float ndotdir = n.dot(ray.direction);
    if(abs(ndotdir)<1e-8)
        return false; // the ray does not intersect with plane

    //compute t
    double d = n.dot(a);
    t = (d - n.dot(ray.origin)) / ndotdir; //check if the triangle is behind the ray
    if (t < min_t)
        return false;
    //intersection point
    p = ray.origin + t*ray.direction;

    //test if it's inside the range of triangle
    //edge 1
    Eigen::Vector3d C;
    Eigen::Vector3d pc = p-c;
    Eigen::Vector3d ac = a-c;
    C = ac.cross(pc);
    if(n.dot(C)<0)
        return false;
    //edge 2
    Eigen::Vector3d pb = p-b;
    C = cb.cross(pb);
    if(n.dot(C)<0)
        return false;
    //edge 3
    Eigen::Vector3d pa = p-a;
    C = ba.cross(pa);
    if(n.dot(C)<0)
        return false;
    n = n.normalized();
    
   // cout << "haha" <<endl;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}


