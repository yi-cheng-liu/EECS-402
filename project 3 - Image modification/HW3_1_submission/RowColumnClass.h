#ifndef _ROWCOLUMN_CLASS_H_
#define _ROWCOLUMN_CLASS_H_

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
};

#endif