#include <iostream>
#include <fstream>
#include <string> 
#include "Constant.h" //
#include "RectangleClass.h" //
#include "PatternClass.h" //
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "menu.h"

using namespace std;

int main(){
    string input;
    int uploadWidth, uploadHeight;
    ColorImageClass uploadPhoto;
    ColorClass color;

    cout << "Enter string for PPM image file name to load: ";
    cin >> input;
    
    //The image is valid, runs the main menu
    if(uploadPhoto.checkImage(input, uploadWidth, uploadHeight)){
        RowColumnClass upLeft, lowRight;
        int operation = 0;

        //Keep runing the main menu until exit
        while(operation != MAIN_EXIT){
            operation = mainMenu();

            //1 - Annotate image with rectangle
            if(operation == MAIN_RECT){
                int choice = rectMenu();
                bool validRect = false;
                int upLeftRow, upLeftCol, lowRightRow, lowRightCol, row ,col;
                upLeftRow = upLeftCol = lowRightRow = lowRightCol = 0;
                row = col = 0;

                //1 - upper left and lower right
                if(choice == RECT_FIRST){
                    cout << "Enter upper left corner row and column: ";
                    cin >> upLeftRow >> upLeftCol;
                    //Error checking - upLeft row/col is smaller than image
                    if(cin.fail() || upLeftRow < IMAGE_MIN ||
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
                        cin >> lowRightRow >> lowRightCol;
                        //Error checking
                        //lowRight row/col is smaller than image
                        //lowRight row/col is smaller than upLeft row/col
                        if(cin.fail() || lowRightRow < IMAGE_MIN ||
                        lowRightCol < IMAGE_MIN ||
                        lowRightRow < upLeftRow ||
                        lowRightCol < upLeftCol){
                            cout << "Error! Enter valid integer ";
                            cout << "for lower right!" << endl;
                        }
                        //Error checking
                        //lowRight row/col is larger than image
                        else if(lowRightCol > uploadWidth || 
                                lowRightRow > uploadHeight ){
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
                else if(choice == RECT_SECOND){
                    cout << "Enter upper left corner row and column: ";
                    cin >> upLeftRow >> upLeftCol;
                    //Error checking - upLeft row/col is smaller than image
                    if(cin.fail()|| upLeftRow < IMAGE_MIN ||
                       upLeftCol < IMAGE_MIN){
                        cout << "Error! Enter valid integer for upper left!";
                        cout << endl;
                    }
                    //upper left is valid, check lower right
                    else{
                        cout << "Enter int for number of rows: ";
                        cin >> row;
                        if(cin.fail()){
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
                            cin >> col;
                            if(cin.fail()){
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
                                lowRightRow = upLeftRow + row;
                                lowRightCol = upLeftCol + col;
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
                    cin >> centerRow >> centerCol;
                    //Error checking
                    //center row/col is smaller/larger than image
                    if(cin.fail() || centerRow < IMAGE_MIN ||
                       centerCol < IMAGE_MIN || 
                       centerRow > uploadHeight ||
                       centerCol > uploadWidth){
                        cout << "Error! Enter valid integer for center!" << endl;
                    }
                    else{
                        cout << "Enter int for half number of rows: ";
                        cin >> row;
                        if(cin.fail()){
                            cout << "Error! Enter valid integer for number of rows!\n";
                        }
                        //Error checking
                        //left/right row is smaller/larger than image
                        else if(centerRow - row < IMAGE_MIN || 
                                centerRow + row > uploadHeight){
                            cout << "ERROR! The rectangle height ";
                            cout << "will be out of bound!" << endl;
                        }
                        else{
                            cout << "Enter int for half number of columns: ";
                            cin >> col;
                            if(cin.fail()){
                                cout << "Error! Enter valid integer for number of columns!\n";
                            }
                            //Error checking
                            //left/right col is smaller/larger than image
                            else if(centerCol - col < IMAGE_MIN || 
                                    centerCol + col > uploadWidth){
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
                    colorChoice = colorMenu();
                    
                    //setup the rectangle
                    RectangleClass Rectangle(upLeft, lowRight);
                    Rectangle.setRectColor(colorChoice);

                    //Fill Menu
                    fillOrNot = fillMenu();
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
                int patternColor;
                patternName = patternMenu();
                PatternClass insertPattern;
                int insertWidth, insertHeight;

                if(insertPattern.checkPattern(patternName, insertWidth, 
                                              insertHeight)){
                    cout << "Enter upper left corner of ";
                    cout << "pattern row and column: ";
                    cin >> patternStartRow >> patternStartCol;
                    if(cin.fail()){
                        cout << "Error! Enter valid row and column! " << endl;
                    }
                    else if(insertWidth + patternStartRow > uploadWidth  || 
                            insertHeight + patternStartCol > uploadHeight){
                        cout << "ERROR! The insert image will be ";
                        cout << "out of bound!" << endl;
                    }
                    else{
                        patternColor = transMenu();
                        insertPattern.setPatternColor(patternColor);
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
                string imgName;
                int imgStartRow, imgStartCol;
                imgName = imageMenu();
                ColorImageClass inertImage;

                int insertWidth, insertHeight; 
                if(inertImage.checkImage(imgName, insertWidth, insertHeight)){
                    cout << "Enter upper left corner to insert ";
                    cout << "image row and column: ";
                    cin >> imgStartRow >> imgStartCol;
                    if(cin.fail() || imgStartRow < IMAGE_MIN || 
                       imgStartCol < IMAGE_MIN){
                        cout << "Error! Enter valid row and column! " << endl;
                    }
                    else if(insertWidth + imgStartRow > uploadWidth  || 
                            insertHeight + imgStartCol > uploadHeight ){
                        cout << "ERROR! The insert image will be ";
                        cout << "out of bound!" << endl;
                    }
                    else{
                        int transparency = transMenu();
                        uploadPhoto.addImage(inertImage, imgStartRow, 
                                             imgStartCol);
                        uploadPhoto.setTransparency(transparency);
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
                cin >> output;
                ofstream outputFile;
                outputFile.open(output.c_str());
                if(outputFile.fail()){
                    cout << "Fail to write the file!" << endl;
                }
                else{
                    outputFile << uploadPhoto.getMagicNumber() << " " << endl;
                    outputFile << uploadPhoto.getWidth() << " ";
                    outputFile << uploadPhoto.getHeight() << " " << endl;
                    outputFile << uploadPhoto.getPixel() << " " << endl;
                    int index = uploadPhoto.getWidth()*uploadPhoto.getHeight();
                    for(int i = 0; i < index; i++){
                        ColorClass* curPixelPtr = uploadPhoto.getPtr() + i;
                        outputFile << curPixelPtr->getRedval();
                        outputFile << " ";
                        outputFile << curPixelPtr->getGreenval();
                        outputFile << " ";
                        outputFile << curPixelPtr->getBlueval();
                        outputFile << " ";
                    }
                }
                outputFile.close();
            }
            cin.clear();
            cin.ignore(200, '\n');
        }

        //5 - Exit the program
        cout << "Thank you for using this program";
    }

    //The image is invalid, terminates the program
    else{
        cout << "Error! Problems with image! Program terminates!" << endl;
    }
}