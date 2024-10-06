#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

DynamicArray::DynamicArray(int initialCapacity)
{
    size = 0;
    capacity = initialCapacity;
    data = new int[capacity];
}
DynamicArray::~DynamicArray()
{
    delete[] data;
}
void DynamicArray::add(int value)
{
    if (size == capacity)
    {
        // Resize the array (double the capacity)
        capacity *= 2;
        int *newData = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
}
int DynamicArray::get(int index) const
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}
int DynamicArray::getSize() const
{
    return size;
}

int DynamicArray::getCapacity() const
{
    return capacity;
}
void DynamicArray::printArray() const
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}