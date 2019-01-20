#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift, //shifted angle
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double r = 0;
    double g = 0;
    double b = 0;
    double h = 0;
    double s = 0;
    double v = 0;
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            r = rgb[(col + row * width) * 3];
            g = rgb[(col + row * width) * 3 + 1];
            b = rgb[(col + row * width) * 3 + 2];
            rgb_to_hsv(r,g,b,h,s,v);
            h = h + shift;
            hsv_to_rgb(h,s,v,r,g,b);
            shifted[(col + row * width) * 3] = r;
            shifted[(col + row * width) * 3 + 1] = g;
            shifted[(col + row * width) * 3 + 2] = b;
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
