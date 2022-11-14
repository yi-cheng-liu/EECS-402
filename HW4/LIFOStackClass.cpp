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
    if(head == 0) {
        LinkedNodeClass* headNode = new LinkedNodeClass(0, newItem, 0);
        head = headNode;
        tail = headNode;
    }
    else {
        LinkedNodeClass* newNode = new LinkedNodeClass(0, newItem, head);
        newNode->setBeforeAndAfterPointers();
        head = newNode;
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
    std::cout << "print out the stack from top to bottom" << std::endl;
    while(curPtr != 0) {
        std::cout << "[" << curPtr->getPrev() << ", ";
        std::cout << curPtr->getValue() << ", ";
        std::cout << curPtr->getNext() << "]";
        if(curPtr->getNext() != 0){
            std::cout << "->";
        }
        curPtr = curPtr->getNext();
    }
    
}

//Returns the number of nodes contained in the stack. 
int LIFOStackClass::getNumElems() const {
    LinkedNodeClass* countNode = head;
    int count = 0;
    if(head == 0){
        return 0;
    }
    else{
        while(countNode != 0){
            count++;
            countNode = countNode->getNext();
        }
    }
    return count;
}

//Clears the stack to an empty state without resulting in any 
//memory leaks. 
// void LIFOStackClass::clear() {

// }