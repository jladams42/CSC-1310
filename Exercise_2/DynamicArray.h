#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
    int *data;
    int size;
    int capacity;

public:
    // Constructor
    DynamicArray(int initialCapacity = 2);
    // Destructor
    ~DynamicArray();
    // Adds an element to the array
    void add(int value);
    // Returns the element at the specified index
    int get(int index) const;
    // Returns the current number of elements
    int getSize() const;
    // Returns the current capacity of the array
    int getCapacity() const;
    // Prints all elements in the array
    void printArray() const;
};
#endif // DYNAMICARRAY_H