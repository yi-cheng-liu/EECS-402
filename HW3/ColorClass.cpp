#include <iostream>
#include "Constant.h"
#include "ColorClass.h"

//constructor
ColorClass::ColorClass(){
    amountRed = COLOR_MAX;
    amountGreen = COLOR_UPPER_LIMIT;
    amountBlue = COLOR_UPPER_LIMIT;
};
//destructor
ColorClass::ColorClass(int inRed, int inGreen, int inBlue){
    //check the red color
    if (inRed > COLOR_UPPER_LIMIT) {
        amountRed = COLOR_UPPER_LIMIT;
    }
    else if (inRed < COLOR_LOWER_LIMIT) {
        amountRed = COLOR_LOWER_LIMIT;
    }
    else {
        amountRed = inRed;
    }
    //check the green color
    if (inGreen > COLOR_UPPER_LIMIT) {
        amountGreen = COLOR_UPPER_LIMIT;
    }
    else if (inGreen < COLOR_LOWER_LIMIT) {
        amountGreen = COLOR_LOWER_LIMIT;
    }
    else {
        amountGreen = inGreen;
    }
    //check the blue color
    if (inBlue > COLOR_UPPER_LIMIT) {
        amountBlue = COLOR_UPPER_LIMIT;
    }
    else if (inBlue < COLOR_LOWER_LIMIT) {
        amountBlue = COLOR_LOWER_LIMIT;
    }
    else {
        amountBlue = inBlue;
    }
};

void ColorClass::setToBlack(){
    amountRed = COLOR_LOWER_LIMIT;
    amountGreen = COLOR_LOWER_LIMIT;
    amountBlue = COLOR_LOWER_LIMIT;
};
void ColorClass::setToRed(){
    amountRed = COLOR_UPPER_LIMIT;
    amountGreen = COLOR_LOWER_LIMIT;
    amountBlue = COLOR_LOWER_LIMIT;
};
void ColorClass::setToGreen(){
    amountRed = COLOR_LOWER_LIMIT;
    amountGreen = COLOR_UPPER_LIMIT;
    amountBlue = COLOR_LOWER_LIMIT;
};
void ColorClass::setToBlue(){
    amountRed = COLOR_LOWER_LIMIT;
    amountGreen = COLOR_LOWER_LIMIT;
    amountBlue = COLOR_UPPER_LIMIT;
};
void ColorClass::setToWhite(){
    amountRed = COLOR_UPPER_LIMIT;
    amountGreen = COLOR_UPPER_LIMIT;
    amountBlue = COLOR_UPPER_LIMIT;
};

int ColorClass::setToSingleColor(int color){
    if(color > COLOR_UPPER_LIMIT){
        return COLOR_UPPER_LIMIT;
    }
    else if(color < COLOR_LOWER_LIMIT){
        return COLOR_LOWER_LIMIT;
    }
    return color;
};
bool ColorClass::setTo(ColorClass inColor){
    this->amountRed = inColor.amountRed;
    this->amountGreen = inColor.amountGreen;
    this->amountBlue = inColor.amountBlue;
    return 0;
};
void ColorClass::setTo(int inRed, int inGreen, int inBlue){
    amountRed = setToSingleColor(inRed);
    amountGreen = setToSingleColor(inGreen);
    amountBlue = setToSingleColor(inBlue);
};

bool ColorClass::clipStatus(int color, int range){
    if ((color > range) || (color < COLOR_LOWER_LIMIT)) {
        return true; //clipped
    }
    return false; //no clipped
}

int ColorClass::getRedval(){
    return amountRed;
};
int ColorClass::getGreenval(){
    return amountGreen;
};
int ColorClass::getBlueval(){
    return amountBlue;
};

bool ColorClass::checkSameColor(ColorClass colorCompare) {
    if (amountRed != colorCompare.amountRed) {
        return false;
    }
    else if (amountGreen != colorCompare.amountGreen) {
        return false;
    }
    else if (amountBlue != colorCompare.amountBlue) {
        return false;
    }
    return true;
}

bool ColorClass::readPixel(int red, int green, int blue, int range){
    if (clipStatus(red, range)) {
        cout << "Red color out of range" << endl;
        return false;
    }
    if (clipStatus(green, range)) {
        cout << "Green color out of range" << endl;
        return false;
    }
    if (clipStatus(blue, range)) {
        cout << "Blue color out of range" << endl;
        return false;
    }
    amountRed = red;
    amountGreen = green;
    amountBlue = blue;
    return true;
}

void ColorClass::setPixelPattern(bool index){
    pixelPattern = index;
}
bool ColorClass::getPixelPattern(){
    return pixelPattern;
}
