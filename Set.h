//
//  Set.h
//  C++ Set Manager
//
//  Created by Adam Socik on 12/3/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#ifndef __C___Set_Manager__Set__
#define __C___Set_Manager__Set__

#include <stdio.h>
#include <vector>

class Set {

public:
    virtual ~Set();
    virtual void replaceSet(std::vector<int> replacement) = 0;
    virtual void displaySet() = 0;
    virtual int add(int element) = 0;
    virtual int size() = 0;
    virtual int valueAtIndex(int index) = 0;
    virtual bool contains(int element) = 0;
    virtual Set* copy() const = 0;
    
    void unionWith(Set *otherSet);
    void intersectWith(Set *otherSet);
    int operator[] (int index);
};

#endif /* defined(__C___Set_Manager__Set__) */

