#ifndef _RECTANGLE_CLASS_H_
#define _RECTANGLE_CLASS_H_

#include "RowColumnClass.h"
#include "ColorClass.h"

using namespace std;

class RectangleClass{
private:
    RowColumnClass startPoint;
    RowColumnClass endPoint;
    ColorClass color;
public:
    //constructor
    RectangleClass(RowColumnClass upLeft, RowColumnClass lowRight);
    //get private variable
    RowColumnClass getStartPoint() const; 
    RowColumnClass getEndPoint() const; 
    ColorClass getColor() const; 
    //set the rectangle color
    void setRectColor(int colorChoice);
};

#endif