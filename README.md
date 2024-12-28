## Assignment 7 - Hash Tables with Separate Chaining
## Author: Aaron Ramirez
## Purpose
This project implements a hash table using separate chaining to handle collisions. The hash table is built on an array of linked lists. Each linked list stores nodes that contain an integer ID and an associated string. The program demonstrates insertion, retrieval, and removal of entries, while tracking and reporting the success of these operations.

## Key Features
1. Separate Chaining for collision resolution.
2. Dynamic insertion and deletion of entries.
3. Hash function using modulo operation.
4. Robust error handling for invalid IDs and duplicate entries.
5. Comprehensive testing in main.cpp covering:
- Underflow scenarios.
- Overflow and mid-range insertions.
- Stress testing with large datasets.
- Retrieval, deletion, and validation of data integrity.

## Program Structure
- LinkedList Class: Implements a doubly linked list to store and manage nodes in separate chaining.
- HashTable Class: Manages an array of linked lists to handle hash table collisions.
- Main Program: Generates test data, inserts it into the hash table, retrieves and removes entries, and prints detailed results.

## Assignment Requirements & Where They Are Met
1. Implement a Separate Chaining Hash Table
- Fulfillment: Created a HashTable class that contains a hash table implemented as an array of LinkedList objects, effectively using separate chaining to handle collisions.
- Code Reference: In hashtable.h, defined the hash table as:
std::unique_ptr<LinkedList[]> table;  // Array of LinkedList objects

2. "Has-a" Relationship
- Fulfillment: The HashTable class "has a" collection of LinkedList objects, demonstrating composition in OOP.
- Code Reference: The HashTable contains the table attribute, which is an array of LinkedList instances.

3. Hash Table Size Defined with #define
- Fulfillment: The size of the hash table is set using a #define directive.
- Code Reference: In hashtable.h:
#define HASHTABLESIZE 15  // Define hash table size

4. Modulo as Hash Function
- Fulfillment: The hash function uses the modulo operation to compute indices.
- Code Reference: In hashtable.cpp:
int HashTable::hash(int id) const {
    return id % HASHTABLESIZE;
}

5. Extensive testing in main.cpp
- Fulfillment: main.cpp includes comprehensive tests that sometimes exceed the table size, ensuring robustness.
- Code Reference: In main.cpp, various test cases are executed to demonstrate functionality under different conditions.

6. Exhaustive Testing in main.cpp
- Fulfillment: Thoroughly tests all hash table functionalities, including insertion, retrieval, deletion, and printing.
- Code Reference: The testing code in main.cpp covers a wide range of scenarios, including edge cases.

7. Implemented Public Methods
- Fulfillment: All required public methods are implemented in the HashTable class:
bool insertEntry(int, string*), 
string getData(int), 
bool removeEntry(int), 
int getCount(), 
void printTable()
- Code Reference: These methods are declared in hashtable.h and defined in hashtable.cpp.

8. Private hash Method
- Fulfillment: A private method hash(int) is implemented to compute hash indices.
- Code Reference: In hashtable.h:
int hash(int) const;  // Hash function

9. Good Programming Practices and Submission Guidelines
- Fulfillment: The code follows best practices, including:
Proper use of smart pointers for memory management.
Implementation of move semantics.
No parameter names in function declarations within headers.
Replacement of literals with defined constants.
Detailed comments and consistent formatting.
- Code Reference: Throughout the code these practices are consistently applied.

10. Simplicity and Efficiency in Hash Table Methods
- Fulfillment: The hash table methods are simple and primarily delegate operations to the linked list methods.
- Code Reference: In hashtable.cpp, methods like insertEntry, getData, and removeEntry are concise and efficient.

## Additional Best Practices
- Memory Safety: By using std::shared_ptr and std::weak_ptr, thelogic ensures that memory is managed safely without leaks.
- Modular Design: The separation of concerns between HashTable and LinkedList enhances readability and maintainability.
- Commenting and Documentation: The comments follow the required format, providing clear explanations of each function's purpose, parameters, and return values.

## Compilation and Run Instructions
Compilation Command: To compile the program, ensure all the files are in the same directory, then use the following command:

g++ -o hashtable main.cpp hashtable.cpp linkedlist.cpp

Run Command: After successful compilation, run the program using:

./hashtable

## Output
The program gives detailed feedback on each operation, ensuring comprehensive testing of    the hash table's functionality. 
The program will:
- Generate random test data.
- Insert the data into the hash table, a summary of successful and failed insertions.
- Retrieve the data based on ID, with a summary of retrievals.
- Remove entries from the table and display a summary of removals.
- Print the contents of the hash table after each operation for easy verification.