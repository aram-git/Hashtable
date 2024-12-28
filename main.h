/* *************************************************
 * Name: Aaron Ramirez
 * Assignment: 7 Hash Tables with Separate Chaining
 * Purpose: main.h - Header file for main application
 ************************************************* */

#ifndef MAIN_H
#define MAIN_H

 // Standard Libraries
#include <iostream>     // For cout, endl
#include <stdlib.h>     // For srand, rand
#include <time.h>       // For time
#include <string>       // For string

// Local Libraries
#include "hashtable.h"  // Include hash table class definition

// **Buffer and ID Constants**
#define BUFFERSIZE 8              // Buffer size for generating random strings
#define MAXID 100                 // Maximum ID value for test data
#define RANDOM_ID_RANGE 100       // Range for generating random IDs in tests

// **Test Data Generation Constants**
#define BASE 5                    // Base size for test data array
#define OFFSET 20                 // Offset for variability in test data size

// **Testing Scenario Constants**
#define TEST_ID 1                 // ID used for specific test cases
#define MID_RANGE_START 40        // Start of mid-range test ID
#define MID_RANGE_END 60          // End of mid-range test ID
#define OVERFLOW_TEST_COUNT 30    // Number of entries for overflow testing
#define OVERFLOW_MULTIPLIER HASHTABLESIZE  // Multiplier for generating overflow entries
#define STRESS_TEST_COUNT 1000    // Number of iterations for stress testing
#define RETRIEVAL_TEST_COUNT 80   // Number of retrieval operations in tests

using std::cout;
using std::endl;
using std::string;

#endif // MAIN_H
