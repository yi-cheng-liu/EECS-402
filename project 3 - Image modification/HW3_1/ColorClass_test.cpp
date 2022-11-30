#include<iostream>
#include<string>
#include"ColorClass.h"

using namespace std;

int main(){
    ColorClass num1;
    num1.setTo(12, 13, 15);
    cout << num1.getBlueval() << endl;
    cout << num1.getRedval() << endl;
    cout << num1.getGreenval() << endl;

    cout << "nothing" << endl;
    return 0;
}
