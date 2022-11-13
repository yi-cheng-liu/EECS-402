#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include<iostream>

using namespace std;

class ColorClass{
    int amountRed;
    int amountGreen;
    int amountBlue;
    bool pixelPattern;
public:
    ColorClass();
    ColorClass(int inRed, int inGreen, int inBlue);
    //set the color
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    //set color
    int setToSingleColor(int color);
    bool setTo(ColorClass inColor);
    void setTo(int inRed, int inGreen, int inBlue);
    //add color and adjust color
    bool addColor(ColorClass &rhs);
    bool adjustBrightness(double adjFactor);
    bool clipStatus(int color, int range);
    //check whether is the same color
    bool checkSameColor(ColorClass colorCompare);
    //get RGB color
    int getRedval();
    int getGreenval();
    int getBlueval();
    bool getPixelPattern();
    //read the pixel color
    bool readPixel(int red, int green, int blue, int range);
    //set the pixel pattern
    void setPixelPattern(bool index);
};

#endif