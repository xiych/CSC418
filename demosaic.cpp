#include "demosaic.h"
#include <cstdlib>
#include <cmath>

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double g1,g2,g3,g4;
    double r1,r2,r3,r4;
    double b1,b2,b3,b4;
    
    int color = 0;
    
    
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            //decide which color it has right now
            if (fmod(row+1,2)==0){ //even row
                if(fmod(col+1,2)==0){//even col
                    //green
                    color = 2;
                }else{//odd col
                    //red
                    color = 1;
                }
            }else{//odd row
                if(fmod(col+1,2)==0){//odd row even col
                    //blue
                    color = 3;
                }else{//odd row odd col
                    //green
                    color = 2;
                }
            }
            
           //one column one row
            if(width==1 && height==1){
                //top left corner - green
                //r
                rgb[(col + row * width) * 3] = 0;
                //g
                rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                //b
                rgb[(col + row * width) * 3+2] = 0;
            }//single column
            else if(width==1 && height!=1){
                if(row==0){
                    //top left corner - green
                    //r
                    rgb[(col + row * width) * 3] = 0;
                    //g
                    rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                    //b
                    rgb[(col + row * width) * 3+2] = 0;
                }else if(row==height-1){
                    if(fmod(height,2)==0){//even rows
                        //r
                        rgb[(col + row * width) * 3] = bayer[col + row * width];
                        //g
                        g1 = bayer[col + (row-1) * width];
                        rgb[(col + row * width) * 3+1] = g1;
                        //b
                        rgb[(col + row * width) * 3+2] = 0;
                    }else{//odd rows
                        //green
                        //r
                        r1 = bayer[col + (row-1) * width];
                        rgb[(col + row * width) * 3] = r1;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        rgb[(col + row * width) * 3+2] = 0;
                    }
                }else{//in the middle
                    if(color==1){//red
                        //r
                        rgb[(col + row * width) * 3] = bayer[col + row * width];
                        //g
                        g1 = bayer[col + (row+1) * width];
                        g2 = bayer[col + (row-1) * width];
                        rgb[(col + row * width) * 3+1] = (g1+g2)/2;
                        //b
                        rgb[(col + row * width) * 3+2] = 0;
                    }else if(color==2){//green
                        //r
                        r1 = bayer[col + (row-1) * width];
                        r2 = bayer[col + (row+1) * width];
                        rgb[(col + row * width) * 3] = (r1+r2)/2;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        rgb[(col + row * width) * 3+2] = 0;
                    }
                }
            }else if(height==1 && width!=1){//one row
                if(col==0){
                    //top left corner - green
                    //r
                    rgb[(col + row * width) * 3] = 0;
                    //g
                    rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                    //b
                    rgb[(col + row * width) * 3+2] = 0;
                }else if(col==width-1){//last one
                    if(fmod(width,2)==0){//even width
                        //blue
                        //r
                        rgb[(col + row * width) * 3] = 0;
                        //g
                        g1 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3+1] = g1;
                        //b
                        rgb[(col + row * width) * 3+2] = bayer[col + row * width];;
                    }else{//odd width
                        //green
                        //r
                        rgb[(col + row * width) * 3] = 0;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];;
                        //b
                        b1 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3+2] = b1;
                    }
                }else{//middle
                    if(color==2){//green
                        //r
                        rgb[(col + row * width) * 3] = 0;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        b1 = bayer[(col+1) + row * width];
                        b2 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3+2] = (b1+b2)/2;
                    }else if(color==3){//blue
                        //r
                        rgb[(col + row * width) * 3] = 0;
                        //g
                        g1 = bayer[(col+1) + row * width];
                        g2 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3+1] = (g1+g2)/2;
                        //b
                        rgb[(col + row * width) * 3+2] = bayer[col + row * width];
                    }
                    
                }
            }
            
            //corners
            if(row==0){
                //top
                if(col==0){
                    //top left corner - green
                    //r
                    r1 = bayer[col + (row+1) * width];
                    rgb[(col + row * width) * 3] = r1;
                    //g
                    rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                    //b
                    b1 = bayer[(col+1) + row * width];
                    rgb[(col + row * width) * 3+2] = b1;
                }else if(col==width-1){//top right corner
                    if(fmod(width,2)==0){//even width
                        //blue
                        //r
                        r1 = bayer[(col-1) + (row+1) * width];
                        rgb[(col + row * width) * 3] = r1;
                        //g
                        g1 = bayer[(col-1) + row * width];
                        g2 = bayer[col + (row+1) * width];
                        rgb[(col + row * width) * 3+1] = (g1+g2)/2;
                        //b
                        rgb[(col + row * width) * 3+2] = bayer[col + row * width];
                    }else{//odd width
                        //green
                        //r
                        r1 = bayer[col + (row+1) * width];
                        rgb[(col + row * width) * 3] = r1;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        b1 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3+2] = b1;
                    }
                }
            }else if(row==height-1){
                //bottom
                if(col==0){
                    if(fmod(height,2)==0){//even height
                        //bottom left corner
                        //red
                        //r
                        rgb[(col + row * width) * 3] = bayer[col + row * width];
                        //g
                        g1 = bayer[(col+1) + row * width];
                        g2 = bayer[col + (row-1) * width];
                        rgb[(col + row * width) * 3+1] = (g1+g2)/2;
                        //b
                        b1 = bayer[(col+1) + (row-1) * width];
                        rgb[(col + row * width) * 3+2] = b1;
                    }else if (fmod(height,2)!=0){//odd height
                        //green
                        //bottom left corner
                        //r
                        r1 = bayer[col + (row-1) * width];
                        rgb[(col + row * width) * 3] = r1;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        b1 = bayer[(col+1) + row * width];
                        rgb[(col + row * width) * 3+2] = b1;
                    }
                }else if(col==width-1){
                    //bottom right corner
                    if (fmod(width,2)==0){//even width
                        if(fmod(height,2)==0){//even height even width
                            //green
                            //r
                            r1 = bayer[(col-1) + row * width];
                            rgb[(col + row * width) * 3] = r1;
                            //g
                            rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                            //b
                            b1 = bayer[col + (row+1) * width];
                            rgb[(col + row * width) * 3+2] = b1;
                        }else{//odd height even width
                            //blue
                            //r
                            r1 = bayer[(col-1) + (row-1) * width];
                            rgb[(col + row * width) * 3] = r1;
                            //g
                            g1 = bayer[col + (row-1) * width];
                            g2 = bayer[(col-1) + row * width];
                            rgb[(col + row * width) * 3+1] = (g1+g2)/2;
                            //b
                            rgb[(col + row * width) * 3+2] = bayer[col + row * width];
                        }
                    }else{//odd width
                        if(fmod(height,2)==0){//even height odd width
                            //red
                            //r
                            rgb[(col + row * width) * 3] = bayer[col + row * width];
                            //g
                            g1 = bayer[col + (row-1) * width];
                            g2 = bayer[(col-1) + row * width];
                            rgb[(col + row * width) * 3+1] = (g1+g2)/2;
                            //b
                            b1 = bayer[(col-1) + (row-1) * width];
                            rgb[(col + row * width) * 3+2] = b1;
                        }else{//odd height odd width
                            //green
                            //r
                            r1 = bayer[col + (row-1) * width];
                            rgb[(col + row * width) * 3] = r1;
                            //g
                            rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                            //b
                            b1 = bayer[(col-1) + row * width];
                            rgb[(col + row * width) * 3+2] = b1;
                        }
                    }
                }
            }
            
            
            //paint inner pixels
            if(col!=0 && col!=width-1 && row!=0 && row!=height-1){
                if(color==1){//red
                    //r
                    rgb[(col + row * width) * 3] = bayer[col + row * width];
                    //g
                    g1 = bayer[(col-1) + row * width];
                    g2 = bayer[col + (row-1) * width];
                    g3 = bayer[col + (row+1) * width];
                    g4 = bayer[(col+1) + row * width];
                    rgb[(col + row * width) * 3+1] = (g1+g2+g3+g4)/4;
                    //b
                    b1 = bayer[(col-1) + (row-1) * width];
                    b2 = bayer[(col+1) + (row+1) * width];
                    b3 = bayer[(col-1) + (row+1) * width];
                    b4 = bayer[(col+1) + (row-1) * width];
                    rgb[(col + row * width) * 3+2] = (b1+b2+b3+b4)/4;
                    continue;
                }else if(color ==2){//green
                    if(fmod(row+1,2)==0){//even rows
                        //r
                        r1 = bayer[(col+1) + row * width];
                        r2 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3] = (r1+r2)/2;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        b1 = bayer[col + (row-1) * width];
                        b2 = bayer[col + (row+1) * width];
                        rgb[(col + row * width) * 3+2] = (b1+b2)/2;
                        continue;
                    }else{//odd rows
                        //r
                        r1 = bayer[col + (row+1) * width];
                        r2 = bayer[col + (row-1) * width];
                        rgb[(col + row * width) * 3] = (r1+r2)/2;
                        //g
                        rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                        //b
                        b1 = bayer[(col+1) + row * width];
                        b2 = bayer[(col-1) + row * width];
                        rgb[(col + row * width) * 3+2] = (b1+b2)/2;
                        continue;
                    }
                }else if (color==3){//blue
                    //r
                    r1 = bayer[(col+1) + (row+1) * width];
                    r2 = bayer[(col+1) + (row-1) * width];
                    r3 = bayer[(col-1) + (row-1) * width];
                    r4 = bayer[(col-1) + (row+1) * width];
                    rgb[(col + row * width) * 3] = (r1+r2+r3+r4)/4;
                    //g
                    g1 = bayer[(col+1) + row * width];
                    g2 = bayer[(col+1) + row * width];
                    g3 = bayer[col + (row-1) * width];
                    g4 = bayer[col + (row+1) * width];
                    rgb[(col + row * width) * 3+1] = (g1+g2+g3+g4)/4;
                    //b
                    rgb[(col + row * width) * 3+2] = bayer[col + row * width];
                    continue;
                }
            }
            
    //paint four edges
    //up edges
    if(row==0 && col!=0 && col!=width-1){ //top
        if(color==3){//blue
            //r
            r1 = bayer[(col-1) + (row+1) * width];
            r2 = bayer[(col+1) + (row+1) * width];
            rgb[(col + row * width) * 3] = (r1+r2)/2;
            //g
            g1 = bayer[(col-1) + row * width];
            g2 = bayer[(col+1) + row * width];
            g3 = bayer[col + (row+1) * width];
            rgb[(col + row * width) * 3+1] = (g1+g2+g3)/3;
            //b
            rgb[(col + row * width) * 3+2] = bayer[col + row * width];
        }else if (color==2){//green
            //r
            r1 = bayer[col + (row+1) * width];
            rgb[(col + row * width) * 3] = r1;
            //g
            rgb[(col + row * width) * 3+1] = bayer[col + row * width];
            //b
            b1 = bayer[(col+1) + row * width];
            b2 = bayer[(col-1) + row * width];
            rgb[(col + row * width) * 3+2] = bayer[col + row * width];
        }
    }else if(row==height-1 && col!=0 && col!=width-1){ //bottom
        if(fmod(height,2)==0){//even height
            if(color==2){//green
                //r
                r1 = bayer[(col+1) + row * width];
                r2 = bayer[(col-1) + row * width];
                rgb[(col + row * width) * 3] = (r1+r2)/2;
                //g
                rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                //b
                b1 = bayer[col + (row-1) * width];
                rgb[(col + row * width) * 3+2] = b1;
            }else if(color==1){//red
                //r
                rgb[(col + row * width) * 3] = bayer[col + row * width];
                //g
                g1 = bayer[(col-1) + row * width];
                g2 = bayer[(col+1) + row * width];
                g3 = bayer[col + (row-1) * width];
                rgb[(col + row * width) * 3+1] = (g1+g2+g3)/3;
                //b
                b1 = bayer[(col-1) + (row-1) * width];
                b2 = bayer[(col+1) + (row-1) * width];
                rgb[(col + row * width) * 3+2] = (b1+b2)/2;
            }
        }else{//odd height
            if(color==2){//green
                //r
                r1 = bayer[col + (row-1) * width];
                rgb[(col + row * width) * 3] = r1;
                //g
                rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                //b
                b1 = bayer[(col+1) + row * width];
                b2 = bayer[(col-1) + row * width];
                rgb[(col + row * width) * 3+2] = b1;
            }else if(color==3){//blue
                //r
                r1 = bayer[(col-1) + (row-1) * width];
                r2 = bayer[(col+1) + (row-1) * width];
                rgb[(col + row * width) * 3] = (r1+r2)/2;
                //g
                g1 = bayer[(col-1) + row * width];
                g2 = bayer[(col+1) + row * width];
                g3 = bayer[col + (row-1) * width];
                rgb[(col + row * width) * 3+1] = (g1+g2+g3)/3;
                //b
                rgb[(col + row * width) * 3+2] = bayer[col + row * width];
            }
        }
    }
    
    if(col==0 && row!=0 && row!=height-1){//left
            if(color==1){//red
                //r
                rgb[(col + row * width) * 3] = bayer[col + row * width];
                //g
                g1 = bayer[(col+1) + row * width];
                g2 = bayer[col + (row-1) * width];
                g3 = bayer[col + (row+1) * width];
                rgb[(col + row * width) * 3+1] = (g1+g2+g3)/3;
                //b
                b1 = bayer[(col+1) + (row-1) * width];
                b2 = bayer[(col+1) + (row+1) * width];
                rgb[(col + row * width) * 3+2] = (b1+b2)/2;
            }else if(color==2){//green
                //r
                r1 = bayer[col + (row-1) * width];
                r2 = bayer[col + (row+1) * width];
                rgb[(col + row * width) * 3] = (r1+r2)/2;
                //g
                rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                //b
                b1 = bayer[(col+1) + row * width];
                rgb[(col + row * width) * 3+2] = b1;
            }
    }else if(col==width-1 && row!=0 && row!=height-1){//right
        if(row!=0 && row!=height-1){
            if(fmod(width,2)==0){//even width
                if(color==2){//green
                    //r
                    r1 = bayer[(col-1) + row * width];
                    rgb[(col + row * width) * 3] = r1;
                    //g
                    rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                    //b
                    b1 = bayer[col + (row-1) * width];
                    b2 = bayer[col + (row+1) * width];
                    rgb[(col + row * width) * 3+2] = (b1+b2)/2;
                }else if(color==3){//blue
                    //r
                    r1 = bayer[(col-1) + (row-1) * width];
                    r2 = bayer[(col-1) + (row+1) * width];
                    rgb[(col + row * width) * 3] = (r1+r2)/2;
                    //g
                    g1 = bayer[col + (row-1) * width];
                    g2 = bayer[col + (row+1) * width];
                    g3 = bayer[(col-1) + row * width];
                    rgb[(col + row * width) * 3+1] = (g1+g2+g3)/3;
                    //b
                    rgb[(col + row * width) * 3+2] = bayer[col + row * width];
                }
            }else{//odd width
                if(color==1){//red
                    //r
                    rgb[(col + row * width) * 3] = bayer[col + row * width];
                    //g
                    g1 = bayer[col + (row-1) * width];
                    g2 = bayer[col + (row+1) * width];
                    g3 = bayer[(col-1) + row * width];
                    rgb[(col + row * width) * 3+1] = (g1+g2+g3)/3;
                    //b
                    b1 = bayer[(col-1) + (row-1) * width];
                    b2 = bayer[(col-1) + (row+1) * width];
                    rgb[(col + row * width) * 3+2] = (b1+b2)/2;
                }else if(color==2){//green
                    //r
                    r1 = bayer[col + (row-1) * width];
                    r2 = bayer[col + (row+1) * width];
                    rgb[(col + row * width) * 3] = (r1+r2)/2;
                    //g
                    rgb[(col + row * width) * 3+1] = bayer[col + row * width];
                    //b
                    b1 = bayer[(col-1) + row * width];
                    rgb[(col + row * width) * 3+2] = b1;
                }
            }
        }
    }
    }
    }
  ////////////////////////////////////////////////////////////////////////////
}
