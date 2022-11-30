#include <iostream>
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

//constructor
FIFOQueueClass::FIFOQueueClass() {
    head = NULL;
    tail = NULL;
}

//destructor
FIFOQueueClass::~FIFOQueueClass() {
    clear();
}

//enqueue nodes to queue
void FIFOQueueClass::enqueue(const int &newItem) {
    // The queue is empty
    if(head == NULL) {
        LinkedNodeClass* headNode = new LinkedNodeClass(NULL, newItem, NULL);
        head = headNode;
        tail = headNode;
    }
    // Add new LinkedNode at the back of the LinkedList
    else {
        LinkedNodeClass* newNode = new LinkedNodeClass(tail, newItem, NULL);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    }
} 

//dequeue the first node of the queue and store the dequeue node value
bool FIFOQueueClass::dequeue(int &outItem) {
    //The queue is empty
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
        LinkedNodeClass* nodeToDequeue = head;
        outItem = head->getValue();
        head = head->getNext();
        delete nodeToDequeue;
        head->setPreviousPointerToNull();
        return true;
    }
}

//print out the queue from first to last
void FIFOQueueClass::print() const {
    LinkedNodeClass *curPtr = head;
    while(curPtr != NULL) {
        std::cout << curPtr->getValue();
        if(curPtr->getNext() != NULL){
            std::cout << " ";
        }
        curPtr = curPtr->getNext();
    }
    std::cout << std::endl;
}

//get the number of elements
int FIFOQueueClass::getNumElems() const {
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

//clear the queue to prevent memory leak
void FIFOQueueClass::clear() {
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