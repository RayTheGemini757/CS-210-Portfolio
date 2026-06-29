#include "ItemTracker.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor automatically loads the data when the object is created
ItemTracker::ItemTracker(const string& filename) {
    loadData(filename);
}

// Reads the text file and counts how many times each item appears
void ItemTracker::loadData(const string& filename) {
    ifstream file(filename);
    string item;

    // Check if the file opened properly
    if (!file.is_open()) {
        cout << "Error: Could not open the input file " << filename << endl;
        return;
    }

    // Read word by word until the end of the file
    while (file >> item) {
        // If the item is already in the map, increment its count. 
        // If it isn't, C++ automatically creates it with a value of 0, then adds 1.
        itemFrequencies[item]++;
    }

    file.close();
}

// Option 1: Look up a specific word
int ItemTracker::getItemFrequency(const string& item) {
    // If the item exists in our map, return its count
    if (itemFrequencies.find(item) != itemFrequencies.end()) {
        return itemFrequencies[item];
    }
    // Return 0 if the item wasn't in the original text file
    return 0;
}

// Option 2: Print out the full list of items and frequencies
void ItemTracker::printAllFrequencies() {
    cout << "\n--- Complete Item List ---" << endl;
    // Loop through the map and print key (item) and value (frequency)
    for (auto const& pair : itemFrequencies) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << "--------------------------" << endl;
}

// Option 3: Print out the text histogram using asterisks
void ItemTracker::printHistogram() {
    cout << "\n--- Item Frequency Histogram ---" << endl;
    for (auto const& pair : itemFrequencies) {
        cout << setw(15) << left << pair.first << " "; // Simple spacing to line things up nicely

        // Loop to print an asterisk for the item's count
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

// Data File Creation: Writes everything out to frequency.dat
void ItemTracker::saveBackup(const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error: Could not create backup file." << endl;
        return;
    }

    // Write the map contents to the backup file
    for (auto const& pair : itemFrequencies) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}