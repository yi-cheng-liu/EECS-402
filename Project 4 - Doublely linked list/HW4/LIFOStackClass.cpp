#include <iostream>
#include "LIFOStackClass.h"
#include "LinkedNodeClass.h"

LIFOStackClass::LIFOStackClass() {
    head = 0;
    tail = 0;
}
LIFOStackClass::~LIFOStackClass() {
    clear();
}
 
void LIFOStackClass::push(const int &newItem) {
    // Add the first node
    if(head == 0) {
        LinkedNodeClass* headNode = new LinkedNodeClass(0, newItem, 0);
        head = headNode;
        tail = headNode;
    }
    // Add new LinkedNode at the back of the LinkedList
    else {
        LinkedNodeClass* newNode = new LinkedNodeClass(tail, newItem,0);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    }
}
//Attempts to take the next item out of the stack.  If the 
//stack is empty, the function returns false and the state 
//of the reference parameter (outItem) is undefined.  If the 
//stack is not empty, the function returns true and outItem 
//becomes a copy of the next item in the stack, which is  
//removed from the data structure. 
bool LIFOStackClass::pop(int &outItem) {
    if(head == 0) {
        return false;
    }
    else if(head == tail) {
        delete head;
        head = tail = 0;
        return true;
    }
    else {
        LinkedNodeClass* nodeToPop = tail;
        outItem = tail->getValue();
        tail = tail->getPrev();
        delete nodeToPop;
        tail->setNextPointerToNull();
        return true;
    }
}

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
    std::cout << std::endl;
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
void LIFOStackClass::clear() {
    LinkedNodeClass* deleteNode = head;
    //only one node to delete
    if(head == tail) {
        delete deleteNode;
    }
    else {
        while(deleteNode->getNext() != 0) {
            deleteNode = deleteNode->getNext();
            delete deleteNode->getPrev();
        }
        delete deleteNode;
        head = tail = 0;
    }
}