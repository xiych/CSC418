//#include "rgb_to_gray.h"
//using namespace std;
//#include <iostream>
//#include <string>
//
//void rgb_to_gray(
//  const std::vector<unsigned char> & rgb,
//  const int width,
//  const int height,
//  std::vector<unsigned char> & gray)
//{
//  gray.resize(height*width);
//  ////////////////////////////////////////////////////////////////////////////
//  // Add your code here
//    int r=0;
//    int g=0;
//    int b=0;
//    int i=0;
//    for (int col = 0; col < width; col++) {
//        for (int row = 0; row < height; row++) {
//            r = static_cast<unsigned int>(rgb[(col + row * width) * 3]);
//            g = static_cast<unsigned int>(rgb[(col + row * width) * 3 + 1]);
//            b = static_cast<unsigned int>(rgb[(col + row * width) * 3 + 2]);
//            i = 0.2126 * r + 0.7152 * g + 0.0722 * b;
//            gray[col + row * width] = static_cast<unsigned char>(i);
//        }
//    }
//  ////////////////////////////////////////////////////////////////////////////
//}
//
//
