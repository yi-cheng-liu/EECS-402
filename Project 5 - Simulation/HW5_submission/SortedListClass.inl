#include <iostream>
#include "SortedListClass.h"

//Programmer: Yi-Cheng, Liu
//Date: December 2022
//Purpose: templated definition of the SortedListClass.h

//Constructor
template <class DAT>
SortedListClass<DAT>::SortedListClass() {
    head = NULL; 
    tail = NULL;
} 

// Copy Constructor
template <class DAT>
SortedListClass<DAT>::SortedListClass(const SortedListClass<DAT> &rhs) {
    head = tail = NULL;
    for (LinkedNodeClass<DAT>* copy = rhs.head; copy; copy = copy->getNext()) {
        this->insertValue(copy->getValue());
    }
} 

//destructor
template <class DAT>
SortedListClass<DAT>::~SortedListClass() {
    clear();
} 

//clear the sorted list to prevent memory leak
template <class DAT>
void SortedListClass<DAT>::clear() {
    LinkedNodeClass<DAT>* deleteNode = head;
    //only one node to delete
    if(head == tail) {
        delete deleteNode;
    }
    else {
        while(deleteNode->getNext() != NULL) {
            deleteNode = deleteNode->getNext();
            delete deleteNode->getPrev();
        }
        delete deleteNode;
        head = tail = NULL;
    }
}

//insert a new node and put into the sorted order
template <class DAT>
void SortedListClass<DAT>::insertValue(const DAT &valToInsert) {
    // empty doublely-linked list
    if(head == NULL) {
        LinkedNodeClass<DAT>* insertNode;
        insertNode = new LinkedNodeClass<DAT>(NULL, valToInsert, NULL);
        head = insertNode;
        tail = insertNode;
    }
    //with at least one node
    else {
        LinkedNodeClass<DAT>* cur = head;
        while((cur != NULL) && (cur->getValue() <= valToInsert)) {
            cur = cur->getNext();
        }
        //add at head
        if(cur == head) {
            LinkedNodeClass<DAT>* insertNode;
            insertNode = new LinkedNodeClass<DAT>(NULL, valToInsert, head);
            insertNode->setBeforeAndAfterPointers();
            head = insertNode;
        }
        //add at tail
        else if (cur == NULL) {
            LinkedNodeClass<DAT>* insertNode;
            insertNode = new LinkedNodeClass<DAT>(tail, valToInsert, NULL);
            insertNode->setBeforeAndAfterPointers();
            tail = insertNode;
        }
        //add at middle
        else {
            LinkedNodeClass<DAT>* insertNode;
            insertNode = new LinkedNodeClass<DAT>(cur->getPrev(), 
                                                  valToInsert, cur);
            insertNode->setBeforeAndAfterPointers();
        }
    }
}   //The value to insert into the list 

//print the doublely linked-list forward
template <class DAT>
void SortedListClass<DAT>::printForward() const {
    std::cout << "Forward List Contents Follow:" << std::endl;
    LinkedNodeClass<DAT>* printPtr = head;
    while(printPtr != NULL){
        std::cout << "  " << printPtr->getValue() << std::endl;
        printPtr = printPtr->getNext();
    }
    std::cout << "End Of List Contents" << std::endl;
}
  
//print the doublely linked-list backwards
template <class DAT>
void SortedListClass<DAT>::printBackward() const {
    std::cout << "Backward List Contents Follow:" << std::endl;
    LinkedNodeClass<DAT>* printPtr = tail;
    while(printPtr != NULL){
        std::cout << "  " << printPtr->getValue() << std::endl;
        printPtr = printPtr->getPrev();
    }
    std::cout << "End Of List Contents" << std::endl;
}

//remove the front node of the list and store the node value
template <class DAT>
bool SortedListClass<DAT>::removeFront(DAT &theVal) {
    // the list is empty
    if(head == NULL) {
        return false;
    }
    //only one node to delete
    else if(head == tail) {
        theVal = head->getValue();
        delete head;
        head = tail = NULL;
        return true;
    }
    else {
        theVal = head->getValue();
        head = head->getNext();
        delete head->getPrev();
        head->setPreviousPointerToNull();
        return true;
    }
} 

//remove the last node of the list and store the node value
template <class DAT>
bool SortedListClass<DAT>::removeLast(DAT &theVal) {
    //the list is empty
    if(head == NULL) {
        return false;
    }
    //only one node to delete
    else if(head == tail) {
        this->removeFront(theVal);
    }
    else {
        theVal = tail->getValue();
        tail = tail->getPrev();
        delete tail->getNext();
        tail->setNextPointerToNull();
    }
    return true;
}

//Returns the number of nodes contained in the list. 
template <class DAT>
int SortedListClass<DAT>::getNumElems() const {
    int count = 0;
    LinkedNodeClass<DAT>* countPtr = head; 
    while(countPtr != NULL) {
        count++;
        countPtr = countPtr->getNext();
    }
    return count;
}

//get the element value when given the index
template <class DAT>
bool SortedListClass<DAT>::getElemAtIndex(const int index, DAT &outVal) const {
    if(index < 0) {
        return false;
    }
    //the index is out of bound
    else if(index >= getNumElems()) {
        return false;
    }
    else {
        int countIndex = 0;
        LinkedNodeClass<DAT>* cur = head;
        while(countIndex < index) {
            countIndex++;
            cur = cur->getNext();
        }
        outVal = cur->getValue();
        return true;
    }
}