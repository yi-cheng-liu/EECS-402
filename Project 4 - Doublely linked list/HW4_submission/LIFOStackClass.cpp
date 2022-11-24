#include <iostream>
#include "LIFOStackClass.h"
#include "LinkedNodeClass.h"

//constructor
LIFOStackClass::LIFOStackClass() {
    head = NULL;
    tail = NULL;
}

//destructor
LIFOStackClass::~LIFOStackClass() {
    clear();
}

//push nodes to stack
void LIFOStackClass::push(const int &newItem) {
    // Add the first node
    if(head == NULL) {
        LinkedNodeClass* headNode = new LinkedNodeClass(NULL, newItem, NULL);
        head = headNode;
        tail = headNode;
    }
    // Add new LinkedNode at the back of the LinkedList
    else {
        LinkedNodeClass* newNode = new LinkedNodeClass(tail, newItem,NULL);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    }
}

//pops the last node of the stack and store the poped node value
bool LIFOStackClass::pop(int &outItem) {
    //The stack is empty
    if(head == NULL) {
        return false;
    }
    //Only one node
    else if(head == tail) {
        outItem = head->getValue();
        delete head;
        head = tail = NULL;
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
    while(curPtr != NULL) {
        std::cout << curPtr->getValue();
        //the last node don't have space
        if(curPtr->getNext() != NULL){
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
    if(head == NULL){
        return 0;
    }
    else{
        while(countNode != NULL){
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
        while(deleteNode->getNext() != NULL) {
            deleteNode = deleteNode->getNext();
            delete deleteNode->getPrev();
        }
        delete deleteNode;
        head = tail = NULL;
    }
}