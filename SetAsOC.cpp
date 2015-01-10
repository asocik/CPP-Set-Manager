//
//  SetAsOC.cpp
//  C++ Set Manager
//
//  Created by Adam Socik on 11/26/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#include "SetAsOC.h"

/*----------------------------------------------------------------------------
 Default constructor for an array set
 ----------------------------------------------------------------------------*/
SetAsOC::SetAsOC() {
    
    set = new int[DEFAULT_SIZE];
    arraySize = DEFAULT_SIZE;
    setSize = 0;
}

/*----------------------------------------------------------------------------
  Copy constructor for an array set
 ----------------------------------------------------------------------------*/
SetAsOC::SetAsOC(const SetAsOC *clone) {
    
    arraySize = clone->arraySize;
    setSize = clone->setSize;
    set = new int[arraySize];
    
    for (int i=0; i<setSize; i++)
        set[i] = clone->set[i];
}

/*----------------------------------------------------------------------------
 Destructor for the set array
 ----------------------------------------------------------------------------*/
SetAsOC::~SetAsOC() {
    delete [] set;
    setSize = 0;
}

/*----------------------------------------------------------------------------
 Returns the size of the set
 ----------------------------------------------------------------------------*/
int SetAsOC::size() {
    return setSize;
}

/*----------------------------------------------------------------------------
 Grows the size of the set array *2 of what it was before
 ----------------------------------------------------------------------------*/
void SetAsOC::resize() {
    
    arraySize *= 2;
    int *newset = new int[arraySize];
    
    // Copy over all relevant data
    for (int i=0; i<setSize; i++)
        newset[i] = set[i];

    // Save new set
    delete [] set;
    set = newset;
}

/*----------------------------------------------------------------------------
 Checks to see if the set contains the integer provided
 ----------------------------------------------------------------------------*/
bool SetAsOC::contains(int element) {
    
    for (int i=0; i<setSize; i++)
        if (set[i] == element)
            return true;
    
    return false;
}

/*----------------------------------------------------------------------------
 Prints out the contents of the set
 ----------------------------------------------------------------------------*/
void SetAsOC::displaySet() {
    
    if (size() == 0) {
        std::cout << "Set is empty\n\n";
        return;
    }
    
    for (int i=0; i<setSize; i++)
        std::cout << set[i] << std::endl;
    std::cout << std::endl;
}

/*----------------------------------------------------------------------------
 Adds the element to the set if it is not already there
 ----------------------------------------------------------------------------*/
int SetAsOC::add(int element) {
    
    // If the set contains the element then don't add it
    if (contains(element))
        return -1;

    if (setSize >= arraySize)
        resize();
    
    set[setSize] = element;     // setSize is also the next available spot
    setSize++;
    return 1;
}

/*----------------------------------------------------------------------------
 Returns the value in the set at the provided index
 ----------------------------------------------------------------------------*/
int SetAsOC::valueAtIndex(int index) {
    
    if (index >= setSize) {
        std::cout << "Index out of bounds\n";
        return set[0];
    }
        
    return set[index];
}

/*----------------------------------------------------------------------------
 Replaces the current set with a new one
 ----------------------------------------------------------------------------*/
void SetAsOC::replaceSet(std::vector<int> replacement) {
    
    delete [] set;
    set = new int[DEFAULT_SIZE];
    arraySize = DEFAULT_SIZE;
    setSize = 0;
    
    for (int val : replacement)
        add(val);
}

/*----------------------------------------------------------------------------
 Calls the copy constructor to return a copy of the set
 ----------------------------------------------------------------------------*/
Set* SetAsOC::copy() const {
    return new SetAsOC(this);
}





