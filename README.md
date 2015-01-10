#C++ Set Manager
The C++ Set Manager is a basic command line program that creates two sets and allows the user to perform several functions on them. While the overall premise of the program is simple, the main point was to intentionally over complicate the problem to take advantage of some of the more advanced features of C++'s object oriented design: inheritance and polymorphism. The program contains s super class Set, and two subclasses SetAsList and SetAsOC. SetAsList implements sets as linked lists while SetAsOC implements sets using a regular resizing array (similar to the vector class). Each of the set types support the following user inputted commands:

* l - Initialize sets A and B using the linked list implementation. The current sets A and B, if they exist, are deleted.
* o - Initialize sets sets A and B using the ordered collection implementation. The current sets A and B, if they exist, are deleted.
* e - Erase set A, A is bound to a new, empty set after this command is complete.
* s - Switch sets; the sets associated with A and B are swapped.
* c - Set A is deep copied into B, the previous content of B is lost.
* d - Display contents of both sets.
* a - Add element to set A (duplicates will not be added).
* u - This command takes the set union of A and B and stores the resulting value in A.
* i - This command takes the set intersection of A and B and stores the resulting value in A.
