#include <iostream> 
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

//Programmer: Yi-Cheng, Liu
//Date: December 2022
//Purpose: templated definition of the FIFOQueueClass.h

//constructor
template <class DT>
FIFOQueueClass<DT>::FIFOQueueClass() {
    head = NULL;
    tail = NULL;
}

//destructor
template <class DT>
FIFOQueueClass<DT>::~FIFOQueueClass() {
    clear();
}

//enqueue nodes to queue
template <class DT>
void FIFOQueueClass<DT>::enqueue(const DT &newItem) {
    // The queue is empty
    if(head == NULL) {
        LinkedNodeClass<DT>* headNode = new LinkedNodeClass<DT>(NULL, newItem, NULL);
        head = headNode;
        tail = headNode;
    }
    // Add new LinkedNode at the back of the LinkedList
    else {
        LinkedNodeClass<DT>* newNode = new LinkedNodeClass<DT>(tail, newItem, NULL);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    }
} 

//dequeue the first node of the queue and store the dequeue node value
template <class DT>
bool FIFOQueueClass<DT>::dequeue(DT &outItem) {
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
        LinkedNodeClass<DT>* nodeToDequeue = head;
        outItem = head->getValue();
        head = head->getNext();
        delete nodeToDequeue;
        head->setPreviousPointerToNull();
        return true;
    }
}

//print out the queue from first to last
template <class DT>
void FIFOQueueClass<DT>::print() const {
    LinkedNodeClass<DT>* curPtr = head;
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
template <class DT>
int FIFOQueueClass<DT>::getNumElems() const {
    LinkedNodeClass<DT>* countNode = head;
    int count = 0;
    if(head == NULL) {
        return 0;
    }
    else{
        while(countNode != NULL) {
            count++;
            countNode = countNode->getNext();
        }
    }
    return count;
}

//clear the queue to prevent memory leak
template <class DT>
void FIFOQueueClass<DT>::clear() {
    LinkedNodeClass<DT>* deleteNode = head;
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