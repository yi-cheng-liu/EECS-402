#ifndef _RECTANGLE_CLASS_H_
#define _RECTANGLE_CLASS_H_

#include "RowColumnClass.h"
#include "ColorClass.h"

using namespace std;

class RectangleClass{
    RowColumnClass start_point_;
    RowColumnClass end_point_;
    ColorClass color_;
public:
    RectangleClass(RowColumnClass upLeft, RowColumnClass lowRight);
    //get private variable
    RowColumnClass getStartPoint(); 
    RowColumnClass getEndPoint(); 
    ColorClass getColor(); 
    //set the rectangle color
    void setRectColor(int colorChoice);
};

#endif