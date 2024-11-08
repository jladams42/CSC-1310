#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class DynamicStack {
private:
    // Node struct for linked list
    struct StackNode {
        T value;
        StackNode* next;
    };

    StackNode* top;

public:
    // Constructor
    DynamicStack() : top (nullptr) {};
    // Destructor
    ~DynamicStack() {
        while (!isEmpty()) {
            T temp;
            pop(temp);
        } 
    }
    // Pushes to the top of the stack.
    void push(T item) {
        StackNode* newNode = new StackNode;
        newNode->value = item;
        newNode->next = top;
        top = newNode;
    }
    // Pops the top node from the stack and deletes it.
    void pop(T item) {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to pop.\n";
            return;
        }
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() const{
        return top == nullptr;
    }
};
#endif