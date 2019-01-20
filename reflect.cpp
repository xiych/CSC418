#include "reflect.h"
#include <cstdlib>

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    
    
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            if(num_channels==1){
                reflected[(col + row * width)]=input[(abs(width - col) + row * width)];
            }else{
                reflected[(col + row * width) * 3]=input[(abs(width - col) + row * width) * 3];
                reflected[(col + row * width) * 3 + 1]=input[(abs(width - col) + row * width) * 3 + 1];
                reflected[(col + row * width) * 3 + 2]=input[(abs(width - col) + row * width) * 3 + 2];
            }
            
        }
    }

  ////////////////////////////////////////////////////////////////////////////
}
