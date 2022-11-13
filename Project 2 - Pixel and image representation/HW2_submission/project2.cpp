//Name: YI-CHENG, LIU (uniquename: liuyiche)
//Date: 27-30/09/2022
//Purpose: use OOP to develop classes for colors and images representation

#include<iostream>
#include<cmath>

using namespace std;

//parameters ColorClass
const int COLOR_UPPER_LIMIT = 1000;
const int COLOR_LOWER_LIMIT = 0;
//parameters for RowColumnClass
const int DEFAULT_ROW_COLUMN_VALUE = -99999;
//parameters for ColorImageClass
const int ROW_SIZE = 10;
const int COLUMN_SIZE = 18;
const int FIRST_COLUMN = 0;

//set the color, containing red, green, and blue
//use to decribing a color
class ColorClass{
    int amountRed;
    int amountGreen;
    int amountBlue;
    //assign a single color and check whether it clipped(true)
    int setToSingleColor(int color);
    //return true if clipped
    bool clipStatus(int color);
public:
    //default constructor - set color to white(all 1000)
    ColorClass();
    //parameterized constructor, check first then assign
    ColorClass(int inRed, int inGreen, int inBlue);
    //set to different colors
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    //assign the color with three amount and check whether in range
    bool setTo(int inRed, int inGreen, int inBlue);
    //set color amount same as the inColor object, 
    //color range already checked while construct or set value
    bool setTo(ColorClass &inColor);
    //add color and check whether in range
    bool addColor(ColorClass &rhs);
    //subtract color and check whether in range
    bool subtractColor(ColorClass &rhs); 
    //adjust the brightness according to the factor
    bool adjustBrightness(double adjFactor);
    //print out the values of the color
    void printComponentValues();    
};

//set the row, column
//use to identity a specific pixel in an image
class RowColumnClass{
    int row;
    int column;
public:
    //default constructor
    RowColumnClass();
    //parameterized constructor
    RowColumnClass(int inRow, int inCol);
    //set the row and column, or just the row or column
    void setRowCol(int inRow, int inCol);
    void setRow(int inRow);
    void setCol(int inCol);
    //get the row or column
    int getRow();
    int getCol();
    //add the row with inRowCol
    void addRowColTo(RowColumnClass &inRowCol);
    void printRowCol();
};

//set the image contained with color
//use to represent a small image
class ColorImageClass{
    ColorClass array2D[ROW_SIZE][COLUMN_SIZE];
    //check whether column or row in range
    bool checkInRange(RowColumnClass &inRowCol); 
public:
    //default constuctor and set size to (10, 18)
    ColorImageClass(); 
    //initilize all pixels to inColor
    void initializeTo(ColorClass &inColor); 
    //add the rhsImg to the color, and check whether clipped
    bool addImageTo(ColorImageClass &rhsImg); 
    //add the images together and return it without adding on to the original
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []); 
    //set the original color to inColor
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor); 
    //set the inColor to original color
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor); 
    //print out the full image
    void printImage(); 
};

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main(){
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];

    //Test some basic ColorClass operations...
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;
    testColor.setToBlack();
    cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;
    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();
    cout << endl;
    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;

    //Test some basic RowColumnClass operations...
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;
    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;
    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;
    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;

    //Test some basic ColorImageClass operations...
    testColor.setToRed();
    testImage.initializeTo(testColor);
    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor)){
        testColor.printComponentValues();
    }
    else{
        cout << "Invalid Index!";
    }
    cout << endl;
    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor)){
        testColor.printComponentValues();
    }
    else{
        cout << "Invalid Index!";
    }
    cout << endl;
    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);
    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);
    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);
    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages);
    //Check some certain values
    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2){
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor)){
            testColor.printComponentValues();
        }
        else{
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    for (int rowInd = 0; rowInd < 8; rowInd += 2){
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor)){
            testColor.printComponentValues();
        }
        else{
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    cout << "Printing entire test image:" << endl;
    testImage.printImage();
    return 0;
}

#endif

//ColorClass - member funtion implementation
//default constructor - set color to white(all 1000)
ColorClass::ColorClass(){
    amountRed = COLOR_UPPER_LIMIT;
    amountGreen = COLOR_UPPER_LIMIT;
    amountBlue = COLOR_UPPER_LIMIT;
};
//parameterized constructor, check first then assign
ColorClass::ColorClass(int inRed, int inGreen, int inBlue){
    //check the red color
    if (inRed > COLOR_UPPER_LIMIT) {
        amountRed = COLOR_UPPER_LIMIT;
    }
    else if (inRed < COLOR_LOWER_LIMIT) {
        amountRed = COLOR_LOWER_LIMIT;
    }
    else {
        amountRed = inRed;
    }
    //check the green color
    if (inGreen > COLOR_UPPER_LIMIT) {
        amountGreen = COLOR_UPPER_LIMIT;
    }
    else if (inGreen < COLOR_LOWER_LIMIT) {
        amountGreen = COLOR_LOWER_LIMIT;
    }
    else {
        amountGreen = inGreen;
    }
    //check the blue color
    if (inBlue > COLOR_UPPER_LIMIT) {
        amountBlue = COLOR_UPPER_LIMIT;
    }
    else if (inBlue < COLOR_LOWER_LIMIT) {
        amountBlue = COLOR_LOWER_LIMIT;
    }
    else {
        amountBlue = inBlue;
    }
};
//set to different colors
void ColorClass::setToBlack(){
    amountRed = COLOR_LOWER_LIMIT;
    amountGreen = COLOR_LOWER_LIMIT;
    amountBlue = COLOR_LOWER_LIMIT;
};
void ColorClass::setToRed(){
    amountRed = COLOR_UPPER_LIMIT;
    amountGreen = COLOR_LOWER_LIMIT;
    amountBlue = COLOR_LOWER_LIMIT;
};
void ColorClass::setToGreen(){
    amountRed = COLOR_LOWER_LIMIT;
    amountGreen = COLOR_UPPER_LIMIT;
    amountBlue = COLOR_LOWER_LIMIT;
};
void ColorClass::setToBlue(){
    amountRed = COLOR_LOWER_LIMIT;
    amountGreen = COLOR_LOWER_LIMIT;
    amountBlue = COLOR_UPPER_LIMIT;
};
void ColorClass::setToWhite(){
    amountRed = COLOR_UPPER_LIMIT;
    amountGreen = COLOR_UPPER_LIMIT;
    amountBlue = COLOR_UPPER_LIMIT;
};
//return true if clipped
bool ColorClass::clipStatus(int color){
    if ((color > COLOR_UPPER_LIMIT) || (color < COLOR_LOWER_LIMIT)) {
        return true; //clipped
    }
    return false; //no clipped
}
//assign a single color and check whether it clipped(true)
int ColorClass::setToSingleColor(int color){
    if(color > COLOR_UPPER_LIMIT){
        return COLOR_UPPER_LIMIT;
    }
    else if(color < COLOR_LOWER_LIMIT){
        return COLOR_LOWER_LIMIT;
    }
    return color;
};
//assign the color with three amount and check whether in range
bool ColorClass::setTo(int inRed, int inGreen, int inBlue){
    amountRed = setToSingleColor(inRed);
    amountGreen = setToSingleColor(inGreen);
    amountBlue = setToSingleColor(inBlue);
    //more than one color clipped, return true
    if(clipStatus(inRed) || clipStatus(inGreen) || clipStatus(inBlue)){
        return true;
    }
    //no clipped, return false
    else {
        return false;
    }
};
//set color amount same as the inColor object, 
//color range already checked while construct or set value
bool ColorClass::setTo(ColorClass &inColor){
    this->amountRed = inColor.amountRed;
    this->amountGreen = inColor.amountGreen;
    this->amountBlue = inColor.amountBlue;
    return 0;
};
//add color and check whether in range
bool ColorClass::addColor(ColorClass &rhs){
    return setTo(amountRed + rhs.amountRed, 
                 amountGreen + rhs.amountGreen, 
                 amountBlue + rhs.amountBlue);
};
//subtract color and check whether in range
bool ColorClass::subtractColor(ColorClass &rhs){
    return setTo(amountRed - rhs.amountRed, 
                 amountGreen - rhs.amountGreen, 
                 amountBlue - rhs.amountBlue);
}; 
//adjust the brightness according to the factor
bool ColorClass::adjustBrightness(double adjFactor){
    return setTo(amountRed * adjFactor, 
                 amountGreen * adjFactor, 
                 amountBlue * adjFactor);
};
//print out the values of the color
void ColorClass::printComponentValues(){
    cout << "R: " << amountRed 
         << " G: " << amountGreen 
         << " B: " << amountBlue;
};

//RowColumnClass - member function implementation
//default constructor
RowColumnClass::RowColumnClass(){
    row = DEFAULT_ROW_COLUMN_VALUE;
    column = DEFAULT_ROW_COLUMN_VALUE;
}
//parameterized constructor
RowColumnClass::RowColumnClass(int inRow, int inCol){
    row = inRow;
    column = inCol;
}
//set the row and column, or just the row or column
void RowColumnClass::setRowCol(int inRow, int inCol){
    row = inRow;
    column = inCol;
};
void RowColumnClass::setRow(int inRow){
    row = inRow;
};
void RowColumnClass::setCol(int inCol){
    column = inCol;
};
//get the row or column
int RowColumnClass::getRow(){
    return row;
};
int RowColumnClass::getCol(){
    return column;
};
//add the row with inRowCol
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol){
    this->row += inRowCol.row;
    this->column += inRowCol.column;
};
void RowColumnClass::printRowCol(){
    cout << "[" << row << "," << column << "]";
};

//ColorImageClass - member function implementation
//default constuctor and set size to (10, 18)
ColorImageClass::ColorImageClass(){
    for(int i = 0; i < ROW_SIZE; i++){
        for(int j = 0; j < COLUMN_SIZE; j++){
            array2D[i][j].setToBlack();
        }
    }
}; 
//initilize all pixels to inColor
void ColorImageClass::initializeTo(ColorClass &inColor){
    for(int i = 0; i < ROW_SIZE; i++){
        for(int j = 0; j < COLUMN_SIZE; j++){
            array2D[i][j].setTo(inColor);
        }
    }
};
//add the rhsImg to the color, and check whether clipped
bool ColorImageClass::addImageTo(ColorImageClass &rhsImg){
    //set the clip status as false
    bool clipped = false;
    for(int i = 0; i < ROW_SIZE; i++){
        for(int j = 0; j < COLUMN_SIZE; j++){
            array2D[i][j].addColor(rhsImg.array2D[i][j]);
            clipped = true;
        }
    }
    //return the clipped status
    if(clipped){
        return true;
    }
    else{
        return false;
    }
};
//add the images together and return it without adding on to the original
bool ColorImageClass::addImages(int numImgsToAdd, 
                                ColorImageClass imagesToAdd []){
    //set the original colorImage to black
    ColorClass Initial;
    Initial.setToBlack();
    this->initializeTo(Initial);
    //set the clip status as false
    bool clipped = false;
    //iterate through the number of images which have to add together
    for(int i = 0; i < numImgsToAdd; i++){
        this->addImageTo(imagesToAdd[i]);
        clipped = true;
    }
    //return the clipped status
    if(clipped){
        return true;
    }
    else{
        return false;
    }
}; 
//check whether column or row in range
bool ColorImageClass::checkInRange(RowColumnClass &inRowCol){
    if(inRowCol.getRow() < 0 || inRowCol.getRow() >= ROW_SIZE - 1 ||
       inRowCol.getCol() < 0 || inRowCol.getCol() >= COLUMN_SIZE - 1){
        return false; //not in range
    }
    else{
        return true; //in range
    }
}
//set the original color to inColor
bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol, 
                                         ColorClass &inColor){
    if(checkInRange(inRowCol)){
        array2D[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
        return true;
    }
    else{
        return false;
    }
};
//set the inColor to original color
bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol, 
                                         ColorClass &outColor){
    if(checkInRange(inRowCol)){
        outColor.setTo(array2D[inRowCol.getRow()][inRowCol.getCol()]);
        return true;
    }
    else{
        return false;
    }
};
//print out the full image
void ColorImageClass::printImage(){
    for(int i = 0; i < ROW_SIZE; i++){
        for(int j = 0; j < COLUMN_SIZE; j++){
            //won't print out "--" in the first or last column of every row
            if(j != FIRST_COLUMN && j!= COLUMN_SIZE){
                cout << "--";
            }
            array2D[i][j].printComponentValues();
        }
        cout << endl;
    }
};