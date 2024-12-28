/* ********************************
 * Name: Aaron Ramirez
 * Assignment: 7 Hash Tables with Separate Chaining
 * Purpose: hashtable.h - Declaration of HashTable class
 **********************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

//Local libraries
#include "linkedlist.h"

//Standard libraries
#include <memory>  // For smart pointers
#include <string>
#include <iostream>

#define HASHTABLESIZE 15  // Define hash table size

class HashTable {
public:
    /**********************
    Constructors/Destructor
    ***********************/
    HashTable();

    /**********************
    Getters/Accessors
    ***********************/
    std::string getData(int) const;  // Retrieve data by ID
    int getCount() const;            // Get total entry count

    /**********************
    Setters/Mutators
    ***********************/
    bool insertEntry(int, std::string*);  // Insert an entry
    bool removeEntry(int);                // Remove entry by ID

    /**********************
    Printing Methods
    ***********************/
    void printTable() const;  // Print the entire hash table

private:
    int hash(int) const;  // Hash function

    /**********************
    Attributes
    ***********************/
    int count;  // Total entry count
    std::unique_ptr<LinkedList[]> table;  // Array of LinkedList objects
};

#endif // HASHTABLE_H
