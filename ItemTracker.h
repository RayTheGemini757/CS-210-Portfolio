#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class ItemTracker {
private:
    // Map to store item names and their purchase frequencies
    map<string, int> itemFrequencies;

    // Private helper function to load data from the file
    void loadData(const string& filename);

public:
    // Constructor
    ItemTracker(const string& filename);

    // Menu Option 1: Search for a specific item's frequency
    int getItemFrequency(const string& item);

    // Menu Option 2: Print all items and their frequencies
    void printAllFrequencies();

    // Menu Option 3: Print a text-based histogram
    void printHistogram();

    // Creates the frequency.dat backup file
    void saveBackup(const string& filename);
};

#endif