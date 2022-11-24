#include <iostream>
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
#include "SortedListClass.h"

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
    // std::cout << "Empty linked list: ";
    // testList.printForward();
    // std::cout << "Add first node: ";
    testList.insertValue(5);
    // testList.printForward();
    // std::cout << "Add 6 at tail: ";
    testList.insertValue(6);
    // testList.printForward();
    // std::cout << "Add 15 at tail: ";
    testList.insertValue(15);
    // testList.printForward();
    // std::cout << "Add 7 at middle: ";
    testList.insertValue(7);
    // testList.printForward();
    // std::cout << "Add 4 at head: ";
    testList.insertValue(4);
    // testList.printForward();
    // std::cout << "Add 5 same num: ";
    testList.insertValue(5);
    testList.printForward();
    testList.printBackward();

    // testList.printForward();
    // std::cout << "Node count: " << testList.getNumElems() << std::endl;
    // testList.printForward();
    // int numOfIndex = 0;
    // if(testList.getElemAtIndex(4, numOfIndex)) {
    //     std::cout << "Get element at index: " << 4 << std::endl;
    //     std::cout << "Index num: " << numOfIndex << std::endl;
    // }
    // if(testList.getElemAtIndex(0, numOfIndex)) {
    //     std::cout << "Get element at index: " << 0 << std::endl;
    //     std::cout << "Index num: " << numOfIndex << std::endl;
    // }
    // if(testList.getElemAtIndex(-1, numOfIndex)) {
    //     std::cout << "Get element at index: " << -1 << std::endl;
    //     std::cout << "Index num: " << numOfIndex << std::endl;
    // }
    // if(testList.getElemAtIndex(6, numOfIndex)) {
    //     std::cout << "Get element at index: " << 6 << std::endl;
    //     std::cout << "Index num: " << numOfIndex << std::endl;
    // }

    // std::cout << "--------------------------------------" << std::endl;
    // //copy constructor
    // SortedListClass testList2(testList);
    // testList.printForward();
    // testList.printBackward();
    // testList2.printForward();
    // testList2.printBackward();
    // std::cout << "--------------------------------------" << std::endl;

    // int removeFront;
    // std::cout << "Before remove: ";
    // testList.printForward();
    // while(testList.removeFront(removeFront)) {
    // // while(testList.removeLast(removeFront)) {
    //     std::cout << "Front! The removed item is: " << removeFront;
    //     std::cout << std::endl;
    //     testList.printForward();
    //     testList.printBackward();
    //     std::cout << "Number of elements: " << testList.getNumElems();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }

    


    //test the clear method
    testList.clear();

    std::cout << std::endl;
    
    LIFOStackClass stack;
    stack.push(12);
    stack.push(18);
    stack.push(8);
    stack.push(2);
    stack.print();
    // std::cout << "Number of elements: " << stack.getNumElems() << std::endl;
    // int popNum;
    // while(stack.pop(popNum)) {
    //     std::cout << "Pop! The removed item is: " << popNum << std::endl;
    //     stack.print();
    //     std::cout << "Number of elements: " << stack.getNumElems();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }
    
    std::cout << std::endl;

    FIFOQueueClass queue;
    queue.enqueue(12);
    queue.enqueue(20);
    queue.enqueue(85);
    queue.enqueue(40);
    queue.enqueue(-8);
    queue.enqueue(2);
    queue.print();
    // std::cout << "Number of elements: " << queue.getNumElems() << std::endl;
    // int enqueueNum;
    // while(queue.dequeue(enqueueNum)) {
    //     std::cout << "Dequeue! The removed item is: " << enqueueNum;
    //     std::cout << std::endl;
    //     queue.print();
    //     std::cout << "Number of elements: " << queue.getNumElems();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }
    
    return 0;
}
#endif