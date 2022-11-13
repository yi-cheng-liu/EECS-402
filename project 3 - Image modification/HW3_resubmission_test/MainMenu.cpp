#include <iostream>
#include <string>
#include "MainMenu.h"
#include "Constant.h"

using namespace std;

//RESUBMISSION CODE
int mainMenu() {
    int choice;
    bool validInput = false;
    cout << "1. Annotate image with rectangle" << endl;
    cout << "2. Annotate image with pattern from file" << endl;
    cout << "3. Insert another image" << endl;
    cout << "4. Write out current image" << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter int for main menu choice: ";
    while (!validInput) {
        cin >> choice;
        if (cin.fail() || choice > MAIN_MENU_MAX || choice < MENU_MIN) {
            cin.clear();
            cin.ignore(IGNORE_LENGTH, '\n');
            cout << "ERROR! Enter valid number from 1-5!\n" << endl;
            cout << "1. Annotate image with rectangle" << endl;
            cout << "2. Annotate image with pattern from file" << endl;
            cout << "3. Insert another image" << endl;
            cout << "4. Write out current image" << endl;
            cout << "5. Exit the program" << endl;
            cout << "Enter int for main menu choice: ";
        }
        else {
            validInput = true;
        }
    }
    return choice;
}