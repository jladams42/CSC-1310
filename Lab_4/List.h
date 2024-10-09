#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

// Struct to hold the node data of the strings passed to it
struct ListNode {
    string data;
    ListNode* next;

    ListNode(const string& str) : data(str), next(nullptr) {} // Contructor for the node
};

class LinkedList {
private:
    ListNode* head; // Pointer to the head position of the linked list
    ListNode* tail; /// Pointer ot the tail (Last) node of the linked list

public:
    LinkedList() : head(nullptr), tail(nullptr) {} // Contructor to intitialize an empty list

    // Destructor to clean up remaining nodes in the list
    ~LinkedList() {
        ListNode* current = head;
        while(current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "\nAll list nodes have been removed.";
    }

    // Appends a new node to the end of the list. 
    void appendNode(string string){
        ListNode* newNode = new ListNode(string);

        // Checks to see if the list is empty, if so it sets the head
        // and tail to the value of the new node. Or else it sets it 
        // to the next node and points the new node to the tail.
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Inserts a newNode alphabetically 
    void insertNode(string string) {
        ListNode* newNode = new ListNode(string); // Creates a new node
        ListNode* current = head; // Creates a current node that points to the head node

        // Sets current to next as long as its not going to a nullptr and < string
        while (current->next != nullptr && current->next->data < string) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        
    }

    // Deletes a node that matches a string input
    void deleteNode(string string) {
        ListNode* current = head; // Initializes a list node of current that points to the head

        // Loops through the linked list until it finds the string that matches the input and is not null
        while (current->next != nullptr && current->next->data != string) {
            current = current->next;
        }

        // Creates a temp node to hold the value being deleted and points the value before to the value
        // after deletion as long is next isn't a nullptr.
        if(current->next != nullptr) {
            ListNode* temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
            delete temp;
        }
    }

    // Simply displays all nodes in the list that aren't nullptrs
    void displayList() {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

#endif