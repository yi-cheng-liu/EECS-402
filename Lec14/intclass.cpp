#include<iostream>

using namespaces std;
class IntClass{
private:
    int val; //The value of the integer
public:
    //Print out attrs of the object 
    void print() const{
        cout << "Val: " << val << endl; 
    }
    //Assign to an integer var 
    void operator=(int iVal){
        val = iVal; 
    }
    const IntClass operator-() const {
        IntClass retVal; 
        retVal.val = -val;
        return retVal;
    }
    //Prefix version (i.e. ++myObj) //increments the value first, and //the expression evaluates to the //incremented value
    const IntClass operator++() {
        IntClass retVal; val++;
        retVal.val = val; return retVal;
    }
//Negate operator. Note: this operator 
//has no "side-effects". In other 
//words, it doesn't change the object 
//is operating on.