#include <iostream>
#include <string>
#include "Constant.h"
#include "RectangleClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"

using namespace std;

//class RectangleClass function definitions
RectangleClass::RectangleClass(RowColumnClass upLeft, RowColumnClass lowRight){
    start_point_ = upLeft;
    end_point_ = lowRight;
}
void RectangleClass::setRectColor(int colorChoice){
    if(colorChoice == ALL_RED){
        color_.setToRed();
    }
    else if(colorChoice == ALL_GREEN){
        color_.setToGreen();
    }
    else if(colorChoice == ALL_BLUE){
        color_.setToBlue();
    }  
    else if(colorChoice == ALL_BLACK){
        color_.setToBlack();
    }
    else if(colorChoice == ALL_WHITE){
        color_.setToWhite();
    }
}
RowColumnClass RectangleClass::getStartPoint(){
    return start_point_;
}
RowColumnClass RectangleClass::getEndPoint(){
    return end_point_;
}
ColorClass RectangleClass::getColor(){
    return color_;
}