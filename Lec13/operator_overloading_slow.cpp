#include <iostream>
using namespace std;


class ChangePocketClass {
public:
    //default constructor
    ChangePocketClass():quarters(0),dimes(0) {}
    //parameterized constructor
    ChangePocketClass(int q, int d): quarters(q), dimes(d){}
    //Copy constructor–called when a copy of an object is needed
    ChangePocketClass(const ChangePocketClass &copy){
        quarters = copy.quarters;
        dimes = copy.dimes; 
    }
    //Assignment operator–called when one object is assigned to another 
    //using a copy constructor everytime
    void operator=(const ChangePocketClass rhs) {
        quarters = rhs.quarters;
        dimes = rhs.dimes; 
    }
    //+operator overloading
    //using a copy constructor everytime
    ChangePocketClass operator+(const ChangePocketClass in) {
        ChangePocketClass result;
        result.quarters = quarters + in.quarters; 
        result.dimes = dimes + in.dimes;
        return result;
    }
    //other member function
    void setQuarters(int val) {
        quarters = val; 
    }
    void setDimes(int val) {
        dimes = val; 
    }
    int getQuarters() {
        return quarters; 
    }
    int getDimes() {
        return dimes; 
    }
private:
    int quarters;
    int dimes;
};

int main(){
    ChangePocketClass c1; 
    ChangePocketClass c2; 
    ChangePocketClass c3; 
    c1.setQuarters(5); 
    c1.setDimes(7); 
    c2.setQuarters(3); 
    c2.setDimes(8);

    c3 = c1 + c2;
    
    cout << "c1 q: " << c1.getQuarters() << " d: " << c1.getDimes() << endl; 
    cout << "c2 q: " << c2.getQuarters() << " d: " << c2.getDimes() << endl; 
    cout << "c3 q: " << c3.getQuarters() << " d: " << c3.getDimes() << endl;
    return 0;
}