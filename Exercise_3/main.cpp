// main.cpp
#include "sorter.h"

using namespace std; 

int main() {
    // Sample data to be sorted
    std::vector<int> data1 = {64, 25, 12, 22, 11};
    std::vector<int> data2 = {64, 25, 12, 22, 11};
    std::vector<int> data3 = {64, 25, 12, 22, 11};
    std::vector<int> data4 = {64, 25, 12, 22, 11};

    // Create sorter objects for each sorting algorithm
    SelectionSorter selectionSorter;
    InsertionSorter insertionSorter;
    BubbleSorter bubbleSorter;
    MergeSorter mergeSorter;

    // Measure and print time for Selection Sort
    std::cout << "Selection Sort:" << std::endl;
    double timeSelection = selectionSorter.measureSortTime(data1);
    selectionSorter.printArray(data1);
    std::cout << "Time taken: " << timeSelection << " microseconds" << std::endl;

    // Measure and print time for Insertion Sort
    std::cout << "Insertion Sort:" << std::endl;
    double timeInsertion = insertionSorter.measureSortTime(data2);
    insertionSorter.printArray(data2);
    std::cout << "Time taken: " << timeInsertion << " microseconds" << std::endl;

    // Measure and print time for Bubble Sort
    std::cout << "Bubble Sort:" << std::endl;
    double timeBubble = bubbleSorter.measureSortTime(data3);
    bubbleSorter.printArray(data3);
    std::cout << "Time taken: " << timeBubble << " microseconds" << std::endl;

    // Measure and print time for Merge Sort
    std::cout << "Merge Sort:" << std::endl;
    double timeMerge = mergeSorter.measureSortTime(data4);
    mergeSorter.printArray(data4);
    std::cout << "Time taken: " << timeMerge << " microseconds" << std::endl;

    return 0;
}
