#include "first_hit.h"
#include <iostream>

using namespace std;
bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    //ray.origin+t*ray.direction is the hit location
    //for each object in the list
    double t1 = 0.0;
    t = 0.0;
    Eigen::Vector3d n1;
    for(int i = 0; i<objects.size();i++){
        if(objects[i]->intersect(ray, min_t, t1, n1)==1){
            if(t==0.0){
                t = t1;
                hit_id = i;
                n = n1;
            }else if(t1<t){ //find a closer object
                t = t1;
                hit_id = i;
                n = n1;
            }
        }
    }
    if(t==0.0){
        return false;
    }else{
        return true;
    }
    
  
    
  ////////////////////////////////////////////////////////////////////////////
}

