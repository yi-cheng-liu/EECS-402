#include <iostream>
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
// #include "SortedListClass.h"

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
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.
  // SortedListClass testList;
  
  // testList.printForward();
  // testList.insertValue(42);
  // testList.printForward();
  LIFOStackClass stack;
  stack.push(12);
  stack.push(10);
  stack.push(8);
  stack.push(6);
  stack.print();
  std::cout << std::endl;
  std::cout << "Number of elements: " << stack.getNumElems() << std::endl;
  
  FIFOQueueClass queue;
  queue.enqueue(12);
  queue.enqueue(10);
  queue.enqueue(8);
  queue.enqueue(6);
  queue.enqueue(4);
  queue.enqueue(2);
  queue.print();
  std::cout << std::endl;
  std::cout << "Number of elements: " << queue.getNumElems() << std::endl;
 
  LinkedNodeClass L1(0, 12, 0);
  std::cout << L1.getNext() << " ";
  std::cout << L1.getPrev() << " ";
  std::cout << L1.getValue();
  
  return 0;
}
#endif