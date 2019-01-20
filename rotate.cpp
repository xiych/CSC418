#include "rotate.h"
#include <iostream>
#include <string>
using namespace std;

void rotate(
            const std::vector<unsigned char> & input,
            const int width,
            const int height,
            const int num_channels,
            std::vector<unsigned char> & rotated)
{
    rotated.resize(height*width*num_channels);
    ////////////////////////////////////////////////////////////////////////////
    int new_width = height;
    int new_height = width;
    std::vector<unsigned char> reflected;
    reflected.resize(height*width*num_channels);
    
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if(num_channels==1){
                reflected[(col + row * width)]=input[(abs(width - col) + row * width)];
            }else{
            reflected[(col + row * width) * 3]=input[(abs(width - col) + row * width) * 3];
            reflected[(col + row * width) * 3 + 1]=input[(abs(width - col) + row * width) * 3 + 1];
            reflected[(col + row * width) * 3 + 2]=input[(abs(width - col) + row * width) * 3 + 2];
            }
        }
    }
    for (int row = 0; row < width; row++) {
      for (int col = 0; col < height; col++) {
          if(num_channels==1){
              rotated[(col + row * height)]= reflected[(row + col * width)];
          }else{
              rotated[(col + row * height) * 3]= reflected[(row + col * width) * 3];
              rotated[(col + row * height) * 3 + 1]= reflected[(row + col * width) * 3 + 1];
              rotated[(col + row * height) * 3 + 2]= reflected[(row + col * width) * 3 + 2];
          }
          
        }
    }
    ////////////////////////////////////////////////////////////////////////////
}
