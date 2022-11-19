#ifndef _SORTED_LIST_CLASS_H_
#define _SORTED_LIST_CLASS_H_

#include "LinkedNodeClass.h"

//The sorted list class does not store any data directly.  Instead, 
//it contains a collection of LinkedNodeClass objects, each of which 
//contains one element. 
class SortedListClass { 
private: 
    LinkedNodeClass *head; //Points to the first node in a list, or NULL 
                           //if list is empty. 
    LinkedNodeClass *tail; //Points to the last node in a list, or NULL 
                           //if list is empty. 
public: 
    SortedListClass(); 
    // SortedListClass(const SortedListClass &rhs); 
    ~SortedListClass(); 
    void clear(); 
    void insertValue(const int &valToInsert);
    void printForward() const; 
    void printBackward() const; 
    bool removeFront(int &theVal); 
    bool removeLast(int &theVal); 
    int getNumElems() const; 
    bool getElemAtIndex(const int index, int &outVal) const; 
};

#endif