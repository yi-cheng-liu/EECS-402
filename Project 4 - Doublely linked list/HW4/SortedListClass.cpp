#include <iostream>
#include "SortedListClass.h"

#ifndef INT_MIN
#define INT_MAX 2147483647 
#define INT_MIN (-INT_MAX - 1)  

//constructor
SortedListClass::SortedListClass() {
    head = 0; 
    tail = 0;
} 
// Copy Constructor
SortedListClass::SortedListClass(const SortedListClass &rhs) {
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
        while(deleteNode->getNext() != 0) {
            deleteNode = deleteNode->getNext();
            delete deleteNode->getPrev();
        }
        delete deleteNode;
        head = tail = 0;
    }
}

//insert a new node and put into the sorted order
void SortedListClass::insertValue(const int &valToInsert) {
    // empty doublely-linked list
    if(head == 0) {
        LinkedNodeClass* insertNode = new LinkedNodeClass(0, valToInsert, 0);
        head = insertNode;
        tail = insertNode;
    }
    //with at least one node
    else {
        LinkedNodeClass* cur = head;
        while((cur != 0) && (cur->getValue() <= valToInsert)) {
            cur = cur->getNext();
        }
        //add at head
        if(cur == head) {
            LinkedNodeClass* insertNode = new LinkedNodeClass(0, valToInsert, head);
            insertNode->setBeforeAndAfterPointers();
            head = insertNode;
        }
        //add at tail
        else if (cur == 0) {
            LinkedNodeClass* insertNode = new LinkedNodeClass(tail, valToInsert, 0);
            insertNode->setBeforeAndAfterPointers();
            tail = insertNode;
        }
        //add at middle
        else {
            LinkedNodeClass* insertNode = new LinkedNodeClass(cur->getPrev(), valToInsert, cur);
            insertNode->setBeforeAndAfterPointers();
        }
    }
}   //The value to insert into the list 

//print the doublely linked-list forward
void SortedListClass::printForward() const {
    // std::cout << "Forward List Contents Follow:" << std::endl;
    LinkedNodeClass* printPtr = head;
    while(printPtr != 0){
        std::cout << "[" << printPtr->getPrev() << ", ";
        std::cout << printPtr->getValue() << ", ";
        std::cout << printPtr->getNext() << "]";
        if(printPtr != tail) {
            //change to indent two spaces and one list element per line
            std::cout << "->"; 
        } 
        printPtr = printPtr->getNext();
    }
    std::cout << std::endl;
    // std::cout << "End Of List Contents" << std::endl;
}
  
//print the doublely linked-list backwards
void SortedListClass::printBackward() const {
    // std::cout << "Backward List Contents Follow:" << std::endl;
    LinkedNodeClass* printPtr = tail;
    while(printPtr != 0){
        std::cout << printPtr->getValue();
        if(printPtr != head) {
            //change to indent two spaces and one list element per line
            std::cout << "->";
        } 
        printPtr = printPtr->getPrev();
    }
    std::cout << std::endl;
    // std::cout << "End Of List Contents" << std::endl;
}

//Removes the front item from the list and returns the value that 
//was contained in it via the reference parameter.  
//If the list was empty, the function returns false to indicate failure, and 
//the contents of the reference parameter upon return is undefined. 

//If the list was not empty and the first item was successfully 
//removed, true is returned, and the reference parameter will 
//be set to the item that was removed. 
bool SortedListClass::removeFront(int &theVal) {
    // the list is empty
    if(head == 0) {
        return false;
    }
    //only one node to delete
    else if(head == tail) {
        theVal = head->getValue();
        delete head;
        head = tail = 0;
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

//Removes the last item from the list and returns the value that 
//was contained in it via the reference parameter.  If the list 
//was empty, the function returns false to indicate failure, and 
//the contents of the reference parameter upon return is undefined. 
//If the list was not empty and the last item was successfully 
//removed, true is returned, and the reference parameter will 
//be set to the item that was removed. 
bool SortedListClass::removeLast(int &theVal) {
    //the list is empty
    if(head == 0) {
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
    while(countPtr != 0) {
        count++;
        countPtr = countPtr->getNext();
    }
    return count;
}

//Provides the value stored in the node at index provided in the 
//0-based "index" parameter.  If the index is out of range, then outVal 
//remains unchanged and false is returned.  Otherwise, the function 
//returns true, and the reference parameter outVal will contain 
//a copy of the value at that location. 
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

#endif