#include <iostream>
#include <fstream>
#include <string>
#include "Constant.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"

using namespace std;

//constructor
PatternClass::PatternClass() {
    pattern1DArray = 0;
}
//destructor
PatternClass::~PatternClass() {
    delete[] pattern1DArray;
    pattern1DArray = 0;
}
//get private variable
int PatternClass::getWidth() const{
    return width;
}
int PatternClass::getHeight() const{
    return height;
}
ColorClass PatternClass::getPatternColor() const{
    return patternColor;
}
bool PatternClass::getPixelValue(int i, int j) const{
    int pixelIndex = i * width + j;
    return pattern1DArray[pixelIndex];
}

// ColorClass* PatternClass::getPtr(){
//     return pattern1DArray;
// }
//set the pattern color
void PatternClass::setPatternColor(int colorChoice){
    if(colorChoice == ALL_RED){
        patternColor.setToRed();
    }
    else if(colorChoice == ALL_GREEN){
        patternColor.setToGreen();
    }
    else if(colorChoice == ALL_BLUE){
        patternColor.setToBlue();
    }
    else if(colorChoice == ALL_BLACK){
        patternColor.setToBlack();
    }
    else if(colorChoice == ALL_WHITE){
        patternColor.setToWhite();
    }
}
//check the pattern
bool PatternClass::checkPattern(string patternName, int &ptnWidth, int &ptnHeight){
    bool validInput;
    ifstream patternFile;

    patternFile.open(patternName.c_str());
    if(patternFile.fail()){
        cout << "ERROR! Unable to open pattern file!" << endl;
        return false;
    }
    
    //Step 1: check width and height
    validInput = false;
    while(!validInput){
        patternFile >> width >> height;
        if (patternFile.eof()){
            cout << "EOF before reading image width and height!" << endl;
            return false;
        }
        else if (width < DIMENSION_MIN || height < DIMENSION_MIN){
            cout << "Dimension of the image is smaller than 1!" << endl;
            return false;
        }
        else{
            validInput = true;
            ptnWidth = width;
            ptnHeight = height;
        }
    }
    
    pattern1DArray = new bool[width * height];
    bool check;

    //load the pattern
    while(!patternFile.eof()){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                int pattern1DIndex = i * width + j;
                patternFile >> check;
                if(patternFile.fail()){
                    cout << "ERROR! Pattern value are not valid!" << endl;
                    return false;
                }
                else{
                    pattern1DArray[pattern1DIndex] = check;
                }
            }
        }
        string temp;
        patternFile >> temp;
        if (temp != "") {
            patternFile.close();
            cout << "ERROR! Number of pattern doesn't match the dimension!";
            cout << endl;
            return false;
        }
    }
    return true;
}