/* *************************************************
 * Name: Aaron Ramirez
 * Assignment: 7 Hash Tables with Separate Chaining
 * Purpose: hashtable.cpp - Implementation of HashTable class
 ***************************************************/

#include "hashtable.h"

HashTable::HashTable() : count(0), table(std::make_unique<LinkedList[]>(HASHTABLESIZE)) {
/* *************************************************
 * Constructor
 * Initializes a hash table with empty linked lists
 * of size HASHTABLESIZE.
 *
 * @param none
 * @exception none
 * @return void
 ************************************************* */
}

int HashTable::hash(int id) const {
/* *************************************************
 * Hash function
 * Maps an ID to an index in the hash table array.
 *
 * @param int id
 * @exception none
 * @return int : index in hash table
 ************************************************* */
    return id % HASHTABLESIZE;
}

bool HashTable::insertEntry(int id, std::string* data) {
/* *************************************************
 * Insert Entry
 * Inserts an entry into the hash table.
 *
 * @param int id : identifier
 * @param string* data : pointer to string data
 * @exception none
 * @return bool : true if insertion succeeded, false otherwise
 ************************************************* */
    bool success = false;
    if (id > 0 && data && !data->empty()) {
        int index = hash(id);
        success = table[index].addNode(id, *data);
        if (success) {
            count++;
        }
    }
    return success;
}

std::string HashTable::getData(int id) const {
/* *************************************************
 * Get Data
 * Retrieves data associated with an ID.
 *
 * @param int id : identifier
 * @exception none
 * @return string : data associated with ID, or empty string if not found
 ************************************************* */
    std::string result;
    if (id > 0) {
        int index = hash(id);
        Data data;  // Define a Data variable instead of a pointer
        if (table[index].getNode(id, data)) {  // Pass Data by reference, not pointer
            result = data.data;
        }
    }
    return result;
}

bool HashTable::removeEntry(int id) {
/* *************************************************
 * Remove Entry
 * Removes an entry with the specified ID from the hash table.
 *
 * @param int id : identifier
 * @exception none
 * @return bool : true if removal succeeded, false otherwise
 ************************************************* */
    bool success = false;
    if (id > 0) {
        int index = hash(id);
        success = table[index].deleteNode(id);
        if (success) {
            count--;
        }
    }
    return success;
}

int HashTable::getCount() const {
/* *************************************************
 * Get Count
 * Returns the total number of entries in the hash table.
 *
 * @param none
 * @exception none
 * @return int : number of entries
 ************************************************* */
    return count;
}

void HashTable::printTable() const {
/* *************************************************
 * Print Table
 * Prints the entire hash table.
 *
 * @param none
 * @exception none
 * @return void
 ************************************************* */
    for (int i = 0; i < HASHTABLESIZE; i++) {
        std::cout << "Entry " << i << ": ";
        table[i].printList();
    }
}
