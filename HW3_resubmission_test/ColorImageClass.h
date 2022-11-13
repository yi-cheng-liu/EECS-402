#ifndef _COLORIMAGE_CLASS_H_
#define _COLORIMAGE_CLASS_H_

#include <string>
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "ColorClass.h"

using namespace std;

class ColorImageClass {
private:
    string magicNumber;
    int width;
    int height;
    int pixelColor;
    ColorClass* pixel1DArray;
    ColorClass transparency;
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
    void addRectangle(const RectangleClass &rec, bool isFilled);
    void addPattern(const PatternClass &ptn, int iRowStart, int iColStart);
    void addImage(const ColorImageClass &img, int iRowStart, int iColStart);
    //set the transparency color
    void setTransparency(int colorChoice);

    //RESUBMISSION CODE
    ColorClass getPixelValue(int i, int j) const;
    //RESUBMISSION CODE
    void writeImage(ofstream& outputFile);
};

#endif