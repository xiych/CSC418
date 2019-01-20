#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    size_t i;
    size_t num = height * width;
    for (i = 0; i < num; i++){
        rgb[3*i] = rgba[4*i];
        rgb[3*i+1] = rgba[4*i+1];
        rgb[3*i+2] = rgba[4*i+2];
    }
  ////////////////////////////////////////////////////////////////////////////
}
