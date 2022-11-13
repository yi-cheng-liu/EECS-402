#include <iostream>
#include "LIFOStackClass.h"
#include "LinkedNodeClass.h"

LIFOStackClass::LIFOStackClass() {
    head = 0;
    tail = 0;
}
// LIFOStackClass::~LIFOStackClass() {

// }
 
void LIFOStackClass::push(const int &newItem) {
    if(head == tail) {
        LinkedNodeClass* headNode = new LinkedNodeClass(0, newItem, 0);
    }
    else {
        LinkedNodeClass* newNode = new LinkedNodeClass(tail, newItem,0);
        tail = newNode;
    }
    
}

//Attempts to take the next item out of the stack.  If the 
//stack is empty, the function returns false and the state 
//of the reference parameter (outItem) is undefined.  If the 
//stack is not empty, the function returns true and outItem 
//becomes a copy of the next item in the stack, which is  
//removed from the data structure. 
// bool LIFOStackClass::pop(int &outItem) {

// }

//Prints out the contents of the stack.  All printing is done 
//on one line, using a single space to separate values, and a 
//single newline character is printed at the end. 
void LIFOStackClass::print() const {
    LinkedNodeClass *curPtr = head;
    while(curPtr != 0) {
        std::cout << curPtr->getValue() << "->";
        curPtr = curPtr->getNext();
    }
}

//Returns the number of nodes contained in the stack. 
// int LIFOStackClass::getNumElems() const {

// }

//Clears the stack to an empty state without resulting in any 
//memory leaks. 
// void LIFOStackClass::clear() {

// }