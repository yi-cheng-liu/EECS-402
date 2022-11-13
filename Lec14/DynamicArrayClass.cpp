#include <iostream>
using namespace std;

class DynAryClass{
private:
    int num;
    char *vals; //Will point to //array of chars
public:
    void setVals(char a, char b, char c){
        num = 3;
        vals = new char[num];
        vals[0] = a;
        vals[1] = b;
        vals[2] = c;
    }
    void setVals(char a, char b, char c, char d){
        num = 4;
        vals = new char[num]; 
        vals[0] = a;
        vals[1] = b;
        vals[2] = c;
        vals[3] = d;
    }
    void changeVal(int index, char c) {
        if (index >= 0 && index < num){
            vals[index] = c; 
        }
        else {
            std::cout << "Out of range" << std::endl; 
        }
    }
    void printInfo() const {
        int i;
        for (i = 0; i < num; i++){
            cout << vals[i];
        }
        cout << endl;
    }
};

int main() {
    //create two DynAryClass
    DynAryClass da1; 
    DynAryClass da2;
    da1.setVals('d', 'r', 'e', 'w'); 
    cout << "da1: "; 
    da1.printInfo();

    da2 = da1;
    cout << "da2 after assigning to da1: "; 
    da2.printInfo();
    
    cout << "Change da1 drew => draw" << endl; 
    da1.changeVal(2, 'a');
    cout << "da1: "; da1.printInfo(); cout << "da2: "; 
    da2.printInfo();
    return 0;
}
