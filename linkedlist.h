/* ********************************
 * Name: Aaron Ramirez
 * Assignment: 7 Hash Tables with Separate Chaining
 * Purpose: linkedlist.h - Declaration of LinkedList class
 **********************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Stamndard libraries
#include <iostream>
#include <string>
#include <memory>  // For smart pointers

//Local libraries
#include "data.h"

#define INVALID_ID -1      // Define invalid ID constant
#define NULL_PTR nullptr   // Define a NULL pointer for clarity

class LinkedList {
public:
    /**********************
    Constructors/Destructor
    ***********************/
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList&&) noexcept;                // Move constructor
    LinkedList& operator=(LinkedList&&) noexcept;     // Move assignment operator

    /**********************
    Getters/Accessors
    ***********************/
    bool getNode(int, Data&) const;            // Retrieve a node's data by ID
    int getCount() const;                      // Get count of nodes in the list

    /**********************
    Setters/Mutators
    ***********************/
    bool addNode(int, const std::string&);     // Add a node
    bool deleteNode(int);                      // Delete a node
    bool clearList();                          // Clear the entire list

    /**********************
    Printing Methods
    ***********************/
    void printList(bool = false) const;        // Print the list forward or backward

private:
    struct Node {
        Data data;
        std::shared_ptr<Node> next;  // Updated to shared_ptr for next node
        std::weak_ptr<Node> prev;    // Updated to weak_ptr for previous node

        Node(const Data& d) : data(d), next(NULL_PTR), prev() {}
    };

    void findNode(int, std::shared_ptr<Node>&) const;  // Locate a node by its ID, if found set the reference to that node

    /**********************
    Attributes
    ***********************/
    std::shared_ptr<Node> head;
};

#endif // LINKEDLIST_H
