#include "simulate_bayer_mosaic.h"
#include <cstdlib>
#include <cmath>

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    //green
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            //green
            if(fmod(row+1,2)==0){//even row
                if(fmod(col+1,2)==0){ //even col
                    //green
                    bayer[col + row * width] = rgb[(col + row * width) * 3 + 1];
                }else if (fmod(col+1,2)!=0){ //odd col
                    //red
                    bayer[col + row * width] = rgb[(col + row * width) * 3];
                }
            }else if (fmod(row+1,2)!=0){//odd row
                if(fmod(col+1,2)==0){ //even col
                    //blue
                    bayer[col + row * width] = rgb[(col + row * width) * 3 + 2];
                }else if (fmod(col+1,2)!=0){ //odd col
                    //green
                    bayer[col + row * width] = rgb[(col + row * width) * 3 + 1];
                }
            }
        }
    }
    
    
  ////////////////////////////////////////////////////////////////////////////
}
