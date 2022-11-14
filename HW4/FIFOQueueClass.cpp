#include <iostream>
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

FIFOQueueClass::FIFOQueueClass() {
    head = 0;
    tail = 0;
}
// FIFOQueueClass::~FIFOQueueClass() {

// }
void FIFOQueueClass::enqueue(const int &newItem) {
    // The queue is empty
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
// bool FIFOQueueClass::dequeue(int &outItem) {

// }
// print out the queue from first to last
void FIFOQueueClass::print() const {
    LinkedNodeClass *curPtr = head;
    std::cout << "print out the queue from first to last" << std::endl;
    while(curPtr != 0) {
        std::cout << "[" << curPtr->getPrev() << ", ";
        std::cout << curPtr->getValue() << ", ";
        std::cout << curPtr->getNext() << "]";
        if(curPtr->getNext() != 0){
            std::cout << "->";
        }
        curPtr = curPtr->getNext();
    }
}

// get the number of elements
int FIFOQueueClass::getNumElems() const {
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