#include <iostream>
#include "LIFOStackClass.h"
#include "LinkedNodeClass.h"

//constructor
LIFOStackClass::LIFOStackClass() {
    head = 0;
    tail = 0;
}

//destructor
LIFOStackClass::~LIFOStackClass() {
    clear();
}

//push nodes to stack
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

//pops the last node of the stack and store the poped node value
bool LIFOStackClass::pop(int &outItem) {
    //The stack is empty
    if(head == 0) {
        return false;
    }
    //Only one node
    else if(head == tail) {
        outItem = head->getValue();
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

//print out the stack from bottom to top
void LIFOStackClass::print() const {
    LinkedNodeClass *curPtr = head;
    while(curPtr != 0) {
        std::cout << curPtr->getValue();
        //the last node don't have space
        if(curPtr->getNext() != 0){
            std::cout << " ";
        }
        curPtr = curPtr->getNext();
    }
    std::cout << std::endl;
}

//get the number of elements
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

//clear the stack to prevent memory leak
void LIFOStackClass::clear() {
    LinkedNodeClass* deleteNode = head;
    //only one node to delete
    if(head == tail) {
        delete deleteNode;
    }
    //at least one node
    else {
        while(deleteNode->getNext() != 0) {
            deleteNode = deleteNode->getNext();
            delete deleteNode->getPrev();
        }
        delete deleteNode;
        head = tail = 0;
    }
}