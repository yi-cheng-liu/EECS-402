#include <iostream>
#include <fstream>
#include <string> 
#include "Constant.h" 
#include "RectangleClass.h" 
#include "PatternClass.h" 
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "MainMenu.h"

using namespace std;

int main(){
    string input;
    int uploadWidth, uploadHeight;
    ColorImageClass uploadPhoto;
    ColorClass color;

    cout << "Enter string for PPM image file name to load: ";
    std::cin >> input;
    
    //The image is valid, runs the main menu
    if(uploadPhoto.checkImage(input, uploadWidth, uploadHeight)){
        RowColumnClass upLeft, lowRight;
        int operation = 0;

        //Keep runing the main menu until exit
        while(operation != MAIN_EXIT){
            operation = mainMenu();

            //1 - Annotate image with rectangle
            if(operation == MAIN_RECT){
                //RESUBMISSION CODE
                //Print out the rectangle menu
                int rectChoice;
                bool validRectInput = false;
                cout << "1. Specify upper left and ";
                cout << "lower right corners of rectangle" << endl;
                cout << "2. Specify upper left corner and ";
                cout << "dimensions of rectangle" << endl;
                cout << "3. Specify extent from center of rectangle" << endl;
                cout << "Enter int for rectangle specification method: ";
                //Error checking - fail-state, unvalid number
                while (!validRectInput) {
                    std::cin >> rectChoice;
                    if (std::cin.fail() || rectChoice > RECT_MENU_MAX || 
                        rectChoice < MENU_MIN) {
                        std::cin.clear();
                        std::cin.ignore(IGNORE_LENGTH, '\n');
                        cout << "ERROR! Enter valid number from 1-3!" << endl;
                        cout << endl;
                        cout << "1. Specify upper left and ";
                        cout <<"lower right corners of rectangle" << endl;
                        cout << "2. Specify upper left corner and ";
                        cout << "dimensions of rectangle" << endl;
                        cout << "3. Specify extent from center of rectangle";
                        cout << endl;
                        cout << "Enter int for rectangle ";
                        cout << "specification method: ";
                    }
                    else{
                        validRectInput = true;
                    }
                }

                bool validRect = false;
                int upLeftRow, upLeftCol, lowRightRow, lowRightCol, row ,col;
                upLeftRow = upLeftCol = lowRightRow = lowRightCol = 0;
                row = col = 0;
                //1 - upper left and lower right
                if(rectChoice == RECT_FIRST){
                    cout << "Enter upper left corner row and column: ";
                    std::cin >> upLeftRow >> upLeftCol;
                    //Error checking - upLeft row/col is smaller than image
                    if(std::cin.fail() || upLeftRow < IMAGE_MIN ||
                       upLeftCol < IMAGE_MIN){
                        cout << "Error! Enter valid integer for upper left!";
                        cout << endl;
                        
                    }
                    //Error checking - upLeft row/col is larger than image
                    else if(upLeftCol > uploadWidth || 
                            upLeftRow > uploadHeight){
                        cout << "ERROR! The rectangle ";
                        cout << "will be out of bound!" << endl;
                    }
                    //upLeft is valid, check lowRight
                    else{
                        cout << "Enter lower right corner row and column: ";
                        std::cin >> lowRightRow >> lowRightCol;
                        //Error checking
                        //lowRight row/col is smaller than image
                        //lowRight row/col is smaller than upLeft row/col
                        if(std::cin.fail() || lowRightRow < IMAGE_MIN ||
                        lowRightCol < IMAGE_MIN ||
                        lowRightRow < upLeftRow ||
                        lowRightCol < upLeftCol){
                            cout << "Error! Enter valid integer ";
                            cout << "for lower right!" << endl;
                        }
                        //Error checking
                        //lowRight row/col is larger than image
                        else if(lowRightCol >= uploadWidth || 
                                lowRightRow >= uploadHeight ){
                            cout << "ERROR! The rectangle ";
                            cout << "will be out of bound!" << endl;
                        }
                        else{
                            upLeft.setRowCol(upLeftRow, upLeftCol);
                            lowRight.setRowCol(lowRightRow, lowRightCol);
                            //the rectangle is valid for writing
                            validRect = true; 
                        }
                    }
                }

                //2 - upper left with row and column
                else if(rectChoice == RECT_SECOND){
                    cout << "Enter upper left corner row and column: ";
                    std::cin >> upLeftRow >> upLeftCol;
                    //Error checking - upLeft row/col is smaller than image
                    if(std::cin.fail()|| upLeftRow < IMAGE_MIN ||
                       upLeftCol < IMAGE_MIN){
                        cout << "Error! Enter valid integer for upper left!";
                        cout << endl;
                    }
                    //upper left is valid, check lower right
                    else{
                        cout << "Enter int for number of rows: ";
                        std::cin >> row;
                        //RESUBMISSION CODE
                        if(std::cin.fail() || row < ROW_COL_MIN){
                            cout << "Error! Enter valid integer ";
                            cout << "for number of rows!" << endl;
                        }
                        //Error checking - lowRight row is larger than image
                        else if(upLeftRow + row > uploadHeight){
                            cout << "ERROR! The rectangle height ";
                            cout << "will be out of bound!" << endl;
                        }
                        else{
                            cout << "Enter int for number of columns: ";
                            std::cin >> col;
                            if(std::cin.fail() || col < ROW_COL_MIN){
                                cout << "Error! Enter valid integer ";
                                cout << "for number of columns!" << endl;
                            }
                            //Error checking
                            //lowRight col is larger than image
                            else if(upLeftCol + col > uploadWidth){
                                cout << "ERROR! The rectangle width ";
                                cout << "will be out of bound!" << endl;
                            }
                            else{
                                lowRightRow = upLeftRow + row - 1;
                                lowRightCol = upLeftCol + col - 1;
                                upLeft.setRowCol(upLeftRow, upLeftCol);
                                lowRight.setRowCol(lowRightRow, lowRightCol);
                                //the rectangle is valid for writing
                                validRect = true;
                            }
                        }
                    }
                }
                
                //3 - rectangle center
                else{
                    int centerRow, centerCol, row, col;
                    centerRow = centerCol = row = col = 0;
                    cout << "Enter rectangle center row and column: ";
                    std::cin >> centerRow >> centerCol;
                    //Error checking
                    //center row/col is smaller/larger than image
                    if(std::cin.fail() || centerRow < IMAGE_MIN ||
                       centerCol < IMAGE_MIN || 
                       centerRow > uploadHeight ||
                       centerCol > uploadWidth){
                        cout << "Error! Enter valid integer for center!";
                        cout << endl;
                    }
                    else{
                        cout << "Enter int for half number of rows: ";
                        std::cin >> row;
                        //RESUBMISSION CODE
                        if(std::cin.fail() || row < ROW_COL_MIN){
                            cout << "Error! Enter valid integer for number";
                            cout << " of rows!\n";
                        }
                        //Error checking
                        //left/right row is smaller/larger than image
                        else if(centerRow - row < IMAGE_MIN || 
                                centerRow + row >= uploadHeight){
                            cout << "ERROR! The rectangle height ";
                            cout << "will be out of bound!" << endl;
                        }
                        else{
                            cout << "Enter int for half number of columns: ";
                            std::cin >> col;
                            if(std::cin.fail() || col < ROW_COL_MIN){
                                cout << "Error! Enter valid integer for ";
                                cout << "number of columns!\n";
                            }
                            //Error checking
                            //left/right col is smaller/larger than image
                            else if(centerCol - col < IMAGE_MIN || 
                                    centerCol + col >= uploadWidth){
                                cout << "ERROR! The rectangle width ";
                                cout << "will be out of bound!" << endl;
                            }
                            else{
                                upLeftRow = centerRow - row;
                                upLeftCol = centerCol - col;
                                lowRightRow = centerRow + row;
                                lowRightCol = centerCol + col;
                                upLeft.setRowCol(upLeftRow, upLeftCol);
                                lowRight.setRowCol(lowRightRow, lowRightCol);
                                //the rectangle is valid for writing
                                validRect = true;
                            }
                        }
                    }
                }
                
                //start the colorMenu and fillMenu
                if(validRect){
                    //Color menu
                    int colorChoice;
                    int fillOrNot;
                    bool validColorInput = false;
                    cout << "1. Red" << endl;
                    cout << "2. Green" << endl;
                    cout << "3. Blue" << endl;
                    cout << "4. Black" << endl;
                    cout << "5. White" << endl;
                    cout << "Enter int for rectangle color: ";
                    while (!validColorInput) {
                        std::cin >> colorChoice;
                        if (std::cin.fail() || colorChoice > COLOR_MENU_MAX || 
                            colorChoice < MENU_MIN) {
                            std::cin.clear();
                            std::cin.ignore(IGNORE_LENGTH, '\n');
                            cout << "ERROR! Enter valid number from 1-5!\n";
                            cout << "1. Red" << endl;
                            cout << "2. Green" << endl;
                            cout << "3. Blue" << endl;
                            cout << "4. Black" << endl;
                            cout << "5. White" << endl;
                            cout << "Enter int for rectangle color: ";
                        }
                        else {
                            validColorInput = true;
                        }
                    }
                    
                    //setup the rectangle
                    RectangleClass Rectangle(upLeft, lowRight);
                    Rectangle.setRectColor(colorChoice);

                    //Fill Menu
                    bool validFillInput = false;
                    cout << "1. No" << endl;
                    cout << "2. Yes" << endl;
                    cout << "Enter int for rectangle fill option: ";
                    while (!validFillInput) {
                        std::cin >> fillOrNot;
                        if (std::cin.fail() || fillOrNot > FILL_MENU_MAX || 
                            fillOrNot < MENU_MIN) {
                            std::cin.clear();
                            std::cin.ignore(IGNORE_LENGTH, '\n');
                            cout << "ERROR! Enter valid number from 1-2!\n";
                            cout << "1. No" << endl;
                            cout << "2. Yes" << endl;
                            cout << "Enter int for rectangle fill option: ";
                        }
                        else {
                            validFillInput = true;
                        }
                    }
                    //1 - not fill
                    if(fillOrNot == 1){
                        uploadPhoto.addRectangle(Rectangle, false);
                    }
                    //2 - fill
                    else{
                        uploadPhoto.addRectangle(Rectangle, true);
                    }
                }
            }

            //2 - Annotate image with pattern from file
            else if(operation == MAIN_PATTERN){
                string patternName;
                int patternStartRow, patternStartCol;
                PatternClass insertPattern;
                int insertWidth, insertHeight;
                bool validPatternInput = false;
                cout << "Enter string for file name containing pattern: ";
                while (!validPatternInput) {
                    cin >> patternName;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(IGNORE_LENGTH, '\n');
                        cout << "ERROR! Enter valid pattern!\n";
                        cout << "Enter string for file name ";
                        cout << "containing pattern: ";
                    }
                    else {
                        validPatternInput = true;
                    }
                }
                //Error checking - check pattern will out of bound
                if(insertPattern.checkPattern(patternName, insertWidth, 
                                              insertHeight)){
                    cout << "Enter upper left corner of ";
                    cout << "pattern row and column: ";
                    std::cin >> patternStartRow >> patternStartCol;
                    if(std::cin.fail() || patternStartRow < IMAGE_MIN || 
                       patternStartCol < IMAGE_MIN){
                        cout << "Error! Enter valid row and column! " << endl;
                    }
                    //RESUBMISSION CODE
                    else if(insertWidth + patternStartCol -1 >= uploadWidth || 
                            insertHeight + patternStartRow -1 >= uploadHeight){
                        cout << "ERROR! The insert pattern will be ";
                        cout << "out of bound!" << endl;
                    }
                    else{
                        //RESUBMISSION CODE
                        //color menu
                        int patternColorChoice;
                        bool validPatternColorInput = false;
                        cout << "1. Red" << endl;
                        cout << "2. Green" << endl;
                        cout << "3. Blue" << endl;
                        cout << "4. Black" << endl;
                        cout << "5. White" << endl;
                        cout << "Enter int for pattern color: ";
                        while (!validPatternColorInput) {
                            std::cin >> patternColorChoice;
                            if (std::cin.fail() || 
                                patternColorChoice > COLOR_MENU_MAX || 
                                patternColorChoice < MENU_MIN) {
                                std::cin.clear();
                                std::cin.ignore(IGNORE_LENGTH, '\n');
                                cout << "ERROR! Enter valid number from 1-5!\n";
                                cout << "1. Red" << endl;
                                cout << "2. Green" << endl;
                                cout << "3. Blue" << endl;
                                cout << "4. Black" << endl;
                                cout << "5. White" << endl;
                                cout << "Enter int for pattern color: ";
                            }
                            else {
                                validPatternColorInput = true;
                            }
                        }
                        //set the color of the pattern and add into the photo
                        insertPattern.setPatternColor(patternColorChoice);
                        uploadPhoto.addPattern(insertPattern, patternStartRow, 
                                               patternStartCol);
                    }
                }
                else{
                    cout << "ERROR! Please check the pattern file!" << endl;
                }
            }
            
            //3 - Insert another image
            else if(operation == MAIN_IMAGE){
                //image menu
                string imgName;
                bool validImageInput = false;
                cout << "Enter string for file name of PPM image to insert: ";
                while (!validImageInput) {
                    std::cin >> imgName;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(IGNORE_LENGTH, '\n');
                        cout << "ERROR! Enter valid image!\n";
                        cout << "Enter string for file name of PPM image to insert: ";
                    }
                    else {
                        validImageInput = true;
                    }
                }

                ColorImageClass inertImage;
                int imgStartRow, imgStartCol;
                int insertWidth, insertHeight; 
                if(inertImage.checkImage(imgName, insertWidth, insertHeight)){
                    cout << "Enter upper left corner to insert ";
                    cout << "image row and column: ";
                    std::cin >> imgStartRow >> imgStartCol;
                    if(std::cin.fail() || imgStartRow < IMAGE_MIN || 
                       imgStartCol < IMAGE_MIN){
                        cout << "Error! Enter valid row and column! " << endl;
                    }
                    else if(insertWidth + imgStartCol - 1 >= uploadWidth || 
                            insertHeight + imgStartRow - 1 >= uploadHeight){
                        cout << "ERROR! The insert image will be ";
                        cout << "out of bound!" << endl;
                    }
                    else{
                        //RESUBMISSION CODE
                        //transparency menu
                        int transChoice;
                        bool validTransInput = false;
                        cout << "1. Red" << endl;
                        cout << "2. Green" << endl;
                        cout << "3. Blue" << endl;
                        cout << "4. Black" << endl;
                        cout << "5. White" << endl;
                        cout << "Enter int for transparecy color: ";
                        while (!validTransInput) {
                            std::cin >> transChoice;
                            if (std::cin.fail() || 
                                transChoice > COLOR_MENU_MAX || 
                                transChoice < MENU_MIN) {
                                std::cin.clear();
                                std::cin.ignore(IGNORE_LENGTH, '\n');
                                cout << "ERROR! Enter valid number from 1-5!";
                                cout << endl;
                                cout << "1. Red" << endl;
                                cout << "2. Green" << endl;
                                cout << "3. Blue" << endl;
                                cout << "4. Black" << endl;
                                cout << "5. White" << endl;
                                cout << "Enter int for transparecy color: ";
                            }
                            else {
                                validTransInput = true;
                            }
                        }
                        uploadPhoto.setTransparency(transChoice);
                        uploadPhoto.addImage(inertImage, imgStartRow, 
                                             imgStartCol);
                        
                    }
                }
                else {
                    cout << "ERROR! Please check the image file!" << endl;
                }
            }
            
            //4 - Write out current image
            else if(operation == MAIN_WRITE){
                string output;
                cout << "Enter string for PPM file name to output: ";
                std::cin >> output;
                ofstream outputFile;
                outputFile.open(output.c_str());
                if(outputFile.fail()){
                    cout << "Fail to write the file!" << endl;
                }
                else{
                    //RESUBMISSION CODE
                    uploadPhoto.writeImage(outputFile);
                }
                outputFile.close();
            }
            std::cin.clear();
            std::cin.ignore(IGNORE_LENGTH, '\n');
        }

        //5 - Exit the program
        cout << "Thank you for using this program";
    }

    //The image is invalid, terminates the program
    else{
        cout << "Error! Problems with image! Program terminates!" << endl;
    }
}
