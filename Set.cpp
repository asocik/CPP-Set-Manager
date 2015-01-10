//
//  Set.cpp
//  C++ Set Manager
//
//  Created by Adam Socik on 12/3/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#include "Set.h"

/*----------------------------------------------------------------------------
 Operator overload of subscripts []
 ----------------------------------------------------------------------------*/
int Set::operator[](int index) {
    return valueAtIndex(index);
}

/*----------------------------------------------------------------------------
 Takes the union of the set with the provided set.
 ----------------------------------------------------------------------------*/
void Set::unionWith(Set *otherSet) {
    for (int i=0; i<otherSet->size(); i++)
        add((*otherSet)[i]);
}

/*----------------------------------------------------------------------------
 Takes the intersection with the set and provided set. The class set is 
 replaced with the new intersection set.
 ----------------------------------------------------------------------------*/
void Set::intersectWith(Set *otherSet) {

    // Create a vector with all intersect values
    std::vector<int> intersect;
    
    for (int i=0; i<otherSet->size(); i++)
        if (contains((*otherSet)[i]))
            intersect.push_back((*otherSet)[i]);
        
    // Replace the set with the new intersect set
    replaceSet(intersect);
}

Set::~Set() {}
