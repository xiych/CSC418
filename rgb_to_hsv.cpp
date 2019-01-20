#include "rgb_to_hsv.h"
#include <algorithm>    // std::min

using namespace std;

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
    
    double src_r = r;
    double src_g = g;
    double src_b = b;
    //get min and max out of r, g, b
    double minimum = min (min (src_r,src_g), src_b);
    double maximum = max (max (src_r,src_g), src_b);
    //calculate v
    v = maximum;
    
    //calculate s
    if (maximum == 0.0){
        s = 0;
        h = 0;
    }else if ((maximum - minimum)==0.0){
        s = 0;
        h = 0;
    }else{
        s = (maximum-minimum) / maximum;
        if(maximum == src_r){
            h = 60 * (0 + (src_g-src_b)/(maximum-minimum));
        }else if (maximum == src_g){
            h = 60 * (2 + (src_b-src_r)/(maximum-minimum));
        }else if (maximum == src_b){
            h = 60 * (4 + (src_r-src_g)/(maximum-minimum));
        }
    }
    if (h < 0){
        h = h + 360;
    }
    
  ////////////////////////////////////////////////////////////////////////////
}
