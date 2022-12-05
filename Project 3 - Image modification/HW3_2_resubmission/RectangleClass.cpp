#include <iostream>
#include <string>
#include "Constant.h"
#include "RectangleClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"

using namespace std;

//class RectangleClass function definitions
RectangleClass::RectangleClass(RowColumnClass upLeft, RowColumnClass lowRight){
    startPoint = upLeft;
    endPoint = lowRight;
}
void RectangleClass::setRectColor(int colorChoice){
    if(colorChoice == ALL_RED){
        color.setToRed();
    }
    else if(colorChoice == ALL_GREEN){
        color.setToGreen();
    }
    else if(colorChoice == ALL_BLUE){
        color.setToBlue();
    }  
    else if(colorChoice == ALL_BLACK){
        color.setToBlack();
    }
    else if(colorChoice == ALL_WHITE){
        color.setToWhite();
    }
}
RowColumnClass RectangleClass::getStartPoint() const{
    return startPoint;
}
RowColumnClass RectangleClass::getEndPoint() const{
    return endPoint;
}
ColorClass RectangleClass::getColor() const{
    return color;
}