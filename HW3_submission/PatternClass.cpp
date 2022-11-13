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
int PatternClass::getWidth() {
    return width_;
}
int PatternClass::getHeight(){
    return height_;
}
ColorClass* PatternClass::getPtr(){
    return pattern1DArray;
}
ColorClass PatternClass::getPatternColor(){
    return pattern_color_;
}
//set the pattern color
void PatternClass::setPatternColor(int colorChoice){
    if(colorChoice == ALL_RED){
        pattern_color_.setToRed();
    }
    else if(colorChoice == ALL_GREEN){
        pattern_color_.setToGreen();
    }
    else if(colorChoice == ALL_BLUE){
        pattern_color_.setToBlue();
    }
    else if(colorChoice == ALL_BLACK){
        pattern_color_.setToBlack();
    }
    else if(colorChoice == ALL_WHITE){
        pattern_color_.setToWhite();
    }
}
//check the pattern
bool PatternClass::checkPattern(string patternName, int &width, int &height){
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
        patternFile >> width_ >> height_;
        if (patternFile.eof()){
            cout << "EOF before reading image width and height!" << endl;
            return false;
        }
        else if (width_ < DIMENSION_MIN || height_ < DIMENSION_MIN){
            cout << "Dimension of the image is smaller than 1!" << endl;
            return false;
        }
        else{
            validInput = true;
            width = width_;
            height = height_;
        }
    }
    
    pattern1DArray = new ColorClass[width_ * height_];
    bool check;
    string temp;

    //load the pattern
    while(!patternFile.eof()){
        for(int i = 0; i < height_; i++){
            for(int j = 0; j < width_; j++){
                int pattern1DIndex = i * width_ + j;

                patternFile >> check;
                if(patternFile.fail()){
                    cout << "ERROR! Pattern value are not valid!" << endl;
                    return false;
                }
                else{
                    pattern1DArray[pattern1DIndex].setTo(pattern_color_);
                    pattern1DArray[pattern1DIndex].setPixelPattern(check);
                }
            }
        }
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