# Doubly Linked List Implementation in C++

This repository contains a C++ implementation of a doubly linked list (DLL) data structure. It provides various functionalities for managing a collection of elements in a linear order, with efficient insertion and deletion at both ends and at any given index.

## Overview

A doubly linked list is a linear data structure where each element (node) contains a data item and pointers to both the next and the previous nodes in the sequence. This structure allows for bidirectional traversal and efficient modifications compared to singly linked lists or arrays in certain scenarios.

This implementation includes the following features:

* **Basic Operations:**
    * Creation of an empty list.
    * Copy constructor for creating a new list as a copy of an existing one.
    * Assignment operator for assigning one list to another.
    * Destructor to properly deallocate memory.
    * Checking if the list is empty.
    * Getting the current size of the list.
    * Printing the elements of the list.

* **Insertion:**
    * Adding an element to the front of the list (`add_front`).
    * Adding an element to the rear of the list (`add_rear`).
    * Inserting an element at a specific index (`add`).

* **Access:**
    * Retrieving the element at the front of the list (`front`).
    * Retrieving the element at the rear of the list (`rear`).
    * Peeking at the element at a specific index without removing it (`peek`).
    * Counting the number of occurrences of a specific item (`items`).
    * Searching for the first occurrence of a specific item and returning its index (`search`).

* **Deletion:**
    * Removing the element from the front of the list (`remove_front`).
    * Removing the element from the rear of the list (`remove_rear`).
    * Removing the element at a specific index (`remove_index`).
    * Removing the first occurrence of a specific item (`remove_item`).

* **Sublist Functionality:**
    * Checking if a given list is a sublist of the current list (`sub_list`).

## Implementation Details

The implementation consists of two main components:

* **`Node` Class:** Represents an individual element in the doubly linked list. Each node contains:
    * A data item of a generic type `Item`.
    * A pointer `next` to the next node in the list.
    * A pointer `prev` to the previous node in the list.

* **`DLList` Class:** Manages the collection of `Node` objects. It maintains:
    * A pointer `head` to the first node in the list.
    * A pointer `tail` to the last node in the list.
    * An integer `count` to keep track of the number of nodes in the list.

The function signatures for the `DLList` class were provided, and this repository contains the implementation of these functions to provide the described functionalities.

## How to Use

To use this doubly linked list implementation in your C++ project:

1.  **Include the Header File:** Copy the contents of your header file (the one containing the class definition and your implementations) into a file named `DLList.h` (or any other name you prefer with a `.h` extension). Make sure this file is accessible in your project's include path.

2.  **Include in Your Source Files:** In your C++ source files where you want to use the `DLList`, include the header file:

    ```c++
    #include "DLList.h"
    ```

3.  **Instantiate and Use:** You can then create instances of the `DLList` class with the desired data type and call its member functions:

    ```c++
    #include <iostream>
    #include "DLList.h"

    int main() {
        DLList<int> myList;

        myList.add_rear(10);
        myList.add_front(5);
        myList.add(1, 7);

        myList.print(); // Output: 5 7 10
        std::cout << std::endl;
        std::cout << "Size: " << myList.size() << std::endl; // Output: Size: 3

        std::cout << "Front: " << myList.front() << std::endl; // Output: Front: 5
        std::cout << "Rear: " << myList.rear() << std::endl;   // Output: Rear: 10

        if (myList.remove_front()) {
            std::cout << "Removed front element." << std::endl;
            myList.print(); // Output: 7 10
            std::cout << std::endl;
        }

        return 0;
    }
    ```

## Further Development

Potential areas for further development or improvement could include:

* Implementing iterators for more convenient traversal of the list.
* Adding sorting functionality.
* Implementing additional list operations (e.g., reversing the list, merging two lists).
* Writing more comprehensive unit tests to ensure the correctness and robustness of the implementation.

## License

*(You can add a license here if you wish, such as MIT, Apache 2.0, etc.)*
