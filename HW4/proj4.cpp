#include <iostream>
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
#include "SortedListClass.h"

#include <vector>

using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 
int main()
{
    SortedListClass testList;
    std::cout << "Empty linked list: ";
    testList.printForward();
    std::cout << "Add first node: ";
    testList.insertValue(5);
    testList.printForward();

    testList.printForward();
    std::cout << "Add at tail: ";
    testList.insertValue(6);
    testList.printForward();
    std::cout << "Add at tail: ";
    testList.insertValue(15);
    testList.printForward();
    std::cout << "Add at middle: ";
    testList.insertValue(7);
    testList.printForward();
    // std::cout << "Add at head: ";
    // testList.insertValue(4);
    // testList.printForward();
    std::cout << "Add same num: ";
    testList.insertValue(5);
    testList.printForward();
    std::cout << "Print backwards: ";
    testList.printBackward();

    testList.printForward();
    std::cout << "Node count: " << testList.getNumElems() << std::endl;
    testList.printForward();
    int numOfIndex = 0;
    if(testList.getElemAtIndex(5, numOfIndex)) {
        std::cout << "Index num: " << numOfIndex << std::endl;
    }
    
    int remove;
    std::cout << "Before remove: ";
    testList.printForward();
    while(testList.removeFront(remove)) {
        std::cout << "Removed: " << remove << std::endl;
        std::cout << "Before remove: ";
        testList.printForward(); //new list
    }
    //test the clear method
    testList.clear();

    std::cout << std::endl;
    
    LIFOStackClass stack;
    stack.push(12);
    stack.push(10);
    stack.push(8);
    stack.push(6);
    stack.print();
    std::cout << "Number of elements: " << stack.getNumElems() << std::endl;
    int popNum;
    if(stack.pop(popNum)) {
        std::cout << "The removed item is: " << popNum << std::endl;
    }
    stack.print();

    std::cout << std::endl;

    FIFOQueueClass queue;
    queue.enqueue(12);
    queue.enqueue(10);
    queue.enqueue(8);
    queue.enqueue(6);
    queue.enqueue(4);
    queue.enqueue(2);
    queue.print();
    if(queue.dequeue(popNum)) {
        std::cout << "The removed item is: " << popNum << std::endl;
    }
    queue.print();
    std::cout << "Number of elements: " << queue.getNumElems() << std::endl;
    std::cout << std::endl;
    return 0;
}
#endif