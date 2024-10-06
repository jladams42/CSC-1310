#include "DynamicArray.h"
#include <iostream>
using namespace std;

int main()
{
    DynamicArray arr;
    // Add int values to the array
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    // Print array size and capacity
    cout << "Array Size: " << arr.getSize() << endl;
    cout << "Array Capacity: " << arr.getCapacity() << endl;
    // Printing element at index 2
    cout << "Element at index 2: " << arr.get(2) << endl;
    // Printing all elements
    cout << "Array elements: ";
    arr.printArray();
    return 0;
}