#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include<iostream>

using namespace std;

class ColorClass{
private:
    int amountRed;
    int amountGreen;
    int amountBlue;
public:
    ColorClass();
    ColorClass(int inRed, int inGreen, int inBlue);
    //set color to
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    //set color
    int setToSingleColor(int color);
    bool setTo(ColorClass inColor);
    void setTo(int inRed, int inGreen, int inBlue);
    bool clipStatus(int color, int range);
    //check whether is the same color
    bool checkSameColor(ColorClass colorCompare);
    
    //RESUBMISSION CODE
    void writePixel(ofstream& outputFile);
    //read the pixel color
    bool readPixel(ifstream &inputFile, const int range);
};

#endif