#include "hsv_to_rgb.h"
#include <cstdlib>
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    r = 0;
    g = 0;
    b = 0;
    
    double c = v * s;
    double h_prime = fmod(h/60.0, 6);
    double x = c * (1- abs(fmod(h_prime,2) - 1));
    double m = v - c;
    
    //define rgb based on h'
    if (h_prime >= 0 && h_prime <= 1){
        r = c;
        g = x;
        b = 0;
    }else if (h_prime > 1 && h_prime <= 2){
        r = x;
        g = c;
        b = 0;
    }else if (h_prime > 2 && h_prime <= 3){
        r = 0;
        g = c;
        b = x;
    }else if (h_prime > 3 && h_prime <= 4){
        r = 0;
        g = x;
        b = c;
    }else if (h_prime > 4 && h_prime <= 5){
        r = x;
        g = 0;
        b = c;
    }else if (h_prime > 5 && h_prime <= 6){
        r = c;
        g = 0;
        b = x;
    }
    
    r = r + m;
    g = g + m;
    b = b + m;
  ////////////////////////////////////////////////////////////////////////////
}
