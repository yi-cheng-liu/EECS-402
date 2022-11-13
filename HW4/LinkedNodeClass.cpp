#include "LinkedNodeClass.h"

LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev, const int &inVal, 
                                 LinkedNodeClass *inNext){
    prevNode = inPrev;
    nextNode = inNext;
    nodeVal = inVal;
}
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
    nextNode = 0;
}
//Sets the object's previous node pointer to NULL.  
void LinkedNodeClass::setPreviousPointerToNull() {
    prevNode = 0;
}
void LinkedNodeClass::setBeforeAndAfterPointers() {
    if(this->nextNode == 0){
        this->prevNode->nextNode = this;
    }
    else if(this->prevNode == 0){
        this->nextNode->prevNode = this;
    }
    else{
        this->prevNode->nextNode = this;
        this->nextNode->prevNode = this;
    }
}