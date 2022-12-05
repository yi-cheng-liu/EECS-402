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
int ColorImageClass::getWidth(){
    return width;
}
int ColorImageClass::getHeight(){
    return height;
}
int ColorImageClass::getPixel(){
    return pixelColor;
}
string ColorImageClass::getMagicNumber(){
    return magicNumber;
}
//check whether the image is valid
bool ColorImageClass::checkImage(string imgName, int &imgWidth, 
                                 int &imgHeight){
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
            imgFile >> magicNumber;
            if (imgFile.eof()){
                cout << "ERROR before reading magic number: P3!" << endl;
                return false;
            }
            else if (magicNumber != "P3"){
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
            imgFile >> width >> height;
            if (imgFile.eof()){
                cout << "EOF before reading image width and height!" << endl;
                return false;
            }
            else if (width < DIMENSION_MIN || height < DIMENSION_MIN){
                cout << "Dimension of the image is smaller than 0!" << endl;
                return false;
            }
            else{
                validInput = true;
                imgWidth = width;
                imgHeight = height;
            }
        }
        
        //Step 3: check pixel
        validInput = false;
        while(!validInput){
            imgFile >> pixelColor;
            if(imgFile.eof()){
                cout << "EOF before maximum color!" << endl;
                return false;
            }
            else if (pixelColor > COLOR_MAX || pixelColor < COLOR_MIN){
                cout << "Maximum Image color must be 0-255!" << endl;
                return false;
            }
            else{
                validInput = true;
            }
        }
        
        pixel1DArray = new ColorClass[width * height];
        int pixel1DIndex = 0;
        // int red, green, blue;
        string temp;

        //RESUBMISSION CODE
        //load the image
        while(!imgFile.eof()){
            for(int i = 0; i < height; i++){
                for(int j = 0; j < width; j++){
                    pixel1DIndex = i * width + j;
                    if(pixel1DArray[pixel1DIndex].readPixel(imgFile, 
                                                            pixelColor)){
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
void ColorImageClass::addRectangle(const RectangleClass &rect, bool isFilled){
    int rectIndex;
    int rectStartRow, rectStartCol, rectEndRow, rectEndCol;
    rectStartRow = rect.getStartPoint().getRow();
    rectStartCol = rect.getStartPoint().getCol();
    rectEndRow = rect.getEndPoint().getRow();
    rectEndCol = rect.getEndPoint().getCol();
    //1 - not fill the rectangle
    if(isFilled == false) {
        //Set the color of left and right col
        for(int i = (rectStartRow); i <= rectEndRow; i++) {
            //left col
            rectIndex = i * width + (rectStartCol);
            pixel1DArray[rectIndex].setTo(rect.getColor());
            //right col
            rectIndex = i * width + (rectEndCol);
            pixel1DArray[rectIndex].setTo(rect.getColor());
        }
        //Set the color of upper and lower row
        for(int j = (rectStartCol); j <= rectEndCol; j++) {
            //upper row
            rectIndex = (rectStartRow) * width + j;
            pixel1DArray[rectIndex].setTo(rect.getColor());
            //lower row
            rectIndex = (rectEndRow) * width + j;
            pixel1DArray[rectIndex].setTo(rect.getColor());
        }
    }
    //2 - fill the rectangle, two for loops
    if(isFilled == true) {
        for(int i = (rectStartRow); i <= rectEndRow; i++) {
            for(int j = (rectStartCol); j <= rectEndCol; j++) {
                rectIndex = i * width + j;
                pixel1DArray[rectIndex].setTo(rect.getColor());
            }
        }
    }
}
//Add pattern to the image
void ColorImageClass::addPattern(const PatternClass &ptn, int pRowStart, 
                                 int pColStart){
    
    for (int i = 0; i < ptn.getHeight(); i++) {
        for (int j = 0; j < ptn.getWidth(); j++) {
            //determine the pattern value
            if(ptn.getPixelValue(i, j)){
                int patternIndex = (pRowStart + i) * width + 
                                   (pColStart + j);
                pixel1DArray[patternIndex].setTo(ptn.getPatternColor());
            }
        }
    }
}
//Add image to the image
void ColorImageClass::addImage(const ColorImageClass &img, int iRowStart, 
                               int iColStart) {
    //RESUBMISSION CODE
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            //Replace the pixel color if different from transparency color
            int iRow = iRowStart + i;
            int iCol = iColStart + j;
            int imageIndex = iRow * width + iCol;            
            if(!img.getPixelValue(i, j).checkSameColor(transparency)) {    
                pixel1DArray[imageIndex].setTo(img.getPixelValue(i, j));
            }
        }
    }
}
//RESUBMISSION CODE
//get the value of the pixel
ColorClass ColorImageClass::getPixelValue(int i, int j) const{
    int pixelIndex = i * width + j;
    return pixel1DArray[pixelIndex];
}
//set transparency
void ColorImageClass::setTransparency(int colorChoice) {
        if(colorChoice == ALL_RED){
            transparency.setToRed();
        }
        else if(colorChoice == ALL_GREEN){
            transparency.setToGreen();
        }
        else if(colorChoice == ALL_BLUE){
            transparency.setToBlue();
        }
        else if(colorChoice == ALL_BLACK){
            transparency.setToBlack();
        }
        else if(colorChoice == ALL_WHITE){
            transparency.setToWhite();
        }
    }

//RESUBMISSION CODE
void ColorImageClass::writeImage(ofstream& outputFile){
    outputFile << this->getMagicNumber() << " " << endl;
    outputFile << this->getWidth() << " ";
    outputFile << this->getHeight() << " " << endl;
    outputFile << this->getPixel() << " " << endl;
    int totalIndex = this->getWidth() * this->getHeight();
    for(int i = 0; i < totalIndex; i++){
        pixel1DArray[i].writePixel(outputFile);
    }
}
