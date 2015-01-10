//
//  SetAsList.cpp
//  C++ Set Manager
//
//  Created by Adam Socik on 11/26/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#include "SetAsList.h"

/*----------------------------------------------------------------------------
 Default constructor for a linked list
 ----------------------------------------------------------------------------*/
SetAsList::SetAsList() {
    head = nullptr;
}

/*----------------------------------------------------------------------------
 Copy constructor for an linked list set
 ----------------------------------------------------------------------------*/
SetAsList::SetAsList(const SetAsList *clone) {
    head = nullptr;
    
    for (Node *current = clone->head; current != nullptr; current = current->next)
        add(current->value);
}

/*----------------------------------------------------------------------------
 Destructor for the set linked list
 ----------------------------------------------------------------------------*/
SetAsList::~SetAsList() {
    
    while (head != nullptr) {
        Node *current = head;
        head = head->next;
        delete current;
    }
}

/*----------------------------------------------------------------------------
 Replaces the current set with a new one
 ----------------------------------------------------------------------------*/
void SetAsList::replaceSet(std::vector<int> replacement) {
    
    // Delete all old values
    while (head != nullptr) {
        Node *current = head;
        head = head->next;
        delete current;
    }
    
    // Add all of the elements to the new set
    head = nullptr;
    for (int val : replacement)
        add(val);
}

/*----------------------------------------------------------------------------
 Prints out the contents of the set
 ----------------------------------------------------------------------------*/
void SetAsList::displaySet() {
    
    if (size() == 0) {
        std::cout << "Set is empty\n\n";
        return;
    }
    
    for (Node *current = head; current != nullptr; current = current->next)
        std::cout << current->value << std::endl;
    std::cout << std::endl;
}

/*----------------------------------------------------------------------------
 Adds the element to the set if it is not already there
 ----------------------------------------------------------------------------*/
int SetAsList::add(int element) {
    
    // Empty list
    if (head == nullptr) {
        head = new Node(element, nullptr);
        return 1;
    }
    
    // If element is in the list then return
    if (contains(element))
        return -1;
    
    // Add to the end of the list
    Node *n1 = nullptr;
    Node *n2 = nullptr;
    for (n1 = head; n1 != nullptr; n1 = n1->next)
        n2 = n1;
    
    n2->next = new Node(element, nullptr);
    return 1;
}

/*----------------------------------------------------------------------------
 Returns the value in the set at the provided index
 ----------------------------------------------------------------------------*/
int SetAsList::valueAtIndex(int index) {
    
    if (index >= size()) {
        std::cout << "Index out of bounds\n";
        return 0;
    }
    
    int count = 0;
    for (Node *current = head; current != nullptr; current = current->next) {
        if (count == index)
            return current->value;
        count++;
    }
    
    return 0;   // Make compiler happy but will never get here
}

/*----------------------------------------------------------------------------
 Returns the size of the set
 ----------------------------------------------------------------------------*/
int SetAsList::size() {
    int count = 0;
    
    for (Node *current = head; current != nullptr; current = current->next)
        count++;
    
    return count;
}

/*----------------------------------------------------------------------------
 Checks to see if the set contains the integer provided
 ----------------------------------------------------------------------------*/
bool SetAsList::contains(int element) {

    for (Node *current = head; current != nullptr; current = current->next)
        if (current->value == element)
            return true;
    
    return false;
}

/*----------------------------------------------------------------------------
 Calls the copy constructor to return a copy of the set
 ----------------------------------------------------------------------------*/
Set* SetAsList::copy() const {
    return new SetAsList(this);
}

