#include <iostream>
#include "LinkedNodeClass.h"

//Constructor
LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev, const int &inVal, 
                                 LinkedNodeClass *inNext){
    prevNode = inPrev;
    nextNode = inNext;
    nodeVal = inVal;
}

//get the node value
int LinkedNodeClass::getValue() const {
    return nodeVal;
}

//Returns the address of the node that follows this node.  
LinkedNodeClass* LinkedNodeClass::getNext() const {
    return nextNode;
}

//Returns the address of the node that comes before this node.  
LinkedNodeClass* LinkedNodeClass::getPrev() const {
    return prevNode;
}

//Sets the object’s next node pointer to NULL. 
void LinkedNodeClass::setNextPointerToNull() {
    nextNode = NULL;
}

//Sets the object's previous node pointer to NULL.  
void LinkedNodeClass::setPreviousPointerToNull() {
    prevNode = NULL;
}

//Set the neighbor nodes with the correct pointer
void LinkedNodeClass::setBeforeAndAfterPointers() {
    //set the tail
    if(this->nextNode == NULL) {
        this->prevNode->nextNode = this;
    }
    //set the head
    else if(this->prevNode == NULL) {
        this->nextNode->prevNode = this;
    }
    //set the middle
    else {
        this->prevNode->nextNode = this;
        this->nextNode->prevNode = this;
    }
}