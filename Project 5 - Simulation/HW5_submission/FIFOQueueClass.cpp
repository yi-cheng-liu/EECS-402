#include "FIFOQueueClass.h"

int main() {
    FIFOQueueClass<int> testQueue1;
    testQueue1.enqueue(12);
    testQueue1.enqueue(10);
    testQueue1.enqueue(9);
    testQueue1.enqueue(56);
    testQueue1.enqueue(4);
    testQueue1.enqueue(278);
    testQueue1.enqueue(5);
    testQueue1.print();
    std::cout << testQueue1.getNumElems() << std::endl;
    int out;
    testQueue1.dequeue(out);
    std::cout << out << std::endl;
    testQueue1.print();
    testQueue1.clear();
    testQueue1.print();
    
    
    FIFOQueueClass<double> testQueue2;
    testQueue2.enqueue(12.4);
    testQueue2.enqueue(4.6);
    testQueue2.enqueue(9.3);
    testQueue2.enqueue(56.3);
    testQueue2.enqueue(4.67);
    testQueue2.enqueue(278.66);
    testQueue2.enqueue(5.5);
    testQueue2.print();
    std::cout << testQueue2.getNumElems() << std::endl;
    double out2;
    testQueue2.dequeue(out2);
    std::cout << out2 << std::endl;
    testQueue2.print();
    testQueue2.clear();
    testQueue2.print();

    FIFOQueueClass<bool> testQueue3;
    testQueue3.enqueue(true);
    testQueue3.enqueue(true);
    testQueue3.enqueue(false);
    testQueue3.enqueue(false);
    testQueue3.enqueue(true);
    testQueue3.enqueue(false);
    testQueue3.enqueue(true);
    testQueue3.print();

    FIFOQueueClass<char> testQueue4;
    testQueue4.enqueue('c');
    testQueue4.enqueue('a');
    testQueue4.enqueue('d');
    testQueue4.enqueue('i');
    testQueue4.enqueue('u');
    testQueue4.enqueue('w');
    testQueue4.enqueue('l');
    testQueue4.print();
    return 0;
}