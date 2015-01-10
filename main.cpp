//
//  main.cpp
//  C++ Set Manager
//
//  Created by Adam Socik on 11/26/14.
//  Copyright (c) 2014 Adam Socik. All rights reserved.
//

#include <iostream>
#include <string>
#include "Set.h"
#include "SetAsOC.h"
#include "SetAsList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Set *setA = nullptr;
    Set *setB = nullptr;
    string input = "";
    int setType = 0;    // 0 = OC, 1 = List
    bool initialized = false;
    
    cout << "-------- Set Manager --------\n"
    << "Type 'l' or 'o' to get started\n\n"
    << "Valid commands are:\n"
    << "'l': Initialize sets as lists\n"
    << "'o' :Initialize sets as ordered collections\n"
    << "'e' :Empty set A (deletes all elements)\n"
    << "'s' :The sets associated with A and B are swapped\n"
    << "'c' :Set A is deep copied into B\n"
    << "'d' :Display the contents of both sets\n"
    << "'a' :Add an element to set A\n"
    << "'u' :Take the set union of set A and B\n"
    << "'i' :Take the set intersecction of set A and B\n"
    << "'q' :Quit the program\n\n";
    
    while (input.compare("q")) {
        cout << "Enter commnand -> ";
        cin >> input;
        
        // Initialize sets as lists
        if (input.compare("l") == 0) {
            
            // If the sets have been initialized then delete them
            if (setA != nullptr) {
                delete setA;
                delete setB;
            }
            
            setA = new SetAsList();
            setB = new SetAsList();
            cout << "Sets initialized as lists\n\n";
            setType = 1;
            initialized = true;
        }
        
        // Initialize sets as ordered collections
        else if (input.compare("o") == 0) {
            
            // If the sets have been initialized then delete them
            if (setA != nullptr) {
                delete setA;
                delete setB;
            }
            
            setA = new SetAsOC();
            setB = new SetAsOC();
            cout << "Sets initialized as ordered collections\n\n";
            setType = 0;
            initialized = true;
        }
        
        // Empty set A (deletes all elements)
        else if (input.compare("e") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            delete setA;
            
            if (setType == 0)
                setA = new SetAsOC();
            else
                setA = new SetAsList();
            
            cout << "Set A was emptied\n\n";
        }
        
        // The sets associated with A and B are swapped
        else if (input.compare("s") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            Set *temp = setA;
            setA = setB;
            setB = temp;
            
            cout << "Set A was switched with set B\n\n";
        }
        
        // Set A is deep copied into B
        else if (input.compare("c") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            delete setB;
            setB = setA->copy();
            
            cout << "Set A was copied into set B\n\n";
        }
        
        // Display the contents of both sets
        else if (input.compare("d") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            cout << "Set A:\n";
            setA->displaySet();
            cout << "Set B:\n";
            setB->displaySet();
        }
        
        // Add an element to set A
        else if (input.compare("a") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            while (true) {
                string stringVal = "";
                cout << "Enter value to add -> ";
                cin  >> stringVal;
                
                try {
                    int intVal = stoi(stringVal);
                    
                    if (setA->add(intVal) == 1)
                        cout << intVal << " added to set A\n\n";
                    else
                        cout << intVal << " is already a member of set A\n\n";
                    break;
                } catch (std::invalid_argument) {
                    cout << "Please enter a valid integer\n\n";
                }
            }
        }
        
        // Take the set union of set A and B
        else if (input.compare("u") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            setA->unionWith(setB);
            cout << "Set union of set A and B stored in A\n\n";
        }
        
        // Take the set intersecction of set A and B
        else if (input.compare("i") == 0) {
            
            if (!initialized) {
                cout << "Type 'l' or 'o' initialize a set before typing other commands\n\n";
                continue;
            }
            
            setA->intersectWith(setB);
            cout << "Set intersection of set A and B stored in A\n\n";
        }
        
        else {
            cout << "Invalid command\n\n";
        }
    }
    
    cout << "\nEnding program...\n\n";
    return 0;
}
