//
//  Color.cpp
//  C++_programming
//
//  Created by Hyunah on 2018. 5. 1..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include "Color.hpp"

class ColorList {
    
public:
    ColorList() : r(0),g(0),b(0) { }
    ColorList(float r,float g, float b) : r(r),g(g),b(b) { }
    
    float getR() { return r; }
    float getG() { return g; }
    float getB() { return b; }
    
    ColorList mixColor(ColorList a, ColorList b){
        return ColorList( a.getR()+b.getR() /2 ,a.getG()+b.getG() /2, a.getB()+b.getB() /2);
    }
    
private:
    float r;
    float g;
    float b;

};



