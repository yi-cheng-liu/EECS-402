#ifndef _COLORIMAGE_CLASS_H_
#define _COLORIMAGE_CLASS_H_

#include <string>
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "ColorClass.h"

using namespace std;

class ColorImageClass {
    string magic_number_;
    int width_;
    int height_;
    int pixel_color_;
    ColorClass* pixel1DArray;
    ColorClass transparency_;
public:
    ColorImageClass();
    ~ColorImageClass();
    //get private variables
    string getMagicNumber();
    int getWidth();
    int getHeight();
    int getPixel();
    ColorClass* getPtr();
    //check the image
    bool checkImage(string fileName, int &width, int &height);
    //add rectangle, pattern and image
    void addRectangle(RectangleClass &rec, bool filled);
    void addPattern(PatternClass &ptn, int iRowStart, int iColStart);
    void addImage(ColorImageClass &img, int iRowStart, int iColStart);
    //set the transparency color
    void setTransparency(int colorChoice);
};

#endif