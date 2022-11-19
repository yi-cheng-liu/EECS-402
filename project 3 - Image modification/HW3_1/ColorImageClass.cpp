#include<iostream>
#include<fstream>
#include<string>
#include"Constant.h"
#include"ColorClass.h"
#include"ColorImageClass.h"
#include"RectangleClass.h"
#include"RowColumnClass.h"

using namespace std;

//constructor and destructor
ColorImageClass::ColorImageClass(){
    pixel1DArray = 0;
}
ColorImageClass::~ColorImageClass(){
    delete[] pixel1DArray;
    pixel1DArray = 0;
}
//get the private member
ColorClass* ColorImageClass::getPtr(){
    return pixel1DArray;
}
int ColorImageClass::getWidth(){
    return width_;
}
int ColorImageClass::getHeight(){
    return height_;
}
int ColorImageClass::getPixel(){
    return pixel_color_;
}
string ColorImageClass::getMagicNumber(){
    return magic_number_;
}
//check whether the image is valid
bool ColorImageClass::checkImage(string imgName, int &width, int &height){
    bool validInput;
    ifstream imgFile;
    
    imgFile.open(imgName.c_str());
    if(imgFile.fail()){
        cout << "ERROR! Unable to open image file!" << endl;
        return false;
    }
    //file is opened

    //check the first three rows
    else{
        //Step 1: check magic number
        validInput = false;
        while(!validInput){
            imgFile >> magic_number_;
            if (imgFile.eof()){
                cout << "ERROR before reading magic number: P3!" << endl;
                return false;
            }
            else if (magic_number_ != "P3"){
                cout << "File does not begin with magic number: P3!" << endl;
                return false;
            }
            else{
                validInput = true;
            }
        }

        //Step 2: check width and height
        validInput = false;
        while(!validInput){
            imgFile >> width_ >> height_;
            if (imgFile.eof()){
                cout << "EOF before reading image width and height!" << endl;
                return false;
            }
            else if (width_ < DIMENSION_MIN || height_ < DIMENSION_MIN){
                cout << "Dimension of the image is smaller than 0!" << endl;
                return false;
            }
            else{
                validInput = true;
                width = width_;
                height = height_;
            }
        }
        
        //Step 3: check pixel
        validInput = false;
        while(!validInput){
            imgFile >> pixel_color_;
            if(imgFile.eof()){
                cout << "EOF before maximum color!" << endl;
                return false;
            }
            else if (pixel_color_ > COLOR_MAX || pixel_color_ < COLOR_MIN){
                cout << "Maximum Image color must be 0-255!" << endl;
                return false;
            }
            else{
                validInput = true;
            }
        }
        
        pixel1DArray = new ColorClass[width_ * height_];
        int pixel1DIndex = 0;
        int red, green, blue;
        string temp;

        //load the image
        while(!imgFile.eof()){
            for(int i = 0; i < height_; i++){
                for(int j = 0; j < width_; j++){
                    pixel1DIndex = i * width_ + j;
                    
                    imgFile >> red >> green >> blue;
                    if(imgFile.fail()){
                        cout << "ERROR! Pixel value are not valid!" << endl;
                        return false;
                    }
                    if(pixel1DArray[pixel1DIndex].readPixel(red, green, blue, 
                                                            pixel_color_)){
                        cout << "";
                    }
                    else {
                        imgFile.close();
                        cout << "ERROR! RGB value exceeds the color range!";
                        cout << endl;
                        return false;
                    }
                }
            }
            imgFile >> temp;
            if (temp != "") {
                imgFile.close();
                cout << "ERROR! Number of pixels doesn't match the dimension!";
                cout << endl;
                return false;
            }
        }
        //after checking all the values, return true
        return true;
    }
}
//Add rectangle to the image
void ColorImageClass::addRectangle(RectangleClass &rect, bool filled){
    int rectIndex;
    int rectStartRow, rectStartCol, rectEndRow, rectEndCol;
    rectStartRow = rect.getStartPoint().getRow();
    rectStartCol = rect.getStartPoint().getCol();
    rectEndRow = rect.getEndPoint().getRow();
    rectEndCol = rect.getEndPoint().getCol();
    //1 - not fill the rectangle
    if(filled == false) {
        //Set the color of left and right col
        for(int i = (rectStartRow - 1); i < rectEndRow; i++) {
            //left col
            rectIndex = i * width_ + (rectStartCol - 1);
            pixel1DArray[rectIndex].setTo(rect.getColor());
            //right col
            rectIndex = i * width_ + (rectEndCol - 1);
            pixel1DArray[rectIndex].setTo(rect.getColor());
        }
        //Set the color of upper and lower row
        for(int j = (rectStartCol - 1); j < rectEndCol; j++) {
            //upper row
            rectIndex = (rectStartRow - 1) * width_ + j;
            pixel1DArray[rectIndex].setTo(rect.getColor());
            //lower row
            rectIndex = (rectEndRow - 1) * width_ + j;
            pixel1DArray[rectIndex].setTo(rect.getColor());
        }
    }
    //2 - fill the rectangle, two for loops
    if(filled == true) {
        for(int i = (rectStartRow - 1); i < rectEndRow; i++) {
            for(int j = (rectStartCol - 1); j < rectEndCol; j++) {
                rectIndex = i * width_ + j;
                pixel1DArray[rectIndex].setTo(rect.getColor());
            }
        }
    }
}

void ColorImageClass::addPattern(PatternClass &ptn, int pRowStart, 
                                 int pColStart){
    int ptnIndex;
    int patternIndex;
    for (int i = 0; i < ptn.getHeight(); i++) {
        for (int j = 0; j < ptn.getWidth(); j++) {
            ptnIndex = i * ptn.getWidth() + j;
            if ((ptn.getPtr() + ptnIndex)->getPixelPattern() == true){
                //Set the pixel to rectangle color
                patternIndex = (pRowStart + i - 1) * width_ + 
                               (pColStart + j - 1);
                pixel1DArray[patternIndex].setTo(ptn.getPatternColor());
            }
        }
    }
}
void ColorImageClass::addImage(ColorImageClass &img, int iRowStart, 
                               int iColStart) {
    int imgIndex;
    int imageIndex;
    for (int i = 0; i < img.height_; i++) {
        for (int j = 0; j < img.width_; j++) {
            imgIndex = i * img.width_ + j;
            //Replace the pixel color if different from transparency color
            if (!(img.getPtr() + imgIndex)->checkSameColor(img.transparency_)){
                imageIndex = (iRowStart + i - 1) * width_ + 
                             (iColStart + j - 1);
                pixel1DArray[imageIndex].setTo(*(img.getPtr() + imgIndex));
            }
        }
    }
}

void ColorImageClass::setTransparency(int colorChoice) {
        if(colorChoice == ALL_RED){
            transparency_.setToRed();
        }
        else if(colorChoice == ALL_GREEN){
            transparency_.setToGreen();
        }
        else if(colorChoice == ALL_BLUE){
            transparency_.setToBlue();
        }
        else if(colorChoice == ALL_BLACK){
            transparency_.setToBlack();
        }
        else if(colorChoice == ALL_WHITE){
            transparency_.setToWhite();
        }
    }

