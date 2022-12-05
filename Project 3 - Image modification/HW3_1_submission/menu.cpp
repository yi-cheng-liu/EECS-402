#include <iostream>
#include<string>
#include "menu.h"
#include "Constant.h"

using namespace std;

void printMainMenu(){
    cout << "1. Annotate image with rectangle" << endl;
    cout << "2. Annotate image with pattern from file" << endl;
    cout << "3. Insert another image" << endl;
    cout << "4. Write out current image" << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter int for main menu choice: ";
};
void printRectMenu(){
    cout << "1. Specify upper left and lower right corners of rectangle" << endl;
    cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
    cout << "3. Specify extent from center of rectangle" << endl;
    cout << "Enter int for rectangle specification method: ";
}
void printColorMenu(){
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    cout << "Enter int for rectangle color: ";
}
void printFillMenu(){
    cout << "1. No" << endl;
    cout << "2. Yes" << endl;
    cout << "Enter int for rectangle fill option: ";
}
void printPatternMenu(){
    cout << "Enter string for file name containing pattern: ";
}
void printImageMenu(){
    cout << "Enter string for file name of PPM image to insert: ";
}
void printTransMenu(){
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    cout << "Enter int for transparecy color: ";
}

int mainMenu() {
    int choice;
    bool validInput = false;

    printMainMenu();

    while (!validInput) {
        cin >> choice;
        if (cin.fail() || choice > MAIN_MENU_MAX || choice < MENU_MIN) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid number from 1-5!\n" << endl;
            printMainMenu();
        }
        else {
            validInput = true;
        }
    }
    return choice;
}
int rectMenu() {
    int choice;
    bool validInput = false;

    printRectMenu();

    while (!validInput) {
        cin >> choice;
        if (cin.fail() || choice > RECT_MENU_MAX || choice < MENU_MIN) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid number from 1-3!\n" << endl;
            printRectMenu();
        }
        else{
            validInput = true;
        }
    }
    return choice;
}
int colorMenu() {
    int choice;
    bool validInput = false;

    printColorMenu();

    while (!validInput) {
        cin >> choice;
        if (cin.fail() || choice > COLOR_MENU_MAX || choice < MENU_MIN) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid number from 1-5!\n";
            printColorMenu();
        }
        else {
            validInput = true;
        }
    }
    return choice;
}
int fillMenu(){
    int choice;
    bool validInput = false;

    printFillMenu();

    while (!validInput) {
        cin >> choice;
        if (cin.fail() || choice > FILL_MENU_MAX || choice < MENU_MIN) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid number from 1-2!\n";
            printFillMenu();
        }
        else {
            validInput = true;
        }
    }
    return choice;
}
string patternMenu(){
    string pattern;
    bool validInput = false;

    printPatternMenu();

    while (!validInput) {
        cin >> pattern;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid pattern!\n";
            printPatternMenu();
        }
        else {
            validInput = true;
        }
    }
    return pattern;
}
string imageMenu(){
    string img;
    bool validInput = false;

    printImageMenu();

    while (!validInput) {
        cin >> img;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid image!\n";
            printImageMenu();
        }
        else {
            validInput = true;
        }
    }
    return img;
}
int transMenu() {
    int choice;
    bool validInput = false;

    printTransMenu();

    while (!validInput) {
        cin >> choice;
        if (cin.fail() || choice > COLOR_MENU_MAX || choice < MENU_MIN) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "ERROR! Enter valid number from 1-5!\n";
            printTransMenu();
        }
        else {
            validInput = true;
        }
    }
    return choice;
}
