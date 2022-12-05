#include<iostream>
#include"RowColumnClass.h"
#include"Constant.h"

using namespace std;

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