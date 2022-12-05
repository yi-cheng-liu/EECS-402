#ifndef _PATTERN_CLASS_H_
#define _PATTERN_CLASS_H_

#include <string>
#include "ColorClass.h"

using namespace std;

class PatternClass {
private:
    int width;
    int height;
    bool* pattern1DArray;
    ColorClass patternColor;
public:
    //constructor and destructor
    PatternClass();
    ~PatternClass();
    //get private variable
    int getWidth() const;
    int getHeight() const;
    ColorClass getPatternColor() const;
    bool getPixelValue(int i, int j) const;
    // ColorClass* getPtr();
    //set the pattern color
    void setPatternColor(int colorChoice);
    //check the pattern
    bool checkPattern(string patternName, int &width, int &height);
};

#endif