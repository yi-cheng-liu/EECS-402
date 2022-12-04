#include "SortedListClass.h"

int main() {
    // SortedListClass<int> testSort1;
    // testSort1.insertValue(12);
    // testSort1.insertValue(10);
    // testSort1.insertValue(9);
    // testSort1.insertValue(56);
    // testSort1.insertValue(4);
    // testSort1.insertValue(278);
    // testSort1.insertValue(5);
    // testSort1.printForward();
    // testSort1.printBackward();
    // int out;
    // std::cout << "Element numbers: " << testSort1.getNumElems() << std::endl;
    // testSort1.getElemAtIndex(2, out);
    // std::cout << "Element index 2: " << out << std::endl;
    // testSort1.removeFront(out);
    // std::cout << "removed front: " << out << std::endl;
    // testSort1.printForward();
    // testSort1.removeLast(out);
    // std::cout << "removed last: "<< out << std::endl;
    // testSort1.printForward();
    // testSort1.clear();
    // testSort1.printForward();
    
    SortedListClass<double> testSort2;
    testSort2.insertValue(12.4);
    testSort2.insertValue(4.6);
    testSort2.insertValue(9.3);
    testSort2.insertValue(56.3);
    testSort2.insertValue(4.67);
    testSort2.insertValue(278.66);
    testSort2.insertValue(5.5);
    testSort2.printForward();
    testSort2.printBackward();
    double out2;
    std::cout << "Element numbers: " << testSort2.getNumElems() << std::endl;
    testSort2.getElemAtIndex(2, out2);
    std::cout << "Element index 2: " << out2 << std::endl;
    testSort2.removeFront(out2);
    std::cout << "removed front: " << out2 << std::endl;
    testSort2.printForward();
    testSort2.removeLast(out2);
    std::cout << "removed last: "<< out2 << std::endl;
    testSort2.printForward();
    testSort2.clear();
    testSort2.printForward();

    // SortedListClass<bool> testSort3;
    // testSort3.insertValue(true);
    // testSort3.insertValue(true);
    // testSort3.insertValue(false);
    // testSort3.insertValue(false);
    // testSort3.insertValue(true);
    // testSort3.insertValue(false);
    // testSort3.insertValue(true);
    // testSort3.printForward();
    // testSort3.printBackward();

    // SortedListClass<char> testSort4;
    // testSort4.insertValue('c');
    // testSort4.insertValue('a');
    // testSort4.insertValue('d');
    // testSort4.insertValue('i');
    // testSort4.insertValue('u');
    // testSort4.insertValue('w');
    // testSort4.insertValue('l');
    // testSort4.printForward();
    // testSort4.printBackward(); 
    return 0;
}