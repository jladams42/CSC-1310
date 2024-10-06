// sorter.h
#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <iostream>
#include <chrono> // Include for time measurement

// Base class for sorting algorithms
class Sorter {
public:
    // Pure virtual function for sorting
    virtual void sort(std::vector<int>& arr) = 0;

    // Method to print the elements of the array
    void printArray(const std::vector<int>& arr) const;

    // Method to measure and return the time taken to sort the array
    double measureSortTime(std::vector<int>& arr);

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Sorter() = default;
};

// Selection Sort implementation
class SelectionSorter : public Sorter {
public:
    void sort(std::vector<int>& arr) override;
};

// Insertion Sort implementation
class InsertionSorter : public Sorter {
public:
    void sort(std::vector<int>& arr) override;
};

// Bubble Sort implementation
class BubbleSorter : public Sorter {
public:
    void sort(std::vector<int>& arr) override;
};

// Merge Sort implementation
class MergeSorter : public Sorter {
public:
    void sort(std::vector<int>& arr) override;

private:
    // Helper functions for merge sort
    void mergeSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int middle, int right);
};

#endif // SORTER_H
