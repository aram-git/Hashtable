/* *************************************************
 * Name: Aaron Ramirez
 * Assignment: 7 Hash Tables with Separate Chaining
 * Purpose: main.cpp - Application driver for Hash Table
 ************************************************* */

#include "main.h"

int main() {
    /* *************************************************
     * This function is the application driver. It creates
     * test data, uses the HashTable object, and thoroughly
     * tests the hash table functionality.
     *
     * @param none
     * @return int : application exit code
     ************************************************* */

    // Seed the random number generator
    srand(time(NULL));

    // Counters for tracking successes and failures
    int successfulInserts = 0;
    int failedInserts = 0;
    int successfulRetrievals = 0;
    int failedRetrievals = 0;
    int successfulRemovals = 0;
    int failedRemovals = 0;

    // Create the hash table object
    HashTable table;

    /********************************************************
     * Underflow Testing - Test retrieval and removal on an
     * empty hash table to confirm handling of empty cases.
     ********************************************************/
    cout << "Underflow Testing: Attempt retrieval and removal on an empty table." << endl;
    int testID = TEST_ID;  // Sample ID for underflow testing
    string data = table.getData(testID);
    if (data.empty()) {
        cout << "Retrieval on empty table correctly returned no data." << endl;
    } else {
        cout << "Error: Retrieval on empty table returned unexpected data." << endl;
    }

    bool removed = table.removeEntry(testID);
    if (!removed) {
        cout << "Removal on empty table correctly failed." << endl;
    } else {
        cout << "Error: Removal on empty table succeeded unexpectedly." << endl;
    }
    cout << "Underflow Testing complete.\n" << endl;

    /********************************************************
     * Mid-Range Testing - Insert entries in the middle range
     * of hash table slots to verify balanced handling.
     ********************************************************/
    cout << "Mid-Range Testing: Insert entries with IDs from " << MID_RANGE_START << " to " << MID_RANGE_END << "." << endl;
    for (int i = MID_RANGE_START; i <= MID_RANGE_END; i++) {
        string testData = "Data_" + std::to_string(i);
        if (table.insertEntry(i, &testData)) {
            cout << "Inserted ID: " << i << " -> " << testData << endl;
            successfulInserts++;
        } else {
            cout << "Failed to insert ID: " << i << endl;
            failedInserts++;
        }
    }
    cout << "Mid-Range Testing complete.\n" << endl;

    /********************************************************
     * Overflow Testing - Insert entries exceeding hash table
     * size to verify handling of collisions and capacity.
     ********************************************************/
    cout << "Overflow Testing: Insert entries exceeding table size to test separate chaining." << endl;
    for (int i = 1; i <= OVERFLOW_TEST_COUNT; i++) {
        string testData = "Overflow_" + std::to_string(i);
        int id = i * OVERFLOW_MULTIPLIER;  // IDs that map to the same slot (overflow/collision)
        if (table.insertEntry(id, &testData)) {
            cout << "Inserted Overflow ID: " << id << " -> " << testData << endl;
            successfulInserts++;
        } else {
            cout << "Failed to insert Overflow ID: " << id << endl;
            failedInserts++;
        }
    }
    cout << "Overflow Testing complete.\n" << endl;

    /********************************************************
     * Stress Testing - Large number of random insertions to
     * test hash table’s robustness and performance.
     ********************************************************/
    cout << "Stress Testing: Inserting large number of random entries." << endl;
    for (int i = 0; i < STRESS_TEST_COUNT; i++) {
        int id = rand() % 1000 + 1;
        string testData = "Stress_" + std::to_string(id);
        bool success = table.insertEntry(id, &testData);
        if (success) {
            successfulInserts++;
        } else {
            failedInserts++;
        }
    }
    cout << "Stress Testing complete.\n" << endl;

    // Display insertion results
    cout << "Summary of Insertion:" << endl;
    cout << "Successful Inserts: " << successfulInserts << endl;
    cout << "Failed Inserts: " << failedInserts << endl << endl;

    // Reset counters for retrieval testing
    successfulRetrievals = 0;
    failedRetrievals = 0;

    /********************************************************
     * Retrieval Testing - Retrieve a mix of valid and
     * invalid IDs to validate the getData function.
     ********************************************************/
    cout << "Retrieval Testing: Attempt to retrieve inserted and non-existent IDs." << endl;
    for (int i = 0; i < RETRIEVAL_TEST_COUNT; i++) {
        int id = rand() % RANDOM_ID_RANGE + 1;  // Random IDs within a certain range
        string data = table.getData(id);
        if (!data.empty()) {
            cout << "Retrieved ID: " << id << " -> " << data << endl;
            successfulRetrievals++;
        } else {
            cout << "ID: " << id << " not found in table." << endl;
            failedRetrievals++;
        }
    }
    cout << "Retrieval Testing complete.\n" << endl;

    // Display retrieval results
    cout << "Summary of Retrieval:" << endl;
    cout << "Successful Retrievals: " << successfulRetrievals << endl;
    cout << "Failed Retrievals: " << failedRetrievals << endl << endl;

    // Reset counters for removal testing
    successfulRemovals = 0;
    failedRemovals = 0;

    /********************************************************
     * Removal Testing - Remove a range of IDs to test the
     * removeEntry function and validate correct count updates.
     ********************************************************/
    cout << "Removal Testing: Remove a set of IDs from the hash table." << endl;
    for (int i = MID_RANGE_START; i <= MID_RANGE_END; i++) {
        bool removed = table.removeEntry(i);
        if (removed) {
            cout << "Removed ID: " << i << endl;
            successfulRemovals++;
        } else {
            cout << "Failed to remove ID: " << i << endl;
            failedRemovals++;
        }
    }
    cout << "Removal Testing complete.\n" << endl;

    // Show the final table after removals
    cout << "Final table after all operations:" << endl;
    table.printTable();
    cout << "Total entries: " << table.getCount() << endl << endl;

    // Display removal results
    cout << "Summary of Removals:" << endl;
    cout << "Successful Removals: " << successfulRemovals << endl;
    cout << "Failed Removals: " << failedRemovals << endl << endl;

    return 0;
}
