#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main() {
    Queue normalQueue;
    Queue instantPassQueue;
    int choice;

    do {
        // Prints the menu for user input
        cout << "Menu:\n";
        cout << "1. ADD RIDER TO THE WAIT LINE.\n";
        cout << "2. REMOVE RIDER FORM THE LINE.\n";
        cout << "3. DONE FOR THE DAY\n";
        cout << "CHOOSE 1-3:\n";

        cin >> choice;
        cin.ignore();

        // Choice 1 adds a user and asks for pass type
        if (choice == 1) {
            string riderName;
            int passType;
            cout << "What is your name? ";
            getline(cin, riderName);
            cout << riderName << " , do you have a(n): " << endl;
            cout << "1. Normal Pass?\n";
            cout << "2. Instant Pass?\n";
            cout << "CHOOSE 1 or 2: ";
            cin >> passType;
            cin.ignore();
            
            // This is a loop to catch if the user to ensure they select 1 or 2
            while (passType != 1 && passType != 2) {
                cin.clear();
                cout << "That ain't right. CHOOSE 1 or 2: ";
                cin >> passType;
                cin.ignore();
            }

            if(passType == 2) {
                instantPassQueue.enqueue(riderName); // Adds user to Instant Queue
            } else {
                normalQueue.enqueue(riderName); // Adds user to nomral queue.
            }
        } else if (choice == 2) { // Removes a person for the line.
            if (!instantPassQueue.isEmpty()) {
                string riderName = instantPassQueue.dequeue(); // Instant rider line.
                cout << riderName << " , InstantPass holder, YOU ARE RIDING!\n";
            } else if (!normalQueue.isEmpty()) {
                string riderName = normalQueue.dequeue(); // Normal rider line.
                cout << riderName << " , normal pass holder, YOU ARE RIDING!\n";
            } else {
                cout << "No riders in the line!\n"; // Empty line.
            }
        } else if (choice == 3) {
            cout << "**IT IS QUITTING TIME!**\n"; // Closing time for the park.
        } else {
            cout << "Not a choice. Choose another selection!\n"; // Invalid input.
        }
    } while (choice != 3);
}