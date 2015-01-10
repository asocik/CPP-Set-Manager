//
//  SetAsList.h
//  C++ Set Manager
//
//  Created by Adam Socik on 11/26/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#ifndef __C___Set_Manager__SetAsList__
#define __C___Set_Manager__SetAsList__

#include <iostream>
#include "Set.h"
#include <vector>

#endif /* defined(__C___Set_Manager__SetAsList__) */

// Node class for the linked list
class Node {
public:
    int value;
    Node *next;
    
    Node(int val, Node* nextNode) : value(val), next(nextNode) {};
};

class SetAsList : public Set {
public:
    Node *head;
    
    SetAsList();
    SetAsList(const SetAsList *clone);
    ~SetAsList();
    void replaceSet(std::vector<int> replacement);
    void displaySet();
    int add(int element);
    int valueAtIndex(int index);
    int size();
    bool contains(int element);
    Set* copy() const;
};

