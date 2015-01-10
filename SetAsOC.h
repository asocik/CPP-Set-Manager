//
//  SetAsOC.h
//  C++ Set Manager
//
//  Created by Adam Socik on 11/26/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#ifndef __C___Set_Manager__SetAsOC__
#define __C___Set_Manager__SetAsOC__

#include <iostream>
#include "Set.h"

#endif /* defined(__C___Set_Manager__SetAsOC__) */

#define DEFAULT_SIZE 10

class SetAsOC : public Set {
public:
    int setSize;        // Size of elements in the set
    int arraySize;      // The actual size of the set
    int *set;           // Array of elements
    
    SetAsOC();
    SetAsOC(const SetAsOC *clone);
    ~SetAsOC();
    void resize();
    void replaceSet(std::vector<int> replacement);
    void displaySet();
    int add(int element);
    int valueAtIndex(int index);
    int size();
    bool contains(int element);
    Set* copy() const;
};
