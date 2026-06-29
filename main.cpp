#include <iostream>
#include "ItemTracker.h"

using namespace std;

// Helper function to print the actual menu choices
void displayMenu() {
    cout << "\n==== Corner Grocer Item Tracker ====" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print total list of frequencies" << endl;
    cout << "3. Print histogram of frequencies" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Initialize the tracker with the source file name
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");

    // Requirements state the backup file must be created at the start without user intervention
    tracker.saveBackup("frequency.dat");

    int choice = 0;
    string searchItem;

    // Loop until user chooses option 4 to exit
    while (choice != 4) {
        displayMenu();

        // Input validation: Check if user entered an actual number
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n'); // Discard bad input
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter the item name you want to look up: ";
            cin >> searchItem;
            cout << searchItem << " appeared " << tracker.getItemFrequency(searchItem) << " times." << endl;
            break;

        case 2:
            tracker.printAllFrequencies();
            break;

        case 3:
            tracker.printHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please select 1, 2, 3, or 4." << endl;
            break;
        }
    }

    return 0;
}