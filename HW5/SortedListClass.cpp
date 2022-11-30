#include <iostream>
#include "SortedListClass.h"

//constructor
SortedListClass::SortedListClass() {
    head = NULL; 
    tail = NULL;
} 

// Copy Constructor
SortedListClass::SortedListClass(const SortedListClass &rhs) {
    head = tail = NULL;
    for (LinkedNodeClass* copy = rhs.head; copy; copy = copy->getNext()) {
        this->insertValue(copy->getValue());
    }
} 

//destructor
SortedListClass::~SortedListClass() {
    clear();
} 

//clear the sorted list to prevent memory leak
void SortedListClass::clear() {
    LinkedNodeClass* deleteNode = head;
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
void SortedListClass::insertValue(const int &valToInsert) {
    // empty doublely-linked list
    if(head == NULL) {
        LinkedNodeClass* insertNode;
        insertNode = new LinkedNodeClass(NULL, valToInsert, NULL);
        head = insertNode;
        tail = insertNode;
    }
    //with at least one node
    else {
        LinkedNodeClass* cur = head;
        while((cur != NULL) && (cur->getValue() <= valToInsert)) {
            cur = cur->getNext();
        }
        //add at head
        if(cur == head) {
            LinkedNodeClass* insertNode;
            insertNode = new LinkedNodeClass(NULL, valToInsert, head);
            insertNode->setBeforeAndAfterPointers();
            head = insertNode;
        }
        //add at tail
        else if (cur == NULL) {
            LinkedNodeClass* insertNode;
            insertNode = new LinkedNodeClass(tail, valToInsert, NULL);
            insertNode->setBeforeAndAfterPointers();
            tail = insertNode;
        }
        //add at middle
        else {
            LinkedNodeClass* insertNode;
            insertNode = new LinkedNodeClass(cur->getPrev(), valToInsert, cur);
            insertNode->setBeforeAndAfterPointers();
        }
    }
}   //The value to insert into the list 

//print the doublely linked-list forward
void SortedListClass::printForward() const {
    std::cout << "Forward List Contents Follow:" << std::endl;
    LinkedNodeClass* printPtr = head;
    while(printPtr != NULL){
        std::cout << "  " << printPtr->getValue() << std::endl;
        printPtr = printPtr->getNext();
    }
    std::cout << "End Of List Contents" << std::endl;
}
  
//print the doublely linked-list backwards
void SortedListClass::printBackward() const {
    std::cout << "Backward List Contents Follow:" << std::endl;
    LinkedNodeClass* printPtr = tail;
    while(printPtr != NULL){
        std::cout << "  " << printPtr->getValue() << std::endl;
        printPtr = printPtr->getPrev();
    }
    std::cout << "End Of List Contents" << std::endl;
}

//remove the front node of the list and store the node value
bool SortedListClass::removeFront(int &theVal) {
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
bool SortedListClass::removeLast(int &theVal) {
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
int SortedListClass::getNumElems() const {
    int count = 0;
    LinkedNodeClass* countPtr = head; 
    while(countPtr != NULL) {
        count++;
        countPtr = countPtr->getNext();
    }
    return count;
}

//get the element value when given the index
bool SortedListClass::getElemAtIndex(const int index, int &outVal) const {
    if(index < 0) {
        return false;
    }
    //the index is out of bound
    else if(index >= getNumElems()) {
        return false;
    }
    else {
        int countIndex = 0;
        LinkedNodeClass* cur = head;
        while(countIndex < index) {
            countIndex++;
            cur = cur->getNext();
        }
        outVal = cur->getValue();
        return true;
    }
}