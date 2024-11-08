#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    // Private Struct for the Queue Node.
    struct QueueNode {
        string riderName;
        QueueNode *next;

        // Node constructor
        QueueNode (const string& name, QueueNode *nextNode = nullptr)
            : riderName(name), next(nextNode) {}
    };

    QueueNode *head;
    QueueNode *tail;
    int numNodes;

public:
    // Queue constructor. 
    Queue() : head(nullptr), tail(nullptr), numNodes(0) {}

    // Function that adds the provided name to the queue
    void enqueue(const string& name) {
        QueueNode *newNode = new QueueNode(name);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        numNodes++;
    }

    // Function to remove from the queue and have them "ride".
    string dequeue() {
        if (isEmpty()) {
            return "";
        }
        string name = head->riderName;
        QueueNode *temp = head;
        head = head->next;
        delete temp;
        numNodes--;
        if (isEmpty()) {
            tail = nullptr;
        }
        return name;
    }

    // Check if the queue is empty.
    bool isEmpty() const {
        return numNodes == 0;
    }

    // Destructor for the Queue.
    ~Queue() {
        while (!isEmpty()) {
            // Lets you know who all didn't get to ride.
            string riderName = dequeue();
            cout << "Oh shoot, I am sorry, our park is closed so " << riderName << " will not get to ride today.\n";
        }
    }
};

#endif