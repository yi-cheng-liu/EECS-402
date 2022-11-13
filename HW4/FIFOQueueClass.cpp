#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

FIFOQueueClass::FIFOQueueClass() {
    head = 0;
    tail = 0;
}
FIFOQueueClass::~FIFOQueueClass() {

}
void FIFOQueueClass::enqueue(const int &newItem) {
    // The queue is empty
    if(head == tail) {
        LinkedNodeClass* headNode = new LinkedNodeClass(0, newItem, 0);
    }
    // Add new LinkedNode at the back of the LinkedList
    else {
        LinkedNodeClass* newNode = new LinkedNodeClass(tail, newItem,0);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    }
} 
bool FIFOQueueClass::dequeue(int &outItem) {

}
void FIFOQueueClass::print() const {

}