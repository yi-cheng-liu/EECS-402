#include <iostream>
#include "LinkedNodeClass.h"

//Programmer: Yi-Cheng, Liu
//Date: December 2022
//Purpose: templated definition of the LinkedNodeClass.h

//Constructor
template <class T>
LinkedNodeClass<T>::LinkedNodeClass(LinkedNodeClass<T> *inPrev, const T &inVal, 
                                 LinkedNodeClass<T> *inNext){
    prevNode = inPrev;
    nextNode = inNext;
    nodeVal = inVal;
}

//Gets the node valuSe
template <class T>
T LinkedNodeClass<T>::getValue() const {
    return nodeVal;
}

//Returns the address of the node that follows this node.  
template <class T>
LinkedNodeClass<T>* LinkedNodeClass<T>::getNext() const {
    return nextNode;
}

//Returns the address of the node that comes before this node.  
template <class T>
LinkedNodeClass<T>* LinkedNodeClass<T>::getPrev() const {
    return prevNode;
}

//Sets the object’s next node pointer to NULL. 
template <class T>
void LinkedNodeClass<T>::setNextPointerToNull() {
    nextNode = NULL;
}

//Sets the object's previous node pointer to NULL.  
template <class T>
void LinkedNodeClass<T>::setPreviousPointerToNull() {
    prevNode = NULL;
}

//Set the neighbor nodes with the correct pointer
template <class T>
void LinkedNodeClass<T>::setBeforeAndAfterPointers() {
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