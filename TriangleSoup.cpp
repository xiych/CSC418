#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"



bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    //first triangle in the
    int hit_id;
    if(first_hit(ray, min_t, triangles, hit_id, t, n)){ //fist triangle hit
        //cout<<"haha" <<endl;
        return true;
    }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}



