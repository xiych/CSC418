#include "over.h"
#include "rgba_to_rgb.h"
#include <iostream>
#include <string>
using namespace std;

void over(
  const std::vector<unsigned char> & A, //source
  const std::vector<unsigned char> & B, //dst
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    //A & B rgba
    double afinal = 0;
    double asrc = 0;
    double adst = 0;
    double ar;
    double ag;
    double ab;
    double br;
    double bg;
    double bb;
    for (int i = 0; i < width * height; i++) {
            asrc = (A[i * 4 + 3]) / 255.0; //extract a from source A
            adst = (B[i * 4 + 3]) / 255.0; //extract a from dst B
//        rsrc = (A[i * 4]) / 255;
//        gsrc = (A[i * 4 + 1]) / 255;
//        bsrc = (A[i * 4 + 2]) / 255;
//        rdst = (B[i * 4]) / 255;
//        gdst = (A[i * 4 + 1]) / 255;
//        bdst = (A[i * 4 + 2]) / 255;
            afinal = (asrc + adst) - asrc*adst;
            C[i*4] = (A[i*4]*asrc+B[i*4]*adst*(1 - asrc))/afinal; //r
            C[i*4+1] = (A[i*4+1]*asrc+ B[i * 4+1]*adst*(1 - asrc))/afinal; //g
            C[i*4+2] = (A[i*4+2]*asrc + B[i * 4+2]*adst*(1 - asrc))/afinal; //b
            C[i*4+3] = afinal * 255.0; //a
    }
  ////////////////////////////////////////////////////////////////////////////
}
