//#include "write_ppm.h"
//#include <fstream>
//#include <cassert>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool write_ppm(
//  const std::string & filename,
//  const std::vector<unsigned char> & data,
//  const int width,
//  const int height,
//  const int num_channels)
//{
//  assert(
//    (num_channels == 3 || num_channels ==1 ) &&
//    ".ppm only supports RGB or grayscale images");
//  ////////////////////////////////////////////////////////////////////////////
//  // Replace with your code here:
//    size_t size = width * height; //w, h and 3 color channels
//    ofstream myImage;        //output stream object
//    myImage.open(filename);
//    if (myImage.fail()){
//        cout << "Unable to create" << endl;
//        return false;
//    }
//    if(num_channels == 1){
//        myImage << "P2" << endl; //P2 OR P5
//        myImage << width << " " << height << endl;
//        myImage << "255" << endl; //the maximum value of the colour components for the pixels
//    }else if(num_channels == 3){
//         //image header for image properties
//            myImage << "P3" << endl; //P3 OR P6
//            myImage << width << " " << height << endl;
//            myImage << "255" << endl; //the maximum value of the colour components for the pixels
//    }
//     //image data for each pixel
//        for (int x = 0; x < size * num_channels; x++){
//            int value = data[x]; // value as an int
//            myImage << value << " " << endl; //num_channels of bytes of colour to each pixel
//        }
//
//    myImage.close();
//
//  return true;
//  ////////////////////////////////////////////////////////////////////////////
//}
