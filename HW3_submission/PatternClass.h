#ifndef _PATTERN_CLASS_H_
#define _PATTERN_CLASS_H_

#include <string>
#include "ColorClass.h"

using namespace std;

class PatternClass {
    int width_;
    int height_;
    ColorClass* pattern1DArray;
    ColorClass pattern_color_;
public:
    //constructor and destructor
    PatternClass();
    ~PatternClass();
    //get private variable
    int getWidth();
    int getHeight();
    ColorClass* getPtr();
    ColorClass getPatternColor();
    //set the pattern color
    void setPatternColor(int colorChoice);
    //check the pattern
    bool checkPattern(string patternName, int &width, int &height);
};

#endif